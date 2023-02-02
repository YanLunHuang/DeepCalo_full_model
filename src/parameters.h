#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include "ap_int.h"
#include "ap_fixed.h"

#include "nnet_utils/nnet_helpers.h"
#include "nnet_utils/nnet_code_gen.h"
//hls-fpga-machine-learning insert includes
#include "nnet_utils/nnet_activation.h"
#include "nnet_utils/nnet_activation_stream.h"
#include "nnet_utils/nnet_conv2d.h"
#include "nnet_utils/nnet_conv2d_stream.h"
#include "nnet_utils/nnet_deepcalo.h"
#include "nnet_utils/nnet_deepcalo_stream.h"
#include "nnet_utils/nnet_dense.h"
#include "nnet_utils/nnet_dense_compressed.h"
#include "nnet_utils/nnet_dense_stream.h"
#include "nnet_utils/nnet_image.h"
#include "nnet_utils/nnet_image_stream.h"
#include "nnet_utils/nnet_merge.h"
#include "nnet_utils/nnet_merge_stream.h"
#include "nnet_utils/nnet_padding.h"
#include "nnet_utils/nnet_padding_stream.h"
#include "nnet_utils/nnet_pooling.h"
#include "nnet_utils/nnet_pooling_stream.h"
#include "nnet_utils/nnet_stream.h"
 
//hls-fpga-machine-learning insert weights
//#include "weights/w1_3.h"
#include "weights/w1_3_new.h"
#include "weights/b1_3.h"
//#include "weights/w2_3.h"
#include "weights/w2_3_new.h"
#include "weights/b2_3.h"
//#include "weights/w7.h"
#include "weights/w7_new.h"
#include "weights/b7.h"
//#include "weights/w11.h"
#include "weights/w11_new.h"
#include "weights/b11.h"
//#include "weights/w13.h"
#include "weights/w13_new.h"
#include "weights/b13.h"
//#include "weights/w18.h"
#include "weights/w18_new.h"
#include "weights/b18.h"
//#include "weights/w22.h"
#include "weights/w22_new.h"
#include "weights/b22.h"
//#include "weights/w27.h"
#include "weights/w27_new.h"
#include "weights/b27.h"
#include "weights/w29.h"
#include "weights/b29.h"
#include "weights/w37.h"
#include "weights/b37.h"
#include "weights/w44.h"
#include "weights/b44.h"
#include "weights/w48.h"
#include "weights/b48.h"
#include "weights/w55.h"
#include "weights/b55.h"
#include "weights/w59.h"
#include "weights/b59.h"
#include "weights/w66.h"
#include "weights/b66.h"
#include "weights/w70.h"
#include "weights/b70.h"
#include "weights/w76.h"
#include "weights/b76.h"
//#include "weights/w80.h"
#include "weights/w80_new.h"
#include "weights/b80.h"
//#include "weights/w83.h"
#include "weights/w83_new.h"
#include "weights/b83.h"
#include "weights/w86.h"
#include "weights/b86.h"

//hls-fpga-machine-learning insert layer-config
// quantized_tracks
struct linear_config2 : nnet::activ_config {
    static const unsigned n_in = 456;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef quantized_tracks_table_t table_t;
};

// time_distributed
struct config3_mult1 : nnet::dense_config {
    static const unsigned n_in = 6;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 2;
    static const unsigned strategy = nnet::resource;
    typedef accum3_t accum_t;
    typedef extend_all_t extend_t;
    typedef d_bias13_t bias_t;
    typedef d_weight13_t weight_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config3_mult2 : nnet::dense_config {
    static const unsigned n_in = 128;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 2;
    static const unsigned strategy = nnet::resource;
    typedef accum13_t accum_t;
	typedef extend_all_t extend_t;
    typedef d_bias23_t bias_t;
    typedef d_weight23_t weight_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config3_relu1 : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;    
};

struct config3_relu2 : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
};

struct config3 : nnet::timedistributed_config {    
    static const unsigned n_in = 6;
    static const unsigned n_hid = 128;
    static const unsigned n_out = 128;
    static const unsigned n_timesteps = 76;  
    
    // dense config
    typedef config3_mult1 dense1_config;
    typedef config3_mult2 dense2_config;
    

    
    //  relu config
    typedef config3_relu1 relu1_config;
    typedef config3_relu2 relu2_config    ;
    
    
};
// sum1d
struct config4 : nnet::sum1d_config {	 
    static const unsigned n_in = N_LAYER_1_3*N_LAYER_2_3;
    static const unsigned height = 76;
    static const unsigned width = 128;
    typedef accum4_t accum_t;	
};

// quantized_Sum1D
struct linear_config5 : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef quantized_Sum1D_table_t table_t;
};

// q_dense_batchnorm_3
struct config7 : nnet::dense_config {
    static const unsigned n_in = 128;
    static const unsigned n_out = 128;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = 2;
    static const unsigned n_zeros = 1104;
    static const unsigned n_nonzeros = 15280;
    static const bool store_weights_in_bram = false;
    typedef accum7_t accum_t;
	typedef extend_all_t extend_t;
    typedef bias7_t bias_t;
    typedef weight7_t weight_t;
    typedef layer7_index index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

// q_dense_batchnorm_3_linear
struct linear_config8 : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_dense_batchnorm_3_linear_table_t table_t;
};

