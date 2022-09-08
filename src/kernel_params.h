#include "ap_fixed.h"
#include "defines.h"

//===============
//Input
//===============

//em_barrel 2464
#define em_barrel_STREAM_LEN  (N_INPUT_1_29*N_INPUT_2_29*N_INPUT_3_29)
//scalars 15
#define scalars_STREAM_LEN  N_INPUT_1_13
//tracks 342
#define tracks_STREAM_LEN  (N_INPUT_1_1*N_INPUT_2_1)

//===============
//Output
//===============
#define OUT_STREAM_LEN  1

typedef ap_fixed<16,6> bigdata_t;
