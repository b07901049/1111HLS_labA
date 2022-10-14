
log_wave -r /
set designtopgroup [add_wave_group "Design Top Signals"]
set coutputgroup [add_wave_group "C Outputs" -into $designtopgroup]
set ap_return__return_group [add_wave_group ap_return__return(axi_slave) -into $coutputgroup]
add_wave /apatb_adders_top/AESL_inst_adders/interrupt -into $ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/s_axi_control_BRESP -into $ap_return__return_group -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/s_axi_control_BREADY -into $ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/s_axi_control_BVALID -into $ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/s_axi_control_RRESP -into $ap_return__return_group -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/s_axi_control_RDATA -into $ap_return__return_group -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/s_axi_control_RREADY -into $ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/s_axi_control_RVALID -into $ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/s_axi_control_ARREADY -into $ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/s_axi_control_ARVALID -into $ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/s_axi_control_ARADDR -into $ap_return__return_group -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/s_axi_control_WSTRB -into $ap_return__return_group -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/s_axi_control_WDATA -into $ap_return__return_group -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/s_axi_control_WREADY -into $ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/s_axi_control_WVALID -into $ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/s_axi_control_AWREADY -into $ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/s_axi_control_AWVALID -into $ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/s_axi_control_AWADDR -into $ap_return__return_group -radix hex
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set return_group [add_wave_group return(wire) -into $cinputgroup]
add_wave /apatb_adders_top/AESL_inst_adders/in3 -into $return_group -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/in2 -into $return_group -radix hex
add_wave /apatb_adders_top/AESL_inst_adders/in1 -into $return_group -radix hex
set blocksiggroup [add_wave_group "Block-level IO Handshake(internal)" -into $designtopgroup]
add_wave /apatb_adders_top/AESL_inst_adders/ap_done -into $blocksiggroup
add_wave /apatb_adders_top/AESL_inst_adders/ap_idle -into $blocksiggroup
add_wave /apatb_adders_top/AESL_inst_adders/ap_ready -into $blocksiggroup
add_wave /apatb_adders_top/AESL_inst_adders/ap_start -into $blocksiggroup
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_adders_top/AESL_inst_adders/ap_rst_n -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_adders_top/AESL_inst_adders/ap_clk -into $clockgroup
set testbenchgroup [add_wave_group "Test Bench Signals"]
set tbinternalsiggroup [add_wave_group "Internal Signals" -into $testbenchgroup]
set tb_simstatus_group [add_wave_group "Simulation Status" -into $tbinternalsiggroup]
set tb_portdepth_group [add_wave_group "Port Depth" -into $tbinternalsiggroup]
add_wave /apatb_adders_top/AUTOTB_TRANSACTION_NUM -into $tb_simstatus_group -radix hex
add_wave /apatb_adders_top/ready_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_adders_top/done_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_adders_top/LENGTH_in1 -into $tb_portdepth_group -radix hex
add_wave /apatb_adders_top/LENGTH_in2 -into $tb_portdepth_group -radix hex
add_wave /apatb_adders_top/LENGTH_in3 -into $tb_portdepth_group -radix hex
add_wave /apatb_adders_top/LENGTH_ap_return -into $tb_portdepth_group -radix hex
set tbcoutputgroup [add_wave_group "C Outputs" -into $testbenchgroup]
set tb_ap_return__return_group [add_wave_group ap_return__return(axi_slave) -into $tbcoutputgroup]
add_wave /apatb_adders_top/control_INTERRUPT -into $tb_ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/control_BRESP -into $tb_ap_return__return_group -radix hex
add_wave /apatb_adders_top/control_BREADY -into $tb_ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/control_BVALID -into $tb_ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/control_RRESP -into $tb_ap_return__return_group -radix hex
add_wave /apatb_adders_top/control_RDATA -into $tb_ap_return__return_group -radix hex
add_wave /apatb_adders_top/control_RREADY -into $tb_ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/control_RVALID -into $tb_ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/control_ARREADY -into $tb_ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/control_ARVALID -into $tb_ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/control_ARADDR -into $tb_ap_return__return_group -radix hex
add_wave /apatb_adders_top/control_WSTRB -into $tb_ap_return__return_group -radix hex
add_wave /apatb_adders_top/control_WDATA -into $tb_ap_return__return_group -radix hex
add_wave /apatb_adders_top/control_WREADY -into $tb_ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/control_WVALID -into $tb_ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/control_AWREADY -into $tb_ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/control_AWVALID -into $tb_ap_return__return_group -color #ffff00 -radix hex
add_wave /apatb_adders_top/control_AWADDR -into $tb_ap_return__return_group -radix hex
set tbcinputgroup [add_wave_group "C Inputs" -into $testbenchgroup]
set tb_return_group [add_wave_group return(wire) -into $tbcinputgroup]
add_wave /apatb_adders_top/in3 -into $tb_return_group -radix hex
add_wave /apatb_adders_top/in2 -into $tb_return_group -radix hex
add_wave /apatb_adders_top/in1 -into $tb_return_group -radix hex
save_wave_config adders.wcfg
run all
quit

