#ifdef _M_IX86
#ifdef _DEBUG
#pragma comment(linker, "/EXPORT:__CrtSetDbgBlockType")
#pragma comment(linker, "/EXPORT:__mbsdup_dbg=__strdup_dbg")
#endif//_DEBUG
#endif//_M_IX86

#ifdef _M_X64
#ifdef _DEBUG
#pragma comment(linker, "/EXPORT:_CrtSetDbgBlockType")
#pragma comment(linker, "/EXPORT:_mbsdup_dbg=_strdup_dbg")
#endif//_DEBUG
#endif//_M_X64