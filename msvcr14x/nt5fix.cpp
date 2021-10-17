#include "stdafx.h"

//#include "awint.hpp"
#include <internal_shared.h>
#include <assert.h>

// 下面的代码修改自老版本的awint.hpp
// Use this macro for caching a function pointer from a DLL
#define STOREFUNCTIONPOINTER(instance, function_name) \
    __KERNEL32Functions[e##function_name] = reinterpret_cast<PVOID>(GetProcAddress(instance, #function_name));

// Use this macro as a cached function pointer from a DLL
#define DYNAMICGETCACHEDFUNCTION(function_pointer_type, function_name, variable_name) \
    const auto variable_name = reinterpret_cast<function_pointer_type>(__KERNEL32Functions[e##function_name])

#define IFDYNAMICGETCACHEDFUNCTION(function_pointer_type, function_name, variable_name) \
    DYNAMICGETCACHEDFUNCTION(function_pointer_type, function_name, variable_name);      \
    if (variable_name != nullptr)

enum wrapKERNEL32Functions {
	eCompareStringW,
	eMaxKernel32Function
};
static PVOID __KERNEL32Functions[eMaxKernel32Function] = { nullptr };

using PFNCOMPARESTRINGW = int(WINAPI*)(__in LCID Locale, __in DWORD dwCmpFlags, __in_ecount(cchCount1) PCNZWCH lpString1, __in int cchCount1, __in_ecount(cchCount2) PCNZWCH lpString2, __in int cchCount2);

// 下面的代码来自老版本的winapisupp.cpp

#ifndef _WIN64
extern "C"
int
WINAPI
CompareStringW(
	_In_ LCID Locale,
	_In_ DWORD dwCmpFlags,
	_In_NLS_string_(cchCount1) PCNZWCH lpString1,
	_In_ int cchCount1,
	_In_NLS_string_(cchCount2) PCNZWCH lpString2,
	_In_ int cchCount2
)
{
	IFDYNAMICGETCACHEDFUNCTION(PFNCOMPARESTRINGW, CompareStringW, pfCompareStringW) {
		if (Locale == LOCALE_INVARIANT)
		{
			if (GetWindowsVersionEx(FALSE) <= 0x0500)
			{
				Locale = MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), SORT_DEFAULT);
			}
		}
		return pfCompareStringW(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2);
	}

	DebugBreak();
	return 0;
}
#endif

static int __cdecl initialize_pointers() {
	HINSTANCE hKernel32 = GetModuleHandleW(L"kernel32.dll");
	_Analysis_assume_(hKernel32);

	STOREFUNCTIONPOINTER(hKernel32, CompareStringW);

	return 0;
}

#ifndef _WIN64
#pragma comment(linker, "/include:?force_included__nt5fix_pinit@@3P6AHXZA")
#else
#pragma comment(linker, "/include:?force_included__nt5fix_pinit@@3P6AHXZEA")
#endif
_CRTALLOC(".CRT$XIC") /*static*/ _PIFV force_included__nt5fix_pinit = initialize_pointers;