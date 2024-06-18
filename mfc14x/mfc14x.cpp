// mfc14x.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

#include "..\msvcr14x\stdafx.cpp"

#ifdef _M_IX86
#pragma comment(lib,"KERNEL32.lib")
#pragma comment(lib,"win2k_kernl32p.lib")
#elif defined(_M_X64)
#pragma comment(lib,"win2k3_KERNEL32.lib")
#pragma comment(lib,"win2k3_kernl32p.lib")
#endif

#pragma comment(linker, "/ENTRY:DllMainCRTStartupForYY_Thunks")
extern "C"
{
	const void* __pfnDllMainCRTStartupForYY_Thunks;
	BOOL __YY_Thunks_Process_Terminating;
	const void* __acrt_atexit_table;
}