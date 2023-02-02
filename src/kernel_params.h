#include "ap_fixed.h"
#include "defines.h"

//===============
//Input
//===============

//em_barrel 2464
#define em_barrel_STREAM_LEN  (N_INPUT_1_21*N_INPUT_2_21*N_INPUT_3_21)
//scalars 15
#define scalars_STREAM_LEN  N_INPUT_1_6
//tracks 342
#define tracks_STREAM_LEN  (N_INPUT_1_1*N_INPUT_2_1)

//===============
//Output
//===============
#define OUT_STREAM_LEN  1

typedef ap_fixed<32,16> bigdata_t;
