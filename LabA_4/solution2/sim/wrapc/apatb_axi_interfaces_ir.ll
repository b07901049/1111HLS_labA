; ModuleID = 'D:/1111HLS/LabA/LabA_4/solution2/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

; Function Attrs: inaccessiblememonly nounwind
declare void @llvm.sideeffect() #0

; Function Attrs: noinline
define void @apatb_axi_interfaces_ir(i16* noalias nocapture nonnull "fpga.decayed.dim.hint"="32" %d_o, i16* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="32" %d_i) local_unnamed_addr #1 {
entry:
  %d_o_copy_0 = alloca [4 x i16], align 512
  %d_o_copy_1 = alloca [4 x i16], align 512
  %d_o_copy_2 = alloca [4 x i16], align 512
  %d_o_copy_3 = alloca [4 x i16], align 512
  %d_o_copy_4 = alloca [4 x i16], align 512
  %d_o_copy_5 = alloca [4 x i16], align 512
  %d_o_copy_6 = alloca [4 x i16], align 512
  %d_o_copy_7 = alloca [4 x i16], align 512
  %d_i_copy_0 = alloca i16, align 512
  %d_i_copy_1 = alloca i16, align 512
  %d_i_copy_2 = alloca i16, align 512
  %d_i_copy_3 = alloca i16, align 512
  %d_i_copy_4 = alloca i16, align 512
  %d_i_copy_5 = alloca i16, align 512
  %d_i_copy_6 = alloca i16, align 512
  %d_i_copy_7 = alloca i16, align 512
  %d_i_copy_8 = alloca i16, align 512
  %d_i_copy_9 = alloca i16, align 512
  %d_i_copy_10 = alloca i16, align 512
  %d_i_copy_11 = alloca i16, align 512
  %d_i_copy_12 = alloca i16, align 512
  %d_i_copy_13 = alloca i16, align 512
  %d_i_copy_14 = alloca i16, align 512
  %d_i_copy_15 = alloca i16, align 512
  %d_i_copy_16 = alloca i16, align 512
  %d_i_copy_17 = alloca i16, align 512
  %d_i_copy_18 = alloca i16, align 512
  %d_i_copy_19 = alloca i16, align 512
  %d_i_copy_20 = alloca i16, align 512
  %d_i_copy_21 = alloca i16, align 512
  %d_i_copy_22 = alloca i16, align 512
  %d_i_copy_23 = alloca i16, align 512
  %d_i_copy_24 = alloca i16, align 512
  %d_i_copy_25 = alloca i16, align 512
  %d_i_copy_26 = alloca i16, align 512
  %d_i_copy_27 = alloca i16, align 512
  %d_i_copy_28 = alloca i16, align 512
  %d_i_copy_29 = alloca i16, align 512
  %d_i_copy_30 = alloca i16, align 512
  %d_i_copy_31 = alloca i16, align 512
  %0 = bitcast i16* %d_o to [32 x i16]*
  %1 = bitcast i16* %d_i to [32 x i16]*
  call void @copy_in([32 x i16]* nonnull %0, [4 x i16]* nonnull align 512 %d_o_copy_0, [4 x i16]* nonnull align 512 %d_o_copy_1, [4 x i16]* nonnull align 512 %d_o_copy_2, [4 x i16]* nonnull align 512 %d_o_copy_3, [4 x i16]* nonnull align 512 %d_o_copy_4, [4 x i16]* nonnull align 512 %d_o_copy_5, [4 x i16]* nonnull align 512 %d_o_copy_6, [4 x i16]* nonnull align 512 %d_o_copy_7, [32 x i16]* nonnull %1, i16* nonnull align 512 %d_i_copy_0, i16* nonnull align 512 %d_i_copy_1, i16* nonnull align 512 %d_i_copy_2, i16* nonnull align 512 %d_i_copy_3, i16* nonnull align 512 %d_i_copy_4, i16* nonnull align 512 %d_i_copy_5, i16* nonnull align 512 %d_i_copy_6, i16* nonnull align 512 %d_i_copy_7, i16* nonnull align 512 %d_i_copy_8, i16* nonnull align 512 %d_i_copy_9, i16* nonnull align 512 %d_i_copy_10, i16* nonnull align 512 %d_i_copy_11, i16* nonnull align 512 %d_i_copy_12, i16* nonnull align 512 %d_i_copy_13, i16* nonnull align 512 %d_i_copy_14, i16* nonnull align 512 %d_i_copy_15, i16* nonnull align 512 %d_i_copy_16, i16* nonnull align 512 %d_i_copy_17, i16* nonnull align 512 %d_i_copy_18, i16* nonnull align 512 %d_i_copy_19, i16* nonnull align 512 %d_i_copy_20, i16* nonnull align 512 %d_i_copy_21, i16* nonnull align 512 %d_i_copy_22, i16* nonnull align 512 %d_i_copy_23, i16* nonnull align 512 %d_i_copy_24, i16* nonnull align 512 %d_i_copy_25, i16* nonnull align 512 %d_i_copy_26, i16* nonnull align 512 %d_i_copy_27, i16* nonnull align 512 %d_i_copy_28, i16* nonnull align 512 %d_i_copy_29, i16* nonnull align 512 %d_i_copy_30, i16* nonnull align 512 %d_i_copy_31)
  %d_o_copy.gep_0 = getelementptr [4 x i16], [4 x i16]* %d_o_copy_0, i64 0, i32 0
  %d_o_copy.gep_1 = getelementptr [4 x i16], [4 x i16]* %d_o_copy_1, i64 0, i32 0
  %d_o_copy.gep_2 = getelementptr [4 x i16], [4 x i16]* %d_o_copy_2, i64 0, i32 0
  %d_o_copy.gep_3 = getelementptr [4 x i16], [4 x i16]* %d_o_copy_3, i64 0, i32 0
  %d_o_copy.gep_4 = getelementptr [4 x i16], [4 x i16]* %d_o_copy_4, i64 0, i32 0
  %d_o_copy.gep_5 = getelementptr [4 x i16], [4 x i16]* %d_o_copy_5, i64 0, i32 0
  %d_o_copy.gep_6 = getelementptr [4 x i16], [4 x i16]* %d_o_copy_6, i64 0, i32 0
  %d_o_copy.gep_7 = getelementptr [4 x i16], [4 x i16]* %d_o_copy_7, i64 0, i32 0
  call void @llvm.sideeffect() #0 [ "xlx_array_partition"(i16* %d_o_copy.gep_0, i32 0, i32 1, i32 0, i1 false) ], !dbg !5
  call void @llvm.sideeffect() #0 [ "xlx_array_partition"(i16* %d_o_copy.gep_1, i32 0, i32 1, i32 0, i1 false) ], !dbg !5
  call void @llvm.sideeffect() #0 [ "xlx_array_partition"(i16* %d_o_copy.gep_2, i32 0, i32 1, i32 0, i1 false) ], !dbg !5
  call void @llvm.sideeffect() #0 [ "xlx_array_partition"(i16* %d_o_copy.gep_3, i32 0, i32 1, i32 0, i1 false) ], !dbg !5
  call void @llvm.sideeffect() #0 [ "xlx_array_partition"(i16* %d_o_copy.gep_4, i32 0, i32 1, i32 0, i1 false) ], !dbg !5
  call void @llvm.sideeffect() #0 [ "xlx_array_partition"(i16* %d_o_copy.gep_5, i32 0, i32 1, i32 0, i1 false) ], !dbg !5
  call void @llvm.sideeffect() #0 [ "xlx_array_partition"(i16* %d_o_copy.gep_6, i32 0, i32 1, i32 0, i1 false) ], !dbg !5
  call void @llvm.sideeffect() #0 [ "xlx_array_partition"(i16* %d_o_copy.gep_7, i32 0, i32 1, i32 0, i1 false) ], !dbg !5
  call void @apatb_axi_interfaces_hw([4 x i16]* %d_o_copy_0, [4 x i16]* %d_o_copy_1, [4 x i16]* %d_o_copy_2, [4 x i16]* %d_o_copy_3, [4 x i16]* %d_o_copy_4, [4 x i16]* %d_o_copy_5, [4 x i16]* %d_o_copy_6, [4 x i16]* %d_o_copy_7, i16* %d_i_copy_0, i16* %d_i_copy_1, i16* %d_i_copy_2, i16* %d_i_copy_3, i16* %d_i_copy_4, i16* %d_i_copy_5, i16* %d_i_copy_6, i16* %d_i_copy_7, i16* %d_i_copy_8, i16* %d_i_copy_9, i16* %d_i_copy_10, i16* %d_i_copy_11, i16* %d_i_copy_12, i16* %d_i_copy_13, i16* %d_i_copy_14, i16* %d_i_copy_15, i16* %d_i_copy_16, i16* %d_i_copy_17, i16* %d_i_copy_18, i16* %d_i_copy_19, i16* %d_i_copy_20, i16* %d_i_copy_21, i16* %d_i_copy_22, i16* %d_i_copy_23, i16* %d_i_copy_24, i16* %d_i_copy_25, i16* %d_i_copy_26, i16* %d_i_copy_27, i16* %d_i_copy_28, i16* %d_i_copy_29, i16* %d_i_copy_30, i16* %d_i_copy_31)
  call void @copy_back([32 x i16]* %0, [4 x i16]* %d_o_copy_0, [4 x i16]* %d_o_copy_1, [4 x i16]* %d_o_copy_2, [4 x i16]* %d_o_copy_3, [4 x i16]* %d_o_copy_4, [4 x i16]* %d_o_copy_5, [4 x i16]* %d_o_copy_6, [4 x i16]* %d_o_copy_7, [32 x i16]* %1, i16* %d_i_copy_0, i16* %d_i_copy_1, i16* %d_i_copy_2, i16* %d_i_copy_3, i16* %d_i_copy_4, i16* %d_i_copy_5, i16* %d_i_copy_6, i16* %d_i_copy_7, i16* %d_i_copy_8, i16* %d_i_copy_9, i16* %d_i_copy_10, i16* %d_i_copy_11, i16* %d_i_copy_12, i16* %d_i_copy_13, i16* %d_i_copy_14, i16* %d_i_copy_15, i16* %d_i_copy_16, i16* %d_i_copy_17, i16* %d_i_copy_18, i16* %d_i_copy_19, i16* %d_i_copy_20, i16* %d_i_copy_21, i16* %d_i_copy_22, i16* %d_i_copy_23, i16* %d_i_copy_24, i16* %d_i_copy_25, i16* %d_i_copy_26, i16* %d_i_copy_27, i16* %d_i_copy_28, i16* %d_i_copy_29, i16* %d_i_copy_30, i16* %d_i_copy_31)
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @onebyonecpy_hls.p0a32i16.3.4([4 x i16]* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_0, [4 x i16]* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_1, [4 x i16]* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_2, [4 x i16]* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_3, [4 x i16]* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_4, [4 x i16]* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_5, [4 x i16]* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_6, [4 x i16]* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_7, [32 x i16]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1") #2 {
entry:
  %1 = icmp eq [4 x i16]* %_0, null
  %2 = icmp eq [32 x i16]* %0, null
  %3 = or i1 %1, %2
  br i1 %3, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %dst.addr.exit, %copy
  %for.loop.idx1 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %dst.addr.exit ]
  %4 = urem i64 %for.loop.idx1, 8
  %5 = udiv i64 %for.loop.idx1, 8
  %dst.addr_0 = getelementptr [4 x i16], [4 x i16]* %_0, i64 0, i64 %5
  %dst.addr_1 = getelementptr [4 x i16], [4 x i16]* %_1, i64 0, i64 %5
  %dst.addr_2 = getelementptr [4 x i16], [4 x i16]* %_2, i64 0, i64 %5
  %dst.addr_3 = getelementptr [4 x i16], [4 x i16]* %_3, i64 0, i64 %5
  %dst.addr_4 = getelementptr [4 x i16], [4 x i16]* %_4, i64 0, i64 %5
  %dst.addr_5 = getelementptr [4 x i16], [4 x i16]* %_5, i64 0, i64 %5
  %dst.addr_6 = getelementptr [4 x i16], [4 x i16]* %_6, i64 0, i64 %5
  %dst.addr_7 = getelementptr [4 x i16], [4 x i16]* %_7, i64 0, i64 %5
  %src.addr = getelementptr [32 x i16], [32 x i16]* %0, i64 0, i64 %for.loop.idx1
  %6 = load i16, i16* %src.addr, align 2
  %7 = trunc i64 %4 to i3
  switch i3 %7, label %dst.addr.case.7 [
    i3 0, label %dst.addr.case.0
    i3 1, label %dst.addr.case.1
    i3 2, label %dst.addr.case.2
    i3 3, label %dst.addr.case.3
    i3 -4, label %dst.addr.case.4
    i3 -3, label %dst.addr.case.5
    i3 -2, label %dst.addr.case.6
  ]

