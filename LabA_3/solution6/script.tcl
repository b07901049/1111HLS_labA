############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
############################################################
open_project LabA_3
set_top array_io
add_files LabA_3/array_io.c
add_files LabA_3/array_io.h
add_files -tb LabA_3/array_io_test.c
add_files -tb Interface_Synthesis/lab3/result.golden.dat
open_solution "solution6" -flow_target vivado
set_part {xcvu9p-flgb2104-1-e}
create_clock -period 4 -name default
source "./LabA_3/solution6/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all
export_design -format ip_catalog
