// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Tool Version Limit: 2022.04
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xadders.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XAdders_CfgInitialize(XAdders *InstancePtr, XAdders_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XAdders_Start(XAdders *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdders_ReadReg(InstancePtr->Control_BaseAddress, XADDERS_CONTROL_ADDR_AP_CTRL) & 0x80;
    XAdders_WriteReg(InstancePtr->Control_BaseAddress, XADDERS_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XAdders_IsDone(XAdders *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdders_ReadReg(InstancePtr->Control_BaseAddress, XADDERS_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XAdders_IsIdle(XAdders *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdders_ReadReg(InstancePtr->Control_BaseAddress, XADDERS_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XAdders_IsReady(XAdders *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdders_ReadReg(InstancePtr->Control_BaseAddress, XADDERS_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XAdders_EnableAutoRestart(XAdders *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdders_WriteReg(InstancePtr->Control_BaseAddress, XADDERS_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XAdders_DisableAutoRestart(XAdders *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdders_WriteReg(InstancePtr->Control_BaseAddress, XADDERS_CONTROL_ADDR_AP_CTRL, 0);
}

u32 XAdders_Get_return(XAdders *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdders_ReadReg(InstancePtr->Control_BaseAddress, XADDERS_CONTROL_ADDR_AP_RETURN);
    return Data;
}
void XAdders_InterruptGlobalEnable(XAdders *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdders_WriteReg(InstancePtr->Control_BaseAddress, XADDERS_CONTROL_ADDR_GIE, 1);
}

void XAdders_InterruptGlobalDisable(XAdders *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdders_WriteReg(InstancePtr->Control_BaseAddress, XADDERS_CONTROL_ADDR_GIE, 0);
}

void XAdders_InterruptEnable(XAdders *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XAdders_ReadReg(InstancePtr->Control_BaseAddress, XADDERS_CONTROL_ADDR_IER);
    XAdders_WriteReg(InstancePtr->Control_BaseAddress, XADDERS_CONTROL_ADDR_IER, Register | Mask);
}

void XAdders_InterruptDisable(XAdders *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XAdders_ReadReg(InstancePtr->Control_BaseAddress, XADDERS_CONTROL_ADDR_IER);
    XAdders_WriteReg(InstancePtr->Control_BaseAddress, XADDERS_CONTROL_ADDR_IER, Register & (~Mask));
}

void XAdders_InterruptClear(XAdders *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    //XAdders_WriteReg(InstancePtr->Control_BaseAddress, XADDERS_CONTROL_ADDR_ISR, Mask);
}

u32 XAdders_InterruptGetEnabled(XAdders *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XAdders_ReadReg(InstancePtr->Control_BaseAddress, XADDERS_CONTROL_ADDR_IER);
}

u32 XAdders_InterruptGetStatus(XAdders *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    // Current Interrupt Clear Behavior is Clear on Read(COR).
    return XAdders_ReadReg(InstancePtr->Control_BaseAddress, XADDERS_CONTROL_ADDR_ISR);
}