dst.addr.case.0:                                  ; preds = %for.loop
  store i16 %6, i16* %dst.addr_0, align 2
  br label %dst.addr.exit

dst.addr.case.1:                                  ; preds = %for.loop
  store i16 %6, i16* %dst.addr_1, align 2
  br label %dst.addr.exit

dst.addr.case.2:                                  ; preds = %for.loop
  store i16 %6, i16* %dst.addr_2, align 2
  br label %dst.addr.exit

dst.addr.case.3:                                  ; preds = %for.loop
  store i16 %6, i16* %dst.addr_3, align 2
  br label %dst.addr.exit

dst.addr.case.4:                                  ; preds = %for.loop
  store i16 %6, i16* %dst.addr_4, align 2
  br label %dst.addr.exit

dst.addr.case.5:                                  ; preds = %for.loop
  store i16 %6, i16* %dst.addr_5, align 2
  br label %dst.addr.exit

dst.addr.case.6:                                  ; preds = %for.loop
  store i16 %6, i16* %dst.addr_6, align 2
  br label %dst.addr.exit

dst.addr.case.7:                                  ; preds = %for.loop
  store i16 %6, i16* %dst.addr_7, align 2
  br label %dst.addr.exit

dst.addr.exit:                                    ; preds = %dst.addr.case.7, %dst.addr.case.6, %dst.addr.case.5, %dst.addr.case.4, %dst.addr.case.3, %dst.addr.case.2, %dst.addr.case.1, %dst.addr.case.0
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx1, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 32
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %dst.addr.exit, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @onebyonecpy_hls.p0a32i16.5.6(i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_0, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_1, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_2, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_3, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_4, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_5, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_6, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_7, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_8, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_9, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_10, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_11, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_12, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_13, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_14, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_15, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_16, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_17, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_18, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_19, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_20, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_21, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_22, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_23, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_24, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_25, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_26, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_27, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_28, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_29, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_30, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_31, [32 x i16]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1") #2 {
entry:
  %1 = icmp eq i16* %_0, null
  %2 = icmp eq [32 x i16]* %0, null
  %3 = or i1 %1, %2
  br i1 %3, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %dst.addr.exit, %copy
  %for.loop.idx1 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %dst.addr.exit ]
  %src.addr = getelementptr [32 x i16], [32 x i16]* %0, i64 0, i64 %for.loop.idx1
  %4 = load i16, i16* %src.addr, align 2
  %5 = trunc i64 %for.loop.idx1 to i5
  switch i5 %5, label %dst.addr.case.31 [
    i5 0, label %dst.addr.case.0
    i5 1, label %dst.addr.case.1
    i5 2, label %dst.addr.case.2
    i5 3, label %dst.addr.case.3
    i5 4, label %dst.addr.case.4
    i5 5, label %dst.addr.case.5
    i5 6, label %dst.addr.case.6
    i5 7, label %dst.addr.case.7
    i5 8, label %dst.addr.case.8
    i5 9, label %dst.addr.case.9
    i5 10, label %dst.addr.case.10
    i5 11, label %dst.addr.case.11
    i5 12, label %dst.addr.case.12
    i5 13, label %dst.addr.case.13
    i5 14, label %dst.addr.case.14
    i5 15, label %dst.addr.case.15
    i5 -16, label %dst.addr.case.16
    i5 -15, label %dst.addr.case.17
    i5 -14, label %dst.addr.case.18
    i5 -13, label %dst.addr.case.19
    i5 -12, label %dst.addr.case.20
    i5 -11, label %dst.addr.case.21
    i5 -10, label %dst.addr.case.22
    i5 -9, label %dst.addr.case.23
    i5 -8, label %dst.addr.case.24
    i5 -7, label %dst.addr.case.25
    i5 -6, label %dst.addr.case.26
    i5 -5, label %dst.addr.case.27
    i5 -4, label %dst.addr.case.28
    i5 -3, label %dst.addr.case.29
    i5 -2, label %dst.addr.case.30
  ]

