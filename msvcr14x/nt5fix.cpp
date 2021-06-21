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
	eCreateThreadpoolTimer,
	eSetThreadpoolTimer,
	eWaitForThreadpoolTimerCallbacks,
	eCloseThreadpoolTimer,
	eCreateThreadpoolWait,
	eSetThreadpoolWait,
	eCloseThreadpoolWait,
	eFlushProcessWriteBuffers,
	eFreeLibraryWhenCallbackReturns,
	eCreateThreadpoolWork,
	eSubmitThreadpoolWork,
	eWaitForThreadpoolWorkCallbacks,
	eCloseThreadpoolWork,
	eCompareStringW,
	eLCMapStringEx,
	eMaxKernel32Function
};
static PVOID __KERNEL32Functions[eMaxKernel32Function] = { nullptr };

using PFNCREATETHREADPOOLTIMER = PTP_TIMER(WINAPI*)(PTP_TIMER_CALLBACK, PVOID, PTP_CALLBACK_ENVIRON);
using PFNSETTHREADPOOLTIMER = VOID(WINAPI*)(PTP_TIMER, PFILETIME, DWORD, DWORD);
using PFNWAITFORTHREADPOOLTIMERCALLBACKS = VOID(WINAPI*)(PTP_TIMER, BOOL);
using PFNCLOSETHREADPOOLTIMER = VOID(WINAPI*)(PTP_TIMER);
using PFNCREATETHREADPOOLWAIT = PTP_WAIT(WINAPI*)(PTP_WAIT_CALLBACK, PVOID, PTP_CALLBACK_ENVIRON);
using PFNSETTHREADPOOLWAIT = VOID(WINAPI*)(PTP_WAIT, HANDLE, PFILETIME);
using PFNCLOSETHREADPOOLWAIT = VOID(WINAPI*)(PTP_WAIT);
using PFNFLUSHPROCESSWRITEBUFFERS = VOID(WINAPI*)();
using PFNFREELIBRARYWHENCALLBACKRETURNS = VOID(WINAPI*)(PTP_CALLBACK_INSTANCE, HMODULE);
using PFNCREATETHREADPOOLWORK = PTP_WORK(WINAPI*)(PTP_WORK_CALLBACK, PVOID, PTP_CALLBACK_ENVIRON);
using PFNSUBMITTHREADPOOLWORK = VOID(WINAPI*)(PTP_WORK);
using PFNWAITFORTHREADPOOLWORKCALLBACKS = VOID(WINAPI*)(PTP_WORK, BOOL);
using PFNCLOSETHREADPOOLWORK = VOID(WINAPI*)(PTP_WORK);
using PFNLCMAPSTRINGEX = int(WINAPI*)(LPCWSTR, DWORD, LPCWSTR, int, LPWSTR, int, LPNLSVERSIONINFO, LPVOID, LPARAM);
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

extern "C"
int
WINAPI
LCMapStringEx(
	_In_opt_ LPCWSTR lpLocaleName,
	_In_ DWORD dwMapFlags,
	_In_reads_(cchSrc) LPCWSTR lpSrcStr,
	_In_ int cchSrc,
	_Out_writes_opt_(cchDest) LPWSTR lpDestStr,
	_In_ int cchDest,
	_In_opt_ LPNLSVERSIONINFO lpVersionInformation,
	_In_opt_ LPVOID lpReserved,
	_In_opt_ LPARAM sortHandle
)
{
	// use LCMapStringEx if it is available (only on Windows Vista+)...
	IFDYNAMICGETCACHEDFUNCTION(PFNLCMAPSTRINGEX, LCMapStringEx, pfLCMapStringEx) {
		return pfLCMapStringEx(lpLocaleName, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest, nullptr, nullptr, 0);
	}

	const auto Locale = LocaleNameToLCID(lpLocaleName, 0);
	if (Locale == 0)
	{
		return 0;
	}

	// ...otherwise fall back to using LCMapString.
	return LCMapStringW(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest);
}