// quantized_scalars
struct linear_config9 : nnet::activ_config {
    static const unsigned n_in = 15;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef quantized_scalars_table_t table_t;
};

// q_activation_7
struct relu_config10 : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_7_table_t table_t;
};

// q_dense_batchnorm
struct config11 : nnet::dense_config {
    static const unsigned n_in = 15;
    static const unsigned n_out = 256;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = 2;
    static const unsigned n_zeros = 260;
    static const unsigned n_nonzeros = 3580;
    static const bool store_weights_in_bram = false;
    typedef accum11_t accum_t;
	typedef extend_all_t extend_t;
    typedef bias11_t bias_t;
    typedef weight11_t weight_t;
    typedef layer11_index index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

// q_dense_batchnorm_linear
struct linear_config12 : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_dense_batchnorm_linear_table_t table_t;
};

// q_dense_batchnorm_4
struct config13 : nnet::dense_config {
    static const unsigned n_in = 128;
    static const unsigned n_out = 128;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = 2;
    static const unsigned n_zeros = 1152;
    static const unsigned n_nonzeros = 15232;
    static const bool store_weights_in_bram = false;
    typedef accum13_t accum_t;
	typedef extend_all_t extend_t;
    typedef bias13_t bias_t;
    typedef weight13_t weight_t;
    typedef layer13_index index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

// q_dense_batchnorm_4_linear
struct linear_config14 : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_dense_batchnorm_4_linear_table_t table_t;
};

// q_activation_4
struct relu_config15 : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_4_table_t table_t;
};

// q_activation_8
struct relu_config16 : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_8_table_t table_t;
};

// concatenate
struct config17 : nnet::concat_config {
    static const unsigned n_elem1_0 = 256;
    static const unsigned n_elem1_1 = 0;
    static const unsigned n_elem1_2 = 0;
    static const unsigned n_elem2_0 = 128;
    static const unsigned n_elem2_1 = 0;
    static const unsigned n_elem2_2 = 0;

    static const int axis = -1;
};

