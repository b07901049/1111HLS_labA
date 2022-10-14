############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
############################################################
open_project LabA_2
set_top adders_io
add_files LabA_2/adders_io.c
add_files LabA_2/adders_io.h
add_files -tb LabA_2/adders_io_test.c
open_solution "solution1" -flow_target vivado
set_part {xcvu9p-flgb2104-1-e}
create_clock -period 2 -name default
source "./LabA_2/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all
export_design -format ip_catalog