extern "C" PTP_TIMER WINAPI CreateThreadpoolTimer(
	_In_ PTP_TIMER_CALLBACK const pfnti, _Inout_opt_ PVOID const pv, _In_opt_ PTP_CALLBACK_ENVIRON const pcbe) {
	// use CreateThreadpoolTimer if it is available (only on Windows Vista+)...
	IFDYNAMICGETCACHEDFUNCTION(PFNCREATETHREADPOOLTIMER, CreateThreadpoolTimer, pfCreateThreadpoolTimer) {
		return pfCreateThreadpoolTimer(pfnti, pv, pcbe);
	}

	// ...otherwise return failure because there is no fall back.
	return nullptr;
}

extern "C" VOID WINAPI SetThreadpoolTimer(_Inout_ PTP_TIMER const pti, _In_opt_ PFILETIME const pftDueTime,
	_In_ DWORD const msPeriod, _In_opt_ DWORD const msWindowLength) {
	// use SetThreadpoolTimer if it is available (only on Windows Vista+)...
	IFDYNAMICGETCACHEDFUNCTION(PFNSETTHREADPOOLTIMER, SetThreadpoolTimer, pfSetThreadpoolTimer) {
		pfSetThreadpoolTimer(pti, pftDueTime, msPeriod, msWindowLength);
	}

	// ...otherwise there is no fall back.
	return;
}

extern "C" VOID WINAPI WaitForThreadpoolTimerCallbacks(
	_Inout_ PTP_TIMER const pti, _In_ BOOL const fCancelPendingCallbacks) {
	// use WaitForThreadpoolTimerCallbacks if it is available (only on Windows Vista+)...
	IFDYNAMICGETCACHEDFUNCTION(
		PFNWAITFORTHREADPOOLTIMERCALLBACKS, WaitForThreadpoolTimerCallbacks, pfWaitForThreadpoolTimerCallbacks) {
		pfWaitForThreadpoolTimerCallbacks(pti, fCancelPendingCallbacks);
	}

	// ...otherwise there is no fall back.
	return;
}

extern "C" VOID WINAPI CloseThreadpoolTimer(_Inout_ PTP_TIMER const pti) {
	// use CloseThreadpoolTimer if it is available (only on Windows Vista+)...
	IFDYNAMICGETCACHEDFUNCTION(PFNCLOSETHREADPOOLTIMER, CloseThreadpoolTimer, pfCloseThreadpoolTimer) {
		pfCloseThreadpoolTimer(pti);
	}

	// ...otherwise there is no fall back.
	return;
}

extern "C" PTP_WAIT WINAPI CreateThreadpoolWait(
	_In_ PTP_WAIT_CALLBACK const pfnwa, _Inout_opt_ PVOID const pv, _In_opt_ PTP_CALLBACK_ENVIRON const pcbe) {
	// use CreateThreadpoolWait if it is available (only on Windows Vista+)...
	IFDYNAMICGETCACHEDFUNCTION(PFNCREATETHREADPOOLWAIT, CreateThreadpoolWait, pfCreateThreadpoolWait) {
		return pfCreateThreadpoolWait(pfnwa, pv, pcbe);
	}

	// ...otherwise return failure because there is no fall back.
	return nullptr;
}

extern "C" VOID WINAPI SetThreadpoolWait(
	_Inout_ PTP_WAIT const pwa, _In_opt_ HANDLE const h, _In_opt_ PFILETIME const pftTimeout) {
	// use SetThreadpoolWait if it is available (only on Windows Vista+)...
	IFDYNAMICGETCACHEDFUNCTION(PFNSETTHREADPOOLWAIT, SetThreadpoolWait, pfSetThreadpoolWait) {
		pfSetThreadpoolWait(pwa, h, pftTimeout);
	}

	// ...otherwise there is no fall back.
}

