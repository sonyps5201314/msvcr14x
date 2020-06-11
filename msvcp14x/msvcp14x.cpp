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