dst.addr.case.0:                                  ; preds = %for.loop
  store i16 %4, i16* %_0, align 512
  br label %dst.addr.exit

dst.addr.case.1:                                  ; preds = %for.loop
  store i16 %4, i16* %_1, align 512
  br label %dst.addr.exit

dst.addr.case.2:                                  ; preds = %for.loop
  store i16 %4, i16* %_2, align 512
  br label %dst.addr.exit

dst.addr.case.3:                                  ; preds = %for.loop
  store i16 %4, i16* %_3, align 512
  br label %dst.addr.exit

dst.addr.case.4:                                  ; preds = %for.loop
  store i16 %4, i16* %_4, align 512
  br label %dst.addr.exit

dst.addr.case.5:                                  ; preds = %for.loop
  store i16 %4, i16* %_5, align 512
  br label %dst.addr.exit

dst.addr.case.6:                                  ; preds = %for.loop
  store i16 %4, i16* %_6, align 512
  br label %dst.addr.exit

dst.addr.case.7:                                  ; preds = %for.loop
  store i16 %4, i16* %_7, align 512
  br label %dst.addr.exit

dst.addr.case.8:                                  ; preds = %for.loop
  store i16 %4, i16* %_8, align 512
  br label %dst.addr.exit

dst.addr.case.9:                                  ; preds = %for.loop
  store i16 %4, i16* %_9, align 512
  br label %dst.addr.exit

