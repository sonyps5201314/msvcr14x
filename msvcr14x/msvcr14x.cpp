// msvcr14x.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"


#ifdef _M_IX86
#pragma comment(lib,"win2k_KERNEL32.lib")
#pragma comment(lib,"win2k_kernl32p.lib")
#elif defined(_M_X64)
#pragma comment(lib,"win2k3_KERNEL32.lib")
#pragma comment(lib,"win2k3_kernl32p.lib")
#endif

#ifndef _WIN64
#define DllMain DllMain_Existence
#include "..\crt\src\vcruntime\dll_dllmain_stub.cpp"
#undef DllMain
extern "C"
{
	//导出一个外部弱符号，指示当前是否处于强行卸载模式。
	BOOL __YY_Thunks_Process_Terminating;
	BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
	{
		switch (dwReason)
		{
		case DLL_PROCESS_DETACH:
			//我们可以通过 lpReserved != NULL 判断，当前是否处于强行卸载模式。
			__YY_Thunks_Process_Terminating = lpReserved != NULL;
			break;
		}
		return DllMain_Existence(hInstance, dwReason, lpReserved);
	}
}
#else
#include "..\crt\src\vcruntime\dll_dllmain_stub.cpp"
#endif