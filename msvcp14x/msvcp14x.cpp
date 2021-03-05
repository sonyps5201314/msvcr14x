// msvcp14x.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

#pragma message("无法编译通过本工程时，请将依赖项中的CONCRT14X(D).lib先临时去掉，本工程及CONCRT14X工程生成成功后再加回来")

#ifdef _M_IX86
#pragma comment(lib,"win2k_KERNEL32.lib")
#pragma comment(lib,"win2k_kernl32p.lib")
#elif defined(_M_X64)
#pragma comment(lib,"win2k3_KERNEL32.lib")
#pragma comment(lib,"win2k3_kernl32p.lib")
#endif

//由于无法修改winapisupp.cpp,所以目前通过下面这样来防止pinit的符号因我们的链接选项中指定了/OPT:REF而被剔除
#include "winapisupp.cpp"
#ifndef _WIN64
#pragma comment(linker, "/include:?force_included__winapisupp_pinit@@3P6AHXZA")
#else
#pragma comment(linker, "/include:?force_included__winapisupp_pinit@@3P6AHXZEA")
#endif
_CRTALLOC(".CRT$XIC") /*static*/ _PIFV force_included__winapisupp_pinit = initialize_pointers;

#ifndef _WIN64
#define DllMain DllMain_Existence
#include "dllmain.cpp"
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
#include "dllmain.cpp"
#endif