dst.addr.case.10:                                 ; preds = %for.loop
  store i16 %4, i16* %_10, align 512
  br label %dst.addr.exit

dst.addr.case.11:                                 ; preds = %for.loop
  store i16 %4, i16* %_11, align 512
  br label %dst.addr.exit

dst.addr.case.12:                                 ; preds = %for.loop
  store i16 %4, i16* %_12, align 512
  br label %dst.addr.exit

dst.addr.case.13:                                 ; preds = %for.loop
  store i16 %4, i16* %_13, align 512
  br label %dst.addr.exit

dst.addr.case.14:                                 ; preds = %for.loop
  store i16 %4, i16* %_14, align 512
  br label %dst.addr.exit

dst.addr.case.15:                                 ; preds = %for.loop
  store i16 %4, i16* %_15, align 512
  br label %dst.addr.exit

dst.addr.case.16:                                 ; preds = %for.loop
  store i16 %4, i16* %_16, align 512
  br label %dst.addr.exit

dst.addr.case.17:                                 ; preds = %for.loop
  store i16 %4, i16* %_17, align 512
  br label %dst.addr.exit

dst.addr.case.18:                                 ; preds = %for.loop
  store i16 %4, i16* %_18, align 512
  br label %dst.addr.exit

dst.addr.case.19:                                 ; preds = %for.loop
  store i16 %4, i16* %_19, align 512
  br label %dst.addr.exit

dst.addr.case.20:                                 ; preds = %for.loop
  store i16 %4, i16* %_20, align 512
  br label %dst.addr.exit

dst.addr.case.21:                                 ; preds = %for.loop
  store i16 %4, i16* %_21, align 512
  br label %dst.addr.exit

dst.addr.case.22:                                 ; preds = %for.loop
  store i16 %4, i16* %_22, align 512
  br label %dst.addr.exit

dst.addr.case.23:                                 ; preds = %for.loop
  store i16 %4, i16* %_23, align 512
  br label %dst.addr.exit

dst.addr.case.24:                                 ; preds = %for.loop
  store i16 %4, i16* %_24, align 512
  br label %dst.addr.exit

dst.addr.case.25:                                 ; preds = %for.loop
  store i16 %4, i16* %_25, align 512
  br label %dst.addr.exit

dst.addr.case.26:                                 ; preds = %for.loop
  store i16 %4, i16* %_26, align 512
  br label %dst.addr.exit

dst.addr.case.27:                                 ; preds = %for.loop
  store i16 %4, i16* %_27, align 512
  br label %dst.addr.exit

dst.addr.case.28:                                 ; preds = %for.loop
  store i16 %4, i16* %_28, align 512
  br label %dst.addr.exit

dst.addr.case.29:                                 ; preds = %for.loop
  store i16 %4, i16* %_29, align 512
  br label %dst.addr.exit

dst.addr.case.30:                                 ; preds = %for.loop
  store i16 %4, i16* %_30, align 512
  br label %dst.addr.exit

dst.addr.case.31:                                 ; preds = %for.loop
  store i16 %4, i16* %_31, align 512
  br label %dst.addr.exit

