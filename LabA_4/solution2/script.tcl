############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
############################################################
open_project LabA_4
set_top axi_interfaces
add_files LabA_4/axi_interfaces.h
add_files LabA_4/axi_interfaces.c
add_files -tb LabA_4/result.golden.dat -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb LabA_4/axi_interfaces_test.c -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution2" -flow_target vivado
set_part {xcvu9p-flgb2104-1-e}
create_clock -period 4 -name default
config_export -format ip_catalog -rtl verilog
source "./LabA_4/solution2/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all
export_design -rtl verilog -format ip_catalog
