#include "ap_fixed.h"
#include "defines.h"

//===============
//Input
//===============

//pipeline 5 sets of input
#define DATA_SET 5
//em_barrel 2464
#define em_barrel_STREAM_LEN  (N_INPUT_1_21*N_INPUT_2_21)
#define em_barrel_CHANNEL_SIZE  N_INPUT_3_21
//scalars 15
#define scalars_STREAM_LEN  N_INPUT_1_6
//tracks 456
#define tracks_STREAM_LEN  (N_INPUT_1_1*N_INPUT_2_1)
//input size 2935
#define input_STREAM_LEN  (em_barrel_STREAM_LEN*em_barrel_CHANNEL_SIZE+scalars_STREAM_LEN+tracks_STREAM_LEN)
//===============
//Output
//===============
#define OUT_STREAM_LEN  1

typedef ap_fixed<32,16> bigdata_t;

struct input_group{
    bigdata_t layer[4];
};