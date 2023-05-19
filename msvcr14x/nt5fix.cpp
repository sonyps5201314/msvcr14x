#include "stdafx.h"

#ifndef _WIN64
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
static int TIME_DayLightCompareDate(const SYSTEMTIME* date,
	const SYSTEMTIME* compareDate)
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
static DWORD TIME_CompTimeZoneID(const TIME_ZONE_INFORMATION* pTZinfo,
	FILETIME* lpFileTime, BOOL islocal)
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
static BOOL TIME_GetTimezoneBias(const TIME_ZONE_INFORMATION* pTZinfo,
	FILETIME* lpFileTime, BOOL islocal, LONG* pBias)
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
	const TIME_ZONE_INFORMATION* lpTimeZoneInformation,
	const SYSTEMTIME* lpLocalTime, LPSYSTEMTIME lpUniversalTime);
BOOL WINAPI TzSpecificLocalTimeToSystemTime(
	const TIME_ZONE_INFORMATION* lpTimeZoneInformation,
	const SYSTEMTIME* lpLocalTime, LPSYSTEMTIME lpUniversalTime)
{
	if (Real_TzSpecificLocalTimeToSystemTime == NULL)
	{
		Real_TzSpecificLocalTimeToSystemTime = (BOOL(__stdcall*)(const TIME_ZONE_INFORMATION*, const SYSTEMTIME*, LPSYSTEMTIME))GetProcAddress(GetModuleHandle(_T("Kernel32.dll")), "TzSpecificLocalTimeToSystemTime");
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
#endif