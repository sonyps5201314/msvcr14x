// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

//基于最新的vc2017版本及最新的windows10sdk制造

#include "targetver.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料
#endif
// Windows 头文件: 
#include <windows.h>

#include <ntdll.h>

#include <ntverp.h>

// TODO: 在此处引用程序需要的其他头文件
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>

EXTERN_C WORD GetWindowsVersionEx(BOOL bRetrieveServicePackVersion);