// msvcr14x.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"


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
	BOOL WINAPI __acrt_DllMain(_In_ HINSTANCE hInstance, _In_ DWORD fdwReason, _In_ LPVOID lpvReserved);
	const void* __pfnDllMainCRTStartupForYY_Thunks = __acrt_DllMain;
	BOOL __YY_Thunks_Disable_Rreload_Dlls;
}