dst.addr.exit:                                    ; preds = %dst.addr.case.31, %dst.addr.case.30, %dst.addr.case.29, %dst.addr.case.28, %dst.addr.case.27, %dst.addr.case.26, %dst.addr.case.25, %dst.addr.case.24, %dst.addr.case.23, %dst.addr.case.22, %dst.addr.case.21, %dst.addr.case.20, %dst.addr.case.19, %dst.addr.case.18, %dst.addr.case.17, %dst.addr.case.16, %dst.addr.case.15, %dst.addr.case.14, %dst.addr.case.13, %dst.addr.case.12, %dst.addr.case.11, %dst.addr.case.10, %dst.addr.case.9, %dst.addr.case.8, %dst.addr.case.7, %dst.addr.case.6, %dst.addr.case.5, %dst.addr.case.4, %dst.addr.case.3, %dst.addr.case.2, %dst.addr.case.1, %dst.addr.case.0
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx1, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 32
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %dst.addr.exit, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @copy_in([32 x i16]* noalias readonly "orig.arg.no"="0", [4 x i16]* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_0, [4 x i16]* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_1, [4 x i16]* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_2, [4 x i16]* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_3, [4 x i16]* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_4, [4 x i16]* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_5, [4 x i16]* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_6, [4 x i16]* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_7, [32 x i16]* noalias readonly "orig.arg.no"="2", i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_01, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_12, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_23, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_34, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_45, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_56, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_67, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_78, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_8, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_9, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_10, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_11, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_129, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_13, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_14, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_15, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_16, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_17, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_18, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_19, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_20, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_21, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_22, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_2310, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_24, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_25, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_26, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_27, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_28, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_29, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_30, i16* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_31) #3 {
entry:
  call void @onebyonecpy_hls.p0a32i16.3.4([4 x i16]* align 512 %_0, [4 x i16]* align 512 %_1, [4 x i16]* align 512 %_2, [4 x i16]* align 512 %_3, [4 x i16]* align 512 %_4, [4 x i16]* align 512 %_5, [4 x i16]* align 512 %_6, [4 x i16]* align 512 %_7, [32 x i16]* %0)
  call void @onebyonecpy_hls.p0a32i16.5.6(i16* align 512 %_01, i16* align 512 %_12, i16* align 512 %_23, i16* align 512 %_34, i16* align 512 %_45, i16* align 512 %_56, i16* align 512 %_67, i16* align 512 %_78, i16* align 512 %_8, i16* align 512 %_9, i16* align 512 %_10, i16* align 512 %_11, i16* align 512 %_129, i16* align 512 %_13, i16* align 512 %_14, i16* align 512 %_15, i16* align 512 %_16, i16* align 512 %_17, i16* align 512 %_18, i16* align 512 %_19, i16* align 512 %_20, i16* align 512 %_21, i16* align 512 %_22, i16* align 512 %_2310, i16* align 512 %_24, i16* align 512 %_25, i16* align 512 %_26, i16* align 512 %_27, i16* align 512 %_28, i16* align 512 %_29, i16* align 512 %_30, i16* align 512 %_31, [32 x i16]* %1)
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @onebyonecpy_hls.p0a32i16.11.12([32 x i16]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0", [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_0, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_1, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_2, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_3, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_4, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_5, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_6, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_7) #2 {
entry:
  %1 = icmp eq [32 x i16]* %0, null
  %2 = icmp eq [4 x i16]* %_0, null
  %3 = or i1 %1, %2
  br i1 %3, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %src.addr.exit, %copy
  %for.loop.idx1 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %src.addr.exit ]
  %dst.addr = getelementptr [32 x i16], [32 x i16]* %0, i64 0, i64 %for.loop.idx1
  %4 = urem i64 %for.loop.idx1, 8
  %5 = udiv i64 %for.loop.idx1, 8
  %src.addr_0 = getelementptr [4 x i16], [4 x i16]* %_0, i64 0, i64 %5
  %src.addr_1 = getelementptr [4 x i16], [4 x i16]* %_1, i64 0, i64 %5
  %src.addr_2 = getelementptr [4 x i16], [4 x i16]* %_2, i64 0, i64 %5
  %src.addr_3 = getelementptr [4 x i16], [4 x i16]* %_3, i64 0, i64 %5
  %src.addr_4 = getelementptr [4 x i16], [4 x i16]* %_4, i64 0, i64 %5
  %src.addr_5 = getelementptr [4 x i16], [4 x i16]* %_5, i64 0, i64 %5
  %src.addr_6 = getelementptr [4 x i16], [4 x i16]* %_6, i64 0, i64 %5
  %src.addr_7 = getelementptr [4 x i16], [4 x i16]* %_7, i64 0, i64 %5
  %6 = trunc i64 %4 to i3
  switch i3 %6, label %src.addr.case.7 [
    i3 0, label %src.addr.case.0
    i3 1, label %src.addr.case.1
    i3 2, label %src.addr.case.2
    i3 3, label %src.addr.case.3
    i3 -4, label %src.addr.case.4
    i3 -3, label %src.addr.case.5
    i3 -2, label %src.addr.case.6
  ]

src.addr.case.0:                                  ; preds = %for.loop
  %_01 = load i16, i16* %src.addr_0, align 2
  br label %src.addr.exit

src.addr.case.1:                                  ; preds = %for.loop
  %_12 = load i16, i16* %src.addr_1, align 2
  br label %src.addr.exit

src.addr.case.2:                                  ; preds = %for.loop
  %_23 = load i16, i16* %src.addr_2, align 2
  br label %src.addr.exit

src.addr.case.3:                                  ; preds = %for.loop
  %_34 = load i16, i16* %src.addr_3, align 2
  br label %src.addr.exit

src.addr.case.4:                                  ; preds = %for.loop
  %_45 = load i16, i16* %src.addr_4, align 2
  br label %src.addr.exit

src.addr.case.5:                                  ; preds = %for.loop
  %_56 = load i16, i16* %src.addr_5, align 2
  br label %src.addr.exit

src.addr.case.6:                                  ; preds = %for.loop
  %_67 = load i16, i16* %src.addr_6, align 2
  br label %src.addr.exit

src.addr.case.7:                                  ; preds = %for.loop
  %_78 = load i16, i16* %src.addr_7, align 2
  br label %src.addr.exit

