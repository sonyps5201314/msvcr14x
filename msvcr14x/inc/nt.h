#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <suppress.h>

#include <ntstatus.h>

#define WIN32_NO_STATUS
#include <Windows.h>

#include <ntdll.h>
#define _NTDEF_

//NTSecAPI.h
typedef _Return_type_success_(return >= 0) LONG NTSTATUS, *PNTSTATUS;

