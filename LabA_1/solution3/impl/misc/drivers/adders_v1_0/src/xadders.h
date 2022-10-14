// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Tool Version Limit: 2022.04
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XADDERS_H
#define XADDERS_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xadders_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u64 Control_BaseAddress;
} XAdders_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XAdders;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XAdders_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XAdders_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XAdders_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XAdders_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XAdders_Initialize(XAdders *InstancePtr, u16 DeviceId);
XAdders_Config* XAdders_LookupConfig(u16 DeviceId);
int XAdders_CfgInitialize(XAdders *InstancePtr, XAdders_Config *ConfigPtr);
#else
int XAdders_Initialize(XAdders *InstancePtr, const char* InstanceName);
int XAdders_Release(XAdders *InstancePtr);
#endif

void XAdders_Start(XAdders *InstancePtr);
u32 XAdders_IsDone(XAdders *InstancePtr);
u32 XAdders_IsIdle(XAdders *InstancePtr);
u32 XAdders_IsReady(XAdders *InstancePtr);
void XAdders_EnableAutoRestart(XAdders *InstancePtr);
void XAdders_DisableAutoRestart(XAdders *InstancePtr);
u32 XAdders_Get_return(XAdders *InstancePtr);


void XAdders_InterruptGlobalEnable(XAdders *InstancePtr);
void XAdders_InterruptGlobalDisable(XAdders *InstancePtr);
void XAdders_InterruptEnable(XAdders *InstancePtr, u32 Mask);
void XAdders_InterruptDisable(XAdders *InstancePtr, u32 Mask);
void XAdders_InterruptClear(XAdders *InstancePtr, u32 Mask);
u32 XAdders_InterruptGetEnabled(XAdders *InstancePtr);
u32 XAdders_InterruptGetStatus(XAdders *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