src.addr.exit:                                    ; preds = %src.addr.case.7, %src.addr.case.6, %src.addr.case.5, %src.addr.case.4, %src.addr.case.3, %src.addr.case.2, %src.addr.case.1, %src.addr.case.0
  %7 = phi i16 [ %_01, %src.addr.case.0 ], [ %_12, %src.addr.case.1 ], [ %_23, %src.addr.case.2 ], [ %_34, %src.addr.case.3 ], [ %_45, %src.addr.case.4 ], [ %_56, %src.addr.case.5 ], [ %_67, %src.addr.case.6 ], [ %_78, %src.addr.case.7 ]
  store i16 %7, i16* %dst.addr, align 2
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx1, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 32
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %src.addr.exit, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @onebyonecpy_hls.p0a32i16.13.14([32 x i16]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0", i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_0, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_1, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_2, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_3, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_4, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_5, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_6, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_7, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_8, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_9, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_10, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_11, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_12, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_13, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_14, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_15, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_16, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_17, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_18, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_19, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_20, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_21, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_22, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_23, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_24, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_25, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_26, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_27, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_28, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_29, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_30, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_31) #2 {
entry:
  %1 = icmp eq [32 x i16]* %0, null
  %2 = icmp eq i16* %_0, null
  %3 = or i1 %1, %2
  br i1 %3, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %src.addr.exit, %copy
  %for.loop.idx1 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %src.addr.exit ]
  %dst.addr = getelementptr [32 x i16], [32 x i16]* %0, i64 0, i64 %for.loop.idx1
  %4 = trunc i64 %for.loop.idx1 to i5
  switch i5 %4, label %src.addr.case.31 [
    i5 0, label %src.addr.case.0
    i5 1, label %src.addr.case.1
    i5 2, label %src.addr.case.2
    i5 3, label %src.addr.case.3
    i5 4, label %src.addr.case.4
    i5 5, label %src.addr.case.5
    i5 6, label %src.addr.case.6
    i5 7, label %src.addr.case.7
    i5 8, label %src.addr.case.8
    i5 9, label %src.addr.case.9
    i5 10, label %src.addr.case.10
    i5 11, label %src.addr.case.11
    i5 12, label %src.addr.case.12
    i5 13, label %src.addr.case.13
    i5 14, label %src.addr.case.14
    i5 15, label %src.addr.case.15
    i5 -16, label %src.addr.case.16
    i5 -15, label %src.addr.case.17
    i5 -14, label %src.addr.case.18
    i5 -13, label %src.addr.case.19
    i5 -12, label %src.addr.case.20
    i5 -11, label %src.addr.case.21
    i5 -10, label %src.addr.case.22
    i5 -9, label %src.addr.case.23
    i5 -8, label %src.addr.case.24
    i5 -7, label %src.addr.case.25
    i5 -6, label %src.addr.case.26
    i5 -5, label %src.addr.case.27
    i5 -4, label %src.addr.case.28
    i5 -3, label %src.addr.case.29
    i5 -2, label %src.addr.case.30
  ]

src.addr.case.0:                                  ; preds = %for.loop
  %_01 = load i16, i16* %_0, align 512
  br label %src.addr.exit

src.addr.case.1:                                  ; preds = %for.loop
  %_110 = load i16, i16* %_1, align 512
  br label %src.addr.exit

src.addr.case.2:                                  ; preds = %for.loop
  %_211 = load i16, i16* %_2, align 512
  br label %src.addr.exit

src.addr.case.3:                                  ; preds = %for.loop
  %_312 = load i16, i16* %_3, align 512
  br label %src.addr.exit

src.addr.case.4:                                  ; preds = %for.loop
  %_413 = load i16, i16* %_4, align 512
  br label %src.addr.exit

src.addr.case.5:                                  ; preds = %for.loop
  %_514 = load i16, i16* %_5, align 512
  br label %src.addr.exit

src.addr.case.6:                                  ; preds = %for.loop
  %_615 = load i16, i16* %_6, align 512
  br label %src.addr.exit

src.addr.case.7:                                  ; preds = %for.loop
  %_716 = load i16, i16* %_7, align 512
  br label %src.addr.exit

src.addr.case.8:                                  ; preds = %for.loop
  %_817 = load i16, i16* %_8, align 512
  br label %src.addr.exit

src.addr.case.9:                                  ; preds = %for.loop
  %_918 = load i16, i16* %_9, align 512
  br label %src.addr.exit

src.addr.case.10:                                 ; preds = %for.loop
  %_1019 = load i16, i16* %_10, align 512
  br label %src.addr.exit

src.addr.case.11:                                 ; preds = %for.loop
  %_1120 = load i16, i16* %_11, align 512
  br label %src.addr.exit

src.addr.case.12:                                 ; preds = %for.loop
  %_1221 = load i16, i16* %_12, align 512
  br label %src.addr.exit

src.addr.case.13:                                 ; preds = %for.loop
  %_1322 = load i16, i16* %_13, align 512
  br label %src.addr.exit

src.addr.case.14:                                 ; preds = %for.loop
  %_1423 = load i16, i16* %_14, align 512
  br label %src.addr.exit

src.addr.case.15:                                 ; preds = %for.loop
  %_1524 = load i16, i16* %_15, align 512
  br label %src.addr.exit

src.addr.case.16:                                 ; preds = %for.loop
  %_1625 = load i16, i16* %_16, align 512
  br label %src.addr.exit

src.addr.case.17:                                 ; preds = %for.loop
  %_1726 = load i16, i16* %_17, align 512
  br label %src.addr.exit

src.addr.case.18:                                 ; preds = %for.loop
  %_1827 = load i16, i16* %_18, align 512
  br label %src.addr.exit

src.addr.case.19:                                 ; preds = %for.loop
  %_1928 = load i16, i16* %_19, align 512
  br label %src.addr.exit

src.addr.case.20:                                 ; preds = %for.loop
  %_2029 = load i16, i16* %_20, align 512
  br label %src.addr.exit

src.addr.case.21:                                 ; preds = %for.loop
  %_2130 = load i16, i16* %_21, align 512
  br label %src.addr.exit

src.addr.case.22:                                 ; preds = %for.loop
  %_2231 = load i16, i16* %_22, align 512
  br label %src.addr.exit

src.addr.case.23:                                 ; preds = %for.loop
  %_2332 = load i16, i16* %_23, align 512
  br label %src.addr.exit

src.addr.case.24:                                 ; preds = %for.loop
  %_2433 = load i16, i16* %_24, align 512
  br label %src.addr.exit

src.addr.case.25:                                 ; preds = %for.loop
  %_2534 = load i16, i16* %_25, align 512
  br label %src.addr.exit

