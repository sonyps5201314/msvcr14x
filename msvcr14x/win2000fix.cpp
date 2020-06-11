#define NONAMELESSUNION
#include "StdAfx.h"
#include <intrin.h>
#if defined(_M_X64)
#pragma message("x64下可以不编译本文件")
#endif

#define TRACE
#define FIXME TRACE
#define DPRINT1 TRACE
#define debugstr_w(x) x

#ifdef _M_X64
int interlocked_cmpxchg128(__int64 *dest, __int64 xchg_high, __int64 xchg_low, __int64 *compare)
{
	return _InterlockedCompareExchange128(dest, xchg_high, xchg_low, compare);
}
#endif

/*__declspec(naked) */__int64 interlocked_cmpxchg64(__int64 *dest, __int64 xchg, __int64 compare)
{
	//__asm push ebx;
	//__asm push esi;
	//__asm mov esi, 12[esp];
	//__asm mov ebx, 16[esp];
	//__asm mov ecx, 20[esp];
	//__asm mov eax, 24[esp];
	//__asm mov edx, 28[esp];
	//__asm lock cmpxchg8b[esi];
	//__asm pop esi;
	//__asm pop ebx;
	//__asm ret;
	return _InterlockedCompareExchange64(dest, xchg, compare);
}

extern "C"
{
	PVOID(WINAPI* Real_EncodePointer)(__in_opt PVOID Ptr);
	PVOID WINAPI EncodePointer(__in_opt PVOID Ptr)
	{
		if (Real_EncodePointer == NULL)
		{
			Real_EncodePointer = (PVOID(__stdcall *)(PVOID))GetProcAddress(GetModuleHandle(_T("Kernel32.dll")), "EncodePointer");
		}

		if (Real_EncodePointer)
		{
			return Real_EncodePointer(Ptr);
		}
		else
		{
			return Ptr;
		}
	}

	__out_opt PVOID(WINAPI* Real_DecodePointer)(__in_opt PVOID Ptr);
	__out_opt PVOID WINAPI DecodePointer(__in_opt PVOID Ptr)
	{
		if (Real_DecodePointer == NULL)
		{
			Real_DecodePointer = (PVOID(__stdcall *)(PVOID))GetProcAddress(GetModuleHandle(_T("Kernel32.dll")), "DecodePointer");
		}

		if (Real_DecodePointer)
		{
			return Real_DecodePointer(Ptr);
		}
		else
		{
			return Ptr;
		}
	}

	BOOL(WINAPI* Real_GetModuleHandleExW)(__in  DWORD dwFlags, __in_opt LPCWSTR lpModuleName, __out HMODULE* phModule);
	BOOL WINAPI GetModuleHandleExW(__in  DWORD dwFlags, __in_opt LPCWSTR lpModuleName, __out HMODULE* phModule)
	{
		if (Real_GetModuleHandleExW == NULL)
		{
			Real_GetModuleHandleExW =
				(BOOL(__stdcall *)(DWORD, LPCWSTR, HMODULE *))GetProcAddress(GetModuleHandle(_T("Kernel32.dll")), "GetModuleHandleExW");
		}

		if (Real_GetModuleHandleExW)
		{
			return Real_GetModuleHandleExW(dwFlags, lpModuleName, phModule);
		}
		else
		{
			HMODULE hModule = GetModuleHandleW(lpModuleName);
			if (phModule)
			{
				*phModule = hModule;
			}
			return hModule != NULL;
		}
	}

	int (WINAPI* Real_CompareStringA)(__in LCID Locale, __in DWORD dwCmpFlags, __in_ecount(cchCount1) PCNZCH lpString1, __in int cchCount1, __in_ecount(cchCount2) PCNZCH lpString2, __in int cchCount2);
	int WINAPI CompareStringA(__in LCID Locale, __in DWORD dwCmpFlags, __in_ecount(cchCount1) PCNZCH lpString1, __in int cchCount1, __in_ecount(cchCount2) PCNZCH lpString2, __in int cchCount2)
	{
		if (Real_CompareStringA == NULL)
		{
			Real_CompareStringA = (int(__stdcall *)(LCID, DWORD, PCNZCH, int, PCNZCH, int))GetProcAddress(GetModuleHandle(_T("Kernel32.dll")), "CompareStringA");
		}

		if (Locale == LOCALE_INVARIANT)
		{
			if (GetWindowsVersionEx(FALSE) <= 0x0500)
			{
				Locale = MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), SORT_DEFAULT);
			}
		}
		return Real_CompareStringA(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2);
	}

	int (WINAPI* Real_CompareStringW)(__in LCID Locale, __in DWORD dwCmpFlags, __in_ecount(cchCount1) PCNZWCH lpString1, __in int cchCount1, __in_ecount(cchCount2) PCNZWCH lpString2, __in int cchCount2);
	int WINAPI CompareStringW(__in LCID Locale, __in DWORD dwCmpFlags, __in_ecount(cchCount1) PCNZWCH lpString1, __in int cchCount1, __in_ecount(cchCount2) PCNZWCH lpString2, __in int cchCount2)
	{
		if (Real_CompareStringW == NULL)
		{
			Real_CompareStringW =
				(int(__stdcall *)(LCID, DWORD, PCNZWCH, int, PCNZWCH, int))GetProcAddress(GetModuleHandle(_T("Kernel32.dll")), "CompareStringW");
		}

		if (Locale == LOCALE_INVARIANT)
		{
			if (GetWindowsVersionEx(FALSE) <= 0x0500)
			{
				Locale = MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), SORT_DEFAULT);
			}
		}

		return Real_CompareStringW(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2);
	}

	/*************************************************************************
	* RtlInterlockedFlushSList   [NTDLL.@]
	*/
	PSLIST_ENTRY WINAPI _RtlInterlockedFlushSList(PSLIST_HEADER list)
	{
		SLIST_HEADER old, _new;

#ifdef _WIN64
		if (!list->Header16.NextEntry) return NULL;
		_new.s.Alignment = _new.s.Region = 0;
		_new.Header16.HeaderType = 1;  /* we use the 16-byte header */
		do
		{
			old = *list;
			_new.Header16.Sequence = old.Header16.Sequence + 1;
		} while (!interlocked_cmpxchg128((__int64 *)list, _new.s.Region, _new.s.Alignment, (__int64 *)&old));
		return (SLIST_ENTRY *)((ULONG_PTR)old.Header16.NextEntry << 4);
#else
		if (!list->s.Next.Next) return NULL;
		_new.Alignment = 0;
		do
		{
			old = *list;
			_new.s.Sequence = old.s.Sequence + 1;
		} while (interlocked_cmpxchg64((__int64 *)&list->Alignment, _new.Alignment,
			old.Alignment) != old.Alignment);
		return old.s.Next.Next;
#endif
	}

	PSLIST_ENTRY WINAPI	InterlockedFlushSList(__inout PSLIST_HEADER ListHead)
	{
		return _RtlInterlockedFlushSList(ListHead);
	}

	/*************************************************************************
	* RtlInterlockedPushEntrySList   [NTDLL.@]
	*/
	PSLIST_ENTRY WINAPI _RtlInterlockedPushEntrySList(PSLIST_HEADER list, PSLIST_ENTRY entry)
	{
		SLIST_HEADER old, _new;

#ifdef _WIN64
		_new.Header16.NextEntry = (ULONG_PTR)entry >> 4;
		do
		{
			old = *list;
			entry->Next = (SLIST_ENTRY *)((ULONG_PTR)old.Header16.NextEntry << 4);
			_new.Header16.Depth = old.Header16.Depth + 1;
			_new.Header16.Sequence = old.Header16.Sequence + 1;
		} while (!interlocked_cmpxchg128((__int64 *)list, _new.s.Region, _new.s.Alignment, (__int64 *)&old));
		return (SLIST_ENTRY *)((ULONG_PTR)old.Header16.NextEntry << 4);
#else
		_new.s.Next.Next = entry;
		do
		{
			old = *list;
			entry->Next = old.s.Next.Next;
			_new.s.Depth = old.s.Depth + 1;
			_new.s.Sequence = old.s.Sequence + 1;
		} while (interlocked_cmpxchg64((__int64 *)&list->Alignment, _new.Alignment,
			old.Alignment) != old.Alignment);
		return old.s.Next.Next;
#endif
	}

	PSLIST_ENTRY(WINAPI* Real_InterlockedPushEntrySList)(_Inout_ PSLIST_HEADER ListHead, _Inout_ __drv_aliasesMem PSLIST_ENTRY ListEntry);
	PSLIST_ENTRY WINAPI	InterlockedPushEntrySList(_Inout_ PSLIST_HEADER ListHead, _Inout_ __drv_aliasesMem PSLIST_ENTRY ListEntry)
	{
		if (Real_InterlockedPushEntrySList == NULL)
		{
			Real_InterlockedPushEntrySList = (PSLIST_ENTRY(__stdcall *)(PSLIST_HEADER, PSLIST_ENTRY))GetProcAddress(GetModuleHandle(_T("Kernel32.dll")), "InterlockedPushEntrySList");
		}
		if (Real_InterlockedPushEntrySList)
		{
			return Real_InterlockedPushEntrySList(ListHead, ListEntry);
		}

		return _RtlInterlockedPushEntrySList(ListHead, ListEntry);
	}

	VOID NTAPI _RtlInitializeSListHead(
		_Out_ PSLIST_HEADER SListHead)
	{
#if defined(_WIN64)
		/* Make sure the header is 16 byte aligned */
		if (((ULONG_PTR)SListHead & 0xf) != 0)
		{
			DPRINT1("Unaligned SListHead: 0x%p\n", SListHead);
			RtlRaiseStatus(STATUS_DATATYPE_MISALIGNMENT);
		}

		/* Initialize the Region member */
#if defined(_IA64_)
	/* On Itanium we store the region in the list head */
		SListHead->Region = (ULONG_PTR)SListHead & VRN_MASK;
#else
	/* On amd64 we don't need to store anything */
		SListHead->s.Region = 0;
#endif /* _IA64_ */
#endif /* _WIN64 */

#if defined(_WIN64)
		SListHead->s.Alignment = 0;
#else
		SListHead->Alignment = 0;
#endif
	}

	VOID(WINAPI* Real_InitializeSListHead)(__inout PSLIST_HEADER ListHead);
	VOID WINAPI InitializeSListHead(__inout PSLIST_HEADER ListHead)
	{
		if (Real_InitializeSListHead == NULL)
		{
			Real_InitializeSListHead = (void(__stdcall *)(PSLIST_HEADER))GetProcAddress(GetModuleHandle(_T("Kernel32.dll")), "InitializeSListHead");
		}
		if (Real_InitializeSListHead)
		{
			return Real_InitializeSListHead(ListHead);
		}

		_RtlInitializeSListHead(ListHead);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define CALINFO_MAX_YEAR 2029

#define LL2FILETIME( ll, pft )\
    (pft)->dwLowDateTime = (UINT)(ll); \
    (pft)->dwHighDateTime = (UINT)((ll) >> 32);
#define FILETIME2LL( pft, ll) \
    ll = (((LONGLONG)((pft)->dwHighDateTime))<<32) + (pft)-> dwLowDateTime ;


	static const int MonthLengths[2][12] =
	{
		{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
	};

	static inline BOOL IsLeapYear(int Year)
	{
		return Year % 4 == 0 && (Year % 100 != 0 || Year % 400 == 0);
	}

	/***********************************************************************
	*  TIME_DayLightCompareDate
	*
	* Compares two dates without looking at the year.
	*
	* PARAMS
	*   date        [in] The local time to compare.
	*   compareDate [in] The daylight savings begin or end date.
	*
	* RETURNS
	*
	*  -1 if date < compareDate
	*   0 if date == compareDate
	*   1 if date > compareDate
	*  -2 if an error occurs
	*/
	static int TIME_DayLightCompareDate(const SYSTEMTIME *date,
		const SYSTEMTIME *compareDate)
	{
		int limit_day, dayinsecs;

		if (date->wMonth < compareDate->wMonth)
			return -1; /* We are in a month before the date limit. */

		if (date->wMonth > compareDate->wMonth)
			return 1; /* We are in a month after the date limit. */

					  /* if year is 0 then date is in day-of-week format, otherwise
					  * it's absolute date.
					  */
		if (compareDate->wYear == 0)
		{
			WORD First;
			/* compareDate->wDay is interpreted as number of the week in the month
			* 5 means: the last week in the month */
			int weekofmonth = compareDate->wDay;
			/* calculate the day of the first DayOfWeek in the month */
			First = (6 + compareDate->wDayOfWeek - date->wDayOfWeek + date->wDay
				) % 7 + 1;
			limit_day = First + 7 * (weekofmonth - 1);
			/* check needed for the 5th weekday of the month */
			if (limit_day > MonthLengths[date->wMonth == 2 && IsLeapYear(date->wYear)]
				[date->wMonth - 1])
				limit_day -= 7;
		}
		else
		{
			limit_day = compareDate->wDay;
		}

		/* convert to seconds */
		limit_day = ((limit_day * 24 + compareDate->wHour) * 60 +
			compareDate->wMinute) * 60;
		dayinsecs = ((date->wDay * 24 + date->wHour) * 60 +
			date->wMinute) * 60 + date->wSecond;
		/* and compare */
		return dayinsecs < limit_day ? -1 :
			dayinsecs > limit_day ? 1 :
			0;   /* date is equal to the date limit. */
	}

	/***********************************************************************
	*  TIME_CompTimeZoneID
	*
	*  Computes the local time bias for a given time and time zone.
	*
	*  PARAMS
	*      pTZinfo     [in] The time zone data.
	*      lpFileTime  [in] The system or local time.
	*      islocal     [in] it is local time.
	*
	*  RETURNS
	*      TIME_ZONE_ID_INVALID    An error occurred
	*      TIME_ZONE_ID_UNKNOWN    There are no transition time known
	*      TIME_ZONE_ID_STANDARD   Current time is standard time
	*      TIME_ZONE_ID_DAYLIGHT   Current time is daylight savings time
	*/
	static DWORD TIME_CompTimeZoneID(const TIME_ZONE_INFORMATION *pTZinfo,
		FILETIME *lpFileTime, BOOL islocal)
	{
		int ret, year;
		BOOL beforeStandardDate, afterDaylightDate;
		DWORD retval = TIME_ZONE_ID_INVALID;
		LONGLONG llTime = 0; /* initialized to prevent gcc complaining */
		SYSTEMTIME SysTime;
		FILETIME ftTemp;

		if (pTZinfo->DaylightDate.wMonth != 0)
		{
			/* if year is 0 then date is in day-of-week format, otherwise
			* it's absolute date.
			*/
			if (pTZinfo->StandardDate.wMonth == 0 ||
				(pTZinfo->StandardDate.wYear == 0 &&
				(pTZinfo->StandardDate.wDay < 1 ||
					pTZinfo->StandardDate.wDay>5 ||
					pTZinfo->DaylightDate.wDay < 1 ||
					pTZinfo->DaylightDate.wDay>5)))
			{
				SetLastError(ERROR_INVALID_PARAMETER);
				return TIME_ZONE_ID_INVALID;
			}

			if (!islocal) {
				FILETIME2LL(lpFileTime, llTime);
				llTime -= pTZinfo->Bias * (LONGLONG)600000000;
				LL2FILETIME(llTime, &ftTemp)
					lpFileTime = &ftTemp;
			}

			FileTimeToSystemTime(lpFileTime, &SysTime);
			year = SysTime.wYear;

			if (!islocal) {
				llTime -= pTZinfo->DaylightBias * (LONGLONG)600000000;
				LL2FILETIME(llTime, &ftTemp)
					FileTimeToSystemTime(lpFileTime, &SysTime);
			}

			/* check for daylight savings */
			if (year == SysTime.wYear) {
				ret = TIME_DayLightCompareDate(&SysTime, &pTZinfo->StandardDate);
				if (ret == -2)
					return TIME_ZONE_ID_INVALID;

				beforeStandardDate = ret < 0;
			}
			else
				beforeStandardDate = SysTime.wYear < year;

			if (!islocal) {
				llTime -= (pTZinfo->StandardBias - pTZinfo->DaylightBias)
					* (LONGLONG)600000000;
				LL2FILETIME(llTime, &ftTemp)
					FileTimeToSystemTime(lpFileTime, &SysTime);
			}

			if (year == SysTime.wYear) {
				ret = TIME_DayLightCompareDate(&SysTime, &pTZinfo->DaylightDate);
				if (ret == -2)
					return TIME_ZONE_ID_INVALID;

				afterDaylightDate = ret >= 0;
			}
			else
				afterDaylightDate = SysTime.wYear > year;

			retval = TIME_ZONE_ID_STANDARD;
			if (pTZinfo->DaylightDate.wMonth < pTZinfo->StandardDate.wMonth) {
				/* Northern hemisphere */
				if (beforeStandardDate && afterDaylightDate)
					retval = TIME_ZONE_ID_DAYLIGHT;
			}
			else    /* Down south */
				if (beforeStandardDate || afterDaylightDate)
					retval = TIME_ZONE_ID_DAYLIGHT;
		}
		else
			/* No transition date */
			retval = TIME_ZONE_ID_UNKNOWN;

		return retval;
	}

	/***********************************************************************
	*  TIME_GetTimezoneBias
	*
	*  Calculates the local time bias for a given time zone.
	*
	* PARAMS
	*  pTZinfo    [in]  The time zone data.
	*  lpFileTime [in]  The system or local time.
	*  islocal    [in]  It is local time.
	*  pBias      [out] The calculated bias in minutes.
	*
	* RETURNS
	*  TRUE when the time zone bias was calculated.
	*/
	static BOOL TIME_GetTimezoneBias(const TIME_ZONE_INFORMATION *pTZinfo,
		FILETIME *lpFileTime, BOOL islocal, LONG *pBias)
	{
		LONG bias = pTZinfo->Bias;
		DWORD tzid = TIME_CompTimeZoneID(pTZinfo, lpFileTime, islocal);

		if (tzid == TIME_ZONE_ID_INVALID)
			return FALSE;
		if (tzid == TIME_ZONE_ID_DAYLIGHT)
			bias += pTZinfo->DaylightBias;
		else if (tzid == TIME_ZONE_ID_STANDARD)
			bias += pTZinfo->StandardBias;
		*pBias = bias;
		return TRUE;
	}

	/***********************************************************************
	*              TzSpecificLocalTimeToSystemTime  (KERNEL32.@)
	*
	*  Converts a local time to a time in utc.
	*
	* PARAMS
	*  lpTimeZoneInformation [in]  The desired time zone.
	*  lpLocalTime           [in]  The local time.
	*  lpUniversalTime       [out] The calculated utc time.
	*
	* RETURNS
	*  Success: TRUE. lpUniversalTime contains the converted time.
	*  Failure: FALSE.
	*/
	BOOL(WINAPI* Real_TzSpecificLocalTimeToSystemTime)(
		const TIME_ZONE_INFORMATION *lpTimeZoneInformation,
		const SYSTEMTIME *lpLocalTime, LPSYSTEMTIME lpUniversalTime);
	BOOL WINAPI TzSpecificLocalTimeToSystemTime(
		const TIME_ZONE_INFORMATION *lpTimeZoneInformation,
		const SYSTEMTIME *lpLocalTime, LPSYSTEMTIME lpUniversalTime)
	{
		if (Real_TzSpecificLocalTimeToSystemTime == NULL)
		{
			Real_TzSpecificLocalTimeToSystemTime = (BOOL(__stdcall *)(const TIME_ZONE_INFORMATION *, const SYSTEMTIME *, LPSYSTEMTIME))GetProcAddress(GetModuleHandle(_T("Kernel32.dll")), "TzSpecificLocalTimeToSystemTime");
		}
		if (Real_TzSpecificLocalTimeToSystemTime)
		{
			return Real_TzSpecificLocalTimeToSystemTime(lpTimeZoneInformation, lpLocalTime, lpUniversalTime);
		}

		FILETIME ft;
		LONG lBias;
		LONGLONG t;
		TIME_ZONE_INFORMATION tzinfo;

		if (lpTimeZoneInformation != NULL)
		{
			tzinfo = *lpTimeZoneInformation;
		}
		else
		{
			if (GetTimeZoneInformation(&tzinfo) == TIME_ZONE_ID_INVALID)
				return FALSE;
		}

		if (!SystemTimeToFileTime(lpLocalTime, &ft))
			return FALSE;
		FILETIME2LL(&ft, t)
			if (!TIME_GetTimezoneBias(&tzinfo, &ft, TRUE, &lBias))
				return FALSE;
		/* convert minutes to 100-nanoseconds-ticks */
		t += (LONGLONG)lBias * 600000000;
		LL2FILETIME(t, &ft)
			return FileTimeToSystemTime(&ft, lpUniversalTime);
	}

	BOOL(WINAPI* Real_IsWow64Process)(__in  HANDLE hProcess, __out PBOOL Wow64Process);
	BOOL WINAPI IsWow64Process(__in  HANDLE hProcess, __out PBOOL Wow64Process)
	{
		if (Real_IsWow64Process == NULL)
		{
			Real_IsWow64Process = (BOOL(__stdcall *)(HANDLE, PBOOL))GetProcAddress(GetModuleHandle(TEXT("Kernel32.dll")), "IsWow64Process");
		}
		if (Real_IsWow64Process)
		{
			return Real_IsWow64Process(hProcess, Wow64Process);
		}
		else
		{
			if (!Wow64Process)
			{
				SetLastError(ERROR_INVALID_PARAMETER);
				return FALSE;
			}
			else
			{
				*Wow64Process = FALSE;
				return TRUE;
			}
		}
	}

	/***********************************************************************
	* 			GetNativeSystemInfo            	[KERNEL32.@]
	*/
	VOID(WINAPI* Real_GetNativeSystemInfo)(
		LPSYSTEM_INFO si	/* [out] Destination for system information, may not be NULL */);
	VOID WINAPI GetNativeSystemInfo(
		LPSYSTEM_INFO si	/* [out] Destination for system information, may not be NULL */)
	{
		if (Real_GetNativeSystemInfo == NULL)
		{
			Real_GetNativeSystemInfo = (void(__stdcall *)(LPSYSTEM_INFO))GetProcAddress(GetModuleHandle(_T("Kernel32.dll")), "GetNativeSystemInfo");
		}
		if (Real_GetNativeSystemInfo)
		{
			return Real_GetNativeSystemInfo(si);
		}

		BOOL is_wow64;

		GetSystemInfo(si);

		IsWow64Process(GetCurrentProcess(), &is_wow64);
		if (is_wow64)
		{
			if (si->u.s.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL)
			{
				si->u.s.wProcessorArchitecture = PROCESSOR_ARCHITECTURE_AMD64;
				si->dwProcessorType = PROCESSOR_AMD_X8664;
			}
			else
			{
				FIXME("Add the proper information for %d in wow64 mode\n",
					si->u.s.wProcessorArchitecture);
			}
		}
	}

	/*************************************************************************
	*		RtlCaptureStackBackTrace (NTDLL.@)
	*/
	USHORT(WINAPI* Real_RtlCaptureStackBackTrace)(ULONG skip, ULONG count, PVOID *buffer, ULONG *hash);
	USHORT WINAPI RtlCaptureStackBackTrace(ULONG skip, ULONG count, PVOID *buffer, ULONG *hash)
	{
		if (Real_RtlCaptureStackBackTrace == NULL)
		{
			Real_RtlCaptureStackBackTrace = (USHORT(__stdcall *)(ULONG, ULONG, PVOID *, ULONG *))GetProcAddress(GetModuleHandle(_T("Kernel32.dll")), "RtlCaptureStackBackTrace");
		}
		if (Real_RtlCaptureStackBackTrace)
		{
			return Real_RtlCaptureStackBackTrace(skip, count, buffer, hash);
		}

		FIXME("RtlCaptureStackBackTrace failed!\n");
		return 0;
	}

}


