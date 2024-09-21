// msvcp14x.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"


#ifdef _M_IX86
#pragma comment(lib,"KERNEL32.lib")
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

#pragma comment(linker, "/ENTRY:DllMainCRTStartupForYY_Thunks")
extern "C"
{
	const void* __pfnDllMainCRTStartupForYY_Thunks;
	BOOL __YY_Thunks_Disable_Rreload_Dlls;
	const void* __acrt_atexit_table;
}