src.addr.case.26:                                 ; preds = %for.loop
  %_2635 = load i16, i16* %_26, align 512
  br label %src.addr.exit

src.addr.case.27:                                 ; preds = %for.loop
  %_2736 = load i16, i16* %_27, align 512
  br label %src.addr.exit

src.addr.case.28:                                 ; preds = %for.loop
  %_2837 = load i16, i16* %_28, align 512
  br label %src.addr.exit

src.addr.case.29:                                 ; preds = %for.loop
  %_2938 = load i16, i16* %_29, align 512
  br label %src.addr.exit

src.addr.case.30:                                 ; preds = %for.loop
  %_3039 = load i16, i16* %_30, align 512
  br label %src.addr.exit

src.addr.case.31:                                 ; preds = %for.loop
  %_3140 = load i16, i16* %_31, align 512
  br label %src.addr.exit

src.addr.exit:                                    ; preds = %src.addr.case.31, %src.addr.case.30, %src.addr.case.29, %src.addr.case.28, %src.addr.case.27, %src.addr.case.26, %src.addr.case.25, %src.addr.case.24, %src.addr.case.23, %src.addr.case.22, %src.addr.case.21, %src.addr.case.20, %src.addr.case.19, %src.addr.case.18, %src.addr.case.17, %src.addr.case.16, %src.addr.case.15, %src.addr.case.14, %src.addr.case.13, %src.addr.case.12, %src.addr.case.11, %src.addr.case.10, %src.addr.case.9, %src.addr.case.8, %src.addr.case.7, %src.addr.case.6, %src.addr.case.5, %src.addr.case.4, %src.addr.case.3, %src.addr.case.2, %src.addr.case.1, %src.addr.case.0
  %5 = phi i16 [ %_01, %src.addr.case.0 ], [ %_110, %src.addr.case.1 ], [ %_211, %src.addr.case.2 ], [ %_312, %src.addr.case.3 ], [ %_413, %src.addr.case.4 ], [ %_514, %src.addr.case.5 ], [ %_615, %src.addr.case.6 ], [ %_716, %src.addr.case.7 ], [ %_817, %src.addr.case.8 ], [ %_918, %src.addr.case.9 ], [ %_1019, %src.addr.case.10 ], [ %_1120, %src.addr.case.11 ], [ %_1221, %src.addr.case.12 ], [ %_1322, %src.addr.case.13 ], [ %_1423, %src.addr.case.14 ], [ %_1524, %src.addr.case.15 ], [ %_1625, %src.addr.case.16 ], [ %_1726, %src.addr.case.17 ], [ %_1827, %src.addr.case.18 ], [ %_1928, %src.addr.case.19 ], [ %_2029, %src.addr.case.20 ], [ %_2130, %src.addr.case.21 ], [ %_2231, %src.addr.case.22 ], [ %_2332, %src.addr.case.23 ], [ %_2433, %src.addr.case.24 ], [ %_2534, %src.addr.case.25 ], [ %_2635, %src.addr.case.26 ], [ %_2736, %src.addr.case.27 ], [ %_2837, %src.addr.case.28 ], [ %_2938, %src.addr.case.29 ], [ %_3039, %src.addr.case.30 ], [ %_3140, %src.addr.case.31 ]
  store i16 %5, i16* %dst.addr, align 2
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx1, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 32
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %src.addr.exit, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @copy_out([32 x i16]* noalias "orig.arg.no"="0", [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_0, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_1, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_2, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_3, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_4, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_5, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_6, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_7, [32 x i16]* noalias "orig.arg.no"="2", i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_01, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_12, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_23, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_34, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_45, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_56, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_67, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_78, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_8, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_9, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_10, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_11, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_129, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_13, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_14, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_15, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_16, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_17, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_18, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_19, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_20, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_21, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_22, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_2310, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_24, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_25, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_26, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_27, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_28, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_29, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_30, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_31) #4 {
entry:
  call void @onebyonecpy_hls.p0a32i16.11.12([32 x i16]* %0, [4 x i16]* align 512 %_0, [4 x i16]* align 512 %_1, [4 x i16]* align 512 %_2, [4 x i16]* align 512 %_3, [4 x i16]* align 512 %_4, [4 x i16]* align 512 %_5, [4 x i16]* align 512 %_6, [4 x i16]* align 512 %_7)
  call void @onebyonecpy_hls.p0a32i16.13.14([32 x i16]* %1, i16* align 512 %_01, i16* align 512 %_12, i16* align 512 %_23, i16* align 512 %_34, i16* align 512 %_45, i16* align 512 %_56, i16* align 512 %_67, i16* align 512 %_78, i16* align 512 %_8, i16* align 512 %_9, i16* align 512 %_10, i16* align 512 %_11, i16* align 512 %_129, i16* align 512 %_13, i16* align 512 %_14, i16* align 512 %_15, i16* align 512 %_16, i16* align 512 %_17, i16* align 512 %_18, i16* align 512 %_19, i16* align 512 %_20, i16* align 512 %_21, i16* align 512 %_22, i16* align 512 %_2310, i16* align 512 %_24, i16* align 512 %_25, i16* align 512 %_26, i16* align 512 %_27, i16* align 512 %_28, i16* align 512 %_29, i16* align 512 %_30, i16* align 512 %_31)
  ret void
}

declare void @apatb_axi_interfaces_hw([4 x i16]*, [4 x i16]*, [4 x i16]*, [4 x i16]*, [4 x i16]*, [4 x i16]*, [4 x i16]*, [4 x i16]*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*)