extern "C" VOID WINAPI CloseThreadpoolWait(_Inout_ PTP_WAIT const pwa) {
	// use CloseThreadpoolWait if it is available (only on Windows Vista+)...
	IFDYNAMICGETCACHEDFUNCTION(PFNCLOSETHREADPOOLWAIT, CloseThreadpoolWait, pfCloseThreadpoolWait) {
		pfCloseThreadpoolWait(pwa);
	}

	// ...otherwise there is no fall back.
}

extern "C" VOID WINAPI FlushProcessWriteBuffers() {
	// use FlushProcessWriteBuffers if it is available (only on Windows Vista+)...
	IFDYNAMICGETCACHEDFUNCTION(PFNFLUSHPROCESSWRITEBUFFERS, FlushProcessWriteBuffers, pfFlushProcessWriteBuffers) {
		pfFlushProcessWriteBuffers();
	}

	// ...otherwise there is no fall back.
}

//下列简化的结构体定义参考了https://github.com/FreeRDP/FreeRDP/blob/master/winpr/libwinpr/pool/pool.h和wine
//并不代表Windows内部也一定是和它们一样
struct _TP_CALLBACK_INSTANCE
{
	LIST_ENTRY Link;
	PTP_WORK Work;//目前仅支持了线程池Work
	BOOL Finished;
	struct
	{
		//CRITICAL_SECTION* critical_section;
		//HANDLE              mutex;
		//HANDLE              semaphore;
		//LONG                semaphore_count;
		//HANDLE              event;
		HMODULE             library;
	} cleanup;
};
struct _TP_WORK
{
	PVOID CallbackParameter;
	PTP_WORK_CALLBACK WorkCallback;
	PTP_CALLBACK_ENVIRON CallbackEnvironment;

	LONG refcount;
	LIST_ENTRY CallbackInstances;
	RTL_CRITICAL_SECTION cs;
};

extern "C" VOID WINAPI FreeLibraryWhenCallbackReturns(
	_Inout_ PTP_CALLBACK_INSTANCE const pci, _In_ HMODULE const mod) {
	// use FreeLibraryWhenCallbackReturns if it is available (only on Windows Vista+)...
	IFDYNAMICGETCACHEDFUNCTION(
		PFNFREELIBRARYWHENCALLBACKRETURNS, FreeLibraryWhenCallbackReturns, pfFreeLibraryWhenCallbackReturns) {
		pfFreeLibraryWhenCallbackReturns(pci, mod);
		return;
	}

	if (!pci || !mod || mod == INVALID_HANDLE_VALUE || pci->cleanup.library)
	{
		assert(FALSE);
		SetLastError(ERROR_INVALID_PARAMETER);
	}
	else
	{
		pci->cleanup.library = mod;
	}
}

extern "C" PTP_WORK WINAPI CreateThreadpoolWork(
	_In_ PTP_WORK_CALLBACK const pfnwk, _Inout_opt_ PVOID const pv, _In_opt_ PTP_CALLBACK_ENVIRON const pcbe) {
	IFDYNAMICGETCACHEDFUNCTION(PFNCREATETHREADPOOLWORK, CreateThreadpoolWork, pfCreateThreadpoolWork) {
		return pfCreateThreadpoolWork(pfnwk, pv, pcbe);
	}
	// the only two callers are taskscheduler.cpp and parallel_algorithms.cpp
	PTP_WORK work = (PTP_WORK)calloc(1, sizeof(TP_WORK));
	if (work)
	{
		work->WorkCallback = pfnwk;
		work->CallbackParameter = pv;
		work->CallbackEnvironment = pcbe;

		work->refcount = 1;
		InitializeListHead(&work->CallbackInstances);
		if (!InitializeCriticalSectionAndSpinCount(&work->cs, 4000))
		{
			assert(FALSE);
			free(work);
			work = NULL;
		}
	}
	if (!work)
	{
		assert(work);
	}
	return work;
}