// q_dense_batchnorm_5
struct config18 : nnet::dense_config {
    static const unsigned n_in = 384;
    static const unsigned n_out = 512;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = 2;
    static const unsigned n_zeros = 13984;
    static const unsigned n_nonzeros = 182624;
    static const bool store_weights_in_bram = false;
    typedef accum18_t accum_t;
	typedef extend_all_t extend_t;
    typedef bias18_t bias_t;
    typedef weight18_t weight_t;
    typedef layer18_index index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

// q_dense_batchnorm_5_linear
struct linear_config19 : nnet::activ_config {
    static const unsigned n_in = 512;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_dense_batchnorm_5_linear_table_t table_t;
};

// q_activation_9
struct relu_config20 : nnet::activ_config {
    static const unsigned n_in = 512;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_9_table_t table_t;
};

// q_dense_batchnorm_6
struct config22 : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = 2;
    static const unsigned n_zeros = 30431;
    static const unsigned n_nonzeros = 493857;
    static const bool store_weights_in_bram = false;
    typedef accum22_t accum_t;
	typedef extend_all_t extend_t;
    typedef bias22_t bias_t;
    typedef weight22_t weight_t;
    typedef layer22_index index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

// q_dense_batchnorm_6_linear
struct linear_config23 : nnet::activ_config {
    static const unsigned n_in = 1024;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_dense_batchnorm_6_linear_table_t table_t;
};

// quantized_em_endcap
struct linear_config24 : nnet::activ_config {
    static const unsigned n_in = 2464;
    static const unsigned n_chan = 4;
    static const unsigned data_transfer_out = 4;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef quantized_em_endcap_table_t table_t;
};

// q_activation_10
struct relu_config25 : nnet::activ_config {
    static const unsigned n_in = 1024;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_10_table_t table_t;
};

// up_sampling2d
struct config26 : nnet::resize_config {
    static const unsigned height = 56;
    static const unsigned width = 11;
    static const unsigned n_chan = 4;
    static const unsigned data_transfer_out = 4;
    static const unsigned new_height = 56;
    static const unsigned new_width = 55;
};

// zp2d_q_conv2d_batchnorm
struct config92 : nnet::padding2d_config {
    static const unsigned in_height = 56;
    static const unsigned in_width = 55;
    static const unsigned n_chan = 4;
    static const unsigned data_transfer_out = 4;
    static const unsigned out_height = 60;
    static const unsigned out_width = 59;
    static const unsigned pad_top = 2;
    static const unsigned pad_bottom = 2;
    static const unsigned pad_left = 2;
    static const unsigned pad_right = 2;
};

// q_dense
struct config27 : nnet::dense_config {
    static const unsigned n_in = 1024;
    static const unsigned n_out = 992;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = 2;
    static const unsigned n_zeros = 110619;
    static const unsigned n_nonzeros = 905189;
    static const bool store_weights_in_bram = false;
    typedef accum27_t accum_t;
	typedef extend_all_t extend_t;
    typedef bias27_t bias_t;
    typedef weight27_t weight_t;
    typedef layer27_index index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

// q_dense_linear
struct linear_config28 : nnet::activ_config {
    static const unsigned n_in = 992;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_dense_linear_table_t table_t;
};

// q_conv2d_batchnorm
struct config29_mult : nnet::dense_config {
    static const unsigned n_in = 100;
    static const unsigned n_out = 16;
    static const unsigned reuse_factor = 5;
    static const unsigned strategy = nnet::resource;
    typedef accum29_t accum_t;
	typedef extend_all_t extend_t;
    typedef bias29_t bias_t;
    typedef weight29_t weight_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config29 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = 60;
    static const unsigned in_width = 59;
    static const unsigned n_chan = 4;
    static const unsigned data_transfer_in = 4;
    static const unsigned data_transfer_out = 16;
    static const unsigned filt_height = 5;
    static const unsigned filt_width = 5;
    static const unsigned kernel_size = filt_height * filt_width;
    static const unsigned n_filt = 16;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = 56;
    static const unsigned out_width = 55;
    static const unsigned reuse_factor = 5;
    static const unsigned n_zeros = 81;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::resource;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_height = 9;
    static const unsigned min_width = 9;
    static const ap_uint<filt_height * filt_width> pixels[min_height * min_width];
    static const unsigned n_partitions = 3080;
    static const unsigned n_pixels = out_height * out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::FillConv2DBuffer<data_T, CONFIG_T>;
    typedef accum29_t accum_t;
    typedef bias29_t bias_t;
    typedef weight29_t weight_t;
    typedef config29_mult mult_config;
};
const ap_uint<config29::filt_height * config29::filt_width> config29::pixels[] = {1,3,7,15,31,30,28,24,16,33,99,231,495,1023,990,924,792,528,1057,3171,7399,15855,32767,31710,29596,25368,16912,33825,101475,236775,507375,1048575,1014750,947100,811800,541200,1082401,3247203,7576807,16236015,33554431,32472030,30307228,25977624,17318416,1082400,3247200,7576800,16236000,33554400,32472000,30307200,25977600,17318400,1082368,3247104,7576576,16235520,33553408,32471040,30306304,25976832,17317888,1081344,3244032,7569408,16220160,33521664,32440320,30277632,25952256,17301504,1048576,3145728,7340032,15728640,32505856,31457280,29360128,25165824,16777216};

// q_conv2d_batchnorm_linear
struct linear_config30 : nnet::activ_config {
    static const unsigned n_in = 49280;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_conv2d_batchnorm_linear_table_t table_t;
};

// q_activation_11
struct relu_config31 : nnet::activ_config {
    static const unsigned n_in = 992;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_11_table_t table_t;
};

// q_activation_12
struct relu_config32 : nnet::activ_config {
    static const unsigned n_in = 49280;
    static const unsigned n_chan = 16;
    static const unsigned data_transfer_out = 16;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_12_table_t table_t;
};

// slice_tensor1d
struct config33 : nnet::slice_tensor1d_config {	 
    static const unsigned n_in = N_LAYER_27;
    static const unsigned start = 0;
    static const unsigned end = 32;	
};

// fi_lm
struct config34 : nnet::film_config {
    static const unsigned height = 56;
    static const unsigned width = 55;
    static const unsigned n_chan = 16;
    static const unsigned data_transfer_out = 16;
    static const unsigned n_inp1 = OUT_HEIGHT_29*OUT_WIDTH_29*N_FILT_29;
    static const unsigned n_inp2 = N_OUTPUTS_1_33;
    typedef accum34_t accum_t;
};

// q_activation_13
struct linear_config35 : nnet::activ_config {
    static const unsigned n_in = 49280;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_13_table_t table_t;
};

// max_pooling2d
struct config36 : nnet::pooling2d_config {
    static const unsigned in_height = 56;
    static const unsigned in_width = 55;
    static const unsigned n_filt = 16;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned pool_height = 2;
    static const unsigned pool_width = 2;

    static const unsigned filt_height = pool_height;
    static const unsigned filt_width = pool_width;
    static const unsigned n_chan = n_filt;
    static const unsigned data_transfer_out = n_filt;

