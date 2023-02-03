/**********
Copyright (c) 2018, Xilinx, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**********/

/*******************************************************************************
Description:
    HLS pragmas can be used to optimize the design : improve throughput, reduce latency and 
    device resource utilization of the resulting RTL code
    This is a wrapper to be used with an hls4ml project to enable proper handling by SDAccel
*******************************************************************************/
#include <iostream>

#include "myproject.h"
#include "kernel_params.h"


extern "C" {

void alveo_hls4ml(
	const input_group *em_barrel, // Read-Only Vector
	const bigdata_t *scalars, // Read-Only Vector
	const bigdata_t *tracks, // Read-Only Vector
	bigdata_t *out       // Output Result
	)
{
	#pragma HLS INTERFACE m_axi port=em_barrel  offset=slave bundle=gmem0
	#pragma HLS INTERFACE m_axi port=scalars  offset=slave bundle=gmem1
	#pragma HLS INTERFACE m_axi port=tracks  offset=slave bundle=gmem2
	#pragma HLS INTERFACE m_axi port=out offset=slave bundle=gmem3
	#pragma HLS INTERFACE s_axilite port=em_barrel   bundle=control
	#pragma HLS INTERFACE s_axilite port=scalars   bundle=control
	#pragma HLS INTERFACE s_axilite port=tracks   bundle=control
	#pragma HLS INTERFACE s_axilite port=out  bundle=control
	#pragma HLS INTERFACE s_axilite port=return bundle=control
	//necessary for hls4ml kernel, not used

	bigdata_t em_barrel_buf[em_barrel_STREAM_LEN][em_barrel_CHANNEL_SIZE];
	#pragma HLS ARRAY_PARTITION variable=em_barrel_buf complete dim=2
	bigdata_t scalars_buf[scalars_STREAM_LEN];
	bigdata_t tracks_buf[tracks_STREAM_LEN];
	bigdata_t out_bigbuf;
	
	hls::stream<input21_t> em_barrel_stream[em_barrel_CHANNEL_SIZE];
	hls::stream<input6_t> scalars_stream[1];
	hls::stream<input_t> tracks_stream[1];
	hls::stream<result_t> out_stream[1];
	//these will get partitioned properly in the hls4ml code

	//#pragma HLS ARRAY_PARTITION   variable=in_buf  complete dim=0
	//#pragma HLS ARRAY_PARTITION   variable=out_buf complete dim=0
	#pragma HLS STREAM   variable=em_barrel_stream  depth=616
	#pragma HLS STREAM   variable=scalars_stream  depth=1
	#pragma HLS STREAM   variable=tracks_stream  depth=76
	#pragma HLS STREAM   variable=out_stream depth=1
	
  //getting data from DRAM
  for (int k = 0; k < DATA_SET; k++){
	#pragma HLS DATAFLOW
	for (int i = 0; i < em_barrel_STREAM_LEN; i++) {
		#pragma HLS PIPELINE II=1
		for (int j = 0; j < em_barrel_CHANNEL_SIZE; j++) {
			#pragma HLS UNROLL
			em_barrel_buf[i][j] = em_barrel[i+k*em_barrel_STREAM_LEN].layer[j];
		}
	}
	for (int i = 0; i < scalars_STREAM_LEN; i++) {
		#pragma HLS PIPELINE II=1
		scalars_buf[i] = scalars[i+k*scalars_STREAM_LEN];
	}
	for (int i = 0; i < tracks_STREAM_LEN; i++) {
		#pragma HLS PIPELINE II=1
		tracks_buf[i] = tracks[i+k*tracks_STREAM_LEN];
	}
	std::cout<<"------------------"<<std::endl;
	//=============================================
	//input
	//=============================================

	for(int i0 = 0; i0 < em_barrel_STREAM_LEN; i0++) {
		#pragma HLS PIPELINE II=1
		for(int i1 = 0; i1 < em_barrel_CHANNEL_SIZE; i1++) {
			#pragma HLS UNROLL
			input21_t tmp = em_barrel_buf[i0][i1];
			em_barrel_stream[i1].write(tmp);
		}
	}
	
	for(int i0 = 0; i0 < scalars_STREAM_LEN; i0++) { 
		#pragma HLS PIPELINE II=1
		input6_t tmp2 = scalars_buf[i0];
		scalars_stream[0].write(tmp2);
	}
	
	for(int i0 = 0; i0 < tracks_STREAM_LEN; i0++) { 
		#pragma HLS PIPELINE II=1
		input_t tmp3 = tracks_buf[i0];
		tracks_stream[0].write(tmp3);
	}
	std::cout<<"inf start"<<std::endl;
	myproject(em_barrel_stream,scalars_stream,tracks_stream,out_stream);
	std::cout<<"inf end"<<std::endl;

	//=============================================
	//output
	//=============================================
	for(int i1 = 0; i1 < OUT_STREAM_LEN; i1++) {
		#pragma HLS PIPELINE II=1
		result_t tmp_small = out_stream[0].read();
		out_bigbuf = tmp_small;
	}
	out[k] = out_bigbuf;
  }
}
}