void ReleaseThreadpoolWork(PTP_WORK pwk)
{
	if (InterlockedDecrement(&pwk->refcount) == 0)
	{
		DeleteCriticalSection(&pwk->cs);
		free(pwk);
		pwk = NULL;
	}
}

//本函数参考了wine的tp_object_execute函数
DWORD __stdcall _Task_scheduler_callback_xp(LPVOID _Args) noexcept {
	const auto instance = static_cast<PTP_CALLBACK_INSTANCE>(_Args);

	EnterCriticalSection(&instance->Work->cs);
	if (!instance->Finished)
	{
		instance->Finished = TRUE;
		instance->Work->WorkCallback(instance, instance->Work->CallbackParameter, instance->Work);
		if (instance->cleanup.library)
		{
			FreeLibrary(instance->cleanup.library);
		}
	}
	RemoveEntryList(&instance->Link);
	LeaveCriticalSection(&instance->Work->cs);

	ReleaseThreadpoolWork(instance->Work);
	free(instance);
	return 0;
}
extern "C" VOID WINAPI SubmitThreadpoolWork(_Inout_ PTP_WORK const pwk) {
	IFDYNAMICGETCACHEDFUNCTION(PFNSUBMITTHREADPOOLWORK, SubmitThreadpoolWork, pfSubmitThreadpoolWork) {
		return pfSubmitThreadpoolWork(pwk);
	}
	// the only two callers are taskscheduler.cpp and parallel_algorithms.cpp
	PTP_CALLBACK_INSTANCE callbackInstance = (PTP_CALLBACK_INSTANCE)calloc(1, sizeof(TP_CALLBACK_INSTANCE));
	if (callbackInstance)
	{
		InterlockedIncrement(&pwk->refcount);
		callbackInstance->Work = pwk;
		callbackInstance->Finished = FALSE;

		EnterCriticalSection(&pwk->cs);
		InsertTailList(&pwk->CallbackInstances, &callbackInstance->Link);
		BOOL bResult = QueueUserWorkItem(_Task_scheduler_callback_xp, callbackInstance, WT_EXECUTEDEFAULT);
		if (!bResult) {
			assert(FALSE);
			RemoveEntryList(&callbackInstance->Link);
		}
		LeaveCriticalSection(&pwk->cs);

		if (!bResult)
		{
			free(callbackInstance);
			callbackInstance = NULL;

			ReleaseThreadpoolWork(pwk);
		}
	}
}

extern "C" VOID
WINAPI
WaitForThreadpoolWorkCallbacks(
	_Inout_ PTP_WORK pwk,
	_In_ BOOL fCancelPendingCallbacks
)
{
	// use WaitForThreadpoolWorkCallbacks if it is available (only on Windows Vista+)...
	IFDYNAMICGETCACHEDFUNCTION(
		PFNWAITFORTHREADPOOLWORKCALLBACKS, WaitForThreadpoolWorkCallbacks, pfWaitForThreadpoolWorkCallbacks) {
		pfWaitForThreadpoolWorkCallbacks(pwk, fCancelPendingCallbacks);
		return;
	}

	// the only two callers are taskscheduler.cpp and parallel_algorithms.cpp
	if (fCancelPendingCallbacks)
	{
		EnterCriticalSection(&pwk->cs);
		PTP_CALLBACK_INSTANCE info = NULL;
		LIST_ENTRY* lptr = NULL;
		for (lptr = pwk->CallbackInstances.Flink; lptr != &pwk->CallbackInstances; lptr = lptr->Flink)
		{
			info = CONTAINING_RECORD(lptr, TP_CALLBACK_INSTANCE, Link);
			info->Finished = TRUE;
		}
		LeaveCriticalSection(&pwk->cs);
	}
	else
	{
		while (TRUE)
		{
			BOOL bFindPendingCallbacks = FALSE;
			EnterCriticalSection(&pwk->cs);
			PTP_CALLBACK_INSTANCE info = NULL;
			LIST_ENTRY* lptr = NULL;
			for (lptr = pwk->CallbackInstances.Flink; lptr != &pwk->CallbackInstances; lptr = lptr->Flink)
			{
				info = CONTAINING_RECORD(lptr, TP_CALLBACK_INSTANCE, Link);
				if (!info->Finished)
				{
					bFindPendingCallbacks = TRUE;
					break;
				}
			}
			LeaveCriticalSection(&pwk->cs);

			if (bFindPendingCallbacks)
			{
				Sleep(10);
			}
			else
			{
				break;
			}
		}
	}
	return;
}