    static const unsigned out_height = 28;
    static const unsigned out_width = 27;
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const nnet::Pool_Op pool_op = nnet::Max;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned reuse_factor = 60000;
    typedef model_default_t accum_t;
};

// zp2d_q_conv2d_batchnorm_1
struct config93 : nnet::padding2d_config {
    static const unsigned in_height = 28;
    static const unsigned in_width = 27;
    static const unsigned n_chan = 16;
    static const unsigned data_transfer_out = 16;
    static const unsigned out_height = 30;
    static const unsigned out_width = 29;
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
};

// q_conv2d_batchnorm_1
struct config37_mult : nnet::dense_config {
    static const unsigned n_in = 144;
    static const unsigned n_out = 32;
    static const unsigned reuse_factor = 24;
    static const unsigned strategy = nnet::resource;
    typedef accum37_t accum_t;
	typedef extend_all_t extend_t;
    typedef bias37_t bias_t;
    typedef weight37_t weight_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config37 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = 30;
    static const unsigned in_width = 29;
    static const unsigned n_chan = 16;
    static const unsigned data_transfer_in = 16;
    static const unsigned data_transfer_out = 32;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned kernel_size = filt_height * filt_width;
    static const unsigned n_filt = 32;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = 28;
    static const unsigned out_width = 27;
    static const unsigned reuse_factor = 24;
    static const unsigned n_zeros = 232;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::resource;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_height = 5;
    static const unsigned min_width = 5;
    static const ap_uint<filt_height * filt_width> pixels[min_height * min_width];
    static const unsigned n_partitions = 756;
    static const unsigned n_pixels = out_height * out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::FillConv2DBuffer<data_T, CONFIG_T>;
    typedef accum37_t accum_t;
    typedef bias37_t bias_t;
    typedef weight37_t weight_t;
    typedef config37_mult mult_config;
};
const ap_uint<config37::filt_height * config37::filt_width> config37::pixels[] = {1,3,7,6,4,9,27,63,54,36,73,219,511,438,292,72,216,504,432,288,64,192,448,384,256};

// q_conv2d_batchnorm_1_linear
struct linear_config38 : nnet::activ_config {
    static const unsigned n_in = 24192;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_conv2d_batchnorm_1_linear_table_t table_t;
};

// slice_tensor1d_1
struct config39 : nnet::slice_tensor1d_config {	 
    static const unsigned n_in = N_LAYER_27;
    static const unsigned start = 32;
    static const unsigned end = 992;	
};

// q_activation_14
struct relu_config40 : nnet::activ_config {
    static const unsigned n_in = 24192;
    static const unsigned n_chan = 32;
    static const unsigned data_transfer_out = 32;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_14_table_t table_t;
};

// slice_tensor1d_2
struct config41 : nnet::slice_tensor1d_config {	 
    static const unsigned n_in = N_OUTPUTS_1_39;
    static const unsigned start = 0;
    static const unsigned end = 64;	
};

// fi_lm_1
struct config42 : nnet::film_config {
    static const unsigned height = 28;
    static const unsigned width = 27;
    static const unsigned n_chan = 32;
    static const unsigned data_transfer_out = 32;
    static const unsigned n_inp1 = OUT_HEIGHT_37*OUT_WIDTH_37*N_FILT_37;
    static const unsigned n_inp2 = N_OUTPUTS_1_41;
    typedef accum42_t accum_t;
};

// q_activation_15
struct linear_config43 : nnet::activ_config {
    static const unsigned n_in = 24192;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_15_table_t table_t;
};

// zp2d_q_conv2d_batchnorm_2
struct config94 : nnet::padding2d_config {
    static const unsigned in_height = 28;
    static const unsigned in_width = 27;
    static const unsigned n_chan = 32;
    static const unsigned data_transfer_out = 32;
    static const unsigned out_height = 30;
    static const unsigned out_width = 29;
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
};

// q_conv2d_batchnorm_2
struct config44_mult : nnet::dense_config {
    static const unsigned n_in = 288;
    static const unsigned n_out = 32;
    static const unsigned reuse_factor = 24;
    static const unsigned strategy = nnet::resource;
    typedef accum44_t accum_t;
	typedef extend_all_t extend_t;
    typedef bias44_t bias_t;
    typedef weight44_t weight_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config44 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = 30;
    static const unsigned in_width = 29;
    static const unsigned n_chan = 32;
    static const unsigned data_transfer_in = 32;
    static const unsigned data_transfer_out = 32;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned kernel_size = filt_height * filt_width;
    static const unsigned n_filt = 32;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = 28;
    static const unsigned out_width = 27;
    static const unsigned reuse_factor = 24;
    static const unsigned n_zeros = 589;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::resource;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_height = 5;
    static const unsigned min_width = 5;
    static const ap_uint<filt_height * filt_width> pixels[min_height * min_width];
    static const unsigned n_partitions = 756;
    static const unsigned n_pixels = out_height * out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::FillConv2DBuffer<data_T, CONFIG_T>;
    typedef accum44_t accum_t;
    typedef bias44_t bias_t;
    typedef weight44_t weight_t;
    typedef config44_mult mult_config;
};
const ap_uint<config44::filt_height * config44::filt_width> config44::pixels[] = {1,3,7,6,4,9,27,63,54,36,73,219,511,438,292,72,216,504,432,288,64,192,448,384,256};

// q_conv2d_batchnorm_2_linear
struct linear_config45 : nnet::activ_config {
    static const unsigned n_in = 24192;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_conv2d_batchnorm_2_linear_table_t table_t;
};

// q_activation_16
struct relu_config46 : nnet::activ_config {
    static const unsigned n_in = 24192;
    static const unsigned n_chan = 32;
    static const unsigned data_transfer_out = 32;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_16_table_t table_t;
};

// max_pooling2d_1
struct config47 : nnet::pooling2d_config {
    static const unsigned in_height = 28;
    static const unsigned in_width = 27;
    static const unsigned n_filt = 32;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned pool_height = 2;
    static const unsigned pool_width = 2;

