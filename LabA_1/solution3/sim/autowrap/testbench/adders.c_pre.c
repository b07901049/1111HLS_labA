# 1 "D:/1111HLS/LabA/LabA_1/adders.c"
# 1 "D:/1111HLS/LabA/LabA_1/adders.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 147 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "D:/1111HLS/LabA/LabA_1/adders.c" 2
# 46 "D:/1111HLS/LabA/LabA_1/adders.c"
# 1 "D:/1111HLS/LabA/LabA_1/adders.h" 1
# 49 "D:/1111HLS/LabA/LabA_1/adders.h"
int adders(int in1, int in2, int in3);
# 47 "D:/1111HLS/LabA/LabA_1/adders.c" 2

int adders(int in1, int in2, int in3) {
#pragma HLS INTERFACE mode=s_axilite port=return


#pragma HLS INTERFACE ap_none port=in3
#pragma HLS INTERFACE ap_none port=in2
#pragma HLS INTERFACE ap_none port=in1


 int sum;

 sum = in1 + in2 + in3;

 return sum;

}
