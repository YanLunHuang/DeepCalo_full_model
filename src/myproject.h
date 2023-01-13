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

#ifndef MYPROJECT_H_
#define MYPROJECT_H_

#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_stream.h"

#include "defines.h"

// Prototype of top level function for C-synthesis
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
);

#endif