    static const unsigned filt_height = pool_height;
    static const unsigned filt_width = pool_width;
    static const unsigned n_chan = n_filt;
    static const unsigned data_transfer_out = n_filt;

    static const unsigned out_height = 14;
    static const unsigned out_width = 13;
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const nnet::Pool_Op pool_op = nnet::Max;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned reuse_factor = 60000;
    typedef model_default_t accum_t;
};

// zp2d_q_conv2d_batchnorm_3
struct config95 : nnet::padding2d_config {
    static const unsigned in_height = 14;
    static const unsigned in_width = 13;
    static const unsigned n_chan = 32;
    static const unsigned data_transfer_out = 32;
    static const unsigned out_height = 16;
    static const unsigned out_width = 15;
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
};

// q_conv2d_batchnorm_3
struct config48_mult : nnet::dense_config {
    static const unsigned n_in = 288;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 96;
    static const unsigned strategy = nnet::resource;
    typedef accum48_t accum_t;
	typedef extend_all_t extend_t;
    typedef bias48_t bias_t;
    typedef weight48_t weight_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config48 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = 16;
    static const unsigned in_width = 15;
    static const unsigned n_chan = 32;
    static const unsigned data_transfer_in = 32;
    static const unsigned data_transfer_out = 1;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned kernel_size = filt_height * filt_width;
    static const unsigned n_filt = 64;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = 14;
    static const unsigned out_width = 13;
    static const unsigned reuse_factor = 96;
    static const unsigned n_zeros = 1145;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::resource;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_height = 5;
    static const unsigned min_width = 5;
    static const ap_uint<filt_height * filt_width> pixels[min_height * min_width];
    static const unsigned n_partitions = 182;
    static const unsigned n_pixels = out_height * out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::FillConv2DBuffer<data_T, CONFIG_T>;
    typedef accum48_t accum_t;
    typedef bias48_t bias_t;
    typedef weight48_t weight_t;
    typedef config48_mult mult_config;
};
const ap_uint<config48::filt_height * config48::filt_width> config48::pixels[] = {1,3,7,6,4,9,27,63,54,36,73,219,511,438,292,72,216,504,432,288,64,192,448,384,256};

// q_conv2d_batchnorm_3_linear
struct linear_config49 : nnet::activ_config {
    static const unsigned n_in = 11648;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_conv2d_batchnorm_3_linear_table_t table_t;
};

// slice_tensor1d_3
struct config50 : nnet::slice_tensor1d_config {	 
    static const unsigned n_in = N_OUTPUTS_1_39;
    static const unsigned start = 64;
    static const unsigned end = 960;	
};

// q_activation_17
struct relu_config51 : nnet::activ_config {
    static const unsigned n_in = 11648;
    static const unsigned n_chan = 64;
    static const unsigned data_transfer_out = 1;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_17_table_t table_t;
};

// slice_tensor1d_4
struct config52 : nnet::slice_tensor1d_config {	 
    static const unsigned n_in = N_OUTPUTS_1_50;
    static const unsigned start = 0;
    static const unsigned end = 128;	
};

// fi_lm_2
struct config53 : nnet::film_config {
    static const unsigned height = 14;
    static const unsigned width = 13;
    static const unsigned n_chan = 64;
    static const unsigned data_transfer_out = 1;
    static const unsigned n_inp1 = OUT_HEIGHT_48*OUT_WIDTH_48*N_FILT_48;
    static const unsigned n_inp2 = N_OUTPUTS_1_52;
    typedef accum53_t accum_t;
};

// q_activation_18
struct linear_config54 : nnet::activ_config {
    static const unsigned n_in = 11648;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_18_table_t table_t;
};

// zp2d_q_conv2d_batchnorm_4
struct config96 : nnet::padding2d_config {
    static const unsigned in_height = 14;
    static const unsigned in_width = 13;
    static const unsigned n_chan = 64;
    static const unsigned data_transfer_out = 1;
    static const unsigned out_height = 16;
    static const unsigned out_width = 15;
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
};

// q_conv2d_batchnorm_4
struct config55_mult : nnet::dense_config {
    static const unsigned n_in = 576;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 96;
    static const unsigned strategy = nnet::resource;
    typedef accum55_t accum_t;
	typedef extend_all_t extend_t;
    typedef bias55_t bias_t;
    typedef weight55_t weight_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config55 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = 16;
    static const unsigned in_width = 15;
    static const unsigned n_chan = 64;
    static const unsigned data_transfer_in = 1;
    static const unsigned data_transfer_out = 1;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned kernel_size = filt_height * filt_width;
    static const unsigned n_filt = 64;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = 14;
    static const unsigned out_width = 13;
    static const unsigned reuse_factor = 96;
    static const unsigned n_zeros = 2301;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::resource;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_height = 5;
    static const unsigned min_width = 5;
    static const ap_uint<filt_height * filt_width> pixels[min_height * min_width];
    static const unsigned n_partitions = 182;
    static const unsigned n_pixels = out_height * out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::FillConv2DBuffer<data_T, CONFIG_T>;
    typedef accum55_t accum_t;
    typedef bias55_t bias_t;
    typedef weight55_t weight_t;
    typedef config55_mult mult_config;
};
const ap_uint<config55::filt_height * config55::filt_width> config55::pixels[] = {1,3,7,6,4,9,27,63,54,36,73,219,511,438,292,72,216,504,432,288,64,192,448,384,256};

// q_conv2d_batchnorm_4_linear
struct linear_config56 : nnet::activ_config {
    static const unsigned n_in = 11648;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_conv2d_batchnorm_4_linear_table_t table_t;
};

// q_activation_19
struct relu_config57 : nnet::activ_config {
    static const unsigned n_in = 11648;
    static const unsigned n_chan = 64;
    static const unsigned data_transfer_out = 1;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_19_table_t table_t;
};

// max_pooling2d_2
struct config58 : nnet::pooling2d_config {
    static const unsigned in_height = 14;
    static const unsigned in_width = 13;
    static const unsigned n_filt = 64;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned pool_height = 2;
    static const unsigned pool_width = 2;

