//
//    rfnoc-hls-neuralnet: Vivado HLS code for neural-net building blocks
//
//    Copyright (C) 2017 EJ Kreinar
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#include <iostream>

#include "myproject.h"
#include "parameters.h"

void myproject(
    hls::stream<input21_t> em_endcap[4], hls::stream<input6_t> scalars[1], hls::stream<input_t> tracks[1],
    hls::stream<result_t> layer87_out[1]
	/*
	//weight18_t w18[196608],
	weight18_t w181[98304],
	weight18_t w182[98304],
	//weight22_t w22[524288],
	weight22_t w23[262144],
	weight22_t w24[262144],
	//weight27_t w27[1015808],
	weight27_t w271[507904],
	weight27_t w272[507904],
	weight55_t w55[36864],
	weight59_t w59[73728],
	weight66_t w66[147456],
	weight70_t w70[294912],
	weight76_t w76[589824],
	weight80_t w80[589824],
	weight83_t w83[65536]
	*/
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS DATAFLOW 

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        //nnet::load_weights_from_txt<d_weight13_t, 768>(w1_3, "w1_3.txt");
        nnet::load_weights_from_txt2<d_weight13_t, 768>(w1_3_new, "w1_3_new.txt");
        nnet::load_weights_from_txt<d_bias13_t, 128>(b1_3, "b1_3.txt");
        nnet::load_weights_from_txt2<d_weight23_t, 16384>(w2_3_new, "w2_3_new.txt");
        //nnet::load_weights_from_txt3<d_weight23_t, 16384>(w2_3, "w2_3.txt");
        nnet::load_weights_from_txt<d_bias23_t, 128>(b2_3, "b2_3.txt");
        nnet::load_weights_from_txt2<weight7_t, 16384>(w7_new, "w7_new.txt");
        //nnet::load_weights_from_txt3<weight7_t, 16384>(w7, "w7.txt");
        nnet::load_weights_from_txt<bias7_t, 128>(b7, "b7.txt");
        nnet::load_weights_from_txt2<weight11_t, 3840>(w11_new, "w11_new.txt");
        //nnet::load_weights_from_txt3<weight11_t, 3840>(w11, "w11.txt");
        nnet::load_weights_from_txt<bias11_t, 256>(b11, "b11.txt");
        nnet::load_weights_from_txt2<weight13_t, 16384>(w13_new, "w13_new.txt");
        //nnet::load_weights_from_txt<weight13_t, 16384>(w13, "w13.txt");
        //nnet::load_weights_from_txt3<weight13_t, 16384>(w13, "w13.txt");
        nnet::load_weights_from_txt<bias13_t, 128>(b13, "b13.txt");
        nnet::load_weights_from_txt2<weight18_t, 196608>(w18_new, "w18_new.txt");
        //nnet::load_weights_from_txt<weight18_t, 196608>(w18, "w18.txt");
        //nnet::load_weights_from_txt<weight18_t, 98304>(w181, "w181.txt");//
        //nnet::load_weights_from_txt<weight18_t, 98304>(w182, "w182.txt");//
        nnet::load_weights_from_txt<bias18_t, 512>(b18, "b18.txt");
        nnet::load_weights_from_txt2<weight22_t, 524288>(w22_new, "w22_new.txt");
        //nnet::load_weights_from_txt<weight22_t, 524288>(w22, "w22.txt");
        //nnet::load_weights_from_txt<weight22_t, 262144>(w23, "w23.txt");//
        //nnet::load_weights_from_txt<weight22_t, 262144>(w24, "w24.txt");//
        nnet::load_weights_from_txt<bias22_t, 1024>(b22, "b22.txt");
        nnet::load_weights_from_txt2<weight27_t, 1015808>(w27_new, "w27_new.txt");
        //nnet::load_weights_from_txt<weight27_t, 1015808>(w27, "w27.txt");
        //nnet::load_weights_from_txt<weight27_t, 507904>(w271, "w271.txt");//
        //nnet::load_weights_from_txt<weight27_t, 507904>(w272, "w272.txt");//
        nnet::load_weights_from_txt<bias27_t, 992>(b27, "b27.txt");
        nnet::load_weights_from_txt<weight29_t, 1600>(w29, "w29.txt");
        nnet::load_weights_from_txt<bias29_t, 16>(b29, "b29.txt");
        nnet::load_weights_from_txt<weight37_t, 4608>(w37, "w37.txt");
        nnet::load_weights_from_txt<bias37_t, 32>(b37, "b37.txt");
        nnet::load_weights_from_txt<weight44_t, 9216>(w44, "w44.txt");
        nnet::load_weights_from_txt<bias44_t, 32>(b44, "b44.txt");
        nnet::load_weights_from_txt<weight48_t, 18432>(w48, "w48.txt");
        nnet::load_weights_from_txt<bias48_t, 64>(b48, "b48.txt");
        nnet::load_weights_from_txt<weight55_t, 36864>(w55, "w55.txt");//
        nnet::load_weights_from_txt<bias55_t, 64>(b55, "b55.txt");
        nnet::load_weights_from_txt<weight59_t, 73728>(w59, "w59.txt");//
        nnet::load_weights_from_txt<bias59_t, 128>(b59, "b59.txt");
        nnet::load_weights_from_txt<weight66_t, 147456>(w66, "w66.txt");//
        nnet::load_weights_from_txt<bias66_t, 128>(b66, "b66.txt");
        nnet::load_weights_from_txt<weight70_t, 294912>(w70, "w70.txt");//
        nnet::load_weights_from_txt<bias70_t, 256>(b70, "b70.txt");
        nnet::load_weights_from_txt<weight76_t, 589824>(w76, "w76.txt");//
        nnet::load_weights_from_txt<bias76_t, 256>(b76, "b76.txt");
        //nnet::load_weights_from_txt<weight80_t, 589824>(w80, "w80.txt");//
        nnet::load_weights_from_txt2<weight80_t, 589824>(w80_new, "w80_new.txt");//
        nnet::load_weights_from_txt<bias80_t, 256>(b80, "b80.txt");
        //nnet::load_weights_from_txt<weight83_t, 65536>(w83, "w83.txt");//
        nnet::load_weights_from_txt2<weight83_t, 65536>(w83_new, "w83_new.txt");//
        nnet::load_weights_from_txt<bias83_t, 256>(b83, "b83.txt");
        nnet::load_weights_from_txt<weight86_t, 256>(w86, "w86.txt");
        nnet::load_weights_from_txt<bias86_t, 1>(b86, "b86.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    //hls-fpga-machine-learning insert layers

    hls::stream<layer2_t> layer2_out[1];
    #pragma HLS STREAM variable=layer2_out depth=76
    nnet::linear_single<input_t, layer2_t, linear_config2>(tracks, layer2_out); // quantized_tracks

    hls::stream<layer3_t> layer3_out[1];
    #pragma HLS STREAM variable=layer3_out depth=76
    nnet::timedistributed_single<layer2_t, layer3_t, config3>(layer2_out, layer3_out, w1_3_new, b1_3, w2_3_new, b2_3); // time_distributed

    hls::stream<layer4_t> layer4_out[1];
    #pragma HLS STREAM variable=layer4_out depth=1
    nnet::sum1d_single<layer3_t, layer4_t, config4>(layer3_out, layer4_out); // sum1d
	/*
    hls::stream<layer5_t> layer5_out[1];
    #pragma HLS STREAM variable=layer5_out depth=1
    nnet::linear_single<layer4_t, layer5_t, linear_config5>(layer4_out, layer5_out); // quantized_Sum1D
	*/
    hls::stream<layer7_t> layer7_out[1];
    #pragma HLS STREAM variable=layer7_out depth=1
    nnet::dense_ss_test<layer4_t, layer7_t, config7>(layer4_out, layer7_out, w7_new, b7); // q_dense_batchnorm_3
	/*
    hls::stream<layer8_t> layer8_out[1];
    #pragma HLS STREAM variable=layer8_out depth=1
    nnet::linear_single<layer7_t, layer8_t, linear_config8>(layer7_out, layer8_out); // q_dense_batchnorm_3_linear
	*/
    hls::stream<layer9_t> layer9_out[1];
    #pragma HLS STREAM variable=layer9_out depth=1
    nnet::linear_single<input6_t, layer9_t, linear_config9>(scalars, layer9_out); // quantized_scalars

    hls::stream<layer10_t> layer10_out[1];
    #pragma HLS STREAM variable=layer10_out depth=1
    nnet::relu_single<layer7_t, layer10_t, relu_config10>(layer7_out, layer10_out); // q_activation_7

    hls::stream<layer11_t> layer11_out[1];
    #pragma HLS STREAM variable=layer11_out depth=1
    nnet::dense_ss_test<layer9_t, layer11_t, config11>(layer9_out, layer11_out, w11_new, b11); // q_dense_batchnorm
	/*
    hls::stream<layer12_t> layer12_out[1];
    #pragma HLS STREAM variable=layer12_out depth=1
    nnet::linear_single<layer11_t, layer12_t, linear_config12>(layer11_out, layer12_out); // q_dense_batchnorm_linear
	*/
    hls::stream<layer13_t> layer13_out[1];
    #pragma HLS STREAM variable=layer13_out depth=1
    nnet::dense_ss_test<layer10_t, layer13_t, config13>(layer10_out, layer13_out, w13_new, b13); // q_dense_batchnorm_4
	/*
    hls::stream<layer14_t> layer14_out[1];
    #pragma HLS STREAM variable=layer14_out depth=1
    nnet::linear_single<layer13_t, layer14_t, linear_config14>(layer13_out, layer14_out); // q_dense_batchnorm_4_linear
	*/
    hls::stream<layer15_t> layer15_out[1];
    #pragma HLS STREAM variable=layer15_out depth=1
    nnet::relu_single<layer11_t, layer15_t, relu_config15>(layer11_out, layer15_out); // q_activation_4

    hls::stream<layer16_t> layer16_out[1];
    #pragma HLS STREAM variable=layer16_out depth=1
    nnet::relu_single<layer13_t, layer16_t, relu_config16>(layer13_out, layer16_out); // q_activation_8

    hls::stream<layer17_t> layer17_out[1];
    #pragma HLS STREAM variable=layer17_out depth=1
    nnet::concatenate1d_single<layer15_t, layer16_t, layer17_t, config17>(layer15_out, layer16_out, layer17_out); // concatenate

    hls::stream<layer18_t> layer18_out[1];
    #pragma HLS STREAM variable=layer18_out depth=1
    nnet::dense_ss_test<layer17_t, layer18_t, config18>(layer17_out, layer18_out, w18_new, b18); // q_dense_batchnorm_5
	/*
    hls::stream<layer19_t> layer19_out[1];
    #pragma HLS STREAM variable=layer19_out depth=1
    nnet::linear_single<layer18_t, layer19_t, linear_config19>(layer18_out, layer19_out); // q_dense_batchnorm_5_linear
	*/
    hls::stream<layer20_t> layer20_out[1];
    #pragma HLS STREAM variable=layer20_out depth=1
    nnet::relu_single<layer18_t, layer20_t, relu_config20>(layer18_out, layer20_out); // q_activation_9

    hls::stream<layer22_t> layer22_out[1];
    #pragma HLS STREAM variable=layer22_out depth=1
    nnet::dense_ss_test<layer20_t, layer22_t, config22>(layer20_out, layer22_out, w22_new, b22); // q_dense_batchnorm_6
	/*
    hls::stream<layer23_t> layer23_out[1];
    #pragma HLS STREAM variable=layer23_out depth=1
    nnet::linear_single<layer22_t, layer23_t, linear_config23>(layer22_out, layer23_out); // q_dense_batchnorm_6_linear
	*/
    hls::stream<layer24_t> layer24_out[4];
    #pragma HLS STREAM variable=layer24_out depth=616
    nnet::linear_switch<input21_t, layer24_t, linear_config24>(em_endcap, layer24_out); // quantized_em_endcap

    hls::stream<layer25_t> layer25_out[1];
    #pragma HLS STREAM variable=layer25_out depth=1
    nnet::relu_single<layer22_t, layer25_t, relu_config25>(layer22_out, layer25_out); // q_activation_10

    hls::stream<layer26_t> layer26_out[4];
    #pragma HLS STREAM variable=layer26_out depth=3080
    nnet::resize_nearest_switch<layer24_t, config26>(layer24_out, layer26_out); // up_sampling2d

    hls::stream<layer92_t> layer92_out[4];
    #pragma HLS STREAM variable=layer92_out depth=3540
    nnet::zeropad2d_cl_switch<layer26_t, layer92_t, config92>(layer26_out, layer92_out); // zp2d_q_conv2d_batchnorm

    hls::stream<layer27_t> layer27_out[1];
    #pragma HLS STREAM variable=layer27_out depth=1
    nnet::dense_ss_test<layer25_t, layer27_t, config27>(layer25_out, layer27_out, w27_new, b27); // q_dense
	/*
    hls::stream<layer28_t> layer28_out[1];
    #pragma HLS STREAM variable=layer28_out depth=1
    nnet::linear_single<layer27_t, layer28_t, linear_config28>(layer27_out, layer28_out); // q_dense_linear
	*/
    hls::stream<layer29_t> layer29_out[16];
    #pragma HLS STREAM variable=layer29_out depth=3080
    nnet::conv_2d_cl_switch<layer92_t, layer29_t, config29>(layer92_out, layer29_out, w29, b29); // q_conv2d_batchnorm
	/*
    hls::stream<layer30_t> layer30_out[1];
    #pragma HLS STREAM variable=layer30_out depth=3080
    nnet::linear_single<layer29_t, layer30_t, linear_config30>(layer29_out, layer30_out); // q_conv2d_batchnorm_linear
	*/
    hls::stream<layer31_t> layer31_out[1];
    #pragma HLS STREAM variable=layer31_out depth=1
    nnet::relu_single<layer27_t, layer31_t, relu_config31>(layer27_out, layer31_out); // q_activation_11

    hls::stream<layer88_t> layer88_cpy1[1];
    #pragma HLS STREAM variable=layer88_cpy1 depth=1
    hls::stream<layer88_t> layer88_cpy2[1];
    #pragma HLS STREAM variable=layer88_cpy2 depth=1
    nnet::clone_stream_single<layer31_t, layer88_t, 992>(layer31_out, layer88_cpy1, layer88_cpy2); // clone_q_activation_11

    hls::stream<layer32_t> layer32_out[16];
    #pragma HLS STREAM variable=layer32_out depth=3080
    nnet::relu_switch<layer29_t, layer32_t, relu_config32>(layer29_out, layer32_out); // q_activation_12

    hls::stream<layer33_t> layer33_out[1];
    #pragma HLS STREAM variable=layer33_out depth=1
    nnet::slice_tensor1d_single<layer88_t, layer33_t, config33>(layer88_cpy1, layer33_out); // slice_tensor1d

    hls::stream<layer34_t> layer34_out[16];
    #pragma HLS STREAM variable=layer34_out depth=3080
    nnet::film_switch<layer32_t, layer33_t, layer34_t, config34>(layer32_out, layer33_out, layer34_out); // fi_lm
	/*
    hls::stream<layer35_t> layer35_out[1];
    #pragma HLS STREAM variable=layer35_out depth=3080
    nnet::linear_single<layer34_t, layer35_t, linear_config35>(layer34_out, layer35_out); // q_activation_13
	*/
    hls::stream<layer36_t> layer36_out[16];
    #pragma HLS STREAM variable=layer36_out depth=756
    nnet::pooling2d_cl_switch<layer34_t, layer36_t, config36>(layer34_out, layer36_out); // max_pooling2d

    hls::stream<layer93_t> layer93_out[16];
    #pragma HLS STREAM variable=layer93_out depth=870
    nnet::zeropad2d_cl_switch<layer36_t, layer93_t, config93>(layer36_out, layer93_out); // zp2d_q_conv2d_batchnorm_1

    hls::stream<layer37_t> layer37_out[32];
    #pragma HLS STREAM variable=layer37_out depth=756
    nnet::conv_2d_cl_switch<layer93_t, layer37_t, config37>(layer93_out, layer37_out, w37, b37); // q_conv2d_batchnorm_1
	/*
    hls::stream<layer38_t> layer38_out[1];
    #pragma HLS STREAM variable=layer38_out depth=756
    nnet::linear_single<layer37_t, layer38_t, linear_config38>(layer37_out, layer38_out); // q_conv2d_batchnorm_1_linear
	*/
    hls::stream<layer39_t> layer39_out[1];
    #pragma HLS STREAM variable=layer39_out depth=1
    nnet::slice_tensor1d_single<layer88_t, layer39_t, config39>(layer88_cpy2, layer39_out); // slice_tensor1d_1

    hls::stream<layer89_t> layer89_cpy1[1];
    #pragma HLS STREAM variable=layer89_cpy1 depth=1
    hls::stream<layer89_t> layer89_cpy2[1];
    #pragma HLS STREAM variable=layer89_cpy2 depth=1
    nnet::clone_stream_single<layer39_t, layer89_t, 960>(layer39_out, layer89_cpy1, layer89_cpy2); // clone_slice_tensor1d_1

    hls::stream<layer40_t> layer40_out[32];
    #pragma HLS STREAM variable=layer40_out depth=756
    nnet::relu_switch<layer37_t, layer40_t, relu_config40>(layer37_out, layer40_out); // q_activation_14

    hls::stream<layer41_t> layer41_out[1];
    #pragma HLS STREAM variable=layer41_out depth=1
    nnet::slice_tensor1d_single<layer89_t, layer41_t, config41>(layer89_cpy1, layer41_out); // slice_tensor1d_2

    hls::stream<layer42_t> layer42_out[32];
    #pragma HLS STREAM variable=layer42_out depth=756
    nnet::film_switch<layer40_t, layer41_t, layer42_t, config42>(layer40_out, layer41_out, layer42_out); // fi_lm_1
	/*
    hls::stream<layer43_t> layer43_out[1];
    #pragma HLS STREAM variable=layer43_out depth=756
    nnet::linear_single<layer42_t, layer43_t, linear_config43>(layer42_out, layer43_out); // q_activation_15
	*/
    hls::stream<layer94_t> layer94_out[32];
    #pragma HLS STREAM variable=layer94_out depth=870
    nnet::zeropad2d_cl_switch<layer42_t, layer94_t, config94>(layer42_out, layer94_out); // zp2d_q_conv2d_batchnorm_2

    hls::stream<layer44_t> layer44_out[32];
    #pragma HLS STREAM variable=layer44_out depth=756
    nnet::conv_2d_cl_switch<layer94_t, layer44_t, config44>(layer94_out, layer44_out, w44, b44); // q_conv2d_batchnorm_2
	/*
    hls::stream<layer45_t> layer45_out[1];
    #pragma HLS STREAM variable=layer45_out depth=756
    nnet::linear_single<layer44_t, layer45_t, linear_config45>(layer44_out, layer45_out); // q_conv2d_batchnorm_2_linear
	*/
    hls::stream<layer46_t> layer46_out[32];
    #pragma HLS STREAM variable=layer46_out depth=756
    nnet::relu_switch<layer44_t, layer46_t, relu_config46>(layer44_out, layer46_out); // q_activation_16

    hls::stream<layer47_t> layer47_out[32];
    #pragma HLS STREAM variable=layer47_out depth=182
    nnet::pooling2d_cl_switch<layer46_t, layer47_t, config47>(layer46_out, layer47_out); // max_pooling2d_1

    hls::stream<layer95_t> layer95_out[32];
    #pragma HLS STREAM variable=layer95_out depth=240
    nnet::zeropad2d_cl_switch<layer47_t, layer95_t, config95>(layer47_out, layer95_out); // zp2d_q_conv2d_batchnorm_3

    hls::stream<layer48_t> layer48_out[1];
    #pragma HLS STREAM variable=layer48_out depth=182
    nnet::conv_2d_cl_switch<layer95_t, layer48_t, config48>(layer95_out, layer48_out, w48, b48); // q_conv2d_batchnorm_3
	/*
    hls::stream<layer49_t> layer49_out[1];
    #pragma HLS STREAM variable=layer49_out depth=182
    nnet::linear_single<layer48_t, layer49_t, linear_config49>(layer48_out, layer49_out); // q_conv2d_batchnorm_3_linear
	*/
    hls::stream<layer50_t> layer50_out[1];
    #pragma HLS STREAM variable=layer50_out depth=1
    nnet::slice_tensor1d_single<layer89_t, layer50_t, config50>(layer89_cpy2, layer50_out); // slice_tensor1d_3

    hls::stream<layer90_t> layer90_cpy1[1];
    #pragma HLS STREAM variable=layer90_cpy1 depth=1
    hls::stream<layer90_t> layer90_cpy2[1];
    #pragma HLS STREAM variable=layer90_cpy2 depth=1
    nnet::clone_stream_single<layer50_t, layer90_t, 896>(layer50_out, layer90_cpy1, layer90_cpy2); // clone_slice_tensor1d_3

    hls::stream<layer51_t> layer51_out[1];
    #pragma HLS STREAM variable=layer51_out depth=182
    nnet::relu_switch<layer48_t, layer51_t, relu_config51>(layer48_out, layer51_out); // q_activation_17

    hls::stream<layer52_t> layer52_out[1];
    #pragma HLS STREAM variable=layer52_out depth=1
    nnet::slice_tensor1d_single<layer90_t, layer52_t, config52>(layer90_cpy1, layer52_out); // slice_tensor1d_4

    hls::stream<layer53_t> layer53_out[1];
    #pragma HLS STREAM variable=layer53_out depth=182
    nnet::film_switch<layer51_t, layer52_t, layer53_t, config53>(layer51_out, layer52_out, layer53_out); // fi_lm_2
	/*
    hls::stream<layer54_t> layer54_out[1];
    #pragma HLS STREAM variable=layer54_out depth=182
    nnet::linear_single<layer53_t, layer54_t, linear_config54>(layer53_out, layer54_out); // q_activation_18
	*/
    hls::stream<layer96_t> layer96_out[1];
    #pragma HLS STREAM variable=layer96_out depth=240
    nnet::zeropad2d_cl_switch<layer53_t, layer96_t, config96>(layer53_out, layer96_out); // zp2d_q_conv2d_batchnorm_4

    hls::stream<layer55_t> layer55_out[1];
    #pragma HLS STREAM variable=layer55_out depth=182
    nnet::conv_2d_cl_switch<layer96_t, layer55_t, config55>(layer96_out, layer55_out, w55, b55); // q_conv2d_batchnorm_4
	/*
    hls::stream<layer56_t> layer56_out[1];
    #pragma HLS STREAM variable=layer56_out depth=182
    nnet::linear_single<layer55_t, layer56_t, linear_config56>(layer55_out, layer56_out); // q_conv2d_batchnorm_4_linear
	*/
    hls::stream<layer57_t> layer57_out[1];
    #pragma HLS STREAM variable=layer57_out depth=182
    nnet::relu_switch<layer55_t, layer57_t, relu_config57>(layer55_out, layer57_out); // q_activation_19

    hls::stream<layer58_t> layer58_out[1];
    #pragma HLS STREAM variable=layer58_out depth=42
    nnet::pooling2d_cl_switch<layer57_t, layer58_t, config58>(layer57_out, layer58_out); // max_pooling2d_2

    hls::stream<layer97_t> layer97_out[1];
    #pragma HLS STREAM variable=layer97_out depth=72
    nnet::zeropad2d_cl_switch<layer58_t, layer97_t, config97>(layer58_out, layer97_out); // zp2d_q_conv2d_batchnorm_5

    hls::stream<layer59_t> layer59_out[1];
    #pragma HLS STREAM variable=layer59_out depth=42
    nnet::conv_2d_cl_switch<layer97_t, layer59_t, config59>(layer97_out, layer59_out, w59, b59); // q_conv2d_batchnorm_5
	/*
    hls::stream<layer60_t> layer60_out[1];
    #pragma HLS STREAM variable=layer60_out depth=42
    nnet::linear_single<layer59_t, layer60_t, linear_config60>(layer59_out, layer60_out); // q_conv2d_batchnorm_5_linear
	*/
    hls::stream<layer61_t> layer61_out[1];
    #pragma HLS STREAM variable=layer61_out depth=1
    nnet::slice_tensor1d_single<layer90_t, layer61_t, config61>(layer90_cpy2, layer61_out); // slice_tensor1d_5

    hls::stream<layer91_t> layer91_cpy1[1];
    #pragma HLS STREAM variable=layer91_cpy1 depth=1
    hls::stream<layer91_t> layer91_cpy2[1];
    #pragma HLS STREAM variable=layer91_cpy2 depth=1
    nnet::clone_stream_single<layer61_t, layer91_t, 768>(layer61_out, layer91_cpy1, layer91_cpy2); // clone_slice_tensor1d_5

    hls::stream<layer62_t> layer62_out[1];
    #pragma HLS STREAM variable=layer62_out depth=42
    nnet::relu_switch<layer59_t, layer62_t, relu_config62>(layer59_out, layer62_out); // q_activation_20

    hls::stream<layer63_t> layer63_out[1];
    #pragma HLS STREAM variable=layer63_out depth=1
    nnet::slice_tensor1d_single<layer91_t, layer63_t, config63>(layer91_cpy1, layer63_out); // slice_tensor1d_6

    hls::stream<layer64_t> layer64_out[1];
    #pragma HLS STREAM variable=layer64_out depth=42
    nnet::film_switch<layer62_t, layer63_t, layer64_t, config64>(layer62_out, layer63_out, layer64_out); // fi_lm_3
	/*
    hls::stream<layer65_t> layer65_out[1];
    #pragma HLS STREAM variable=layer65_out depth=42
    nnet::linear_single<layer64_t, layer65_t, linear_config65>(layer64_out, layer65_out); // q_activation_21
	*/
    hls::stream<layer98_t> layer98_out[1];
    #pragma HLS STREAM variable=layer98_out depth=72
    nnet::zeropad2d_cl_switch<layer64_t, layer98_t, config98>(layer64_out, layer98_out); // zp2d_q_conv2d_batchnorm_6

    hls::stream<layer66_t> layer66_out[1];
    #pragma HLS STREAM variable=layer66_out depth=42
    nnet::conv_2d_cl_switch<layer98_t, layer66_t, config66>(layer98_out, layer66_out, w66, b66); // q_conv2d_batchnorm_6
	/*
    hls::stream<layer67_t> layer67_out[1];
    #pragma HLS STREAM variable=layer67_out depth=42
    nnet::linear_single<layer66_t, layer67_t, linear_config67>(layer66_out, layer67_out); // q_conv2d_batchnorm_6_linear
	*/
    hls::stream<layer68_t> layer68_out[1];
    #pragma HLS STREAM variable=layer68_out depth=42 
    nnet::relu_switch<layer66_t, layer68_t, relu_config68>(layer66_out, layer68_out); // q_activation_22

    hls::stream<layer69_t> layer69_out[1];
    #pragma HLS STREAM variable=layer69_out depth=9
    nnet::pooling2d_cl_switch<layer68_t, layer69_t, config69>(layer68_out, layer69_out); // max_pooling2d_3

    hls::stream<layer99_t> layer99_out[1];
    #pragma HLS STREAM variable=layer99_out depth=25
    nnet::zeropad2d_cl_switch<layer69_t, layer99_t, config99>(layer69_out, layer99_out); // zp2d_q_conv2d_batchnorm_7

    hls::stream<layer70_t> layer70_out[1];
    #pragma HLS STREAM variable=layer70_out depth=9
    nnet::conv_2d_cl_switch<layer99_t, layer70_t, config70>(layer99_out, layer70_out, w70, b70); // q_conv2d_batchnorm_7
	/*
    hls::stream<layer71_t> layer71_out[1];
    #pragma HLS STREAM variable=layer71_out depth=9
    nnet::linear_single<layer70_t, layer71_t, linear_config71>(layer70_out, layer71_out); // q_conv2d_batchnorm_7_linear
	*/
    hls::stream<layer72_t> layer72_out[1];
    #pragma HLS STREAM variable=layer72_out depth=9
    nnet::relu_switch<layer70_t, layer72_t, relu_config72>(layer70_out, layer72_out); // q_activation_23

    hls::stream<layer73_t> layer73_out[1];
    #pragma HLS STREAM variable=layer73_out depth=1
    nnet::slice_tensor1d_single<layer91_t, layer73_t, config73>(layer91_cpy2, layer73_out); // slice_tensor1d_7
	
    hls::stream<layer74_t> layer74_out[1];
    #pragma HLS STREAM variable=layer74_out depth=9
    nnet::film_switch<layer72_t, layer73_t, layer74_t, config74>(layer72_out, layer73_out, layer74_out); // fi_lm_4
	/*
    hls::stream<layer75_t> layer75_out[1];
    #pragma HLS STREAM variable=layer75_out depth=9
    nnet::linear_single<layer74_t, layer75_t, linear_config75>(layer74_out, layer75_out); // q_activation_24
	*/
    hls::stream<layer100_t> layer100_out[1];
    #pragma HLS STREAM variable=layer100_out depth=25
    nnet::zeropad2d_cl_switch<layer74_t, layer100_t, config100>(layer74_out, layer100_out); // zp2d_q_conv2d_batchnorm_8

    hls::stream<layer76_t> layer76_out[1];
    #pragma HLS STREAM variable=layer76_out depth=9
    nnet::conv_2d_cl_switch<layer100_t, layer76_t, config76>(layer100_out, layer76_out, w76, b76); // q_conv2d_batchnorm_8
	/*
    hls::stream<layer77_t> layer77_out[1];
    #pragma HLS STREAM variable=layer77_out depth=9
    nnet::linear_single<layer76_t, layer77_t, linear_config77>(layer76_out, layer77_out); // q_conv2d_batchnorm_8_linear
	*/
    hls::stream<layer78_t> layer78_out[1];
    #pragma HLS STREAM variable=layer78_out depth=9
    nnet::relu_switch<layer76_t, layer78_t, relu_config78>(layer76_out, layer78_out); // q_activation_25

    hls::stream<layer80_t> layer80_out[1];
    #pragma HLS STREAM variable=layer80_out depth=1
    nnet::dense_ss_test<layer78_t, layer80_t, config80>(layer78_out, layer80_out, w80_new, b80); // q_dense_batchnorm_7
	/*
    hls::stream<layer81_t> layer81_out[1];
    #pragma HLS STREAM variable=layer81_out depth=1
    nnet::linear_single<layer80_t, layer81_t, linear_config81>(layer80_out, layer81_out); // q_dense_batchnorm_7_linear
	*/
    hls::stream<layer82_t> layer82_out[1];
    #pragma HLS STREAM variable=layer82_out depth=1
    nnet::relu_switch<layer80_t, layer82_t, relu_config82>(layer80_out, layer82_out); // q_activation_26

    hls::stream<layer83_t> layer83_out[1];
    #pragma HLS STREAM variable=layer83_out depth=1
    nnet::dense_ss_test<layer82_t, layer83_t, config83>(layer82_out, layer83_out, w83_new, b83); // q_dense_batchnorm_8
	/*
    hls::stream<layer84_t> layer84_out[1];
    #pragma HLS STREAM variable=layer84_out depth=1
    nnet::linear_single<layer83_t, layer84_t, linear_config84>(layer83_out, layer84_out); // q_dense_batchnorm_8_linear
	*/
    hls::stream<layer85_t> layer85_out[1];
    #pragma HLS STREAM variable=layer85_out depth=1
    nnet::relu_switch<layer83_t, layer85_t, relu_config85>(layer83_out, layer85_out); // q_activation_27

    hls::stream<layer86_t> layer86_out[1];
    #pragma HLS STREAM variable=layer86_out depth=1
    nnet::dense_ss<layer85_t, layer86_t, config86>(layer85_out, layer86_out, w86, b86); // q_dense_1

    nnet::linear_single<layer86_t, result_t, linear_config87>(layer86_out, layer87_out); // q_dense_1_linear

}
