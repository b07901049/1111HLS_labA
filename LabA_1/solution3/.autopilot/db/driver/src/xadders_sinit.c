// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Tool Version Limit: 2022.04
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xadders.h"

extern XAdders_Config XAdders_ConfigTable[];

XAdders_Config *XAdders_LookupConfig(u16 DeviceId) {
	XAdders_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XADDERS_NUM_INSTANCES; Index++) {
		if (XAdders_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XAdders_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XAdders_Initialize(XAdders *InstancePtr, u16 DeviceId) {
	XAdders_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XAdders_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XAdders_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