; Function Attrs: argmemonly noinline norecurse
define internal void @copy_back([32 x i16]* noalias "orig.arg.no"="0", [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_0, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_1, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_2, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_3, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_4, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_5, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_6, [4 x i16]* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_7, [32 x i16]* noalias "orig.arg.no"="2", i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_01, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_12, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_23, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_34, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_45, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_56, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_67, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_78, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_8, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_9, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_10, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_11, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_129, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_13, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_14, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_15, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_16, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_17, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_18, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_19, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_20, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_21, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_22, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_2310, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_24, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_25, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_26, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_27, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_28, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_29, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_30, i16* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" %_31) #4 {
entry:
  call void @onebyonecpy_hls.p0a32i16.11.12([32 x i16]* %0, [4 x i16]* align 512 %_0, [4 x i16]* align 512 %_1, [4 x i16]* align 512 %_2, [4 x i16]* align 512 %_3, [4 x i16]* align 512 %_4, [4 x i16]* align 512 %_5, [4 x i16]* align 512 %_6, [4 x i16]* align 512 %_7)
  ret void
}

define void @axi_interfaces_hw_stub_wrapper([4 x i16]*, [4 x i16]*, [4 x i16]*, [4 x i16]*, [4 x i16]*, [4 x i16]*, [4 x i16]*, [4 x i16]*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*, i16*) #5 {
entry:
  %40 = alloca [32 x i16]
  %41 = alloca [32 x i16]
  call void @copy_out([32 x i16]* %40, [4 x i16]* %0, [4 x i16]* %1, [4 x i16]* %2, [4 x i16]* %3, [4 x i16]* %4, [4 x i16]* %5, [4 x i16]* %6, [4 x i16]* %7, [32 x i16]* %41, i16* %8, i16* %9, i16* %10, i16* %11, i16* %12, i16* %13, i16* %14, i16* %15, i16* %16, i16* %17, i16* %18, i16* %19, i16* %20, i16* %21, i16* %22, i16* %23, i16* %24, i16* %25, i16* %26, i16* %27, i16* %28, i16* %29, i16* %30, i16* %31, i16* %32, i16* %33, i16* %34, i16* %35, i16* %36, i16* %37, i16* %38, i16* %39)
  %42 = bitcast [32 x i16]* %40 to i16*
  %43 = bitcast [32 x i16]* %41 to i16*
  call void @axi_interfaces_hw_stub(i16* %42, i16* %43)
  call void @copy_in([32 x i16]* %40, [4 x i16]* %0, [4 x i16]* %1, [4 x i16]* %2, [4 x i16]* %3, [4 x i16]* %4, [4 x i16]* %5, [4 x i16]* %6, [4 x i16]* %7, [32 x i16]* %41, i16* %8, i16* %9, i16* %10, i16* %11, i16* %12, i16* %13, i16* %14, i16* %15, i16* %16, i16* %17, i16* %18, i16* %19, i16* %20, i16* %21, i16* %22, i16* %23, i16* %24, i16* %25, i16* %26, i16* %27, i16* %28, i16* %29, i16* %30, i16* %31, i16* %32, i16* %33, i16* %34, i16* %35, i16* %36, i16* %37, i16* %38, i16* %39)
  ret void
}

declare void @axi_interfaces_hw_stub(i16*, i16*)

attributes #0 = { inaccessiblememonly nounwind }
attributes #1 = { noinline "fpga.wrapper.func"="wrapper" }
attributes #2 = { argmemonly noinline norecurse "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyin" }
attributes #4 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyout" }
attributes #5 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
!5 = !DILocation(line: 6, column: 9, scope: !6)
!6 = !DILexicalBlockFile(scope: !8, file: !7, discriminator: 0)
!7 = !DIFile(filename: "D:/1111HLS/LabA/LabA_4/solution2/directives.tcl", directory: "D:\5C1111HLS\5CLabA")
!8 = distinct !DISubprogram(name: "axi_interfaces", scope: !9, file: !9, line: 57, type: !10, isLocal: false, isDefinition: true, scopeLine: 57, flags: DIFlagPrototyped, isOptimized: false, unit: !18, variables: !4)
!9 = !DIFile(filename: "LabA_4/axi_interfaces.c", directory: "D:\5C1111HLS\5CLabA")
!10 = !DISubroutineType(types: !11)
!11 = !{null, !12, !16}
!12 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !13, size: 64)
!13 = !DIDerivedType(tag: DW_TAG_typedef, name: "dout_t", file: !14, line: 52, baseType: !15)
!14 = !DIFile(filename: "LabA_4/axi_interfaces.h", directory: "D:\5C1111HLS\5CLabA")
!15 = !DIBasicType(name: "short", size: 16, encoding: DW_ATE_signed)
!16 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !17, size: 64)
!17 = !DIDerivedType(tag: DW_TAG_typedef, name: "din_t", file: !14, line: 51, baseType: !15)
!18 = distinct !DICompileUnit(language: DW_LANG_C99, file: !19, producer: "clang version 7.0.0 ", isOptimized: true, runtimeVersion: 0, emissionKind: FullDebug, enums: !4, globals: !20)
!19 = !DIFile(filename: "D:/1111HLS/LabA/LabA_4/solution2/.autopilot/db\5Caxi_interfaces.pp.0.c", directory: "D:\5C1111HLS\5CLabA")
!20 = !{!21}
!21 = !DIGlobalVariableExpression(var: !22, expr: !DIExpression())
!22 = distinct !DIGlobalVariable(name: "acc", scope: !8, file: !9, line: 61, type: !23, isLocal: true, isDefinition: true)
!23 = !DICompositeType(tag: DW_TAG_array_type, baseType: !24, size: 256, elements: !26)
!24 = !DIDerivedType(tag: DW_TAG_typedef, name: "dacc_t", file: !14, line: 53, baseType: !25)
!25 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!26 = !{!27}
!27 = !DISubrange(count: 8)
