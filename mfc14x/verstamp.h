#pragma once
// ==++==
//
//   
//    Copyright (c) 2006 Microsoft Corporation.  All rights reserved.
//   
//    The use and distribution terms for this software are contained in the file
//    named license.txt, which can be found in the root of this distribution.
//    By using this software in any fashion, you are agreeing to be bound by the
//    terms of this license.
//   
//    You must not remove this notice, or any other, from this software.
//   
//
// ==--==
#include "version.h"		//                    maintained version file

#if defined(_WIN32) || defined(WIN32)
#include <winver.h>
#elif PLATFORM_UNIX
// Don't do anything
#else	/* !WIN32 */
#include <ver.h>
#endif	/* !WIN32 */

#if 	(rmm < 10)
#define rmmpad "0"
#else
#define rmmpad
#endif

#if 	(rup == 0)

#define VERSION_STR1(a,b,c,d) 		#a "." rmmpad #b

#else	/* !(rup == 0) */

#define VERSION_STR1(a,b,c,d) 		#a "." rmmpad #b "." ruppad #c "." #d

#if 	(rup < 10)
#define ruppad "000"
#elif	(rup < 100)
#define ruppad "00"
#elif	(rup < 1000)
#define ruppad "0"
#else
#define ruppad
#endif

#endif	/* !(rup == 0) */

#define VERSION_STR2(a,b,c,d) 		VERSION_STR1(a,b,c,d)
#define VER_PRODUCTVERSION_STR		VERSION_STR2(rmj,rmm,rup,rev)
#define VER_PRODUCTVERSION			rmj,rmm,rup,rev

/*--------------------------------------------------------------*/
/* the following section defines values used in the version 	*/
/* data structure for all files, and which do not change.		*/
/*--------------------------------------------------------------*/
#define _SHIP

#if defined(_SHIP) && !defined(_DEBUG)
#define VER_DEBUG					0
#else
#define VER_DEBUG					VS_FF_DEBUG
#endif

#if defined(_SHIP)
#define VER_PRIVATEBUILD			0
#else
#define VER_PRIVATEBUILD			VS_FF_PRIVATEBUILD
#endif

#if defined(_SHIP)
#define VER_PRERELEASE				0
#else
#define VER_PRERELEASE				VS_FF_PRERELEASE
#endif

#define VER_FILEFLAGSMASK			VS_FFI_FILEFLAGSMASK
#if defined(_WIN32) || defined(WIN32)
#define VER_FILEOS					VOS__WINDOWS32
#else
#define VER_FILEOS					VOS_DOS_WINDOWS16
#endif
#define VER_FILEFLAGS				(VER_PRIVATEBUILD|VER_PRERELEASE|VER_DEBUG)

#define VER_COMPANYNAME_STR			"Microsoft Corporation"
#define VER_PRODUCTNAME_STR			"Microsoft® Visual Studio®"