    static const unsigned filt_height = pool_height;
    static const unsigned filt_width = pool_width;
    static const unsigned n_chan = n_filt;
    static const unsigned data_transfer_out = 1;

    static const unsigned out_height = 7;
    static const unsigned out_width = 6;
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const nnet::Pool_Op pool_op = nnet::Max;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned reuse_factor = 60000;
    typedef model_default_t accum_t;
};

// zp2d_q_conv2d_batchnorm_5
struct config97 : nnet::padding2d_config {
    static const unsigned in_height = 7;
    static const unsigned in_width = 6;
    static const unsigned n_chan = 64;
    static const unsigned data_transfer_out = 1;
    static const unsigned out_height = 9;
    static const unsigned out_width = 8;
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
};

// q_conv2d_batchnorm_5
struct config59_mult : nnet::dense_config {
    static const unsigned n_in = 576;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 288;
    static const unsigned strategy = nnet::resource;
    typedef accum59_t accum_t;
	typedef extend_all_t extend_t;
    typedef bias59_t bias_t;
    typedef weight59_t weight_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config59 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = 9;
    static const unsigned in_width = 8;
    static const unsigned n_chan = 64;
    static const unsigned data_transfer_in = 1;
    static const unsigned data_transfer_out = 1;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned kernel_size = filt_height * filt_width;
    static const unsigned n_filt = 128;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = 7;
    static const unsigned out_width = 6;
    static const unsigned reuse_factor = 288;
    static const unsigned n_zeros = 4673;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::resource;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_height = 5;
    static const unsigned min_width = 5;
    static const ap_uint<filt_height * filt_width> pixels[min_height * min_width];
    static const unsigned n_partitions = 42;
    static const unsigned n_pixels = out_height * out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::FillConv2DBuffer<data_T, CONFIG_T>;
    typedef accum59_t accum_t;
    typedef bias59_t bias_t;
    typedef weight59_t weight_t;
    typedef config59_mult mult_config;
};
const ap_uint<config59::filt_height * config59::filt_width> config59::pixels[] = {1,3,7,6,4,9,27,63,54,36,73,219,511,438,292,72,216,504,432,288,64,192,448,384,256};

// q_conv2d_batchnorm_5_linear
struct linear_config60 : nnet::activ_config {
    static const unsigned n_in = 5376;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_conv2d_batchnorm_5_linear_table_t table_t;
};

// slice_tensor1d_5
struct config61 : nnet::slice_tensor1d_config {	 
    static const unsigned n_in = N_OUTPUTS_1_50;
    static const unsigned start = 128;
    static const unsigned end = 896;	
};

// q_activation_20
struct relu_config62 : nnet::activ_config {
    static const unsigned n_in = 5376;
    static const unsigned n_chan = 128;
    static const unsigned data_transfer_out = 1;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_20_table_t table_t;
};

// slice_tensor1d_6
struct config63 : nnet::slice_tensor1d_config {	 
    static const unsigned n_in = N_OUTPUTS_1_61;
    static const unsigned start = 0;
    static const unsigned end = 256;	
};

// fi_lm_3
struct config64 : nnet::film_config {
    static const unsigned height = 7;
    static const unsigned width = 6;
    static const unsigned n_chan = 128;
    static const unsigned data_transfer_out = 1;
    static const unsigned n_inp1 = OUT_HEIGHT_59*OUT_WIDTH_59*N_FILT_59;
    static const unsigned n_inp2 = N_OUTPUTS_1_63;
    typedef accum64_t accum_t;
};

// q_activation_21
struct linear_config65 : nnet::activ_config {
    static const unsigned n_in = 5376;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_21_table_t table_t;
};

// zp2d_q_conv2d_batchnorm_6
struct config98 : nnet::padding2d_config {
    static const unsigned in_height = 7;
    static const unsigned in_width = 6;
    static const unsigned n_chan = 128;
    static const unsigned data_transfer_out = 1;
    static const unsigned out_height = 9;
    static const unsigned out_width = 8;
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
};

// q_conv2d_batchnorm_6
struct config66_mult : nnet::dense_config {
    static const unsigned n_in = 1152;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 288;
    static const unsigned strategy = nnet::resource;
    typedef accum66_t accum_t;
	typedef extend_all_t extend_t;
    typedef bias66_t bias_t;
    typedef weight66_t weight_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config66 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = 9;
    static const unsigned in_width = 8;
    static const unsigned n_chan = 128;
    static const unsigned data_transfer_in = 1;
    static const unsigned data_transfer_out = 1;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned kernel_size = filt_height * filt_width;
    static const unsigned n_filt = 128;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = 7;
    static const unsigned out_width = 6;
    static const unsigned reuse_factor = 288;
    static const unsigned n_zeros = 9814;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::resource;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_height = 5;
    static const unsigned min_width = 5;
    static const ap_uint<filt_height * filt_width> pixels[min_height * min_width];
    static const unsigned n_partitions = 42;
    static const unsigned n_pixels = out_height * out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::FillConv2DBuffer<data_T, CONFIG_T>;
    typedef accum66_t accum_t;
    typedef bias66_t bias_t;
    typedef weight66_t weight_t;
    typedef config66_mult mult_config;
};
const ap_uint<config66::filt_height * config66::filt_width> config66::pixels[] = {1,3,7,6,4,9,27,63,54,36,73,219,511,438,292,72,216,504,432,288,64,192,448,384,256};

// q_conv2d_batchnorm_6_linear
struct linear_config67 : nnet::activ_config {
    static const unsigned n_in = 5376;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_conv2d_batchnorm_6_linear_table_t table_t;
};

// q_activation_22
struct relu_config68 : nnet::activ_config {
    static const unsigned n_in = 5376;
    static const unsigned n_chan = 128;
    static const unsigned data_transfer_out = 1;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_22_table_t table_t;
};

// max_pooling2d_3
struct config69 : nnet::pooling2d_config {
    static const unsigned in_height = 7;
    static const unsigned in_width = 6;
    static const unsigned n_filt = 128;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned pool_height = 2;
    static const unsigned pool_width = 2;

