// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 MSVCR14X_EXPORT
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// MSVCR14X_API 函数视为自 DLL 导入，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef MSVCR14X_EXPORTS
#define MSVCR14X_API __declspec(dllexport)
#else
#define MSVCR14X_API __declspec(dllimport)
#endif

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_OBSOLETE_NO_WARNINGS

#include <suppress.h>
#define __WARNING_NOT_SATISFIED 28020
#define __WARNING_UNUSED_ASSIGNMENT 28931

#include <vcruntime.h>
#undef _VCRT_DEFINED_CRTIMP