extern "C" VOID WINAPI CloseThreadpoolWork(_Inout_ PTP_WORK const pwk) {
	IFDYNAMICGETCACHEDFUNCTION(PFNCLOSETHREADPOOLWORK, CloseThreadpoolWork, pfCloseThreadpoolWork) {
		return pfCloseThreadpoolWork(pwk);
	}
	// the only two callers are taskscheduler.cpp and parallel_algorithms.cpp
	if (pwk)
	{
		BOOL bFindPendingCallbacks = FALSE;
		EnterCriticalSection(&pwk->cs);
		PTP_CALLBACK_INSTANCE info = NULL;
		LIST_ENTRY* lptr = NULL;
		for (lptr = pwk->CallbackInstances.Flink; lptr != &pwk->CallbackInstances; lptr = lptr->Flink)
		{
			info = CONTAINING_RECORD(lptr, TP_CALLBACK_INSTANCE, Link);
			if (!info->Finished)
			{
				bFindPendingCallbacks = TRUE;
				break;
			}
		}
		LeaveCriticalSection(&pwk->cs);

		assert(!bFindPendingCallbacks);

		ReleaseThreadpoolWork(pwk);
	}
}

static int __cdecl initialize_pointers() {
	HINSTANCE hKernel32 = GetModuleHandleW(L"kernel32.dll");
	_Analysis_assume_(hKernel32);

	STOREFUNCTIONPOINTER(hKernel32, CreateThreadpoolTimer);
	STOREFUNCTIONPOINTER(hKernel32, SetThreadpoolTimer);
	STOREFUNCTIONPOINTER(hKernel32, WaitForThreadpoolTimerCallbacks);
	STOREFUNCTIONPOINTER(hKernel32, CloseThreadpoolTimer);

	STOREFUNCTIONPOINTER(hKernel32, CreateThreadpoolWait);
	STOREFUNCTIONPOINTER(hKernel32, SetThreadpoolWait);
	STOREFUNCTIONPOINTER(hKernel32, CloseThreadpoolWait);

	STOREFUNCTIONPOINTER(hKernel32, FlushProcessWriteBuffers);
	STOREFUNCTIONPOINTER(hKernel32, FreeLibraryWhenCallbackReturns);

	STOREFUNCTIONPOINTER(hKernel32, CreateThreadpoolWork);
	STOREFUNCTIONPOINTER(hKernel32, SubmitThreadpoolWork);
	STOREFUNCTIONPOINTER(hKernel32, WaitForThreadpoolWorkCallbacks);
	STOREFUNCTIONPOINTER(hKernel32, CloseThreadpoolWork);

	STOREFUNCTIONPOINTER(hKernel32, CompareStringW);
	STOREFUNCTIONPOINTER(hKernel32, LCMapStringEx);

	return 0;
}

#ifndef _WIN64
#pragma comment(linker, "/include:?force_included__nt5fix_pinit@@3P6AHXZA")
#else
#pragma comment(linker, "/include:?force_included__nt5fix_pinit@@3P6AHXZEA")
#endif
_CRTALLOC(".CRT$XIC") /*static*/ _PIFV force_included__nt5fix_pinit = initialize_pointers;