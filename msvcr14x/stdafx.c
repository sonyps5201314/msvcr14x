// stdafx.cpp : 只包括标准包含文件的源文件
// msvcr14x.pch 将作为预编译标头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用

WORD GetWindowsVersionEx(BOOL bRetrieveServicePackVersion)
{
	OSVERSIONINFOEX VersionInformation;
	//RTL_OSVERSIONINFOEXW和OSVERSIONINFOEXW其实是同一个结构
	NTSTATUS(NTAPI * _RtlGetVersion)(
		OUT  PRTL_OSVERSIONINFOW lpVersionInformation)
		= (NTSTATUS(__stdcall *)(PRTL_OSVERSIONINFOW))GetProcAddress(GetModuleHandle(_T("ntdll.dll")), "RtlGetVersion");
	if (_RtlGetVersion)
	{
		RTL_OSVERSIONINFOEXW VersionInformation;
		NTSTATUS ntRet;
		VersionInformation.dwOSVersionInfoSize = sizeof(VersionInformation);
		ntRet = _RtlGetVersion((PRTL_OSVERSIONINFOW)&VersionInformation);
		if (NT_SUCCESS(ntRet))
		{
			if (!bRetrieveServicePackVersion)
			{
				return MAKEWORD(VersionInformation.dwMinorVersion, VersionInformation.dwMajorVersion);
			}
			else
			{
				return MAKEWORD(VersionInformation.wServicePackMinor, VersionInformation.wServicePackMajor);
			}
		}
	}

	VersionInformation.dwOSVersionInfoSize = sizeof(VersionInformation);
#pragma warning( disable : 4996)
	GetVersionEx((LPOSVERSIONINFO)&VersionInformation);
#pragma warning( default: 4996)
	if (!bRetrieveServicePackVersion)
	{
		return MAKEWORD(VersionInformation.dwMinorVersion, VersionInformation.dwMajorVersion);
	}
	else
	{
		return MAKEWORD(VersionInformation.wServicePackMinor, VersionInformation.wServicePackMajor);
	}
}