    static const unsigned filt_height = pool_height;
    static const unsigned filt_width = pool_width;
    static const unsigned n_chan = n_filt;
    static const unsigned data_transfer_out = 1;

    static const unsigned out_height = 3;
    static const unsigned out_width = 3;
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const nnet::Pool_Op pool_op = nnet::Max;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned reuse_factor = 60000;
    typedef model_default_t accum_t;
};

// zp2d_q_conv2d_batchnorm_7
struct config99 : nnet::padding2d_config {
    static const unsigned in_height = 3;
    static const unsigned in_width = 3;
    static const unsigned n_chan = 128;
    static const unsigned data_transfer_out = 1;
    static const unsigned out_height = 5;
    static const unsigned out_width = 5;
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
};

// q_conv2d_batchnorm_7
struct config70_mult : nnet::dense_config {
    static const unsigned n_in = 1152;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 1152;
    static const unsigned strategy = nnet::resource;
    typedef accum70_t accum_t;
	typedef extend_all_t extend_t;
    typedef bias70_t bias_t;
    typedef weight70_t weight_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config70 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = 5;
    static const unsigned in_width = 5;
    static const unsigned n_chan = 128;
    static const unsigned data_transfer_in = 1;
    static const unsigned data_transfer_out = 1;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned kernel_size = filt_height * filt_width;
    static const unsigned n_filt = 256;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = 3;
    static const unsigned out_width = 3;
    static const unsigned reuse_factor = 1152;
    static const unsigned n_zeros = 19839;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::resource;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_height = 5;
    static const unsigned min_width = 5;
    static const ap_uint<filt_height * filt_width> pixels[min_height * min_width];
    static const unsigned n_partitions = 9;
    static const unsigned n_pixels = out_height * out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::FillConv2DBuffer<data_T, CONFIG_T>;
    typedef accum70_t accum_t;
    typedef bias70_t bias_t;
    typedef weight70_t weight_t;
    typedef config70_mult mult_config;
};
const ap_uint<config70::filt_height * config70::filt_width> config70::pixels[] = {1,3,7,6,4,9,27,63,54,36,73,219,511,438,292,72,216,504,432,288,64,192,448,384,256};

// q_conv2d_batchnorm_7_linear
struct linear_config71 : nnet::activ_config {
    static const unsigned n_in = 2304;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_conv2d_batchnorm_7_linear_table_t table_t;
};

// q_activation_23
struct relu_config72 : nnet::activ_config {
    static const unsigned n_in = 2304;
    static const unsigned n_chan = 256;
    static const unsigned data_transfer_out = 1;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_23_table_t table_t;
};

// slice_tensor1d_7
struct config73 : nnet::slice_tensor1d_config {	 
    static const unsigned n_in = N_OUTPUTS_1_61;
    static const unsigned start = 256;
    static const unsigned end = 768;	
};

// fi_lm_4
struct config74 : nnet::film_config {
    static const unsigned height = 3;
    static const unsigned width = 3;
    static const unsigned n_chan = 256;
    static const unsigned data_transfer_out = 1;
    static const unsigned n_inp1 = OUT_HEIGHT_70*OUT_WIDTH_70*N_FILT_70;
    static const unsigned n_inp2 = N_OUTPUTS_1_73;
    typedef accum74_t accum_t;
};

// q_activation_24
struct linear_config75 : nnet::activ_config {
    static const unsigned n_in = 2304;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_24_table_t table_t;
};

// zp2d_q_conv2d_batchnorm_8
struct config100 : nnet::padding2d_config {
    static const unsigned in_height = 3;
    static const unsigned in_width = 3;
    static const unsigned n_chan = 256;
    static const unsigned data_transfer_out = 1;
    static const unsigned out_height = 5;
    static const unsigned out_width = 5;
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
};

// q_conv2d_batchnorm_8
struct config76_mult : nnet::dense_config {
    static const unsigned n_in = 2304;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 1152;
    static const unsigned strategy = nnet::resource;
    typedef accum76_t accum_t;
	typedef extend_all_t extend_t;
    typedef bias76_t bias_t;
    typedef weight76_t weight_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config76 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = 5;
    static const unsigned in_width = 5;
    static const unsigned n_chan = 256;
    static const unsigned data_transfer_in = 1;
    static const unsigned data_transfer_out = 1;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned kernel_size = filt_height * filt_width;
    static const unsigned n_filt = 256;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = 3;
    static const unsigned out_width = 3;
    static const unsigned reuse_factor = 1152;
    static const unsigned n_zeros = 42045;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::resource;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_height = 5;
    static const unsigned min_width = 5;
    static const ap_uint<filt_height * filt_width> pixels[min_height * min_width];
    static const unsigned n_partitions = 9;
    static const unsigned n_pixels = out_height * out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::FillConv2DBuffer<data_T, CONFIG_T>;
    typedef accum76_t accum_t;
    typedef bias76_t bias_t;
    typedef weight76_t weight_t;
    typedef config76_mult mult_config;
};
const ap_uint<config76::filt_height * config76::filt_width> config76::pixels[] = {1,3,7,6,4,9,27,63,54,36,73,219,511,438,292,72,216,504,432,288,64,192,448,384,256};

// q_conv2d_batchnorm_8_linear
struct linear_config77 : nnet::activ_config {
    static const unsigned n_in = 2304;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_conv2d_batchnorm_8_linear_table_t table_t;
};

// q_activation_25
struct relu_config78 : nnet::activ_config {
    static const unsigned n_in = 2304;
    static const unsigned n_chan = 256;
    static const unsigned data_transfer_out = 1;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_25_table_t table_t;
};

// q_dense_batchnorm_7
struct config80 : nnet::dense_config {
    static const unsigned n_in = 2304;
    static const unsigned n_out = 256;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = 2;
    static const unsigned n_zeros = 42101;
    static const unsigned n_nonzeros = 547723;
    static const bool store_weights_in_bram = false;
    typedef accum80_t accum_t;
	typedef extend_all_t extend_t;
    typedef bias80_t bias_t;
    typedef weight80_t weight_t;
    typedef layer80_index index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

// q_dense_batchnorm_7_linear
struct linear_config81 : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_dense_batchnorm_7_linear_table_t table_t;
};

// q_activation_26
struct relu_config82 : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned n_chan = 256;
    static const unsigned data_transfer_out = 1;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_26_table_t table_t;
};

// q_dense_batchnorm_8
struct config83 : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 256;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = 2;
    static const unsigned n_zeros = 3911;
    static const unsigned n_nonzeros = 61625;
    static const bool store_weights_in_bram = false;
    typedef accum83_t accum_t;
	typedef extend_all_t extend_t;
    typedef bias83_t bias_t;
    typedef weight83_t weight_t;
    typedef layer83_index index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

// q_dense_batchnorm_8_linear
struct linear_config84 : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_dense_batchnorm_8_linear_table_t table_t;
};

// q_activation_27
struct relu_config85 : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned n_chan = 256;
    static const unsigned data_transfer_out = 1;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_activation_27_table_t table_t;
};

// q_dense_1
struct config86 : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 1;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 256;
    static const bool store_weights_in_bram = false;
    typedef accum86_t accum_t;
	typedef extend_all_t extend_t;
    typedef bias86_t bias_t;
    typedef weight86_t weight_t;
    typedef layer86_index index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

// q_dense_1_linear
struct linear_config87 : nnet::activ_config {
    static const unsigned n_in = 1;
    static const unsigned n_chan = 1;
    static const unsigned data_transfer_out = 1;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 60000;
    typedef q_dense_1_linear_table_t table_t;
};


#endif
