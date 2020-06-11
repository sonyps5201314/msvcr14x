#define _CRT_SECURE_NO_WARNINGS
#define _CRT_OBSOLETE_NO_WARNINGS
#define _EXCLUDE_MBSTRING_CONST_CORRECT_OVERLOADS
#define _CRT_NO_INLINE_DEPRECATED_WCSTOK

#include <corecrt_internal.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <wchar.h>
#include <time.h>
#include <conio.h>
#include <float.h>
#include <mbctype.h>
#include <vcruntime_exception.h>
#include <vcruntime_internal.h>
#include <vcruntime_typeinfo.h>
#include <corecrt_io.h>
#include <corecrt_internal_stdio.h>
#include <direct.h>
#include <sys/stat.h>
#include <sys/timeb.h>
#include <sys/utime.h>
#include <corecrt_internal_securecrt.h>
#include <uchar.h>
#include <signal.h>
#include <new.h>
#include <fpieee.h>

//bsearch.cpp
#ifdef _M_CEE
#define __fileDECL __clrcall
#else
#define __fileDECL __cdecl
#endif

//getproc.cpp
typedef int(__cdecl* proc_address_type)();

namespace __crt_state_management
{
	template <typename F, typename... Arguments>
	auto wrapped_invoke(F fp, Arguments... arguments)
	{
		__crt_state_management::enter_os_call();
		auto ret = fp(arguments...);
		__crt_state_management::leave_os_call();
		return ret;
	}

	template <typename F, typename... Arguments>
	void wrapped_invoke_void(F fp, Arguments... arguments)
	{
		__crt_state_management::enter_os_call();
		fp(arguments...);
		__crt_state_management::leave_os_call();
	}
}

extern "C"
{
	_CRTIMP void __cdecl _o_abort()
	{
		return __crt_state_management::wrapped_invoke_void(abort);
	}
	_CRTIMP int __cdecl _o__access(char const * const path, int const access_mode)
	{
		return __crt_state_management::wrapped_invoke(_access, path, access_mode);
	}
	_CRTIMP errno_t __cdecl _o__access_s(char const * const path, int const access_mode)
	{
		return __crt_state_management::wrapped_invoke(_access_s, path, access_mode);
	}
	_CRTIMP FILE * __cdecl _o___acrt_iob_func(unsigned const id)
	{
		return __crt_state_management::wrapped_invoke(__acrt_iob_func, id);
	}
	_CRTIMP void __cdecl _o__aligned_free(void * const block)
	{
		return __crt_state_management::wrapped_invoke_void(_aligned_free, block);
	}
	_CRTIMP void * __cdecl _o__aligned_malloc(size_t const size, size_t const alignment)
	{
		return __crt_state_management::wrapped_invoke(_aligned_malloc, size, alignment);
	}
	_CRTIMP size_t __cdecl _o__aligned_msize(void * const block, size_t const alignment, size_t const offset)
	{
		return __crt_state_management::wrapped_invoke(_aligned_msize, block, alignment, offset);
	}
	_CRTIMP void * __cdecl _o__aligned_offset_malloc(size_t const size, size_t const alignment, size_t const offset)
	{
		return __crt_state_management::wrapped_invoke(_aligned_offset_malloc, size, alignment, offset);
	}
	_CRTIMP void * __cdecl _o__aligned_offset_realloc(void * const block, size_t const size, size_t const alignment, size_t const offset)
	{
		return __crt_state_management::wrapped_invoke(_aligned_offset_realloc, block, size, alignment, offset);
	}
	_CRTIMP void * __cdecl _o__aligned_offset_recalloc(void * const block, size_t const count, size_t const size, size_t const alignment, size_t const offset)
	{
		return __crt_state_management::wrapped_invoke(_aligned_offset_recalloc, block, count, size, alignment, offset);
	}
	_CRTIMP void * __cdecl _o__aligned_realloc(void * const block, size_t const size, size_t const alignment)
	{
		return __crt_state_management::wrapped_invoke(_aligned_realloc, block, size, alignment);
	}
	_CRTIMP void * __cdecl _o__aligned_recalloc(void * const block, size_t const count, size_t const size, size_t const alignment)
	{
		return __crt_state_management::wrapped_invoke(_aligned_recalloc, block, count, size, alignment);
	}
	_CRTIMP char * __cdecl _o_asctime(tm const * const tm_value)
	{
		return __crt_state_management::wrapped_invoke(asctime, tm_value);
	}
	_CRTIMP errno_t __cdecl _o_asctime_s(char * const buffer, size_t const size_in_chars, tm const * const tm_value)
	{
		return __crt_state_management::wrapped_invoke(asctime_s, buffer, size_in_chars, tm_value);
	}
	_CRTIMP int __cdecl _o__atodbl(_CRT_DOUBLE * const result, char * const string)
	{
		return __crt_state_management::wrapped_invoke(_atodbl, result, string);
	}
	_CRTIMP int __cdecl _o__atodbl_l(_CRT_DOUBLE * const result, char * const string, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_atodbl_l, result, string, locale);
	}
	_CRTIMP double __cdecl _o_atof(char const * const string)
	{
		return __crt_state_management::wrapped_invoke(atof, string);
	}
	_CRTIMP double __cdecl _o__atof_l(char const * const string, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_atof_l, string, locale);
	}
	_CRTIMP int __cdecl _o__atoflt(_CRT_FLOAT * const result, char const * const string)
	{
		return __crt_state_management::wrapped_invoke(_atoflt, result, string);
	}
	_CRTIMP int __cdecl _o__atoflt_l(_CRT_FLOAT * const result, char const * const string, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_atoflt_l, result, string, locale);
	}
	_CRTIMP int __cdecl _o_atoi(char const * const string)
	{
		return __crt_state_management::wrapped_invoke(atoi, string);
	}
	_CRTIMP int __cdecl _o__atoi_l(char const * const string, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_atoi_l, string, locale);
	}
	_CRTIMP __int64 __cdecl _o__atoi64(char const * const string)
	{
		return __crt_state_management::wrapped_invoke(_atoi64, string);
	}
	_CRTIMP __int64 __cdecl _o__atoi64_l(char const * const string, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_atoi64_l, string, locale);
	}
	_CRTIMP long __cdecl _o_atol(char const * const string)
	{
		return __crt_state_management::wrapped_invoke(atol, string);
	}
	_CRTIMP long __cdecl _o__atol_l(char const * const string, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_atol_l, string, locale);
	}
	_CRTIMP int __cdecl _o__atoldbl(_LDOUBLE * const result, char * const string)
	{
		return __crt_state_management::wrapped_invoke(_atoldbl, result, string);
	}
	_CRTIMP int __cdecl _o__atoldbl_l(_LDOUBLE * const result, char * const string, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_atoldbl_l, result, string, locale);
	}
	_CRTIMP long long __cdecl _o_atoll(char const * const string)
	{
		return __crt_state_management::wrapped_invoke(atoll, string);
	}
	_CRTIMP long long __cdecl _o__atoll_l(char const * const string, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_atoll_l, string, locale);
	}
	_CRTIMP void __cdecl _o__beep(unsigned const frequency, unsigned const duration)
	{
		return __crt_state_management::wrapped_invoke_void(_beep, frequency, duration);
	}
	_CRTIMP uintptr_t __cdecl _o__beginthread(_beginthread_proc_type const procedure, unsigned int const stack_size, void * const context)
	{
		return __crt_state_management::wrapped_invoke(_beginthread, procedure, stack_size, context);
	}
	_CRTIMP uintptr_t __cdecl _o__beginthreadex(void * const security_descriptor, unsigned int const stack_size, _beginthreadex_proc_type const procedure, void * const context, unsigned int const creation_flags, unsigned int * const thread_id_result)
	{
		return __crt_state_management::wrapped_invoke(_beginthreadex, security_descriptor, stack_size, procedure, context, creation_flags, thread_id_result);
	}
	_CRTIMP void *__fileDECL _o_bsearch(void const * const key, void const * const base, size_t num, size_t const width, int(__fileDECL * const compare) (void const*, void const*))
	{
		return __crt_state_management::wrapped_invoke(bsearch, key, base, num, width, compare);
	}
	_CRTIMP void *__fileDECL _o_bsearch_s(void const * const key, void const * const base, size_t num, size_t const width, int(__fileDECL * const compare) (void*, void const*, void const*), void * const context)
	{
		return __crt_state_management::wrapped_invoke(bsearch_s, key, base, num, width, compare, context);
	}
	_CRTIMP wint_t __cdecl _o_btowc(int c)
	{
		return __crt_state_management::wrapped_invoke(btowc, c);
	}
	_CRTIMP int __cdecl _o__callnewh(size_t const size)
	{
		return __crt_state_management::wrapped_invoke(_callnewh, size);
	}
	_CRTIMP void * __cdecl _o_calloc(size_t const count, size_t const size)
	{
		return __crt_state_management::wrapped_invoke(calloc, count, size);
	}
	_CRTIMP void * __cdecl _o__calloc_base(size_t const count, size_t const size)
	{
		return __crt_state_management::wrapped_invoke(_calloc_base, count, size);
	}
	_CRTIMP void __cdecl _o__cexit()
	{
		return __crt_state_management::wrapped_invoke_void(_cexit);
	}
	_CRTIMP char * __cdecl _o__cgets(char * const string)
	{
		return __crt_state_management::wrapped_invoke(_cgets, string);
	}
	_CRTIMP errno_t __cdecl _o__cgets_s(char * const source_string, size_t const size_in_bytes, size_t * const size_read)
	{
		return __crt_state_management::wrapped_invoke(_cgets_s, source_string, size_in_bytes, size_read);
	}
	_CRTIMP wchar_t * __cdecl _o__cgetws(wchar_t * const string)
	{
		return __crt_state_management::wrapped_invoke(_cgetws, string);
	}
	_CRTIMP errno_t __cdecl _o__cgetws_s(wchar_t * const string_buffer, size_t const size_in_words, size_t * const size_read)
	{
		return __crt_state_management::wrapped_invoke(_cgetws_s, string_buffer, size_in_words, size_read);
	}
	_CRTIMP int __cdecl _o__chdir(char const * const path)
	{
		return __crt_state_management::wrapped_invoke(_chdir, path);
	}
	_CRTIMP int __cdecl _o__chdrive(int const drive_number)
	{
		return __crt_state_management::wrapped_invoke(_chdrive, drive_number);
	}
	_CRTIMP int __cdecl _o__chmod(char const * const path, int const mode)
	{
		return __crt_state_management::wrapped_invoke(_chmod, path, mode);
	}
	_CRTIMP int __cdecl _o__chsize(int const fh, long const size)
	{
		return __crt_state_management::wrapped_invoke(_chsize, fh, size);
	}
	_CRTIMP errno_t __cdecl _o__chsize_s(int const fh, __int64 const size)
	{
		return __crt_state_management::wrapped_invoke(_chsize_s, fh, size);
	}
	_CRTIMP void __cdecl _o_clearerr(FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke_void(clearerr, stream);
	}
	_CRTIMP errno_t __cdecl _o_clearerr_s(FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(clearerr_s, public_stream);
	}
	_CRTIMP int __cdecl _o__close(int const fh)
	{
		return __crt_state_management::wrapped_invoke(_close, fh);
	}
	_CRTIMP int __cdecl _o__commit(int const fh)
	{
		return __crt_state_management::wrapped_invoke(_commit, fh);
	}
	_CRTIMP int __cdecl _o__configthreadlocale(int i)
	{
		return __crt_state_management::wrapped_invoke(_configthreadlocale, i);
	}
	_CRTIMP errno_t __cdecl _o__configure_narrow_argv(_crt_argv_mode const mode)
	{
		return __crt_state_management::wrapped_invoke(_configure_narrow_argv, mode);
	}
	_CRTIMP errno_t __cdecl _o__configure_wide_argv(_crt_argv_mode const mode)
	{
		return __crt_state_management::wrapped_invoke(_configure_wide_argv, mode);
	}
	_CRTIMP int __cdecl _o___conio_common_vcprintf(unsigned __int64 const options, char const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__conio_common_vcprintf, options, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___conio_common_vcprintf_p(unsigned __int64 const options, char const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__conio_common_vcprintf_p, options, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___conio_common_vcprintf_s(unsigned __int64 const options, char const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__conio_common_vcprintf_s, options, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___conio_common_vcscanf(unsigned __int64 const options, char const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__conio_common_vcscanf, options, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___conio_common_vcwprintf(unsigned __int64 const options, wchar_t const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__conio_common_vcwprintf, options, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___conio_common_vcwprintf_p(unsigned __int64 const options, wchar_t const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__conio_common_vcwprintf_p, options, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___conio_common_vcwprintf_s(unsigned __int64 const options, wchar_t const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__conio_common_vcwprintf_s, options, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___conio_common_vcwscanf(unsigned __int64 const options, wchar_t const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__conio_common_vcwscanf, options, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o__cputs(char const * const string)
	{
		return __crt_state_management::wrapped_invoke(_cputs, string);
	}
	_CRTIMP int __cdecl _o__cputws(wchar_t const * string)
	{
		return __crt_state_management::wrapped_invoke(_cputws, string);
	}
	_CRTIMP int __cdecl _o__creat(char const * const path, int const pmode)
	{
		return __crt_state_management::wrapped_invoke(_creat, path, pmode);
	}
	_CRTIMP _locale_t __cdecl _o__create_locale(int _category, const char * _locale)
	{
		return __crt_state_management::wrapped_invoke(_create_locale, _category, _locale);
	}
	_CRTIMP int __cdecl _o__crt_atexit(_PVFV const function)
	{
		return __crt_state_management::wrapped_invoke(_crt_atexit, function);
	}
	_CRTIMP errno_t __cdecl _o__ctime32_s(char * const buffer, size_t const size_in_chars, __time32_t const * const time_t_value)
	{
		return __crt_state_management::wrapped_invoke(_ctime32_s, buffer, size_in_chars, time_t_value);
	}
	_CRTIMP errno_t __cdecl _o__ctime64_s(char * const buffer, size_t const size_in_chars, __time64_t const * const time_t_value)
	{
		return __crt_state_management::wrapped_invoke(_ctime64_s, buffer, size_in_chars, time_t_value);
	}
	_CRTIMP intptr_t __cdecl _o__cwait(int * const exit_code_result, intptr_t const process_id, int const action_code)
	{
		return __crt_state_management::wrapped_invoke(_cwait, exit_code_result, process_id, action_code);
	}
	_CRTIMP int * __cdecl _o___daylight()
	{
		return __crt_state_management::wrapped_invoke(__daylight);
	}
	_CRTIMP double __cdecl _o__difftime32(__time32_t const b, __time32_t const a)
	{
		return __crt_state_management::wrapped_invoke(_difftime32, b, a);
	}
	_CRTIMP double __cdecl _o__difftime64(__time64_t const b, __time64_t const a)
	{
		return __crt_state_management::wrapped_invoke(_difftime64, b, a);
	}
	_CRTIMP long * __cdecl _o___dstbias()
	{
		return __crt_state_management::wrapped_invoke(__dstbias);
	}
	_CRTIMP int __cdecl _o__dup(int const fh)
	{
		return __crt_state_management::wrapped_invoke(_dup, fh);
	}
	_CRTIMP int __cdecl _o__dup2(int const source_fh, int const target_fh)
	{
		return __crt_state_management::wrapped_invoke(_dup2, source_fh, target_fh);
	}
	_CRTIMP errno_t __cdecl _o__dupenv_s(char ** const buffer_pointer, size_t * const buffer_count, char const * const name)
	{
		return __crt_state_management::wrapped_invoke(_dupenv_s, buffer_pointer, buffer_count, name);
	}
	_CRTIMP char * __cdecl _o__ecvt(double const value, int const requested_digits, int * const decimal_point, int * const sign)
	{
		return __crt_state_management::wrapped_invoke(_ecvt, value, requested_digits, decimal_point, sign);
	}
	_CRTIMP errno_t __cdecl _o__ecvt_s(char * const buffer, size_t const buffer_count, double const value, int const requested_digits, int * const decimal_point, int * const sign)
	{
		return __crt_state_management::wrapped_invoke(_ecvt_s, buffer, buffer_count, value, requested_digits, decimal_point, sign);
	}
	_CRTIMP void __cdecl _o__endthread()
	{
		return __crt_state_management::wrapped_invoke_void(_endthread);
	}
	_CRTIMP void __cdecl _o__endthreadex(unsigned int const return_code)
	{
		return __crt_state_management::wrapped_invoke_void(_endthreadex, return_code);
	}
	_CRTIMP int __cdecl _o__eof(int const fh)
	{
		return __crt_state_management::wrapped_invoke(_eof, fh);
	}
	_CRTIMP int * __cdecl _o__errno()
	{
		return __crt_state_management::wrapped_invoke(_errno);
	}
	_CRTIMP int __cdecl _o__execute_onexit_table(_onexit_table_t * const table)
	{
		return __crt_state_management::wrapped_invoke(_execute_onexit_table, table);
	}
	_CRTIMP intptr_t __cdecl _o__execv(char const * const file_name, char const * const * const arguments)
	{
		return __crt_state_management::wrapped_invoke(_execv, file_name, arguments);
	}
	_CRTIMP intptr_t __cdecl _o__execve(char const * const file_name, char const * const * const arguments, char const * const * const environment)
	{
		return __crt_state_management::wrapped_invoke(_execve, file_name, arguments, environment);
	}
	_CRTIMP intptr_t __cdecl _o__execvp(char const * const file_name, char const * const * const arguments)
	{
		return __crt_state_management::wrapped_invoke(_execvp, file_name, arguments);
	}
	_CRTIMP intptr_t __cdecl _o__execvpe(char const * const file_name, char const * const * const arguments, char const * const * const environment)
	{
		return __crt_state_management::wrapped_invoke(_execvpe, file_name, arguments, environment);
	}
	_CRTIMP void __cdecl _o__exit(int const return_code)
	{
		return __crt_state_management::wrapped_invoke_void(_exit, return_code);
	}
	_CRTIMP void __cdecl _o_exit(int const return_code)
	{
		return __crt_state_management::wrapped_invoke_void(exit, return_code);
	}
	_CRTIMP void * __cdecl _o__expand(void * const block, size_t const size)
	{
		return __crt_state_management::wrapped_invoke(_expand, block, size);
	}
	_CRTIMP int __cdecl _o_fclose(FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(fclose, public_stream);
	}
	_CRTIMP int __cdecl _o__fclose_nolock(FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(_fclose_nolock, public_stream);
	}
	_CRTIMP int __cdecl _o__fcloseall()
	{
		return __crt_state_management::wrapped_invoke(_fcloseall);
	}
	_CRTIMP char * __cdecl _o__fcvt(double const value, int const requested_digits, int * const decimal_point, int * const sign)
	{
		return __crt_state_management::wrapped_invoke(_fcvt, value, requested_digits, decimal_point, sign);
	}
	_CRTIMP errno_t __cdecl _o__fcvt_s(char * const buffer, size_t const buffer_count, double const value, int const requested_digits, int * const decimal_point, int * const sign)
	{
		return __crt_state_management::wrapped_invoke(_fcvt_s, buffer, buffer_count, value, requested_digits, decimal_point, sign);
	}
	_CRTIMP FILE * __cdecl _o__fdopen(int const fh, char const * const mode)
	{
		return __crt_state_management::wrapped_invoke(_fdopen, fh, mode);
	}
	_CRTIMP int __cdecl _o_feof(FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(feof, public_stream);
	}
	_CRTIMP int __cdecl _o_ferror(FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(ferror, public_stream);
	}
	_CRTIMP int __cdecl _o_fflush(FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(fflush, public_stream);
	}
	_CRTIMP int __cdecl _o__fflush_nolock(FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(_fflush_nolock, public_stream);
	}
	_CRTIMP int __cdecl _o_fgetc(FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(fgetc, public_stream);
	}
	_CRTIMP int __cdecl _o__fgetc_nolock(FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(_fgetc_nolock, public_stream);
	}
	_CRTIMP int __cdecl _o__fgetchar()
	{
		return __crt_state_management::wrapped_invoke(_fgetchar);
	}
	_CRTIMP int __cdecl _o_fgetpos(FILE * const stream, fpos_t * const position)
	{
		return __crt_state_management::wrapped_invoke(fgetpos, stream, position);
	}
	_CRTIMP char * __cdecl _o_fgets(char * const string, int const count, FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(fgets, string, count, stream);
	}
	_CRTIMP wint_t __cdecl _o_fgetwc(FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(fgetwc, stream);
	}
	_CRTIMP wint_t __cdecl _o__fgetwc_nolock(FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(_fgetwc_nolock, public_stream);
	}
	_CRTIMP wint_t __cdecl _o__fgetwchar()
	{
		return __crt_state_management::wrapped_invoke(_fgetwchar);
	}
	_CRTIMP wchar_t * __cdecl _o_fgetws(wchar_t * const string, int const count, FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(fgetws, string, count, stream);
	}
	_CRTIMP long __cdecl _o__filelength(int const fh)
	{
		return __crt_state_management::wrapped_invoke(_filelength, fh);
	}
	_CRTIMP __int64 __cdecl _o__filelengthi64(int const fh)
	{
		return __crt_state_management::wrapped_invoke(_filelengthi64, fh);
	}
	_CRTIMP int __cdecl _o__fileno(FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(_fileno, public_stream);
	}
	_CRTIMP int __cdecl _o__findclose(intptr_t const handle)
	{
		return __crt_state_management::wrapped_invoke(_findclose, handle);
	}
	_CRTIMP intptr_t __cdecl _o__findfirst32(char const * const pattern, _finddata32_t * const result)
	{
		return __crt_state_management::wrapped_invoke(_findfirst32, pattern, result);
	}
	_CRTIMP intptr_t __cdecl _o__findfirst32i64(char const * const pattern, _finddata32i64_t * const result)
	{
		return __crt_state_management::wrapped_invoke(_findfirst32i64, pattern, result);
	}
	_CRTIMP intptr_t __cdecl _o__findfirst64(char const * const pattern, __finddata64_t * const result)
	{
		return __crt_state_management::wrapped_invoke(_findfirst64, pattern, result);
	}
	_CRTIMP intptr_t __cdecl _o__findfirst64i32(char const * const pattern, _finddata64i32_t * const result)
	{
		return __crt_state_management::wrapped_invoke(_findfirst64i32, pattern, result);
	}
	_CRTIMP int __cdecl _o__findnext32(intptr_t const handle, _finddata32_t * const result)
	{
		return __crt_state_management::wrapped_invoke(_findnext32, handle, result);
	}
	_CRTIMP int __cdecl _o__findnext32i64(intptr_t const handle, _finddata32i64_t * const result)
	{
		return __crt_state_management::wrapped_invoke(_findnext32i64, handle, result);
	}
	_CRTIMP int __cdecl _o__findnext64(intptr_t const handle, __finddata64_t * const result)
	{
		return __crt_state_management::wrapped_invoke(_findnext64, handle, result);
	}
	_CRTIMP int __cdecl _o__findnext64i32(intptr_t const handle, _finddata64i32_t * const result)
	{
		return __crt_state_management::wrapped_invoke(_findnext64i32, handle, result);
	}
	_CRTIMP int __cdecl _o__flushall()
	{
		return __crt_state_management::wrapped_invoke(_flushall);
	}
	_CRTIMP FILE * __cdecl _o_fopen(char const * const file, char const * const mode)
	{
		return __crt_state_management::wrapped_invoke(fopen, file, mode);
	}
	_CRTIMP errno_t __cdecl _o_fopen_s(FILE ** const result, char const * const file, char const * const mode)
	{
		return __crt_state_management::wrapped_invoke(fopen_s, result, file, mode);
	}
	_CRTIMP int __cdecl _o_fputc(int const c, FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(fputc, c, stream);
	}
	_CRTIMP int __cdecl _o__fputc_nolock(int const c, FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(_fputc_nolock, c, public_stream);
	}
	_CRTIMP int __cdecl _o__fputchar(int const c)
	{
		return __crt_state_management::wrapped_invoke(_fputchar, c);
	}
	_CRTIMP int __cdecl _o_fputs(char const * const string, FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(fputs, string, stream);
	}
	_CRTIMP wint_t __cdecl _o_fputwc(wchar_t const c, FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(fputwc, c, stream);
	}
	_CRTIMP wint_t __cdecl _o__fputwc_nolock(wchar_t const c, FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(_fputwc_nolock, c, public_stream);
	}
	_CRTIMP wint_t __cdecl _o__fputwchar(wchar_t const c)
	{
		return __crt_state_management::wrapped_invoke(_fputwchar, c);
	}
	_CRTIMP int __cdecl _o_fputws(wchar_t const * const string, FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(fputws, string, stream);
	}
	_CRTIMP size_t __cdecl _o_fread(void * const buffer, size_t const element_size, size_t const element_count, FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(fread, buffer, element_size, element_count, stream);
	}
	_CRTIMP size_t __cdecl _o__fread_nolock(void * const buffer, size_t const element_size, size_t const element_count, FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(_fread_nolock, buffer, element_size, element_count, stream);
	}
	_CRTIMP size_t __cdecl _o__fread_nolock_s(void * const buffer, size_t const buffer_size, size_t const element_size, size_t const element_count, FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(_fread_nolock_s, buffer, buffer_size, element_size, element_count, public_stream);
	}
	_CRTIMP size_t __cdecl _o_fread_s(void * const buffer, size_t const buffer_size, size_t const element_size, size_t const element_count, FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(fread_s, buffer, buffer_size, element_size, element_count, stream);
	}
	_CRTIMP void __cdecl _o_free(void * const block)
	{
		return __crt_state_management::wrapped_invoke_void(free, block);
	}
	_CRTIMP void __cdecl _o__free_base(void * const block)
	{
		return __crt_state_management::wrapped_invoke_void(_free_base, block);
	}
	_CRTIMP void __cdecl _o__free_locale(_locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke_void(_free_locale, plocinfo);
	}
	_CRTIMP FILE * __cdecl _o_freopen(char const * const file_name, char const * const mode, FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(freopen, file_name, mode, public_stream);
	}
	_CRTIMP errno_t __cdecl _o_freopen_s(FILE ** const result, char const * const file_name, char const * const mode, FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(freopen_s, result, file_name, mode, public_stream);
	}
	_CRTIMP int __cdecl _o_fseek(FILE * const public_stream, long const offset, int const whence)
	{
		return __crt_state_management::wrapped_invoke(fseek, public_stream, offset, whence);
	}
	_CRTIMP int __cdecl _o__fseek_nolock(FILE * const public_stream, long const offset, int const whence)
	{
		return __crt_state_management::wrapped_invoke(_fseek_nolock, public_stream, offset, whence);
	}
	_CRTIMP int __cdecl _o__fseeki64(FILE * const public_stream, __int64 const offset, int const whence)
	{
		return __crt_state_management::wrapped_invoke(_fseeki64, public_stream, offset, whence);
	}
	_CRTIMP int __cdecl _o__fseeki64_nolock(FILE * const public_stream, __int64 const offset, int const whence)
	{
		return __crt_state_management::wrapped_invoke(_fseeki64_nolock, public_stream, offset, whence);
	}
	_CRTIMP int __cdecl _o_fsetpos(FILE * const stream, fpos_t const * const position)
	{
		return __crt_state_management::wrapped_invoke(fsetpos, stream, position);
	}
	_CRTIMP FILE * __cdecl _o__fsopen(char const * const file, char const * const mode, int const share_flag)
	{
		return __crt_state_management::wrapped_invoke(_fsopen, file, mode, share_flag);
	}
	_CRTIMP int __cdecl _o__fstat32(int const fh, struct _stat32 * const result)
	{
		return __crt_state_management::wrapped_invoke(_fstat32, fh, result);
	}
	_CRTIMP int __cdecl _o__fstat32i64(int const fh, struct _stat32i64 * const result)
	{
		return __crt_state_management::wrapped_invoke(_fstat32i64, fh, result);
	}
	_CRTIMP int __cdecl _o__fstat64(int const fh, struct _stat64 * const result)
	{
		return __crt_state_management::wrapped_invoke(_fstat64, fh, result);
	}
	_CRTIMP int __cdecl _o__fstat64i32(int const fh, struct _stat64i32 * const result)
	{
		return __crt_state_management::wrapped_invoke(_fstat64i32, fh, result);
	}
	_CRTIMP long __cdecl _o_ftell(FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(ftell, public_stream);
	}
	_CRTIMP long __cdecl _o__ftell_nolock(FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(_ftell_nolock, public_stream);
	}
	_CRTIMP __int64 __cdecl _o__ftelli64(FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(_ftelli64, public_stream);
	}
	_CRTIMP __int64 __cdecl _o__ftelli64_nolock(FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(_ftelli64_nolock, public_stream);
	}
	_CRTIMP void __cdecl _o__ftime32(__timeb32 * const tp)
	{
		return __crt_state_management::wrapped_invoke_void(_ftime32, tp);
	}
	_CRTIMP errno_t __cdecl _o__ftime32_s(__timeb32 * const tp)
	{
		return __crt_state_management::wrapped_invoke(_ftime32_s, tp);
	}
	_CRTIMP void __cdecl _o__ftime64(__timeb64 * const tp)
	{
		return __crt_state_management::wrapped_invoke_void(_ftime64, tp);
	}
	_CRTIMP errno_t __cdecl _o__ftime64_s(__timeb64 * const tp)
	{
		return __crt_state_management::wrapped_invoke(_ftime64_s, tp);
	}
	_CRTIMP char * __cdecl _o__fullpath(char * const user_buffer, char const * const path, size_t const max_count)
	{
		return __crt_state_management::wrapped_invoke(_fullpath, user_buffer, path, max_count);
	}
	_CRTIMP int __cdecl _o__futime32(int const fh, __utimbuf32 * const times)
	{
		return __crt_state_management::wrapped_invoke(_futime32, fh, times);
	}
	_CRTIMP int __cdecl _o__futime64(int const fh, __utimbuf64 * const times)
	{
		return __crt_state_management::wrapped_invoke(_futime64, fh, times);
	}
	_CRTIMP size_t __cdecl _o_fwrite(void const * const buffer, size_t const size, size_t const count, FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(fwrite, buffer, size, count, stream);
	}
	_CRTIMP size_t __cdecl _o__fwrite_nolock(void const * const buffer, size_t const element_size, size_t const element_count, FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(_fwrite_nolock, buffer, element_size, element_count, public_stream);
	}
	_CRTIMP char * __cdecl _o__gcvt(double const value, int const precision, char * const buffer)
	{
		return __crt_state_management::wrapped_invoke(_gcvt, value, precision, buffer);
	}
	_CRTIMP errno_t __cdecl _o__gcvt_s(char * const buffer, size_t const buffer_count, double const value, int const precision)
	{
		return __crt_state_management::wrapped_invoke(_gcvt_s, buffer, buffer_count, value, precision);
	}
	_CRTIMP errno_t __cdecl _o__get_daylight(int * const result)
	{
		return __crt_state_management::wrapped_invoke(_get_daylight, result);
	}
	_CRTIMP errno_t _o__get_doserrno(unsigned long * const result)
	{
		return __crt_state_management::wrapped_invoke(_get_doserrno, result);
	}
	_CRTIMP errno_t __cdecl _o__get_dstbias(long * result)
	{
		return __crt_state_management::wrapped_invoke(_get_dstbias, result);
	}
	_CRTIMP errno_t _o__get_errno(int * const result)
	{
		return __crt_state_management::wrapped_invoke(_get_errno, result);
	}
	_CRTIMP errno_t __cdecl _o__get_fmode(int * const pMode)
	{
		return __crt_state_management::wrapped_invoke(_get_fmode, pMode);
	}
	_CRTIMP intptr_t __cdecl _o__get_heap_handle()
	{
		return __crt_state_management::wrapped_invoke(_get_heap_handle);
	}
	_CRTIMP char ** __cdecl _o__get_initial_narrow_environment()
	{
		return __crt_state_management::wrapped_invoke(_get_initial_narrow_environment);
	}
	_CRTIMP wchar_t ** __cdecl _o__get_initial_wide_environment()
	{
		return __crt_state_management::wrapped_invoke(_get_initial_wide_environment);
	}
	_CRTIMP _invalid_parameter_handler __cdecl _o__get_invalid_parameter_handler()
	{
		return __crt_state_management::wrapped_invoke(_get_invalid_parameter_handler);
	}
	_CRTIMP char * __cdecl _o__get_narrow_winmain_command_line()
	{
		return __crt_state_management::wrapped_invoke(_get_narrow_winmain_command_line);
	}
	_CRTIMP intptr_t __cdecl _o__get_osfhandle(int const fh)
	{
		return __crt_state_management::wrapped_invoke(_get_osfhandle, fh);
	}
	_CRTIMP errno_t __cdecl _o__get_pgmptr(char ** const result)
	{
		return __crt_state_management::wrapped_invoke(_get_pgmptr, result);
	}
	_CRTIMP errno_t __cdecl _o__get_stream_buffer_pointers(FILE * const public_stream, char *** const base, char *** const ptr, int ** const count)
	{
		return __crt_state_management::wrapped_invoke(_get_stream_buffer_pointers, public_stream, base, ptr, count);
	}
	_CRTIMP terminate_handler __cdecl _o__get_terminate()
	{
		return __crt_state_management::wrapped_invoke(_get_terminate);
	}
	_CRTIMP _invalid_parameter_handler __cdecl _o__get_thread_local_invalid_parameter_handler()
	{
		return __crt_state_management::wrapped_invoke(_get_thread_local_invalid_parameter_handler);
	}
	_CRTIMP errno_t __cdecl _o__get_timezone(long * result)
	{
		return __crt_state_management::wrapped_invoke(_get_timezone, result);
	}
	_CRTIMP errno_t __cdecl _o__get_tzname(size_t * const length, char * const buffer, size_t const size_in_bytes, int const index)
	{
		return __crt_state_management::wrapped_invoke(_get_tzname, length, buffer, size_in_bytes, index);
	}
	_CRTIMP wchar_t * __cdecl _o__get_wide_winmain_command_line()
	{
		return __crt_state_management::wrapped_invoke(_get_wide_winmain_command_line);
	}
	_CRTIMP errno_t __cdecl _o__get_wpgmptr(wchar_t ** const result)
	{
		return __crt_state_management::wrapped_invoke(_get_wpgmptr, result);
	}
	_CRTIMP int __cdecl _o_getc(FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(getc, stream);
	}
	_CRTIMP int __cdecl _o__getc_nolock(FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(_getc_nolock, stream);
	}
	_CRTIMP int __cdecl _o__getch()
	{
		return __crt_state_management::wrapped_invoke(_getch);
	}
	_CRTIMP int __cdecl _o__getch_nolock()
	{
		return __crt_state_management::wrapped_invoke(_getch_nolock);
	}
	_CRTIMP int __cdecl _o_getchar()
	{
		return __crt_state_management::wrapped_invoke(getchar);
	}
	_CRTIMP int __cdecl _o__getche()
	{
		return __crt_state_management::wrapped_invoke(_getche);
	}
	_CRTIMP int __cdecl _o__getche_nolock()
	{
		return __crt_state_management::wrapped_invoke(_getche_nolock);
	}
	_CRTIMP char * __cdecl _o__getcwd(char * const user_buffer, int const max_length)
	{
		return __crt_state_management::wrapped_invoke(_getcwd, user_buffer, max_length);
	}
	_CRTIMP char * __cdecl _o__Getdays()
	{
		return __crt_state_management::wrapped_invoke(_Getdays);
	}
	_CRTIMP char * __cdecl _o__getdcwd(int const drive_number, char * const user_buffer, int const max_length)
	{
		return __crt_state_management::wrapped_invoke(_getdcwd, drive_number, user_buffer, max_length);
	}
	_CRTIMP unsigned __cdecl _o__getdiskfree(unsigned const drive_number, _diskfree_t * const result)
	{
		return __crt_state_management::wrapped_invoke(_getdiskfree, drive_number, result);
	}
	_CRTIMP proc_address_type __cdecl _o__getdllprocaddr(intptr_t const module_handle_value, char * const procedure_name, intptr_t const ordinal)
	{
		return __crt_state_management::wrapped_invoke(_getdllprocaddr, module_handle_value, procedure_name, ordinal);
	}
	_CRTIMP int __cdecl _o__getdrive()
	{
		return __crt_state_management::wrapped_invoke(_getdrive);
	}
	_CRTIMP unsigned long __cdecl _o__getdrives()
	{
		return __crt_state_management::wrapped_invoke(_getdrives);
	}
	_CRTIMP char * __cdecl _o_getenv(char const * const name)
	{
		return __crt_state_management::wrapped_invoke(getenv, name);
	}
	_CRTIMP errno_t __cdecl _o_getenv_s(size_t * const required_count, char * const buffer, size_t const buffer_count, char const * const name)
	{
		return __crt_state_management::wrapped_invoke(getenv_s, required_count, buffer, buffer_count, name);
	}
	_CRTIMP int __cdecl _o__getmbcp()
	{
		return __crt_state_management::wrapped_invoke(_getmbcp);
	}
	_CRTIMP char * __cdecl _o__Getmonths()
	{
		return __crt_state_management::wrapped_invoke(_Getmonths);
	}
	_CRTIMP char * __cdecl _o_gets(char * const result)
	{
		return __crt_state_management::wrapped_invoke(gets, result);
	}
	_CRTIMP char * __cdecl _o_gets_s(char * const result, size_t const result_size_in_characters)
	{
		return __crt_state_management::wrapped_invoke(gets_s, result, result_size_in_characters);
	}
	_CRTIMP unsigned __cdecl _o__getsystime(tm * const result)
	{
		return __crt_state_management::wrapped_invoke(_getsystime, result);
	}
	_CRTIMP void * __cdecl _o__Gettnames()
	{
		return __crt_state_management::wrapped_invoke(_Gettnames);
	}
	_CRTIMP int __cdecl _o__getw(FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(_getw, stream);
	}
	_CRTIMP wint_t __cdecl _o_getwc(FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(getwc, stream);
	}
	_CRTIMP wint_t __cdecl _o__getwc_nolock(FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(_getwc_nolock, stream);
	}
	_CRTIMP wint_t __cdecl _o__getwch()
	{
		return __crt_state_management::wrapped_invoke(_getwch);
	}
	_CRTIMP wint_t __cdecl _o__getwch_nolock()
	{
		return __crt_state_management::wrapped_invoke(_getwch_nolock);
	}
	_CRTIMP wint_t __cdecl _o_getwchar()
	{
		return __crt_state_management::wrapped_invoke(getwchar);
	}
	_CRTIMP wint_t __cdecl _o__getwche()
	{
		return __crt_state_management::wrapped_invoke(_getwche);
	}
	_CRTIMP wint_t __cdecl _o__getwche_nolock()
	{
		return __crt_state_management::wrapped_invoke(_getwche_nolock);
	}
	_CRTIMP wchar_t * __cdecl _o__getws(wchar_t * const result)
	{
		return __crt_state_management::wrapped_invoke(_getws, result);
	}
	_CRTIMP wchar_t * __cdecl _o__getws_s(wchar_t * const result, size_t const result_size_in_characters)
	{
		return __crt_state_management::wrapped_invoke(_getws_s, result, result_size_in_characters);
	}
	_CRTIMP tm * __cdecl _o__gmtime32(__time32_t const * const time_value)
	{
		return __crt_state_management::wrapped_invoke(_gmtime32, time_value);
	}
	_CRTIMP errno_t __cdecl _o__gmtime32_s(tm * const result, __time32_t const * const time_value)
	{
		return __crt_state_management::wrapped_invoke(_gmtime32_s, result, time_value);
	}
	_CRTIMP tm * __cdecl _o__gmtime64(__time64_t const * const time_value)
	{
		return __crt_state_management::wrapped_invoke(_gmtime64, time_value);
	}
	_CRTIMP errno_t __cdecl _o__gmtime64_s(tm * const result, __time64_t const * const time_value)
	{
		return __crt_state_management::wrapped_invoke(_gmtime64_s, result, time_value);
	}
	_CRTIMP int __cdecl _o__heapchk()
	{
		return __crt_state_management::wrapped_invoke(_heapchk);
	}
	_CRTIMP int __cdecl _o__heapmin()
	{
		return __crt_state_management::wrapped_invoke(_heapmin);
	}
	_CRTIMP char * __cdecl _o__i64toa(__int64 const value, char * const buffer, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_i64toa, value, buffer, radix);
	}
	_CRTIMP errno_t __cdecl _o__i64toa_s(__int64 const value, char * const buffer, size_t const buffer_count, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_i64toa_s, value, buffer, buffer_count, radix);
	}
	_CRTIMP wchar_t * __cdecl _o__i64tow(__int64 const value, wchar_t * const buffer, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_i64tow, value, buffer, radix);
	}
	_CRTIMP errno_t __cdecl _o__i64tow_s(__int64 const value, wchar_t * const buffer, size_t const buffer_count, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_i64tow_s, value, buffer, buffer_count, radix);
	}
	_CRTIMP int __cdecl _o__initialize_narrow_environment()
	{
		return __crt_state_management::wrapped_invoke(_initialize_narrow_environment);
	}
	_CRTIMP int __cdecl _o__initialize_onexit_table(_onexit_table_t * const table)
	{
		return __crt_state_management::wrapped_invoke(_initialize_onexit_table, table);
	}
	_CRTIMP int __cdecl _o__initialize_wide_environment()
	{
		return __crt_state_management::wrapped_invoke(_initialize_wide_environment);
	}
	_CRTIMP void __cdecl _o__invalid_parameter_noinfo()
	{
		return __crt_state_management::wrapped_invoke_void(_invalid_parameter_noinfo);
	}
	_CRTIMP void __cdecl _o__invalid_parameter_noinfo_noreturn()
	{
		return __crt_state_management::wrapped_invoke_void(_invalid_parameter_noinfo_noreturn);
	}
	_CRTIMP int __cdecl _o_is_wctype(wint_t c, wctype_t mask)
	{
		return __crt_state_management::wrapped_invoke(is_wctype, c, mask);
	}
	_CRTIMP int __cdecl _o__isatty(int const fh)
	{
		return __crt_state_management::wrapped_invoke(_isatty, fh);
	}
	_CRTIMP int __cdecl _o__isctype(int const c, int const mask)
	{
		return __crt_state_management::wrapped_invoke(_isctype, c, mask);
	}
	_CRTIMP int __cdecl _o__isctype_l(int const c, int const mask, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_isctype_l, c, mask, locale);
	}
	_CRTIMP int __cdecl _o__ismbcalnum(unsigned int const c)
	{
		return __crt_state_management::wrapped_invoke(_ismbcalnum, c);
	}
	_CRTIMP int __cdecl _o__ismbcalnum_l(unsigned int const c, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbcalnum_l, c, locale);
	}
	_CRTIMP int __cdecl _o__ismbcalpha(unsigned int const c)
	{
		return __crt_state_management::wrapped_invoke(_ismbcalpha, c);
	}
	_CRTIMP int __cdecl _o__ismbcalpha_l(unsigned int const c, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbcalpha_l, c, locale);
	}
	_CRTIMP int __cdecl _o__ismbcblank(unsigned int const c)
	{
		return __crt_state_management::wrapped_invoke(_ismbcblank, c);
	}
	_CRTIMP int __cdecl _o__ismbcblank_l(unsigned int const c, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbcblank_l, c, locale);
	}
	_CRTIMP int __cdecl _o__ismbcdigit(unsigned int const c)
	{
		return __crt_state_management::wrapped_invoke(_ismbcdigit, c);
	}
	_CRTIMP int __cdecl _o__ismbcdigit_l(unsigned int const c, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbcdigit_l, c, locale);
	}
	_CRTIMP int __cdecl _o__ismbcgraph(unsigned int const c)
	{
		return __crt_state_management::wrapped_invoke(_ismbcgraph, c);
	}
	_CRTIMP int __cdecl _o__ismbcgraph_l(unsigned int const c, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbcgraph_l, c, locale);
	}
	_CRTIMP int __cdecl _o__ismbchira(unsigned int c)
	{
		return __crt_state_management::wrapped_invoke(_ismbchira, c);
	}
	_CRTIMP int __cdecl _o__ismbchira_l(unsigned int c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_ismbchira_l, c, plocinfo);
	}
	_CRTIMP int __cdecl _o__ismbckata(unsigned int c)
	{
		return __crt_state_management::wrapped_invoke(_ismbckata, c);
	}
	_CRTIMP int __cdecl _o__ismbckata_l(unsigned int c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_ismbckata_l, c, plocinfo);
	}
	_CRTIMP int __cdecl _o__ismbcl0_l(unsigned int c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_ismbcl0_l, c, plocinfo);
	}
	_CRTIMP int __cdecl _o__ismbcl1_l(unsigned int c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_ismbcl1_l, c, plocinfo);
	}
	_CRTIMP int __cdecl _o__ismbcl2(unsigned int c)
	{
		return __crt_state_management::wrapped_invoke(_ismbcl2, c);
	}
	_CRTIMP int __cdecl _o__ismbcl2_l(unsigned int c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_ismbcl2_l, c, plocinfo);
	}
	_CRTIMP int __cdecl _o__ismbclegal_l(unsigned int c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_ismbclegal_l, c, plocinfo);
	}
	_CRTIMP int __cdecl _o__ismbclower(unsigned int const c)
	{
		return __crt_state_management::wrapped_invoke(_ismbclower, c);
	}
	_CRTIMP int __cdecl _o__ismbclower_l(unsigned int const c, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbclower_l, c, locale);
	}
	_CRTIMP int __cdecl _o__ismbcprint(unsigned int const c)
	{
		return __crt_state_management::wrapped_invoke(_ismbcprint, c);
	}
	_CRTIMP int __cdecl _o__ismbcprint_l(unsigned int const c, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbcprint_l, c, locale);
	}
	_CRTIMP int __cdecl _o__ismbcpunct(unsigned int const c)
	{
		return __crt_state_management::wrapped_invoke(_ismbcpunct, c);
	}
	_CRTIMP int __cdecl _o__ismbcpunct_l(unsigned int const c, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbcpunct_l, c, locale);
	}
	_CRTIMP int __cdecl _o__ismbcspace(unsigned int const c)
	{
		return __crt_state_management::wrapped_invoke(_ismbcspace, c);
	}
	_CRTIMP int __cdecl _o__ismbcspace_l(unsigned int const c, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbcspace_l, c, locale);
	}
	_CRTIMP int __cdecl _o__ismbcsymbol_l(unsigned int c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_ismbcsymbol_l, c, plocinfo);
	}
	_CRTIMP int __cdecl _o__ismbcupper(unsigned int const c)
	{
		return __crt_state_management::wrapped_invoke(_ismbcupper, c);
	}
	_CRTIMP int __cdecl _o__ismbcupper_l(unsigned int const c, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbcupper_l, c, locale);
	}
	_CRTIMP int __cdecl _o__ismbslead_l(const unsigned char * string, const unsigned char * current, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_ismbslead_l, string, current, plocinfo);
	}
	_CRTIMP int __cdecl _o__ismbstrail(unsigned char const * const string, unsigned char const * const current)
	{
		return __crt_state_management::wrapped_invoke(_ismbstrail, string, current);
	}
	_CRTIMP int __cdecl _o__ismbstrail_l(unsigned char const * string, unsigned char const * current, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbstrail_l, string, current, locale);
	}
	_CRTIMP int __cdecl _o_iswctype(wint_t const c, wctype_t const mask)
	{
		return __crt_state_management::wrapped_invoke(iswctype, c, mask);
	}
	_CRTIMP int __cdecl _o__iswctype_l(wint_t const c, wctype_t const mask, _locale_t __iswctype_l)
	{
		return __crt_state_management::wrapped_invoke(_iswctype_l, c, mask, __iswctype_l);
	}
	_CRTIMP char * __cdecl _o__itoa(int const value, char * const buffer, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_itoa, value, buffer, radix);
	}
	_CRTIMP errno_t __cdecl _o__itoa_s(int const value, char * const buffer, size_t const buffer_count, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_itoa_s, value, buffer, buffer_count, radix);
	}
	_CRTIMP wchar_t * __cdecl _o__itow(int const value, wchar_t * const buffer, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_itow, value, buffer, radix);
	}
	_CRTIMP errno_t __cdecl _o__itow_s(int const value, wchar_t * const buffer, size_t const buffer_count, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_itow_s, value, buffer, buffer_count, radix);
	}
	_CRTIMP int __cdecl _o__kbhit()
	{
		return __crt_state_management::wrapped_invoke(_kbhit);
	}
	_CRTIMP unsigned int __cdecl _o____lc_codepage_func()
	{
		return __crt_state_management::wrapped_invoke(___lc_codepage_func);
	}
	_CRTIMP unsigned int __cdecl _o____lc_collate_cp_func()
	{
		return __crt_state_management::wrapped_invoke(___lc_collate_cp_func);
	}
	_CRTIMP wchar_t ** __cdecl _o____lc_locale_name_func()
	{
		return __crt_state_management::wrapped_invoke(___lc_locale_name_func);
	}
	_CRTIMP void *__fileDECL _o__lfind(void const * const key, void const * const base, unsigned int * const num, unsigned int const width, int(__fileDECL * const compare) (void const*, void const*))
	{
		return __crt_state_management::wrapped_invoke(_lfind, key, base, num, width, compare);
	}
	_CRTIMP void *__fileDECL _o__lfind_s(void const * const key, void const * const base, unsigned int * const num, size_t const width, int(__fileDECL * const compare) (void*, void const*, void const*), void * const context)
	{
		return __crt_state_management::wrapped_invoke(_lfind_s, key, base, num, width, compare, context);
	}
	_CRTIMP intptr_t __cdecl _o__loaddll(char * szName)
	{
		return __crt_state_management::wrapped_invoke(_loaddll, szName);
	}
	_CRTIMP lconv * __cdecl _o_localeconv()
	{
		return __crt_state_management::wrapped_invoke(localeconv);
	}
	_CRTIMP tm * __cdecl _o__localtime32(__time32_t const * const ptime)
	{
		return __crt_state_management::wrapped_invoke(_localtime32, ptime);
	}
	_CRTIMP errno_t __cdecl _o__localtime32_s(tm * const ptm, __time32_t const * const ptime)
	{
		return __crt_state_management::wrapped_invoke(_localtime32_s, ptm, ptime);
	}
	_CRTIMP tm * __cdecl _o__localtime64(__time64_t const * const ptime)
	{
		return __crt_state_management::wrapped_invoke(_localtime64, ptime);
	}
	_CRTIMP errno_t __cdecl _o__localtime64_s(tm * const ptm, __time64_t const * const ptime)
	{
		return __crt_state_management::wrapped_invoke(_localtime64_s, ptm, ptime);
	}
	_CRTIMP void __cdecl _o__lock_file(FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke_void(_lock_file, stream);
	}
	_CRTIMP int __cdecl _o__locking(int const fh, int const locking_mode, long const number_of_bytes)
	{
		return __crt_state_management::wrapped_invoke(_locking, fh, locking_mode, number_of_bytes);
	}
	_CRTIMP void *__fileDECL _o__lsearch(const void * const key, void * const base, unsigned int * const num, unsigned int const width, int(__fileDECL * compare) (void const*, void const*))
	{
		return __crt_state_management::wrapped_invoke(_lsearch, key, base, num, width, compare);
	}
	_CRTIMP void *__fileDECL _o__lsearch_s(void const * const key, void * const base, unsigned int * const num, size_t const width, int(__fileDECL * compare) (void*, void const*, void const*), void * const context)
	{
		return __crt_state_management::wrapped_invoke(_lsearch_s, key, base, num, width, compare, context);
	}
	_CRTIMP long __cdecl _o__lseek(int const fh, long const offset, int const origin)
	{
		return __crt_state_management::wrapped_invoke(_lseek, fh, offset, origin);
	}
	_CRTIMP __int64 __cdecl _o__lseeki64(int const fh, __int64 const offset, int const origin)
	{
		return __crt_state_management::wrapped_invoke(_lseeki64, fh, offset, origin);
	}
	_CRTIMP char * __cdecl _o__ltoa(long const value, char * const buffer, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_ltoa, value, buffer, radix);
	}
	_CRTIMP errno_t __cdecl _o__ltoa_s(long const value, char * const buffer, size_t const buffer_count, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_ltoa_s, value, buffer, buffer_count, radix);
	}
	_CRTIMP wchar_t * __cdecl _o__ltow(long const value, wchar_t * const buffer, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_ltow, value, buffer, radix);
	}
	_CRTIMP errno_t __cdecl _o__ltow_s(long const value, wchar_t * const buffer, size_t const buffer_count, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_ltow_s, value, buffer, buffer_count, radix);
	}
	_CRTIMP void __cdecl _o__makepath(char * const result_buffer, char const * const drive, char const * const directory, char const * const file_name, char const * const extension)
	{
		return __crt_state_management::wrapped_invoke_void(_makepath, result_buffer, drive, directory, file_name, extension);
	}
	_CRTIMP errno_t __cdecl _o__makepath_s(char * const result_buffer, size_t const result_count, char const * const drive, char const * const directory, char const * const file_name, char const * const extension)
	{
		return __crt_state_management::wrapped_invoke(_makepath_s, result_buffer, result_count, drive, directory, file_name, extension);
	}
	_CRTIMP void * __cdecl _o_malloc(size_t const size)
	{
		return __crt_state_management::wrapped_invoke(malloc, size);
	}
	_CRTIMP void * __cdecl _o__malloc_base(size_t const size)
	{
		return __crt_state_management::wrapped_invoke(_malloc_base, size);
	}
	_CRTIMP int __cdecl _o____mb_cur_max_func()
	{
		return __crt_state_management::wrapped_invoke(___mb_cur_max_func);
	}
	_CRTIMP unsigned int __cdecl _o__mbbtombc_l(unsigned int c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbbtombc_l, c, plocinfo);
	}
	_CRTIMP int __cdecl _o__mbbtype(unsigned char const c, int const ctype)
	{
		return __crt_state_management::wrapped_invoke(_mbbtype, c, ctype);
	}
	_CRTIMP int __cdecl _o__mbbtype_l(unsigned char const c, int const ctype, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_mbbtype_l, c, ctype, locale);
	}
	_CRTIMP void __cdecl _o__mbccpy_l(unsigned char * dst, const unsigned char * src, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke_void(_mbccpy_l, dst, src, plocinfo);
	}
	_CRTIMP errno_t __cdecl _o__mbccpy_s_l(unsigned char * _Dst, size_t _SizeInBytes, int * _PCopied, const unsigned char * _Src, _LOCALE_ARG_DECL)
	{
		return __crt_state_management::wrapped_invoke(_mbccpy_s_l, _Dst, _SizeInBytes, _PCopied, _Src, _LocInfo);
	}
	_CRTIMP unsigned int __cdecl _o__mbcjistojms_l(unsigned int c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbcjistojms_l, c, plocinfo);
	}
	_CRTIMP unsigned int __cdecl _o__mbcjmstojis_l(unsigned int c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbcjmstojis_l, c, plocinfo);
	}
	_CRTIMP size_t __cdecl _o__mbclen(unsigned char const * c)
	{
		return __crt_state_management::wrapped_invoke(_mbclen, c);
	}
	_CRTIMP size_t __cdecl _o__mbclen_l(unsigned char const * c, _locale_t locale)
	{
		return __crt_state_management::wrapped_invoke(_mbclen_l, c, locale);
	}
	_CRTIMP unsigned int __cdecl _o__mbctohira(unsigned int c)
	{
		return __crt_state_management::wrapped_invoke(_mbctohira, c);
	}
	_CRTIMP unsigned int __cdecl _o__mbctohira_l(unsigned int c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbctohira_l, c, plocinfo);
	}
	_CRTIMP unsigned int __cdecl _o__mbctokata_l(unsigned int c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbctokata_l, c, plocinfo);
	}
	_CRTIMP unsigned int __cdecl _o__mbctolower_l(unsigned int c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbctolower_l, c, plocinfo);
	}
	_CRTIMP unsigned int __cdecl _o__mbctombb_l(unsigned int c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbctombb_l, c, plocinfo);
	}
	_CRTIMP unsigned int __cdecl _o__mbctoupper_l(unsigned int c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbctoupper_l, c, plocinfo);
	}
	_CRTIMP int __cdecl _o_mblen(char const * const string, size_t const max_count)
	{
		return __crt_state_management::wrapped_invoke(mblen, string, max_count);
	}
	_CRTIMP int __cdecl _o__mblen_l(char const * const string, size_t const max_count, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_mblen_l, string, max_count, locale);
	}
	_CRTIMP size_t __cdecl _o_mbrlen(const char * s, size_t n, mbstate_t * pst)
	{
		return __crt_state_management::wrapped_invoke(mbrlen, s, n, pst);
	}
	_CRTIMP size_t __cdecl _o_mbrtoc16(char16_t * pc16, const char * s, size_t n, mbstate_t * ps)
	{
		return __crt_state_management::wrapped_invoke(mbrtoc16, pc16, s, n, ps);
	}
	_CRTIMP size_t __cdecl _o_mbrtoc32(char32_t * pc32, const char * s, size_t n, mbstate_t * ps)
	{
		return __crt_state_management::wrapped_invoke(mbrtoc32, pc32, s, n, ps);
	}
	_CRTIMP size_t __cdecl _o_mbrtowc(wchar_t * dst, const char * s, size_t n, mbstate_t * pst)
	{
		return __crt_state_management::wrapped_invoke(mbrtowc, dst, s, n, pst);
	}
	_CRTIMP int __cdecl _o__mbsbtype(unsigned char const * const string, size_t const length)
	{
		return __crt_state_management::wrapped_invoke(_mbsbtype, string, length);
	}
	_CRTIMP int __cdecl _o__mbsbtype_l(unsigned char const * string, size_t length, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_mbsbtype_l, string, length, locale);
	}
	_CRTIMP errno_t __cdecl _o__mbscat_s_l(unsigned char * _Dst, size_t _SizeInBytes, const unsigned char * _Src, _LOCALE_ARG_DECL)
	{
		return __crt_state_management::wrapped_invoke(_mbscat_s_l, _Dst, _SizeInBytes, _Src, _LocInfo);
	}
	_CRTIMP const unsigned char * __cdecl _o__mbschr_l(const unsigned char * string, unsigned int c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbschr_l, string, c, plocinfo);
	}
	_CRTIMP int __cdecl _o__mbscmp_l(const unsigned char * s1, const unsigned char * s2, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbscmp_l, s1, s2, plocinfo);
	}
	_CRTIMP int __cdecl _o__mbscoll_l(const unsigned char * s1, const unsigned char * s2, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbscoll_l, s1, s2, plocinfo);
	}
	_CRTIMP errno_t __cdecl _o__mbscpy_s_l(unsigned char * _Dst, size_t _SizeInBytes, const unsigned char * _Src, _LOCALE_ARG_DECL)
	{
		return __crt_state_management::wrapped_invoke(_mbscpy_s_l, _Dst, _SizeInBytes, _Src, _LocInfo);
	}
	_CRTIMP size_t __cdecl _o__mbscspn_l(const unsigned char * string, const unsigned char * charset, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbscspn_l, string, charset, plocinfo);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsdec_l(const unsigned char * string, const unsigned char * current, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsdec_l, string, current, plocinfo);
	}
	_CRTIMP int __cdecl _o__mbsicmp_l(const unsigned char * s1, const unsigned char * s2, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsicmp_l, s1, s2, plocinfo);
	}
	_CRTIMP int __cdecl _o__mbsicoll_l(const unsigned char * s1, const unsigned char * s2, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsicoll_l, s1, s2, plocinfo);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsinc_l(const unsigned char * current, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsinc_l, current, plocinfo);
	}
	_CRTIMP size_t __cdecl _o__mbslen_l(const unsigned char * s, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbslen_l, s, plocinfo);
	}
	_CRTIMP errno_t __cdecl _o__mbslwr_s_l(unsigned char * string, size_t sizeInBytes, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbslwr_s_l, string, sizeInBytes, plocinfo);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsnbcat_l(unsigned char * dst, const unsigned char * src, size_t cnt, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbcat_l, dst, src, cnt, plocinfo);
	}
	_CRTIMP int __cdecl _o__mbsnbcmp_l(const unsigned char * s1, const unsigned char * s2, size_t n, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbcmp_l, s1, s2, n, plocinfo);
	}
	_CRTIMP size_t __cdecl _o__mbsnbcnt_l(const unsigned char * string, size_t ccnt, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbcnt_l, string, ccnt, plocinfo);
	}
	_CRTIMP int __cdecl _o__mbsnbcoll_l(const unsigned char * s1, const unsigned char * s2, size_t n, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbcoll_l, s1, s2, n, plocinfo);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsnbcpy_l(unsigned char * dst, const unsigned char * src, size_t cnt, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbcpy_l, dst, src, cnt, plocinfo);
	}
	_CRTIMP int __cdecl _o__mbsnbicmp_l(const unsigned char * s1, const unsigned char * s2, size_t n, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbicmp_l, s1, s2, n, plocinfo);
	}
	_CRTIMP int __cdecl _o__mbsnbicoll(const unsigned char * s1, const unsigned char * s2, size_t n)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbicoll, s1, s2, n);
	}
	_CRTIMP int __cdecl _o__mbsnbicoll_l(const unsigned char * s1, const unsigned char * s2, size_t n, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbicoll_l, s1, s2, n, plocinfo);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsnbset_l(unsigned char * string, unsigned int val, size_t count, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbset_l, string, val, count, plocinfo);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsncat_l(unsigned char * dst, const unsigned char * src, size_t cnt, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsncat_l, dst, src, cnt, plocinfo);
	}
	_CRTIMP size_t __cdecl _o__mbsnccnt_l(const unsigned char * string, size_t bcnt, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsnccnt_l, string, bcnt, plocinfo);
	}
	_CRTIMP int __cdecl _o__mbsncmp_l(const unsigned char * s1, const unsigned char * s2, size_t n, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsncmp_l, s1, s2, n, plocinfo);
	}
	_CRTIMP int __cdecl _o__mbsncoll_l(const unsigned char * s1, const unsigned char * s2, size_t n, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsncoll_l, s1, s2, n, plocinfo);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsncpy_l(unsigned char * dst, const unsigned char * src, size_t cnt, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsncpy_l, dst, src, cnt, plocinfo);
	}
	_CRTIMP unsigned int __cdecl _o__mbsnextc_l(const unsigned char * s, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsnextc_l, s, plocinfo);
	}
	_CRTIMP int __cdecl _o__mbsnicmp_l(const unsigned char * s1, const unsigned char * s2, size_t n, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsnicmp_l, s1, s2, n, plocinfo);
	}
	_CRTIMP int __cdecl _o__mbsnicoll_l(const unsigned char * s1, const unsigned char * s2, size_t n, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsnicoll_l, s1, s2, n, plocinfo);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsninc_l(const unsigned char * string, size_t ccnt, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsninc_l, string, ccnt, plocinfo);
	}
	_CRTIMP size_t __cdecl _o__mbsnlen(const unsigned char * s, size_t maxsize)
	{
		return __crt_state_management::wrapped_invoke(_mbsnlen, s, maxsize);
	}
	_CRTIMP size_t __cdecl _o__mbsnlen_l(const unsigned char * s, size_t sizeInBytes, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsnlen_l, s, sizeInBytes, plocinfo);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsnset_l(unsigned char * string, unsigned int val, size_t count, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsnset_l, string, val, count, plocinfo);
	}
	_CRTIMP const unsigned char * __cdecl _o__mbspbrk_l(const unsigned char * string, const unsigned char * charset, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbspbrk_l, string, charset, plocinfo);
	}
	_CRTIMP const unsigned char * __cdecl _o__mbsrchr_l(const unsigned char * str, unsigned int c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsrchr_l, str, c, plocinfo);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsrev_l(unsigned char * string, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsrev_l, string, plocinfo);
	}
	_CRTIMP size_t __cdecl _o_mbsrtowcs(wchar_t * wcs, const char ** ps, size_t n, mbstate_t * pst)
	{
		return __crt_state_management::wrapped_invoke(mbsrtowcs, wcs, ps, n, pst);
	}
	_CRTIMP errno_t __cdecl _o_mbsrtowcs_s(size_t * pRetValue, wchar_t * dst, size_t sizeInWords, const char ** ps, size_t n, mbstate_t * pmbst)
	{
		return __crt_state_management::wrapped_invoke(mbsrtowcs_s, pRetValue, dst, sizeInWords, ps, n, pmbst);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsset_l(unsigned char * string, unsigned int val, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsset_l, string, val, plocinfo);
	}
	_CRTIMP errno_t __cdecl _o__mbsset_s_l(unsigned char * _Dst, size_t _SizeInBytes, unsigned int _Value, _LOCALE_ARG_DECL)
	{
		return __crt_state_management::wrapped_invoke(_mbsset_s_l, _Dst, _SizeInBytes, _Value, _LocInfo);
	}
	_CRTIMP size_t __cdecl _o__mbsspn_l(const unsigned char * string, const unsigned char * charset, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsspn_l, string, charset, plocinfo);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsspnp_l(const unsigned char * string, const unsigned char * charset, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsspnp_l, string, charset, plocinfo);
	}
	_CRTIMP const unsigned char * __cdecl _o__mbsstr_l(const unsigned char * str1, const unsigned char * str2, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsstr_l, str1, str2, plocinfo);
	}
	_CRTIMP unsigned char * __cdecl _o__mbstok(unsigned char * string, const unsigned char * sepset)
	{
		return __crt_state_management::wrapped_invoke(_mbstok, string, sepset);
	}
	_CRTIMP unsigned char * __cdecl _o__mbstok_l(unsigned char * const string, unsigned char const * const sepset, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_mbstok_l, string, sepset, locale);
	}
	_CRTIMP unsigned char * __cdecl _o__mbstok_s_l(unsigned char * _String, const unsigned char * _Control, unsigned char ** _Context, _LOCALE_ARG_DECL)
	{
		return __crt_state_management::wrapped_invoke(_mbstok_s_l, _String, _Control, _Context, _LocInfo);
	}
	_CRTIMP size_t __cdecl _o_mbstowcs(wchar_t * pwcs, const char * s, size_t n)
	{
		return __crt_state_management::wrapped_invoke(mbstowcs, pwcs, s, n);
	}
	_CRTIMP size_t __cdecl _o__mbstowcs_l(wchar_t * pwcs, const char * s, size_t n, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbstowcs_l, pwcs, s, n, plocinfo);
	}
	_CRTIMP errno_t __cdecl _o_mbstowcs_s(size_t * pConvertedChars, wchar_t * pwcs, size_t sizeInWords, const char * s, size_t n)
	{
		return __crt_state_management::wrapped_invoke(mbstowcs_s, pConvertedChars, pwcs, sizeInWords, s, n);
	}
	_CRTIMP errno_t __cdecl _o__mbstowcs_s_l(size_t * pConvertedChars, wchar_t * pwcs, size_t sizeInWords, const char * s, size_t n, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbstowcs_s_l, pConvertedChars, pwcs, sizeInWords, s, n, plocinfo);
	}
	_CRTIMP size_t __cdecl _o__mbstrlen(char const * const string)
	{
		return __crt_state_management::wrapped_invoke(_mbstrlen, string);
	}
	_CRTIMP size_t __cdecl _o__mbstrlen_l(char const * const string, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_mbstrlen_l, string, locale);
	}
	_CRTIMP size_t __cdecl _o__mbstrnlen(char const * const string, size_t const max_size)
	{
		return __crt_state_management::wrapped_invoke(_mbstrnlen, string, max_size);
	}
	_CRTIMP size_t __cdecl _o__mbstrnlen_l(char const * const string, size_t const max_size, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_mbstrnlen_l, string, max_size, locale);
	}
	_CRTIMP errno_t __cdecl _o__mbsupr_s_l(unsigned char * string, size_t sizeInBytes, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbsupr_s_l, string, sizeInBytes, plocinfo);
	}
	_CRTIMP int __cdecl _o_mbtowc(wchar_t * pwc, const char * s, size_t n)
	{
		return __crt_state_management::wrapped_invoke(mbtowc, pwc, s, n);
	}
	_CRTIMP int __cdecl _o__mbtowc_l(wchar_t * pwc, const char * s, size_t n, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_mbtowc_l, pwc, s, n, plocinfo);
	}
	_CRTIMP int __cdecl _o__memicmp(void const * const lhs, void const * const rhs, size_t const count)
	{
		return __crt_state_management::wrapped_invoke(_memicmp, lhs, rhs, count);
	}
	_CRTIMP int __cdecl _o__memicmp_l(void const * const lhs, void const * const rhs, size_t const count, _locale_t const plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_memicmp_l, lhs, rhs, count, plocinfo);
	}
	_CRTIMP int __cdecl _o__mkdir(char const * const path)
	{
		return __crt_state_management::wrapped_invoke(_mkdir, path);
	}
	_CRTIMP __time32_t __cdecl _o__mkgmtime32(tm * const tb)
	{
		return __crt_state_management::wrapped_invoke(_mkgmtime32, tb);
	}
	_CRTIMP __time64_t __cdecl _o__mkgmtime64(tm * const tb)
	{
		return __crt_state_management::wrapped_invoke(_mkgmtime64, tb);
	}
	_CRTIMP char * __cdecl _o__mktemp(char * const template_string)
	{
		return __crt_state_management::wrapped_invoke(_mktemp, template_string);
	}
	_CRTIMP errno_t __cdecl _o__mktemp_s(char * const template_string, size_t const buffer_size_in_chars)
	{
		return __crt_state_management::wrapped_invoke(_mktemp_s, template_string, buffer_size_in_chars);
	}
	_CRTIMP __time32_t __cdecl _o__mktime32(tm * const tb)
	{
		return __crt_state_management::wrapped_invoke(_mktime32, tb);
	}
	_CRTIMP __time64_t __cdecl _o__mktime64(tm * const tb)
	{
		return __crt_state_management::wrapped_invoke(_mktime64, tb);
	}
	_CRTIMP size_t __cdecl _o__msize(void * const block)
	{
		return __crt_state_management::wrapped_invoke(_msize, block);
	}
	_CRTIMP int __cdecl _o__open_osfhandle(intptr_t const osfhandle, int const source_flags)
	{
		return __crt_state_management::wrapped_invoke(_open_osfhandle, osfhandle, source_flags);
	}
	_CRTIMP int * __cdecl _o___p___argc()
	{
		return __crt_state_management::wrapped_invoke(__p___argc);
	}
	_CRTIMP char *** __cdecl _o___p___argv()
	{
		return __crt_state_management::wrapped_invoke(__p___argv);
	}
	_CRTIMP wchar_t *** __cdecl _o___p___wargv()
	{
		return __crt_state_management::wrapped_invoke(__p___wargv);
	}
	_CRTIMP char ** __cdecl _o___p__acmdln()
	{
		return __crt_state_management::wrapped_invoke(__p__acmdln);
	}
	_CRTIMP int * __cdecl _o___p__commode()
	{
		return __crt_state_management::wrapped_invoke(__p__commode);
	}
	_CRTIMP char *** __cdecl _o___p__environ()
	{
		return __crt_state_management::wrapped_invoke(__p__environ);
	}
	_CRTIMP int * __cdecl _o___p__fmode()
	{
		return __crt_state_management::wrapped_invoke(__p__fmode);
	}
	_CRTIMP unsigned char * __cdecl _o___p__mbcasemap()
	{
		return __crt_state_management::wrapped_invoke(__p__mbcasemap);
	}
	_CRTIMP unsigned char * __cdecl _o___p__mbctype()
	{
		return __crt_state_management::wrapped_invoke(__p__mbctype);
	}
	_CRTIMP char ** __cdecl _o___p__pgmptr()
	{
		return __crt_state_management::wrapped_invoke(__p__pgmptr);
	}
	_CRTIMP wchar_t ** __cdecl _o___p__wcmdln()
	{
		return __crt_state_management::wrapped_invoke(__p__wcmdln);
	}
	_CRTIMP wchar_t *** __cdecl _o___p__wenviron()
	{
		return __crt_state_management::wrapped_invoke(__p__wenviron);
	}
	_CRTIMP wchar_t ** __cdecl _o___p__wpgmptr()
	{
		return __crt_state_management::wrapped_invoke(__p__wpgmptr);
	}
	_CRTIMP int __cdecl _o__pclose(FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(_pclose, stream);
	}
	_CRTIMP unsigned short const * __cdecl _o___pctype_func()
	{
		return __crt_state_management::wrapped_invoke(__pctype_func);
	}
	_CRTIMP int __cdecl _o__pipe(int * const phandles, unsigned const psize, int const textmode)
	{
		return __crt_state_management::wrapped_invoke(_pipe, phandles, psize, textmode);
	}
	_CRTIMP FILE * __cdecl _o__popen(char const * const command, char const * const type)
	{
		return __crt_state_management::wrapped_invoke(_popen, command, type);
	}
	_CRTIMP int __cdecl _o_putc(int const c, FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(putc, c, stream);
	}
	_CRTIMP int __cdecl _o__putc_nolock(int const c, FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(_putc_nolock, c, stream);
	}
	_CRTIMP int __cdecl _o__putch(int const c)
	{
		return __crt_state_management::wrapped_invoke(_putch, c);
	}
	_CRTIMP int __cdecl _o__putch_nolock(int const c)
	{
		return __crt_state_management::wrapped_invoke(_putch_nolock, c);
	}
	_CRTIMP int __cdecl _o_putchar(int const c)
	{
		return __crt_state_management::wrapped_invoke(putchar, c);
	}
	_CRTIMP int __cdecl _o__putenv(char const * const option)
	{
		return __crt_state_management::wrapped_invoke(_putenv, option);
	}
	_CRTIMP errno_t __cdecl _o__putenv_s(char const * const name, char const * const value)
	{
		return __crt_state_management::wrapped_invoke(_putenv_s, name, value);
	}
	_CRTIMP int __cdecl _o_puts(char const * const string)
	{
		return __crt_state_management::wrapped_invoke(puts, string);
	}
	_CRTIMP int __cdecl _o__putw(int const value, FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(_putw, value, stream);
	}
	_CRTIMP wint_t __cdecl _o_putwc(wchar_t const c, FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(putwc, c, stream);
	}
	_CRTIMP wint_t __cdecl _o__putwc_nolock(wchar_t const c, FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(_putwc_nolock, c, stream);
	}
	_CRTIMP wint_t __cdecl _o__putwch(wchar_t const c)
	{
		return __crt_state_management::wrapped_invoke(_putwch, c);
	}
	_CRTIMP wint_t __cdecl _o__putwch_nolock(wchar_t const c)
	{
		return __crt_state_management::wrapped_invoke(_putwch_nolock, c);
	}
	_CRTIMP wint_t __cdecl _o_putwchar(wchar_t const c)
	{
		return __crt_state_management::wrapped_invoke(putwchar, c);
	}
	_CRTIMP int __cdecl _o__putws(wchar_t const * const string)
	{
		return __crt_state_management::wrapped_invoke(_putws, string);
	}
	_CRTIMP unsigned short const * __cdecl _o___pwctype_func()
	{
		return __crt_state_management::wrapped_invoke(__pwctype_func);
	}
	_CRTIMP int __cdecl _o_raise(int const signum)
	{
		return __crt_state_management::wrapped_invoke(raise, signum);
	}
	_CRTIMP int __cdecl _o_rand()
	{
		return __crt_state_management::wrapped_invoke(rand);
	}
	_CRTIMP errno_t __cdecl _o_rand_s(unsigned int * const result)
	{
		return __crt_state_management::wrapped_invoke(rand_s, result);
	}
	_CRTIMP int __cdecl _o__read(int const fh, void * const buffer, unsigned const buffer_size)
	{
		return __crt_state_management::wrapped_invoke(_read, fh, buffer, buffer_size);
	}
	_CRTIMP void * __cdecl _o_realloc(void * const block, size_t const size)
	{
		return __crt_state_management::wrapped_invoke(realloc, block, size);
	}
	_CRTIMP void * __cdecl _o__realloc_base(void * const block, size_t const size)
	{
		return __crt_state_management::wrapped_invoke(_realloc_base, block, size);
	}
	_CRTIMP void * __cdecl _o__recalloc(void * const block, size_t const count, size_t const size)
	{
		return __crt_state_management::wrapped_invoke(_recalloc, block, count, size);
	}
	_CRTIMP int __cdecl _o__register_onexit_function(_onexit_table_t * const table, _onexit_t const function)
	{
		return __crt_state_management::wrapped_invoke(_register_onexit_function, table, function);
	}
	_CRTIMP int __cdecl _o_remove(char const * const path)
	{
		return __crt_state_management::wrapped_invoke(remove, path);
	}
	_CRTIMP int __cdecl _o_rename(char const * const old_name, char const * const new_name)
	{
		return __crt_state_management::wrapped_invoke(rename, old_name, new_name);
	}
	_CRTIMP int __cdecl _o__resetstkoflw()
	{
		return __crt_state_management::wrapped_invoke(_resetstkoflw);
	}
	_CRTIMP void __cdecl _o_rewind(FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke_void(rewind, public_stream);
	}
	_CRTIMP int __cdecl _o__rmdir(char const * const path)
	{
		return __crt_state_management::wrapped_invoke(_rmdir, path);
	}
	_CRTIMP int __cdecl _o__rmtmp()
	{
		return __crt_state_management::wrapped_invoke(_rmtmp);
	}
	_CRTIMP void __cdecl _o__searchenv(char const * const file_name, char const * const environment_variable, char * const result_buffer)
	{
		return __crt_state_management::wrapped_invoke_void(_searchenv, file_name, environment_variable, result_buffer);
	}
	_CRTIMP errno_t __cdecl _o__searchenv_s(char const * const file_name, char const * const environment_variable, char * const result_buffer, size_t const result_count)
	{
		return __crt_state_management::wrapped_invoke(_searchenv_s, file_name, environment_variable, result_buffer, result_count);
	}
	_CRTIMP int __cdecl _o__seh_filter_dll(unsigned long const xcptnum, PEXCEPTION_POINTERS const pxcptinfoptrs)
	{
		return __crt_state_management::wrapped_invoke(_seh_filter_dll, xcptnum, pxcptinfoptrs);
	}
	_CRTIMP int __cdecl _o__seh_filter_exe(unsigned long const xcptnum, PEXCEPTION_POINTERS const pxcptinfoptrs)
	{
		return __crt_state_management::wrapped_invoke(_seh_filter_exe, xcptnum, pxcptinfoptrs);
	}
	_CRTIMP unsigned int __cdecl _o__set_abort_behavior(unsigned int flags, unsigned int mask)
	{
		return __crt_state_management::wrapped_invoke(_set_abort_behavior, flags, mask);
	}
	_CRTIMP void __cdecl _o__set_app_type(_crt_app_type const new_app_type)
	{
		return __crt_state_management::wrapped_invoke_void(_set_app_type, new_app_type);
	}
	_CRTIMP errno_t _o__set_doserrno(unsigned long const value)
	{
		return __crt_state_management::wrapped_invoke(_set_doserrno, value);
	}
	_CRTIMP errno_t _o__set_errno(int const value)
	{
		return __crt_state_management::wrapped_invoke(_set_errno, value);
	}
	_CRTIMP errno_t __cdecl _o__set_fmode(int const mode)
	{
		return __crt_state_management::wrapped_invoke(_set_fmode, mode);
	}
	_CRTIMP _invalid_parameter_handler __cdecl _o__set_invalid_parameter_handler(_invalid_parameter_handler const new_handler)
	{
		return __crt_state_management::wrapped_invoke(_set_invalid_parameter_handler, new_handler);
	}
	_CRTIMP _PNH __cdecl _o__set_new_handler(_PNH new_handler)
	{
		return __crt_state_management::wrapped_invoke(_set_new_handler, new_handler);
	}
	_CRTIMP int __cdecl _o__set_new_mode(int const mode)
	{
		return __crt_state_management::wrapped_invoke(_set_new_mode, mode);
	}
	_CRTIMP terminate_handler __cdecl _o_set_terminate(terminate_handler const new_handler)
	{
		return __crt_state_management::wrapped_invoke(set_terminate, new_handler);
	}
	_CRTIMP _invalid_parameter_handler __cdecl _o__set_thread_local_invalid_parameter_handler(_invalid_parameter_handler const new_handler)
	{
		return __crt_state_management::wrapped_invoke(_set_thread_local_invalid_parameter_handler, new_handler);
	}
	_CRTIMP void __cdecl _o_setbuf(FILE * const stream, char * const buffer)
	{
		return __crt_state_management::wrapped_invoke_void(setbuf, stream, buffer);
	}
	_CRTIMP void __cdecl _o__seterrormode(int const mode)
	{
		return __crt_state_management::wrapped_invoke_void(_seterrormode, mode);
	}
	_CRTIMP char * __cdecl _o_setlocale(int _category, char const * _locale)
	{
		return __crt_state_management::wrapped_invoke(setlocale, _category, _locale);
	}
	_CRTIMP int __cdecl _o__setmbcp(int const codepage)
	{
		return __crt_state_management::wrapped_invoke(_setmbcp, codepage);
	}
	_CRTIMP int __cdecl _o__setmode(int const fh, int const mode)
	{
		return __crt_state_management::wrapped_invoke(_setmode, fh, mode);
	}
	_CRTIMP unsigned __cdecl _o__setsystime(tm * const source, unsigned const milliseconds)
	{
		return __crt_state_management::wrapped_invoke(_setsystime, source, milliseconds);
	}
	_CRTIMP int __cdecl _o_setvbuf(FILE * const public_stream, char * const buffer, int const type, size_t const buffer_size_in_bytes)
	{
		return __crt_state_management::wrapped_invoke(setvbuf, public_stream, buffer, type, buffer_size_in_bytes);
	}
	_CRTIMP void __cdecl _o__sleep(unsigned long duration)
	{
		return __crt_state_management::wrapped_invoke_void(_sleep, duration);
	}
	_CRTIMP int __cdecl _o__sopen(char const * const path, int const oflag, int const shflag, const int _PMode)
	{
		return __crt_state_management::wrapped_invoke(_sopen, path, oflag, shflag, _PMode);
	}
	_CRTIMP errno_t __cdecl _o__sopen_dispatch(char const * const path, int const oflag, int const shflag, int const pmode, int * const pfh, int const secure)
	{
		return __crt_state_management::wrapped_invoke(_sopen_dispatch, path, oflag, shflag, pmode, pfh, secure);
	}
	_CRTIMP errno_t __cdecl _o__sopen_s(int * const pfh, char const * const path, int const oflag, int const shflag, int const pmode)
	{
		return __crt_state_management::wrapped_invoke(_sopen_s, pfh, path, oflag, shflag, pmode);
	}
	_CRTIMP intptr_t __cdecl _o__spawnv(int const mode, char const * const file_name, char const * const * const arguments)
	{
		return __crt_state_management::wrapped_invoke(_spawnv, mode, file_name, arguments);
	}
	_CRTIMP intptr_t __cdecl _o__spawnve(int const mode, char const * const file_name, char const * const * const arguments, char const * const * const environment)
	{
		return __crt_state_management::wrapped_invoke(_spawnve, mode, file_name, arguments, environment);
	}
	_CRTIMP intptr_t __cdecl _o__spawnvp(int const mode, char const * const file_name, char const * const * const arguments)
	{
		return __crt_state_management::wrapped_invoke(_spawnvp, mode, file_name, arguments);
	}
	_CRTIMP intptr_t __cdecl _o__spawnvpe(int const mode, char const * const file_name, char const * const * const arguments, char const * const * const environment)
	{
		return __crt_state_management::wrapped_invoke(_spawnvpe, mode, file_name, arguments, environment);
	}
	_CRTIMP void __cdecl _o__splitpath(char const * const path, char * const drive, char * const directory, char * const file_name, char * const extension)
	{
		return __crt_state_management::wrapped_invoke_void(_splitpath, path, drive, directory, file_name, extension);
	}
	_CRTIMP errno_t __cdecl _o__splitpath_s(char const * const path, char * const drive, size_t const drive_count, char * const directory, size_t const directory_count, char * const file_name, size_t const file_name_count, char * const extension, size_t const extension_count)
	{
		return __crt_state_management::wrapped_invoke(_splitpath_s, path, drive, drive_count, directory, directory_count, file_name, file_name_count, extension, extension_count);
	}
	_CRTIMP void __cdecl _o_srand(unsigned int const seed)
	{
		return __crt_state_management::wrapped_invoke_void(srand, seed);
	}
	_CRTIMP int __cdecl _o__stat32(char const * const path, struct _stat32 * const result)
	{
		return __crt_state_management::wrapped_invoke(_stat32, path, result);
	}
	_CRTIMP int __cdecl _o__stat32i64(char const * const path, struct _stat32i64 * const result)
	{
		return __crt_state_management::wrapped_invoke(_stat32i64, path, result);
	}
	_CRTIMP int __cdecl _o__stat64(char const * const path, struct _stat64 * const result)
	{
		return __crt_state_management::wrapped_invoke(_stat64, path, result);
	}
	_CRTIMP int __cdecl _o__stat64i32(char const * const path, struct _stat64i32 * const result)
	{
		return __crt_state_management::wrapped_invoke(_stat64i32, path, result);
	}
	_CRTIMP int __cdecl _o___stdio_common_vfprintf(unsigned __int64 const options, FILE * const stream, char const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__stdio_common_vfprintf, options, stream, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___stdio_common_vfprintf_p(unsigned __int64 const options, FILE * const stream, char const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__stdio_common_vfprintf_p, options, stream, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___stdio_common_vfprintf_s(unsigned __int64 const options, FILE * const stream, char const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__stdio_common_vfprintf_s, options, stream, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___stdio_common_vfscanf(unsigned __int64 const options, FILE * const stream, char const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__stdio_common_vfscanf, options, stream, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___stdio_common_vfwprintf(unsigned __int64 const options, FILE * const stream, wchar_t const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__stdio_common_vfwprintf, options, stream, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___stdio_common_vfwprintf_p(unsigned __int64 const options, FILE * const stream, wchar_t const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__stdio_common_vfwprintf_p, options, stream, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___stdio_common_vfwprintf_s(unsigned __int64 const options, FILE * const stream, wchar_t const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__stdio_common_vfwprintf_s, options, stream, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___stdio_common_vfwscanf(unsigned __int64 const options, FILE * const stream, wchar_t const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__stdio_common_vfwscanf, options, stream, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___stdio_common_vsnprintf_s(unsigned __int64 const options, char * const buffer, size_t const buffer_count, size_t const max_count, char const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__stdio_common_vsnprintf_s, options, buffer, buffer_count, max_count, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___stdio_common_vsnwprintf_s(unsigned __int64 const options, wchar_t * const buffer, size_t const buffer_count, size_t const max_count, wchar_t const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__stdio_common_vsnwprintf_s, options, buffer, buffer_count, max_count, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___stdio_common_vsprintf(unsigned __int64 const options, char * const buffer, size_t const buffer_count, char const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__stdio_common_vsprintf, options, buffer, buffer_count, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___stdio_common_vsprintf_p(unsigned __int64 const options, char * const buffer, size_t const buffer_count, char const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__stdio_common_vsprintf_p, options, buffer, buffer_count, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___stdio_common_vsprintf_s(unsigned __int64 const options, char * const buffer, size_t const buffer_count, char const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__stdio_common_vsprintf_s, options, buffer, buffer_count, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___stdio_common_vsscanf(unsigned __int64 const options, char const * const buffer, size_t const buffer_count, char const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__stdio_common_vsscanf, options, buffer, buffer_count, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___stdio_common_vswprintf(unsigned __int64 const options, wchar_t * const buffer, size_t const buffer_count, wchar_t const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__stdio_common_vswprintf, options, buffer, buffer_count, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___stdio_common_vswprintf_p(unsigned __int64 const options, wchar_t * const buffer, size_t const buffer_count, wchar_t const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__stdio_common_vswprintf_p, options, buffer, buffer_count, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___stdio_common_vswprintf_s(unsigned __int64 const options, wchar_t * const buffer, size_t const buffer_count, wchar_t const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__stdio_common_vswprintf_s, options, buffer, buffer_count, format, locale, arglist);
	}
	_CRTIMP int __cdecl _o___stdio_common_vswscanf(unsigned __int64 const options, wchar_t const * const buffer, size_t const buffer_count, wchar_t const * const format, _locale_t const locale, va_list const arglist)
	{
		return __crt_state_management::wrapped_invoke(__stdio_common_vswscanf, options, buffer, buffer_count, format, locale, arglist);
	}
	_CRTIMP errno_t __cdecl _o_strcat_s(char * const destination, size_t const size_in_elements, char const * const source)
	{
		return __crt_state_management::wrapped_invoke(strcat_s, destination, size_in_elements, source);
	}
	_CRTIMP int __cdecl _o_strcoll(const char * _string1, const char * _string2)
	{
		return __crt_state_management::wrapped_invoke(strcoll, _string1, _string2);
	}
	_CRTIMP int __cdecl _o__strcoll_l(const char * _string1, const char * _string2, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_strcoll_l, _string1, _string2, plocinfo);
	}
	_CRTIMP errno_t __cdecl _o_strcpy_s(char * const destination, size_t const size_in_elements, char const * const source)
	{
		return __crt_state_management::wrapped_invoke(strcpy_s, destination, size_in_elements, source);
	}
	_CRTIMP char * __cdecl _o__strdate(char * const buffer)
	{
		return __crt_state_management::wrapped_invoke(_strdate, buffer);
	}
	_CRTIMP errno_t __cdecl _o__strdate_s(char * const buffer, size_t const size_in_chars)
	{
		return __crt_state_management::wrapped_invoke(_strdate_s, buffer, size_in_chars);
	}
	_CRTIMP char * __cdecl _o__strdup(char const * const string)
	{
		return __crt_state_management::wrapped_invoke(_strdup, string);
	}
	_CRTIMP char * __cdecl _o__strerror(char const * const message)
	{
		return __crt_state_management::wrapped_invoke(_strerror, message);
	}
	_CRTIMP char * __cdecl _o_strerror(int const error_number)
	{
		return __crt_state_management::wrapped_invoke(strerror, error_number);
	}
	_CRTIMP errno_t __cdecl _o__strerror_s(char * const buffer, size_t const buffer_count, char const * const message)
	{
		return __crt_state_management::wrapped_invoke(_strerror_s, buffer, buffer_count, message);
	}
	_CRTIMP errno_t __cdecl _o_strerror_s(char * const buffer, size_t const buffer_count, int const error_number)
	{
		return __crt_state_management::wrapped_invoke(strerror_s, buffer, buffer_count, error_number);
	}
	_CRTIMP size_t __cdecl _o__Strftime(char * const string, size_t const max_size, char const * const format, tm const * const timeptr, void * const lc_time_arg)
	{
		return __crt_state_management::wrapped_invoke(_Strftime, string, max_size, format, timeptr, lc_time_arg);
	}
	_CRTIMP size_t __cdecl _o_strftime(char * const string, size_t const max_size, char const * const format, tm const * const timeptr)
	{
		return __crt_state_management::wrapped_invoke(strftime, string, max_size, format, timeptr);
	}
	_CRTIMP size_t __cdecl _o__strftime_l(char * const string, size_t const max_size, char const * const format, tm const * const timeptr, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_strftime_l, string, max_size, format, timeptr, locale);
	}
	_CRTIMP int __cdecl _o__stricmp(char const * const lhs, char const * const rhs)
	{
		return __crt_state_management::wrapped_invoke(_stricmp, lhs, rhs);
	}
	_CRTIMP int __cdecl _o__stricmp_l(char const * const lhs, char const * const rhs, _locale_t const plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_stricmp_l, lhs, rhs, plocinfo);
	}
	_CRTIMP int __cdecl _o__stricoll(const char * _string1, const char * _string2)
	{
		return __crt_state_management::wrapped_invoke(_stricoll, _string1, _string2);
	}
	_CRTIMP int __cdecl _o__stricoll_l(const char * _string1, const char * _string2, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_stricoll_l, _string1, _string2, plocinfo);
	}
	_CRTIMP char * __cdecl _o__strlwr(char * string)
	{
		return __crt_state_management::wrapped_invoke(_strlwr, string);
	}
	_CRTIMP char * __cdecl _o__strlwr_l(char * string, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_strlwr_l, string, plocinfo);
	}
	_CRTIMP errno_t __cdecl _o__strlwr_s(char * string, size_t sizeInBytes)
	{
		return __crt_state_management::wrapped_invoke(_strlwr_s, string, sizeInBytes);
	}
	_CRTIMP errno_t __cdecl _o__strlwr_s_l(char * string, size_t sizeInBytes, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_strlwr_s_l, string, sizeInBytes, plocinfo);
	}
	_CRTIMP errno_t __cdecl _o_strncat_s(char * const destination, size_t const size_in_elements, char const * const source, size_t const count)
	{
		return __crt_state_management::wrapped_invoke(strncat_s, destination, size_in_elements, source, count);
	}
	_CRTIMP int __cdecl _o__strncoll(const char * _string1, const char * _string2, size_t count)
	{
		return __crt_state_management::wrapped_invoke(_strncoll, _string1, _string2, count);
	}
	_CRTIMP int __cdecl _o__strncoll_l(const char * _string1, const char * _string2, size_t count, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_strncoll_l, _string1, _string2, count, plocinfo);
	}
	_CRTIMP errno_t __cdecl _o_strncpy_s(char * const destination, size_t const size_in_elements, char const * const source, size_t const count)
	{
		return __crt_state_management::wrapped_invoke(strncpy_s, destination, size_in_elements, source, count);
	}
	_CRTIMP int __cdecl _o__strnicmp(char const * const lhs, char const * const rhs, size_t const count)
	{
		return __crt_state_management::wrapped_invoke(_strnicmp, lhs, rhs, count);
	}
	_CRTIMP int __cdecl _o__strnicmp_l(char const * const lhs, char const * const rhs, size_t const count, _locale_t const plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_strnicmp_l, lhs, rhs, count, plocinfo);
	}
	_CRTIMP int __cdecl _o__strnicoll(const char * _string1, const char * _string2, size_t count)
	{
		return __crt_state_management::wrapped_invoke(_strnicoll, _string1, _string2, count);
	}
	_CRTIMP int __cdecl _o__strnicoll_l(const char * _string1, const char * _string2, size_t count, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_strnicoll_l, _string1, _string2, count, plocinfo);
	}
	_CRTIMP errno_t __cdecl _o__strnset_s(char * const destination, size_t const size_in_elements, int const value, size_t const count)
	{
		return __crt_state_management::wrapped_invoke(_strnset_s, destination, size_in_elements, value, count);
	}
	_CRTIMP errno_t __cdecl _o__strset_s(char * const destination, size_t const size_in_elements, int const value)
	{
		return __crt_state_management::wrapped_invoke(_strset_s, destination, size_in_elements, value);
	}
	_CRTIMP char * __cdecl _o__strtime(char * const buffer)
	{
		return __crt_state_management::wrapped_invoke(_strtime, buffer);
	}
	_CRTIMP errno_t __cdecl _o__strtime_s(char * const buffer, size_t const size_in_chars)
	{
		return __crt_state_management::wrapped_invoke(_strtime_s, buffer, size_in_chars);
	}
	_CRTIMP double __cdecl _o_strtod(char const * const string, char ** const end_ptr)
	{
		return __crt_state_management::wrapped_invoke(strtod, string, end_ptr);
	}
	_CRTIMP double __cdecl _o__strtod_l(char const * const string, char ** const end_ptr, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_strtod_l, string, end_ptr, locale);
	}
	_CRTIMP float __cdecl _o_strtof(char const * const string, char ** const end_ptr)
	{
		return __crt_state_management::wrapped_invoke(strtof, string, end_ptr);
	}
	_CRTIMP float __cdecl _o__strtof_l(char const * const string, char ** const end_ptr, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_strtof_l, string, end_ptr, locale);
	}
	_CRTIMP __int64 __cdecl _o__strtoi64(char const * const string, char ** const end_ptr, int const base)
	{
		return __crt_state_management::wrapped_invoke(_strtoi64, string, end_ptr, base);
	}
	_CRTIMP __int64 __cdecl _o__strtoi64_l(char const * const string, char ** const end_ptr, int const base, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_strtoi64_l, string, end_ptr, base, locale);
	}
	_CRTIMP char * __cdecl _o_strtok(char * const string, char const * const control)
	{
		return __crt_state_management::wrapped_invoke(strtok, string, control);
	}
	_CRTIMP char * __cdecl _o_strtok_s(char * string, char const * control, char ** context)
	{
		return __crt_state_management::wrapped_invoke(strtok_s, string, control, context);
	}
	_CRTIMP long __cdecl _o_strtol(char const * const string, char ** const end_ptr, int const base)
	{
		return __crt_state_management::wrapped_invoke(strtol, string, end_ptr, base);
	}
	_CRTIMP long __cdecl _o__strtol_l(char const * const string, char ** const end_ptr, int const base, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_strtol_l, string, end_ptr, base, locale);
	}
	_CRTIMP long double __cdecl _o_strtold(char const * const string, char ** const end_ptr)
	{
		return __crt_state_management::wrapped_invoke(strtold, string, end_ptr);
	}
	_CRTIMP long double __cdecl _o__strtold_l(char const * const string, char ** const end_ptr, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_strtold_l, string, end_ptr, locale);
	}
	_CRTIMP long long __cdecl _o_strtoll(char const * const string, char ** const end_ptr, int const base)
	{
		return __crt_state_management::wrapped_invoke(strtoll, string, end_ptr, base);
	}
	_CRTIMP long long __cdecl _o__strtoll_l(char const * const string, char ** const end_ptr, int const base, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_strtoll_l, string, end_ptr, base, locale);
	}
	_CRTIMP unsigned __int64 __cdecl _o__strtoui64(char const * const string, char ** const end_ptr, int const base)
	{
		return __crt_state_management::wrapped_invoke(_strtoui64, string, end_ptr, base);
	}
	_CRTIMP unsigned __int64 __cdecl _o__strtoui64_l(char const * const string, char ** const end_ptr, int const base, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_strtoui64_l, string, end_ptr, base, locale);
	}
	_CRTIMP unsigned long __cdecl _o_strtoul(char const * const string, char ** const end_ptr, int const base)
	{
		return __crt_state_management::wrapped_invoke(strtoul, string, end_ptr, base);
	}
	_CRTIMP unsigned long __cdecl _o__strtoul_l(char const * const string, char ** const end_ptr, int const base, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_strtoul_l, string, end_ptr, base, locale);
	}
	_CRTIMP unsigned long long __cdecl _o_strtoull(char const * const string, char ** const end_ptr, int const base)
	{
		return __crt_state_management::wrapped_invoke(strtoull, string, end_ptr, base);
	}
	_CRTIMP unsigned long long __cdecl _o__strtoull_l(char const * const string, char ** const end_ptr, int const base, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_strtoull_l, string, end_ptr, base, locale);
	}
	_CRTIMP char * __cdecl _o__strupr(char * string)
	{
		return __crt_state_management::wrapped_invoke(_strupr, string);
	}
	_CRTIMP char * __cdecl _o__strupr_l(char * string, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_strupr_l, string, plocinfo);
	}
	_CRTIMP errno_t __cdecl _o__strupr_s(char * string, size_t sizeInBytes)
	{
		return __crt_state_management::wrapped_invoke(_strupr_s, string, sizeInBytes);
	}
	_CRTIMP errno_t __cdecl _o__strupr_s_l(char * string, size_t sizeInBytes, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_strupr_s_l, string, sizeInBytes, plocinfo);
	}
	_CRTIMP size_t __cdecl _o__strxfrm_l(char * _string1, const char * _string2, size_t _count, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_strxfrm_l, _string1, _string2, _count, plocinfo);
	}
	_CRTIMP void __cdecl _o__swab(char * source, char * destination, int bytes)
	{
		return __crt_state_management::wrapped_invoke_void(_swab, source, destination, bytes);
	}
	_CRTIMP int __cdecl _o_system(char const * const command)
	{
		return __crt_state_management::wrapped_invoke(system, command);
	}
	_CRTIMP long __cdecl _o__tell(int const fh)
	{
		return __crt_state_management::wrapped_invoke(_tell, fh);
	}
	_CRTIMP __int64 __cdecl _o__telli64(int const fh)
	{
		return __crt_state_management::wrapped_invoke(_telli64, fh);
	}
	_CRTIMP void __cdecl _o_terminate()
	{
		return __crt_state_management::wrapped_invoke_void(terminate);
	}
	_CRTIMP int __cdecl _o__timespec32_get(_timespec32 * const ts, int const base)
	{
		return __crt_state_management::wrapped_invoke(_timespec32_get, ts, base);
	}
	_CRTIMP int __cdecl _o__timespec64_get(_timespec64 * const ts, int const base)
	{
		return __crt_state_management::wrapped_invoke(_timespec64_get, ts, base);
	}
	_CRTIMP long * __cdecl _o___timezone()
	{
		return __crt_state_management::wrapped_invoke(__timezone);
	}
	_CRTIMP errno_t __cdecl _o_tmpfile_s(FILE ** const stream)
	{
		return __crt_state_management::wrapped_invoke(tmpfile_s, stream);
	}
	_CRTIMP errno_t __cdecl _o_tmpnam_s(char * const result_buffer, size_t const result_buffer_count)
	{
		return __crt_state_management::wrapped_invoke(tmpnam_s, result_buffer, result_buffer_count);
	}
	_CRTIMP int __cdecl _o_tolower(int const c)
	{
		return __crt_state_management::wrapped_invoke(tolower, c);
	}
	_CRTIMP int __cdecl _o__tolower_l(int const c, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_tolower_l, c, locale);
	}
	_CRTIMP int __cdecl _o_toupper(int const c)
	{
		return __crt_state_management::wrapped_invoke(toupper, c);
	}
	_CRTIMP int __cdecl _o__toupper_l(int const c, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_toupper_l, c, locale);
	}
	_CRTIMP wint_t __cdecl _o_towlower(wint_t c)
	{
		return __crt_state_management::wrapped_invoke(towlower, c);
	}
	_CRTIMP wint_t __cdecl _o__towlower_l(wint_t c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_towlower_l, c, plocinfo);
	}
	_CRTIMP wint_t __cdecl _o_towupper(wint_t c)
	{
		return __crt_state_management::wrapped_invoke(towupper, c);
	}
	_CRTIMP wint_t __cdecl _o__towupper_l(wint_t c, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_towupper_l, c, plocinfo);
	}
	_CRTIMP char ** __cdecl _o___tzname()
	{
		return __crt_state_management::wrapped_invoke(__tzname);
	}
	_CRTIMP void __cdecl _o__tzset()
	{
		return __crt_state_management::wrapped_invoke_void(_tzset);
	}
	_CRTIMP char * __cdecl _o__ui64toa(unsigned __int64 const value, char * const buffer, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_ui64toa, value, buffer, radix);
	}
	_CRTIMP errno_t __cdecl _o__ui64toa_s(unsigned __int64 const value, char * const buffer, size_t const buffer_count, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_ui64toa_s, value, buffer, buffer_count, radix);
	}
	_CRTIMP wchar_t * __cdecl _o__ui64tow(unsigned __int64 const value, wchar_t * const buffer, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_ui64tow, value, buffer, radix);
	}
	_CRTIMP errno_t __cdecl _o__ui64tow_s(unsigned __int64 const value, wchar_t * const buffer, size_t const buffer_count, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_ui64tow_s, value, buffer, buffer_count, radix);
	}
	_CRTIMP char * __cdecl _o__ultoa(unsigned long const value, char * const buffer, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_ultoa, value, buffer, radix);
	}
	_CRTIMP errno_t __cdecl _o__ultoa_s(unsigned long const value, char * const buffer, size_t const buffer_count, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_ultoa_s, value, buffer, buffer_count, radix);
	}
	_CRTIMP wchar_t * __cdecl _o__ultow(unsigned long const value, wchar_t * const buffer, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_ultow, value, buffer, radix);
	}
	_CRTIMP errno_t __cdecl _o__ultow_s(unsigned long const value, wchar_t * const buffer, size_t const buffer_count, int const radix)
	{
		return __crt_state_management::wrapped_invoke(_ultow_s, value, buffer, buffer_count, radix);
	}
	_CRTIMP int __cdecl _o__umask(int const mode)
	{
		return __crt_state_management::wrapped_invoke(_umask, mode);
	}
	_CRTIMP errno_t __cdecl _o__umask_s(int const mode, int * const old_mode)
	{
		return __crt_state_management::wrapped_invoke(_umask_s, mode, old_mode);
	}
	_CRTIMP int __cdecl _o_ungetc(int const c, FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(ungetc, c, stream);
	}
	_CRTIMP int __cdecl _o__ungetc_nolock(int const c, FILE * public_stream)
	{
		return __crt_state_management::wrapped_invoke(_ungetc_nolock, c, public_stream);
	}
	_CRTIMP int __cdecl _o__ungetch(int const c)
	{
		return __crt_state_management::wrapped_invoke(_ungetch, c);
	}
	_CRTIMP int __cdecl _o__ungetch_nolock(int const c)
	{
		return __crt_state_management::wrapped_invoke(_ungetch_nolock, c);
	}
	_CRTIMP wint_t __cdecl _o_ungetwc(wint_t const c, FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke(ungetwc, c, stream);
	}
	_CRTIMP wint_t __cdecl _o__ungetwc_nolock(wint_t const c, FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(_ungetwc_nolock, c, public_stream);
	}
	_CRTIMP wint_t __cdecl _o__ungetwch(wint_t const c)
	{
		return __crt_state_management::wrapped_invoke(_ungetwch, c);
	}
	_CRTIMP wint_t __cdecl _o__ungetwch_nolock(wint_t const c)
	{
		return __crt_state_management::wrapped_invoke(_ungetwch_nolock, c);
	}
	_CRTIMP int __cdecl _o__unlink(char const * const path)
	{
		return __crt_state_management::wrapped_invoke(_unlink, path);
	}
	_CRTIMP int __cdecl _o__unloaddll(intptr_t hMod)
	{
		return __crt_state_management::wrapped_invoke(_unloaddll, hMod);
	}
	_CRTIMP void __cdecl _o__unlock_file(FILE * const stream)
	{
		return __crt_state_management::wrapped_invoke_void(_unlock_file, stream);
	}
	_CRTIMP int __cdecl _o__utime32(char const * const file_name, __utimbuf32 * const times)
	{
		return __crt_state_management::wrapped_invoke(_utime32, file_name, times);
	}
	_CRTIMP int __cdecl _o__utime64(char const * const file_name, __utimbuf64 * const times)
	{
		return __crt_state_management::wrapped_invoke(_utime64, file_name, times);
	}
	_CRTIMP wchar_t * __cdecl _o__W_Getdays()
	{
		return __crt_state_management::wrapped_invoke(_W_Getdays);
	}
	_CRTIMP wchar_t * __cdecl _o__W_Getmonths()
	{
		return __crt_state_management::wrapped_invoke(_W_Getmonths);
	}
	_CRTIMP void * __cdecl _o__W_Gettnames()
	{
		return __crt_state_management::wrapped_invoke(_W_Gettnames);
	}
	_CRTIMP int __cdecl _o__waccess(wchar_t const * const path, int const access_mode)
	{
		return __crt_state_management::wrapped_invoke(_waccess, path, access_mode);
	}
	_CRTIMP errno_t __cdecl _o__waccess_s(wchar_t const * const path, int const access_mode)
	{
		return __crt_state_management::wrapped_invoke(_waccess_s, path, access_mode);
	}
	_CRTIMP wchar_t * __cdecl _o__wasctime(tm const * const tm_value)
	{
		return __crt_state_management::wrapped_invoke(_wasctime, tm_value);
	}
	_CRTIMP errno_t __cdecl _o__wasctime_s(wchar_t * const buffer, size_t const size_in_chars, tm const * const tm_value)
	{
		return __crt_state_management::wrapped_invoke(_wasctime_s, buffer, size_in_chars, tm_value);
	}
	_CRTIMP int __cdecl _o__wchdir(wchar_t const * const path)
	{
		return __crt_state_management::wrapped_invoke(_wchdir, path);
	}
	_CRTIMP int __cdecl _o__wchmod(wchar_t const * const path, int const mode)
	{
		return __crt_state_management::wrapped_invoke(_wchmod, path, mode);
	}
	_CRTIMP int __cdecl _o__wcreat(wchar_t const * const path, int const pmode)
	{
		return __crt_state_management::wrapped_invoke(_wcreat, path, pmode);
	}
	_CRTIMP _locale_t __cdecl _o__wcreate_locale(int _category, const wchar_t * locale)
	{
		return __crt_state_management::wrapped_invoke(_wcreate_locale, _category, locale);
	}
	_CRTIMP size_t __cdecl _o_wcrtomb(char * const destination, wchar_t const wchar, mbstate_t * const state)
	{
		return __crt_state_management::wrapped_invoke(wcrtomb, destination, wchar, state);
	}
	_CRTIMP errno_t __cdecl _o_wcrtomb_s(size_t * const return_value, char * const destination, size_t const destination_count, wchar_t const wchar, mbstate_t * const state)
	{
		return __crt_state_management::wrapped_invoke(wcrtomb_s, return_value, destination, destination_count, wchar, state);
	}
	_CRTIMP errno_t __cdecl _o_wcscat_s(wchar_t * const destination, size_t const size_in_elements, wchar_t const * const source)
	{
		return __crt_state_management::wrapped_invoke(wcscat_s, destination, size_in_elements, source);
	}
	_CRTIMP int __cdecl _o_wcscoll(const wchar_t * _string1, const wchar_t * _string2)
	{
		return __crt_state_management::wrapped_invoke(wcscoll, _string1, _string2);
	}
	_CRTIMP int __cdecl _o__wcscoll_l(const wchar_t * _string1, const wchar_t * _string2, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_wcscoll_l, _string1, _string2, plocinfo);
	}
	_CRTIMP wchar_t * __cdecl _o_wcscpy(wchar_t * const destination, wchar_t const * source)
	{
		return __crt_state_management::wrapped_invoke(wcscpy, destination, source);
	}
	_CRTIMP errno_t __cdecl _o_wcscpy_s(wchar_t * const destination, size_t const size_in_elements, wchar_t const * const source)
	{
		return __crt_state_management::wrapped_invoke(wcscpy_s, destination, size_in_elements, source);
	}
	_CRTIMP wchar_t * __cdecl _o__wcsdup(wchar_t const * const string)
	{
		return __crt_state_management::wrapped_invoke(_wcsdup, string);
	}
	_CRTIMP wchar_t * __cdecl _o___wcserror(wchar_t const * const message)
	{
		return __crt_state_management::wrapped_invoke(__wcserror, message);
	}
	_CRTIMP wchar_t * __cdecl _o__wcserror(int const error_number)
	{
		return __crt_state_management::wrapped_invoke(_wcserror, error_number);
	}
	_CRTIMP errno_t __cdecl _o__wcserror_s(wchar_t * const buffer, size_t const buffer_count, int const error_number)
	{
		return __crt_state_management::wrapped_invoke(_wcserror_s, buffer, buffer_count, error_number);
	}
	_CRTIMP size_t __cdecl _o__Wcsftime(wchar_t * const buffer, size_t const max_size, wchar_t const * const format, tm const * const timeptr, void * const lc_time_arg)
	{
		return __crt_state_management::wrapped_invoke(_Wcsftime, buffer, max_size, format, timeptr, lc_time_arg);
	}
	_CRTIMP size_t __cdecl _o_wcsftime(wchar_t * const buffer, size_t const max_size, wchar_t const * const format, tm const * const timeptr)
	{
		return __crt_state_management::wrapped_invoke(wcsftime, buffer, max_size, format, timeptr);
	}
	_CRTIMP size_t __cdecl _o__wcsftime_l(wchar_t * const buffer, size_t const max_size, wchar_t const * const format, tm const * const timeptr, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_wcsftime_l, buffer, max_size, format, timeptr, locale);
	}
	_CRTIMP int __cdecl _o__wcsicmp(wchar_t const * const lhs, wchar_t const * const rhs)
	{
		return __crt_state_management::wrapped_invoke(_wcsicmp, lhs, rhs);
	}
	_CRTIMP int __cdecl _o__wcsicmp_l(wchar_t const * const lhs, wchar_t const * const rhs, _locale_t const plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_wcsicmp_l, lhs, rhs, plocinfo);
	}
	_CRTIMP int __cdecl _o__wcsicoll(const wchar_t * _string1, const wchar_t * _string2)
	{
		return __crt_state_management::wrapped_invoke(_wcsicoll, _string1, _string2);
	}
	_CRTIMP int __cdecl _o__wcsicoll_l(const wchar_t * _string1, const wchar_t * _string2, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_wcsicoll_l, _string1, _string2, plocinfo);
	}
	_CRTIMP wchar_t * __cdecl _o__wcslwr(wchar_t * wsrc)
	{
		return __crt_state_management::wrapped_invoke(_wcslwr, wsrc);
	}
	_CRTIMP wchar_t * __cdecl _o__wcslwr_l(wchar_t * wsrc, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_wcslwr_l, wsrc, plocinfo);
	}
	_CRTIMP errno_t __cdecl _o__wcslwr_s(wchar_t * wsrc, size_t sizeInWords)
	{
		return __crt_state_management::wrapped_invoke(_wcslwr_s, wsrc, sizeInWords);
	}
	_CRTIMP errno_t __cdecl _o__wcslwr_s_l(wchar_t * wsrc, size_t sizeInWords, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_wcslwr_s_l, wsrc, sizeInWords, plocinfo);
	}
	_CRTIMP errno_t __cdecl _o_wcsncat_s(wchar_t * const destination, size_t const size_in_elements, wchar_t const * const source, size_t const count)
	{
		return __crt_state_management::wrapped_invoke(wcsncat_s, destination, size_in_elements, source, count);
	}
	_CRTIMP int __cdecl _o__wcsncoll(const wchar_t * _string1, const wchar_t * _string2, size_t count)
	{
		return __crt_state_management::wrapped_invoke(_wcsncoll, _string1, _string2, count);
	}
	_CRTIMP int __cdecl _o__wcsncoll_l(const wchar_t * _string1, const wchar_t * _string2, size_t count, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_wcsncoll_l, _string1, _string2, count, plocinfo);
	}
	_CRTIMP errno_t __cdecl _o_wcsncpy_s(wchar_t * const destination, size_t const size_in_elements, wchar_t const * const source, size_t const count)
	{
		return __crt_state_management::wrapped_invoke(wcsncpy_s, destination, size_in_elements, source, count);
	}
	_CRTIMP int __cdecl _o__wcsnicmp(wchar_t const * const lhs, wchar_t const * const rhs, size_t const count)
	{
		return __crt_state_management::wrapped_invoke(_wcsnicmp, lhs, rhs, count);
	}
	_CRTIMP int __cdecl _o__wcsnicmp_l(wchar_t const * const lhs, wchar_t const * const rhs, size_t const count, _locale_t const plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_wcsnicmp_l, lhs, rhs, count, plocinfo);
	}
	_CRTIMP int __cdecl _o__wcsnicoll(const wchar_t * _string1, const wchar_t * _string2, size_t count)
	{
		return __crt_state_management::wrapped_invoke(_wcsnicoll, _string1, _string2, count);
	}
	_CRTIMP int __cdecl _o__wcsnicoll_l(const wchar_t * _string1, const wchar_t * _string2, size_t count, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_wcsnicoll_l, _string1, _string2, count, plocinfo);
	}
	_CRTIMP wchar_t * __cdecl _o__wcsnset(wchar_t * const string, wchar_t const value, size_t const count)
	{
		return __crt_state_management::wrapped_invoke(_wcsnset, string, value, count);
	}
	_CRTIMP errno_t __cdecl _o__wcsnset_s(wchar_t * const destination, size_t const size_in_elements, wchar_t const value, size_t const count)
	{
		return __crt_state_management::wrapped_invoke(_wcsnset_s, destination, size_in_elements, value, count);
	}
	_CRTIMP size_t __cdecl _o_wcsrtombs(char * const destination, wchar_t const ** const source, size_t const n, mbstate_t * const state)
	{
		return __crt_state_management::wrapped_invoke(wcsrtombs, destination, source, n, state);
	}
	_CRTIMP errno_t __cdecl _o_wcsrtombs_s(size_t * const return_value, char * const destination, size_t const destination_count, wchar_t const ** const source, size_t const n, mbstate_t * const state)
	{
		return __crt_state_management::wrapped_invoke(wcsrtombs_s, return_value, destination, destination_count, source, n, state);
	}
	_CRTIMP wchar_t * __cdecl _o__wcsset(wchar_t * const string, wchar_t const value)
	{
		return __crt_state_management::wrapped_invoke(_wcsset, string, value);
	}
	_CRTIMP errno_t __cdecl _o__wcsset_s(wchar_t * const destination, size_t const size_in_elements, wchar_t const value)
	{
		return __crt_state_management::wrapped_invoke(_wcsset_s, destination, size_in_elements, value);
	}
	_CRTIMP double __cdecl _o_wcstod(wchar_t const * const string, wchar_t ** const end_ptr)
	{
		return __crt_state_management::wrapped_invoke(wcstod, string, end_ptr);
	}
	_CRTIMP double __cdecl _o__wcstod_l(wchar_t const * const string, wchar_t ** const end_ptr, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_wcstod_l, string, end_ptr, locale);
	}
	_CRTIMP float __cdecl _o_wcstof(wchar_t const * const string, wchar_t ** const end_ptr)
	{
		return __crt_state_management::wrapped_invoke(wcstof, string, end_ptr);
	}
	_CRTIMP float __cdecl _o__wcstof_l(wchar_t const * const string, wchar_t ** const end_ptr, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_wcstof_l, string, end_ptr, locale);
	}
	_CRTIMP __int64 __cdecl _o__wcstoi64(wchar_t const * const string, wchar_t ** const end_ptr, int const base)
	{
		return __crt_state_management::wrapped_invoke(_wcstoi64, string, end_ptr, base);
	}
	_CRTIMP __int64 __cdecl _o__wcstoi64_l(wchar_t const * const string, wchar_t ** const end_ptr, int const base, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_wcstoi64_l, string, end_ptr, base, locale);
	}
	_CRTIMP wchar_t * __cdecl _o_wcstok(wchar_t * const string, wchar_t const * const control, wchar_t ** const context)
	{
		return __crt_state_management::wrapped_invoke(wcstok, string, control, context);
	}
	_CRTIMP wchar_t * __cdecl _o_wcstok_s(wchar_t * const string, wchar_t const * const control, wchar_t ** const context)
	{
		return __crt_state_management::wrapped_invoke(wcstok_s, string, control, context);
	}
	_CRTIMP long __cdecl _o_wcstol(wchar_t const * const string, wchar_t ** const end_ptr, int const base)
	{
		return __crt_state_management::wrapped_invoke(wcstol, string, end_ptr, base);
	}
	_CRTIMP long __cdecl _o__wcstol_l(wchar_t const * const string, wchar_t ** const end_ptr, int const base, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_wcstol_l, string, end_ptr, base, locale);
	}
	_CRTIMP long double __cdecl _o_wcstold(wchar_t const * const string, wchar_t ** const end_ptr)
	{
		return __crt_state_management::wrapped_invoke(wcstold, string, end_ptr);
	}
	_CRTIMP long double __cdecl _o__wcstold_l(wchar_t const * const string, wchar_t ** const end_ptr, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_wcstold_l, string, end_ptr, locale);
	}
	_CRTIMP long long __cdecl _o_wcstoll(wchar_t const * const string, wchar_t ** const end_ptr, int const base)
	{
		return __crt_state_management::wrapped_invoke(wcstoll, string, end_ptr, base);
	}
	_CRTIMP long long __cdecl _o__wcstoll_l(wchar_t const * const string, wchar_t ** const end_ptr, int const base, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_wcstoll_l, string, end_ptr, base, locale);
	}
	_CRTIMP size_t __cdecl _o_wcstombs(char * s, const wchar_t * pwcs, size_t n)
	{
		return __crt_state_management::wrapped_invoke(wcstombs, s, pwcs, n);
	}
	_CRTIMP size_t __cdecl _o__wcstombs_l(char * s, const wchar_t * pwcs, size_t n, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_wcstombs_l, s, pwcs, n, plocinfo);
	}
	_CRTIMP errno_t __cdecl _o_wcstombs_s(size_t * pConvertedChars, char * dst, size_t sizeInBytes, const wchar_t * src, size_t n)
	{
		return __crt_state_management::wrapped_invoke(wcstombs_s, pConvertedChars, dst, sizeInBytes, src, n);
	}
	_CRTIMP errno_t __cdecl _o__wcstombs_s_l(size_t * pConvertedChars, char * dst, size_t sizeInBytes, const wchar_t * src, size_t n, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_wcstombs_s_l, pConvertedChars, dst, sizeInBytes, src, n, plocinfo);
	}
	_CRTIMP unsigned __int64 __cdecl _o__wcstoui64(wchar_t const * const string, wchar_t ** const end_ptr, int const base)
	{
		return __crt_state_management::wrapped_invoke(_wcstoui64, string, end_ptr, base);
	}
	_CRTIMP unsigned __int64 __cdecl _o__wcstoui64_l(wchar_t const * const string, wchar_t ** const end_ptr, int const base, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_wcstoui64_l, string, end_ptr, base, locale);
	}
	_CRTIMP unsigned long __cdecl _o_wcstoul(wchar_t const * const string, wchar_t ** const end_ptr, int const base)
	{
		return __crt_state_management::wrapped_invoke(wcstoul, string, end_ptr, base);
	}
	_CRTIMP unsigned long __cdecl _o__wcstoul_l(wchar_t const * const string, wchar_t ** const end_ptr, int const base, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_wcstoul_l, string, end_ptr, base, locale);
	}
	_CRTIMP unsigned long long __cdecl _o_wcstoull(wchar_t const * const string, wchar_t ** const end_ptr, int const base)
	{
		return __crt_state_management::wrapped_invoke(wcstoull, string, end_ptr, base);
	}
	_CRTIMP unsigned long long __cdecl _o__wcstoull_l(wchar_t const * const string, wchar_t ** const end_ptr, int const base, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_wcstoull_l, string, end_ptr, base, locale);
	}
	_CRTIMP wchar_t * __cdecl _o__wcsupr(wchar_t * wsrc)
	{
		return __crt_state_management::wrapped_invoke(_wcsupr, wsrc);
	}
	_CRTIMP wchar_t * __cdecl _o__wcsupr_l(wchar_t * wsrc, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_wcsupr_l, wsrc, plocinfo);
	}
	_CRTIMP errno_t __cdecl _o__wcsupr_s(wchar_t * wsrc, size_t sizeInWords)
	{
		return __crt_state_management::wrapped_invoke(_wcsupr_s, wsrc, sizeInWords);
	}
	_CRTIMP errno_t __cdecl _o__wcsupr_s_l(wchar_t * wsrc, size_t sizeInWords, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_wcsupr_s_l, wsrc, sizeInWords, plocinfo);
	}
	_CRTIMP size_t __cdecl _o__wcsxfrm_l(wchar_t * _string1, const wchar_t * _string2, size_t _count, _locale_t plocinfo)
	{
		return __crt_state_management::wrapped_invoke(_wcsxfrm_l, _string1, _string2, _count, plocinfo);
	}
	_CRTIMP wchar_t * __cdecl _o__wctime32(__time32_t const * const time_t_value)
	{
		return __crt_state_management::wrapped_invoke(_wctime32, time_t_value);
	}
	_CRTIMP errno_t __cdecl _o__wctime32_s(wchar_t * const buffer, size_t const size_in_chars, __time32_t const * const time_t_value)
	{
		return __crt_state_management::wrapped_invoke(_wctime32_s, buffer, size_in_chars, time_t_value);
	}
	_CRTIMP wchar_t * __cdecl _o__wctime64(__time64_t const * const time_t_value)
	{
		return __crt_state_management::wrapped_invoke(_wctime64, time_t_value);
	}
	_CRTIMP errno_t __cdecl _o__wctime64_s(wchar_t * const buffer, size_t const size_in_chars, __time64_t const * const time_t_value)
	{
		return __crt_state_management::wrapped_invoke(_wctime64_s, buffer, size_in_chars, time_t_value);
	}
	_CRTIMP int __cdecl _o_wctob(wint_t const wchar)
	{
		return __crt_state_management::wrapped_invoke(wctob, wchar);
	}
	_CRTIMP int __cdecl _o_wctomb(char * const destination, wchar_t const wchar)
	{
		return __crt_state_management::wrapped_invoke(wctomb, destination, wchar);
	}
	_CRTIMP int __cdecl _o__wctomb_l(char * const destination, wchar_t const wchar, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_wctomb_l, destination, wchar, locale);
	}
	_CRTIMP errno_t __cdecl _o_wctomb_s(int * const return_value, char * const destination, size_t const destination_count, wchar_t const wchar)
	{
		return __crt_state_management::wrapped_invoke(wctomb_s, return_value, destination, destination_count, wchar);
	}
	_CRTIMP int __cdecl _o__wctomb_s_l(int * const return_value, char * const destination, size_t const destination_count, wchar_t const wchar, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_wctomb_s_l, return_value, destination, destination_count, wchar, locale);
	}
	_CRTIMP errno_t __cdecl _o__wdupenv_s(wchar_t ** const buffer_pointer, size_t * const buffer_count, wchar_t const * const name)
	{
		return __crt_state_management::wrapped_invoke(_wdupenv_s, buffer_pointer, buffer_count, name);
	}
	_CRTIMP intptr_t __cdecl _o__wexecv(wchar_t const * const file_name, wchar_t const * const * const arguments)
	{
		return __crt_state_management::wrapped_invoke(_wexecv, file_name, arguments);
	}
	_CRTIMP intptr_t __cdecl _o__wexecve(wchar_t const * const file_name, wchar_t const * const * const arguments, wchar_t const * const * const environment)
	{
		return __crt_state_management::wrapped_invoke(_wexecve, file_name, arguments, environment);
	}
	_CRTIMP intptr_t __cdecl _o__wexecvp(wchar_t const * const file_name, wchar_t const * const * const arguments)
	{
		return __crt_state_management::wrapped_invoke(_wexecvp, file_name, arguments);
	}
	_CRTIMP intptr_t __cdecl _o__wexecvpe(wchar_t const * const file_name, wchar_t const * const * const arguments, wchar_t const * const * const environment)
	{
		return __crt_state_management::wrapped_invoke(_wexecvpe, file_name, arguments, environment);
	}
	_CRTIMP FILE * __cdecl _o__wfdopen(int const fh, wchar_t const * const mode)
	{
		return __crt_state_management::wrapped_invoke(_wfdopen, fh, mode);
	}
	_CRTIMP intptr_t __cdecl _o__wfindfirst32(wchar_t const * const pattern, _wfinddata32_t * const result)
	{
		return __crt_state_management::wrapped_invoke(_wfindfirst32, pattern, result);
	}
	_CRTIMP intptr_t __cdecl _o__wfindfirst32i64(wchar_t const * const pattern, _wfinddata32i64_t * const result)
	{
		return __crt_state_management::wrapped_invoke(_wfindfirst32i64, pattern, result);
	}
	_CRTIMP intptr_t __cdecl _o__wfindfirst64(wchar_t const * const pattern, _wfinddata64_t * const result)
	{
		return __crt_state_management::wrapped_invoke(_wfindfirst64, pattern, result);
	}
	_CRTIMP intptr_t __cdecl _o__wfindfirst64i32(wchar_t const * const pattern, _wfinddata64i32_t * const result)
	{
		return __crt_state_management::wrapped_invoke(_wfindfirst64i32, pattern, result);
	}
	_CRTIMP int __cdecl _o__wfindnext32(intptr_t const handle, _wfinddata32_t * const result)
	{
		return __crt_state_management::wrapped_invoke(_wfindnext32, handle, result);
	}
	_CRTIMP int __cdecl _o__wfindnext32i64(intptr_t const handle, _wfinddata32i64_t * const result)
	{
		return __crt_state_management::wrapped_invoke(_wfindnext32i64, handle, result);
	}
	_CRTIMP int __cdecl _o__wfindnext64(intptr_t const handle, _wfinddata64_t * const result)
	{
		return __crt_state_management::wrapped_invoke(_wfindnext64, handle, result);
	}
	_CRTIMP int __cdecl _o__wfindnext64i32(intptr_t const handle, _wfinddata64i32_t * const result)
	{
		return __crt_state_management::wrapped_invoke(_wfindnext64i32, handle, result);
	}
	_CRTIMP FILE * __cdecl _o__wfopen(wchar_t const * const file, wchar_t const * const mode)
	{
		return __crt_state_management::wrapped_invoke(_wfopen, file, mode);
	}
	_CRTIMP errno_t __cdecl _o__wfopen_s(FILE ** const result, wchar_t const * const file, wchar_t const * const mode)
	{
		return __crt_state_management::wrapped_invoke(_wfopen_s, result, file, mode);
	}
	_CRTIMP FILE * __cdecl _o__wfreopen(wchar_t const * const file_name, wchar_t const * const mode, FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(_wfreopen, file_name, mode, public_stream);
	}
	_CRTIMP errno_t __cdecl _o__wfreopen_s(FILE ** const result, wchar_t const * const file_name, wchar_t const * const mode, FILE * const public_stream)
	{
		return __crt_state_management::wrapped_invoke(_wfreopen_s, result, file_name, mode, public_stream);
	}
	_CRTIMP FILE * __cdecl _o__wfsopen(wchar_t const * const file, wchar_t const * const mode, int const share_flag)
	{
		return __crt_state_management::wrapped_invoke(_wfsopen, file, mode, share_flag);
	}
	_CRTIMP wchar_t * __cdecl _o__wfullpath(wchar_t * const user_buffer, wchar_t const * const path, size_t const max_count)
	{
		return __crt_state_management::wrapped_invoke(_wfullpath, user_buffer, path, max_count);
	}
	_CRTIMP wchar_t * __cdecl _o__wgetcwd(wchar_t * const user_buffer, int const max_length)
	{
		return __crt_state_management::wrapped_invoke(_wgetcwd, user_buffer, max_length);
	}
	_CRTIMP wchar_t * __cdecl _o__wgetdcwd(int const drive_number, wchar_t * const user_buffer, int const max_length)
	{
		return __crt_state_management::wrapped_invoke(_wgetdcwd, drive_number, user_buffer, max_length);
	}
	_CRTIMP wchar_t * __cdecl _o__wgetenv(wchar_t const * const name)
	{
		return __crt_state_management::wrapped_invoke(_wgetenv, name);
	}
	_CRTIMP errno_t __cdecl _o__wgetenv_s(size_t * const required_count, wchar_t * const buffer, size_t const buffer_count, wchar_t const * const name)
	{
		return __crt_state_management::wrapped_invoke(_wgetenv_s, required_count, buffer, buffer_count, name);
	}
	_CRTIMP void __cdecl _o__wmakepath(wchar_t * const result_buffer, wchar_t const * const drive, wchar_t const * const directory, wchar_t const * const file_name, wchar_t const * const extension)
	{
		return __crt_state_management::wrapped_invoke_void(_wmakepath, result_buffer, drive, directory, file_name, extension);
	}
	_CRTIMP errno_t __cdecl _o__wmakepath_s(wchar_t * const result_buffer, size_t const result_count, wchar_t const * const drive, wchar_t const * const directory, wchar_t const * const file_name, wchar_t const * const extension)
	{
		return __crt_state_management::wrapped_invoke(_wmakepath_s, result_buffer, result_count, drive, directory, file_name, extension);
	}
	_CRTIMP errno_t __cdecl _o_wmemcpy_s(wchar_t * const destination, size_t const size_in_elements, wchar_t const * const source, size_t const count)
	{
		return __crt_state_management::wrapped_invoke(wmemcpy_s, destination, size_in_elements, source, count);
	}
	_CRTIMP errno_t __cdecl _o_wmemmove_s(wchar_t * const destination, size_t const size_in_elements, wchar_t const * const source, size_t const count)
	{
		return __crt_state_management::wrapped_invoke(wmemmove_s, destination, size_in_elements, source, count);
	}
	_CRTIMP int __cdecl _o__wmkdir(wchar_t const * const path)
	{
		return __crt_state_management::wrapped_invoke(_wmkdir, path);
	}
	_CRTIMP wchar_t * __cdecl _o__wmktemp(wchar_t * const template_string)
	{
		return __crt_state_management::wrapped_invoke(_wmktemp, template_string);
	}
	_CRTIMP errno_t __cdecl _o__wmktemp_s(wchar_t * const template_string, size_t const buffer_size_in_chars)
	{
		return __crt_state_management::wrapped_invoke(_wmktemp_s, template_string, buffer_size_in_chars);
	}
	_CRTIMP void __cdecl _o__wperror(wchar_t const * const wide_user_prefix)
	{
		return __crt_state_management::wrapped_invoke_void(_wperror, wide_user_prefix);
	}
	_CRTIMP FILE * __cdecl _o__wpopen(wchar_t const * const command, wchar_t const * const type)
	{
		return __crt_state_management::wrapped_invoke(_wpopen, command, type);
	}
	_CRTIMP int __cdecl _o__wputenv(wchar_t const * const option)
	{
		return __crt_state_management::wrapped_invoke(_wputenv, option);
	}
	_CRTIMP errno_t __cdecl _o__wputenv_s(wchar_t const * const name, wchar_t const * const value)
	{
		return __crt_state_management::wrapped_invoke(_wputenv_s, name, value);
	}
	_CRTIMP int __cdecl _o__wremove(wchar_t const * const path)
	{
		return __crt_state_management::wrapped_invoke(_wremove, path);
	}
	_CRTIMP int __cdecl _o__wrename(wchar_t const * const old_name, wchar_t const * const new_name)
	{
		return __crt_state_management::wrapped_invoke(_wrename, old_name, new_name);
	}
	_CRTIMP int __cdecl _o__write(int const fh, void const * const buffer, unsigned const size)
	{
		return __crt_state_management::wrapped_invoke(_write, fh, buffer, size);
	}
	_CRTIMP int __cdecl _o__wrmdir(wchar_t const * const path)
	{
		return __crt_state_management::wrapped_invoke(_wrmdir, path);
	}
	_CRTIMP void __cdecl _o__wsearchenv(wchar_t const * const file_name, wchar_t const * const environment_variable, wchar_t * const result_buffer)
	{
		return __crt_state_management::wrapped_invoke_void(_wsearchenv, file_name, environment_variable, result_buffer);
	}
	_CRTIMP errno_t __cdecl _o__wsearchenv_s(wchar_t const * const file_name, wchar_t const * const environment_variable, wchar_t * const result_buffer, size_t const result_count)
	{
		return __crt_state_management::wrapped_invoke(_wsearchenv_s, file_name, environment_variable, result_buffer, result_count);
	}
	_CRTIMP wchar_t * __cdecl _o__wsetlocale(int _category, const wchar_t * _wlocale)
	{
		return __crt_state_management::wrapped_invoke(_wsetlocale, _category, _wlocale);
	}
	_CRTIMP errno_t __cdecl _o__wsopen_dispatch(wchar_t const * const path, int const oflag, int const shflag, int const pmode, int * const pfh, int const secure)
	{
		return __crt_state_management::wrapped_invoke(_wsopen_dispatch, path, oflag, shflag, pmode, pfh, secure);
	}
	_CRTIMP errno_t __cdecl _o__wsopen_s(int * const pfh, wchar_t const * const path, int const oflag, int const shflag, int const pmode)
	{
		return __crt_state_management::wrapped_invoke(_wsopen_s, pfh, path, oflag, shflag, pmode);
	}
	_CRTIMP intptr_t __cdecl _o__wspawnv(int const mode, wchar_t const * const file_name, wchar_t const * const * const arguments)
	{
		return __crt_state_management::wrapped_invoke(_wspawnv, mode, file_name, arguments);
	}
	_CRTIMP intptr_t __cdecl _o__wspawnve(int const mode, wchar_t const * const file_name, wchar_t const * const * const arguments, wchar_t const * const * const environment)
	{
		return __crt_state_management::wrapped_invoke(_wspawnve, mode, file_name, arguments, environment);
	}
	_CRTIMP intptr_t __cdecl _o__wspawnvp(int const mode, wchar_t const * const file_name, wchar_t const * const * const arguments)
	{
		return __crt_state_management::wrapped_invoke(_wspawnvp, mode, file_name, arguments);
	}
	_CRTIMP intptr_t __cdecl _o__wspawnvpe(int const mode, wchar_t const * const file_name, wchar_t const * const * const arguments, wchar_t const * const * const environment)
	{
		return __crt_state_management::wrapped_invoke(_wspawnvpe, mode, file_name, arguments, environment);
	}
	_CRTIMP void __cdecl _o__wsplitpath(wchar_t const * const path, wchar_t * const drive, wchar_t * const directory, wchar_t * const file_name, wchar_t * const extension)
	{
		return __crt_state_management::wrapped_invoke_void(_wsplitpath, path, drive, directory, file_name, extension);
	}
	_CRTIMP errno_t __cdecl _o__wsplitpath_s(wchar_t const * const path, wchar_t * const drive, size_t const drive_count, wchar_t * const directory, size_t const directory_count, wchar_t * const file_name, size_t const file_name_count, wchar_t * const extension, size_t const extension_count)
	{
		return __crt_state_management::wrapped_invoke(_wsplitpath_s, path, drive, drive_count, directory, directory_count, file_name, file_name_count, extension, extension_count);
	}
	_CRTIMP int __cdecl _o__wstat32(wchar_t const * const path, struct _stat32 * const result)
	{
		return __crt_state_management::wrapped_invoke(_wstat32, path, result);
	}
	_CRTIMP int __cdecl _o__wstat32i64(wchar_t const * const path, struct _stat32i64 * const result)
	{
		return __crt_state_management::wrapped_invoke(_wstat32i64, path, result);
	}
	_CRTIMP int __cdecl _o__wstat64(wchar_t const * const path, struct _stat64 * const result)
	{
		return __crt_state_management::wrapped_invoke(_wstat64, path, result);
	}
	_CRTIMP int __cdecl _o__wstat64i32(wchar_t const * const path, struct _stat64i32 * const result)
	{
		return __crt_state_management::wrapped_invoke(_wstat64i32, path, result);
	}
	_CRTIMP wchar_t * __cdecl _o__wstrdate(wchar_t * const buffer)
	{
		return __crt_state_management::wrapped_invoke(_wstrdate, buffer);
	}
	_CRTIMP errno_t __cdecl _o__wstrdate_s(wchar_t * const buffer, size_t const size_in_chars)
	{
		return __crt_state_management::wrapped_invoke(_wstrdate_s, buffer, size_in_chars);
	}
	_CRTIMP wchar_t * __cdecl _o__wstrtime(wchar_t * const buffer)
	{
		return __crt_state_management::wrapped_invoke(_wstrtime, buffer);
	}
	_CRTIMP errno_t __cdecl _o__wstrtime_s(wchar_t * const buffer, size_t const size_in_chars)
	{
		return __crt_state_management::wrapped_invoke(_wstrtime_s, buffer, size_in_chars);
	}
	_CRTIMP int __cdecl _o__wsystem(wchar_t const * const command)
	{
		return __crt_state_management::wrapped_invoke(_wsystem, command);
	}
	_CRTIMP errno_t __cdecl _o__wtmpnam_s(wchar_t * const result_buffer, size_t const result_buffer_count)
	{
		return __crt_state_management::wrapped_invoke(_wtmpnam_s, result_buffer, result_buffer_count);
	}
	_CRTIMP double __cdecl _o__wtof(wchar_t const * const string)
	{
		return __crt_state_management::wrapped_invoke(_wtof, string);
	}
	_CRTIMP double __cdecl _o__wtof_l(wchar_t const * const string, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_wtof_l, string, locale);
	}
	_CRTIMP int __cdecl _o__wtoi(wchar_t const * const string)
	{
		return __crt_state_management::wrapped_invoke(_wtoi, string);
	}
	_CRTIMP int __cdecl _o__wtoi_l(wchar_t const * const string, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_wtoi_l, string, locale);
	}
	_CRTIMP __int64 __cdecl _o__wtoi64(wchar_t const * const string)
	{
		return __crt_state_management::wrapped_invoke(_wtoi64, string);
	}
	_CRTIMP __int64 __cdecl _o__wtoi64_l(wchar_t const * const string, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_wtoi64_l, string, locale);
	}
	_CRTIMP long __cdecl _o__wtol(wchar_t const * const string)
	{
		return __crt_state_management::wrapped_invoke(_wtol, string);
	}
	_CRTIMP long __cdecl _o__wtol_l(wchar_t const * const string, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_wtol_l, string, locale);
	}
	_CRTIMP long long __cdecl _o__wtoll(wchar_t const * const string)
	{
		return __crt_state_management::wrapped_invoke(_wtoll, string);
	}
	_CRTIMP long long __cdecl _o__wtoll_l(wchar_t const * const string, _locale_t const locale)
	{
		return __crt_state_management::wrapped_invoke(_wtoll_l, string, locale);
	}
	_CRTIMP int __cdecl _o__wunlink(wchar_t const * const path)
	{
		return __crt_state_management::wrapped_invoke(_wunlink, path);
	}
	_CRTIMP int __cdecl _o__wutime32(wchar_t const * const file_name, __utimbuf32 * const times)
	{
		return __crt_state_management::wrapped_invoke(_wutime32, file_name, times);
	}
	_CRTIMP int __cdecl _o__wutime64(wchar_t const * const file_name, __utimbuf64 * const times)
	{
		return __crt_state_management::wrapped_invoke(_wutime64, file_name, times);
	}

	//math
	_CRTIMP double __cdecl _o_acos(double _X)
	{
		return __crt_state_management::wrapped_invoke(acos, _X);
	}
	_CRTIMP double __cdecl _o_acosh(double _X)
	{
		return __crt_state_management::wrapped_invoke(acosh, _X);
	}
	_CRTIMP float __cdecl _o_acoshf(float _X)
	{
		return __crt_state_management::wrapped_invoke(acoshf, _X);
	}
	_CRTIMP long double __cdecl _o_acoshl(long double _X)
	{
		return __crt_state_management::wrapped_invoke(acoshl, _X);
	}
	_CRTIMP double __cdecl _o_asin(double _X)
	{
		return __crt_state_management::wrapped_invoke(asin, _X);
	}
	_CRTIMP double __cdecl _o_asinh(double _X)
	{
		return __crt_state_management::wrapped_invoke(asinh, _X);
	}
	_CRTIMP float __cdecl _o_asinhf(float _X)
	{
		return __crt_state_management::wrapped_invoke(asinhf, _X);
	}
	_CRTIMP long double __cdecl _o_asinhl(long double _X)
	{
		return __crt_state_management::wrapped_invoke(asinhl, _X);
	}
	_CRTIMP double __cdecl _o_atan(double _X)
	{
		return __crt_state_management::wrapped_invoke(atan, _X);
	}
	_CRTIMP double __cdecl _o_atan2(double _Y, double _X)
	{
		return __crt_state_management::wrapped_invoke(atan2, _Y, _X);
	}
	_CRTIMP double __cdecl _o_atanh(double _X)
	{
		return __crt_state_management::wrapped_invoke(atanh, _X);
	}
	_CRTIMP float __cdecl _o_atanhf(float _X)
	{
		return __crt_state_management::wrapped_invoke(atanhf, _X);
	}
	_CRTIMP long double __cdecl _o_atanhl(long double _X)
	{
		return __crt_state_management::wrapped_invoke(atanhl, _X);
	}
	_CRTIMP double __cdecl _o__cabs(_complex _Complex_value)
	{
		return __crt_state_management::wrapped_invoke(_cabs, _Complex_value);
	}
	_CRTIMP double __cdecl _o_cbrt(double _X)
	{
		return __crt_state_management::wrapped_invoke(cbrt, _X);
	}
	_CRTIMP float __cdecl _o_cbrtf(float _X)
	{
		return __crt_state_management::wrapped_invoke(cbrtf, _X);
	}
	_CRTIMP double __cdecl _o_ceil(double _X)
	{
		return __crt_state_management::wrapped_invoke(ceil, _X);
	}
	_CRTIMP double __cdecl _o_cos(double _X)
	{
		return __crt_state_management::wrapped_invoke(cos, _X);
	}
	_CRTIMP double __cdecl _o_cosh(double _X)
	{
		return __crt_state_management::wrapped_invoke(cosh, _X);
	}
	_CRTIMP short __cdecl _o__d_int(double * _Px, short _Xexp)
	{
		return __crt_state_management::wrapped_invoke(_d_int, _Px, _Xexp);
	}
	_CRTIMP short __cdecl _o__dclass(double _X)
	{
		return __crt_state_management::wrapped_invoke(_dclass, _X);
	}
	_CRTIMP double __cdecl _o__dlog(double _X, int _Baseflag)
	{
		return __crt_state_management::wrapped_invoke(_dlog, _X, _Baseflag);
	}
	_CRTIMP short __cdecl _o__dnorm(unsigned short * _Ps)
	{
		return __crt_state_management::wrapped_invoke(_dnorm, _Ps);
	}
	_CRTIMP int __cdecl _o__dpcomp(double _X, double _Y)
	{
		return __crt_state_management::wrapped_invoke(_dpcomp, _X, _Y);
	}
	_CRTIMP double __cdecl _o__dpoly(double _X, double const * _Tab, int _N)
	{
		return __crt_state_management::wrapped_invoke(_dpoly, _X, _Tab, _N);
	}
	_CRTIMP short __cdecl _o__dscale(double * _Px, long _Lexp)
	{
		return __crt_state_management::wrapped_invoke(_dscale, _Px, _Lexp);
	}
	_CRTIMP int __cdecl _o__dsign(double _X)
	{
		return __crt_state_management::wrapped_invoke(_dsign, _X);
	}
	_CRTIMP double __cdecl _o__dsin(double _X, unsigned int _Qoff)
	{
		return __crt_state_management::wrapped_invoke(_dsin, _X, _Qoff);
	}
	_CRTIMP short __cdecl _o__dtest(double * _Px)
	{
		return __crt_state_management::wrapped_invoke(_dtest, _Px);
	}
	_CRTIMP short __cdecl _o__dunscale(short * _Pex, double * _Px)
	{
		return __crt_state_management::wrapped_invoke(_dunscale, _Pex, _Px);
	}
	_CRTIMP double __cdecl _o_erf(double _X)
	{
		return __crt_state_management::wrapped_invoke(erf, _X);
	}
	_CRTIMP double __cdecl _o_erfc(double _X)
	{
		return __crt_state_management::wrapped_invoke(erfc, _X);
	}
	_CRTIMP float __cdecl _o_erfcf(float _X)
	{
		return __crt_state_management::wrapped_invoke(erfcf, _X);
	}
	_CRTIMP long double __cdecl _o_erfcl(long double _X)
	{
		return __crt_state_management::wrapped_invoke(erfcl, _X);
	}
	_CRTIMP float __cdecl _o_erff(float _X)
	{
		return __crt_state_management::wrapped_invoke(erff, _X);
	}
	_CRTIMP long double __cdecl _o_erfl(long double _X)
	{
		return __crt_state_management::wrapped_invoke(erfl, _X);
	}
	_CRTIMP double __cdecl _o_exp(double _X)
	{
		return __crt_state_management::wrapped_invoke(exp, _X);
	}
	_CRTIMP double __cdecl _o_exp2(double _X)
	{
		return __crt_state_management::wrapped_invoke(exp2, _X);
	}
	_CRTIMP float __cdecl _o_exp2f(float _X)
	{
		return __crt_state_management::wrapped_invoke(exp2f, _X);
	}
	_CRTIMP long double __cdecl _o_exp2l(long double _X)
	{
		return __crt_state_management::wrapped_invoke(exp2l, _X);
	}
	_CRTIMP double __cdecl _o_fabs(double _X)
	{
		return __crt_state_management::wrapped_invoke(fabs, _X);
	}
	_CRTIMP short __cdecl _o__fd_int(float * _Px, short _Xexp)
	{
		return __crt_state_management::wrapped_invoke(_fd_int, _Px, _Xexp);
	}
	_CRTIMP short __cdecl _o__fdclass(float _X)
	{
		return __crt_state_management::wrapped_invoke(_fdclass, _X);
	}
	_CRTIMP short __cdecl _o__fdexp(float * _Px, float _Y, long _Eoff)
	{
		return __crt_state_management::wrapped_invoke(_fdexp, _Px, _Y, _Eoff);
	}
	_CRTIMP float __cdecl _o__fdlog(float _X, int _Baseflag)
	{
		return __crt_state_management::wrapped_invoke(_fdlog, _X, _Baseflag);
	}
	_CRTIMP int __cdecl _o__fdpcomp(float _X, float _Y)
	{
		return __crt_state_management::wrapped_invoke(_fdpcomp, _X, _Y);
	}
	_CRTIMP float __cdecl _o__fdpoly(float _X, float const * _Tab, int _N)
	{
		return __crt_state_management::wrapped_invoke(_fdpoly, _X, _Tab, _N);
	}
	_CRTIMP short __cdecl _o__fdscale(float * _Px, long _Lexp)
	{
		return __crt_state_management::wrapped_invoke(_fdscale, _Px, _Lexp);
	}
	_CRTIMP int __cdecl _o__fdsign(float _X)
	{
		return __crt_state_management::wrapped_invoke(_fdsign, _X);
	}
	_CRTIMP float __cdecl _o__fdsin(float _X, unsigned int _Qoff)
	{
		return __crt_state_management::wrapped_invoke(_fdsin, _X, _Qoff);
	}
	_CRTIMP double __cdecl _o_floor(double _X)
	{
		return __crt_state_management::wrapped_invoke(floor, _X);
	}
	_CRTIMP double __cdecl _o_fma(double _X, double _Y, double _Z)
	{
		return __crt_state_management::wrapped_invoke(fma, _X, _Y, _Z);
	}
	_CRTIMP float __cdecl _o_fmaf(float _X, float _Y, float _Z)
	{
		return __crt_state_management::wrapped_invoke(fmaf, _X, _Y, _Z);
	}
	_CRTIMP long double __cdecl _o_fmal(long double _X, long double _Y, long double _Z)
	{
		return __crt_state_management::wrapped_invoke(fmal, _X, _Y, _Z);
	}
	_CRTIMP double __cdecl _o_fmod(double _X, double _Y)
	{
		return __crt_state_management::wrapped_invoke(fmod, _X, _Y);
	}
	_CRTIMP double __cdecl _o_frexp(double _X, int * _Y)
	{
		return __crt_state_management::wrapped_invoke(frexp, _X, _Y);
	}
	_CRTIMP double __cdecl _o__hypot(double _X, double _Y)
	{
		return __crt_state_management::wrapped_invoke(_hypot, _X, _Y);
	}
	_CRTIMP double __cdecl _o_hypot(double _X, double _Y)
	{
		return __crt_state_management::wrapped_invoke(hypot, _X, _Y);
	}
	_CRTIMP float __cdecl _o__hypotf(float _X, float _Y)
	{
		return __crt_state_management::wrapped_invoke(_hypotf, _X, _Y);
	}
	_CRTIMP double __cdecl _o__j0(double _X)
	{
		return __crt_state_management::wrapped_invoke(_j0, _X);
	}
	_CRTIMP double __cdecl _o__j1(double _X)
	{
		return __crt_state_management::wrapped_invoke(_j1, _X);
	}
	_CRTIMP double __cdecl _o__jn(int _X, double _Y)
	{
		return __crt_state_management::wrapped_invoke(_jn, _X, _Y);
	}
	_CRTIMP short __cdecl _o__ld_int(long double * _Px, short _Xexp)
	{
		return __crt_state_management::wrapped_invoke(_ld_int, _Px, _Xexp);
	}
	_CRTIMP short __cdecl _o__ldclass(long double _X)
	{
		return __crt_state_management::wrapped_invoke(_ldclass, _X);
	}
	_CRTIMP short __cdecl _o__ldexp(long double * _Px, long double _Y, long _Eoff)
	{
		return __crt_state_management::wrapped_invoke(_ldexp, _Px, _Y, _Eoff);
	}
	_CRTIMP double __cdecl _o_ldexp(double _X, int _Y)
	{
		return __crt_state_management::wrapped_invoke(ldexp, _X, _Y);
	}
	_CRTIMP long double __cdecl _o__ldlog(long double _X, int _Baseflag)
	{
		return __crt_state_management::wrapped_invoke(_ldlog, _X, _Baseflag);
	}
	_CRTIMP int __cdecl _o__ldpcomp(long double _X, long double _Y)
	{
		return __crt_state_management::wrapped_invoke(_ldpcomp, _X, _Y);
	}
	_CRTIMP long double __cdecl _o__ldpoly(long double _X, long double const * _Tab, int _N)
	{
		return __crt_state_management::wrapped_invoke(_ldpoly, _X, _Tab, _N);
	}
	_CRTIMP short __cdecl _o__ldscale(long double * _Px, long _Lexp)
	{
		return __crt_state_management::wrapped_invoke(_ldscale, _Px, _Lexp);
	}
	_CRTIMP int __cdecl _o__ldsign(long double _X)
	{
		return __crt_state_management::wrapped_invoke(_ldsign, _X);
	}
	_CRTIMP long double __cdecl _o__ldsin(long double _X, unsigned int _Qoff)
	{
		return __crt_state_management::wrapped_invoke(_ldsin, _X, _Qoff);
	}
	_CRTIMP short __cdecl _o__ldtest(long double * _Px)
	{
		return __crt_state_management::wrapped_invoke(_ldtest, _Px);
	}
	_CRTIMP short __cdecl _o__ldunscale(short * _Pex, long double * _Px)
	{
		return __crt_state_management::wrapped_invoke(_ldunscale, _Pex, _Px);
	}
	_CRTIMP double __cdecl _o_lgamma(double _X)
	{
		return __crt_state_management::wrapped_invoke(lgamma, _X);
	}
	_CRTIMP float __cdecl _o_lgammaf(float _X)
	{
		return __crt_state_management::wrapped_invoke(lgammaf, _X);
	}
	_CRTIMP long double __cdecl _o_lgammal(long double _X)
	{
		return __crt_state_management::wrapped_invoke(lgammal, _X);
	}
	_CRTIMP long long __cdecl _o_llrint(double _X)
	{
		return __crt_state_management::wrapped_invoke(llrint, _X);
	}
	_CRTIMP long long __cdecl _o_llrintf(float _X)
	{
		return __crt_state_management::wrapped_invoke(llrintf, _X);
	}
	_CRTIMP long long __cdecl _o_llrintl(long double _X)
	{
		return __crt_state_management::wrapped_invoke(llrintl, _X);
	}
	_CRTIMP long long __cdecl _o_llround(double _X)
	{
		return __crt_state_management::wrapped_invoke(llround, _X);
	}
	_CRTIMP long long __cdecl _o_llroundf(float _X)
	{
		return __crt_state_management::wrapped_invoke(llroundf, _X);
	}
	_CRTIMP long long __cdecl _o_llroundl(long double _X)
	{
		return __crt_state_management::wrapped_invoke(llroundl, _X);
	}
	_CRTIMP double __cdecl _o_log(double _X)
	{
		return __crt_state_management::wrapped_invoke(log, _X);
	}
	_CRTIMP double __cdecl _o_log10(double _X)
	{
		return __crt_state_management::wrapped_invoke(log10, _X);
	}
	_CRTIMP double __cdecl _o_log1p(double _X)
	{
		return __crt_state_management::wrapped_invoke(log1p, _X);
	}
	_CRTIMP float __cdecl _o_log1pf(float _X)
	{
		return __crt_state_management::wrapped_invoke(log1pf, _X);
	}
	_CRTIMP long double __cdecl _o_log1pl(long double _X)
	{
		return __crt_state_management::wrapped_invoke(log1pl, _X);
	}
	_CRTIMP double __cdecl _o_log2(double _X)
	{
		return __crt_state_management::wrapped_invoke(log2, _X);
	}
	_CRTIMP float __cdecl _o_log2f(float _X)
	{
		return __crt_state_management::wrapped_invoke(log2f, _X);
	}
	_CRTIMP long double __cdecl _o_log2l(long double _X)
	{
		return __crt_state_management::wrapped_invoke(log2l, _X);
	}
	_CRTIMP double __cdecl _o_logb(double _X)
	{
		return __crt_state_management::wrapped_invoke(logb, _X);
	}
	_CRTIMP float __cdecl _o_logbf(float _X)
	{
		return __crt_state_management::wrapped_invoke(logbf, _X);
	}
	_CRTIMP long double __cdecl _o_logbl(long double _X)
	{
		return __crt_state_management::wrapped_invoke(logbl, _X);
	}
	_CRTIMP long __cdecl _o_lrint(double _X)
	{
		return __crt_state_management::wrapped_invoke(lrint, _X);
	}
	_CRTIMP long __cdecl _o_lrintf(float _X)
	{
		return __crt_state_management::wrapped_invoke(lrintf, _X);
	}
	_CRTIMP long __cdecl _o_lrintl(long double _X)
	{
		return __crt_state_management::wrapped_invoke(lrintl, _X);
	}
	_CRTIMP long __cdecl _o_lround(double _X)
	{
		return __crt_state_management::wrapped_invoke(lround, _X);
	}
	_CRTIMP long __cdecl _o_lroundf(float _X)
	{
		return __crt_state_management::wrapped_invoke(lroundf, _X);
	}
	_CRTIMP long __cdecl _o_lroundl(long double _X)
	{
		return __crt_state_management::wrapped_invoke(lroundl, _X);
	}
	_CRTIMP double __cdecl _o_modf(double _X, double * _Y)
	{
		return __crt_state_management::wrapped_invoke(modf, _X, _Y);
	}
	_CRTIMP double __cdecl _o_nan(char const * _X)
	{
		return __crt_state_management::wrapped_invoke(nan, _X);
	}
	_CRTIMP float __cdecl _o_nanf(char const * _X)
	{
		return __crt_state_management::wrapped_invoke(nanf, _X);
	}
	_CRTIMP long double __cdecl _o_nanl(char const * _X)
	{
		return __crt_state_management::wrapped_invoke(nanl, _X);
	}
	_CRTIMP double __cdecl _o_nearbyint(double _X)
	{
		return __crt_state_management::wrapped_invoke(nearbyint, _X);
	}
	_CRTIMP float __cdecl _o_nearbyintf(float _X)
	{
		return __crt_state_management::wrapped_invoke(nearbyintf, _X);
	}
	_CRTIMP long double __cdecl _o_nearbyintl(long double _X)
	{
		return __crt_state_management::wrapped_invoke(nearbyintl, _X);
	}
	_CRTIMP double __cdecl _o_nextafter(double _X, double _Y)
	{
		return __crt_state_management::wrapped_invoke(nextafter, _X, _Y);
	}
	_CRTIMP float __cdecl _o_nextafterf(float _X, float _Y)
	{
		return __crt_state_management::wrapped_invoke(nextafterf, _X, _Y);
	}
	_CRTIMP long double __cdecl _o_nextafterl(long double _X, long double _Y)
	{
		return __crt_state_management::wrapped_invoke(nextafterl, _X, _Y);
	}
	_CRTIMP double __cdecl _o_nexttoward(double _X, long double _Y)
	{
		return __crt_state_management::wrapped_invoke(nexttoward, _X, _Y);
	}
	_CRTIMP float __cdecl _o_nexttowardf(float _X, long double _Y)
	{
		return __crt_state_management::wrapped_invoke(nexttowardf, _X, _Y);
	}
	_CRTIMP long double __cdecl _o_nexttowardl(long double _X, long double _Y)
	{
		return __crt_state_management::wrapped_invoke(nexttowardl, _X, _Y);
	}
	_CRTIMP double __cdecl _o_pow(double _X, double _Y)
	{
		return __crt_state_management::wrapped_invoke(pow, _X, _Y);
	}
	_CRTIMP float __cdecl _o_powf(float _X, float _Y)
	{
		return __crt_state_management::wrapped_invoke(powf, _X, _Y);
	}
	_CRTIMP double __cdecl _o_remainder(double _X, double _Y)
	{
		return __crt_state_management::wrapped_invoke(remainder, _X, _Y);
	}
	_CRTIMP float __cdecl _o_remainderf(float _X, float _Y)
	{
		return __crt_state_management::wrapped_invoke(remainderf, _X, _Y);
	}
	_CRTIMP long double __cdecl _o_remainderl(long double _X, long double _Y)
	{
		return __crt_state_management::wrapped_invoke(remainderl, _X, _Y);
	}
	_CRTIMP double __cdecl _o_remquo(double _X, double _Y, int * _Z)
	{
		return __crt_state_management::wrapped_invoke(remquo, _X, _Y, _Z);
	}
	_CRTIMP float __cdecl _o_remquof(float _X, float _Y, int * _Z)
	{
		return __crt_state_management::wrapped_invoke(remquof, _X, _Y, _Z);
	}
	_CRTIMP long double __cdecl _o_remquol(long double _X, long double _Y, int * _Z)
	{
		return __crt_state_management::wrapped_invoke(remquol, _X, _Y, _Z);
	}
	_CRTIMP double __cdecl _o_rint(double _X)
	{
		return __crt_state_management::wrapped_invoke(rint, _X);
	}
	_CRTIMP float __cdecl _o_rintf(float _X)
	{
		return __crt_state_management::wrapped_invoke(rintf, _X);
	}
	_CRTIMP long double __cdecl _o_rintl(long double _X)
	{
		return __crt_state_management::wrapped_invoke(rintl, _X);
	}
	_CRTIMP double __cdecl _o_round(double _X)
	{
		return __crt_state_management::wrapped_invoke(round, _X);
	}
	_CRTIMP float __cdecl _o_roundf(float _X)
	{
		return __crt_state_management::wrapped_invoke(roundf, _X);
	}
	_CRTIMP long double __cdecl _o_roundl(long double _X)
	{
		return __crt_state_management::wrapped_invoke(roundl, _X);
	}
	_CRTIMP double __cdecl _o_scalbln(double _X, long _Y)
	{
		return __crt_state_management::wrapped_invoke(scalbln, _X, _Y);
	}
	_CRTIMP float __cdecl _o_scalblnf(float _X, long _Y)
	{
		return __crt_state_management::wrapped_invoke(scalblnf, _X, _Y);
	}
	_CRTIMP long double __cdecl _o_scalblnl(long double _X, long _Y)
	{
		return __crt_state_management::wrapped_invoke(scalblnl, _X, _Y);
	}
	_CRTIMP double __cdecl _o_scalbn(double _X, int _Y)
	{
		return __crt_state_management::wrapped_invoke(scalbn, _X, _Y);
	}
	_CRTIMP float __cdecl _o_scalbnf(float _X, int _Y)
	{
		return __crt_state_management::wrapped_invoke(scalbnf, _X, _Y);
	}
	_CRTIMP long double __cdecl _o_scalbnl(long double _X, int _Y)
	{
		return __crt_state_management::wrapped_invoke(scalbnl, _X, _Y);
	}
	_CRTIMP double __cdecl _o_sin(double _X)
	{
		return __crt_state_management::wrapped_invoke(sin, _X);
	}
	_CRTIMP double __cdecl _o_sinh(double _X)
	{
		return __crt_state_management::wrapped_invoke(sinh, _X);
	}
	_CRTIMP double __cdecl _o_sqrt(double _X)
	{
		return __crt_state_management::wrapped_invoke(sqrt, _X);
	}
	_CRTIMP double __cdecl _o_tan(double _X)
	{
		return __crt_state_management::wrapped_invoke(tan, _X);
	}
	_CRTIMP double __cdecl _o_tanh(double _X)
	{
		return __crt_state_management::wrapped_invoke(tanh, _X);
	}
	_CRTIMP double __cdecl _o_tgamma(double _X)
	{
		return __crt_state_management::wrapped_invoke(tgamma, _X);
	}
	_CRTIMP float __cdecl _o_tgammaf(float _X)
	{
		return __crt_state_management::wrapped_invoke(tgammaf, _X);
	}
	_CRTIMP long double __cdecl _o_tgammal(long double _X)
	{
		return __crt_state_management::wrapped_invoke(tgammal, _X);
	}
	_CRTIMP double __cdecl _o__y0(double _X)
	{
		return __crt_state_management::wrapped_invoke(_y0, _X);
	}
	_CRTIMP double __cdecl _o__y1(double _X)
	{
		return __crt_state_management::wrapped_invoke(_y1, _X);
	}
	_CRTIMP double __cdecl _o__yn(int _X, double _Y)
	{
		return __crt_state_management::wrapped_invoke(_yn, _X, _Y);
	}

	//misc
	_CRTIMP errno_t __cdecl _o__controlfp_s(unsigned int * _CurrentState, unsigned int _NewValue, unsigned int _Mask)
	{
		return __crt_state_management::wrapped_invoke(_controlfp_s, _CurrentState, _NewValue, _Mask);
	}
	_CRTIMP int __cdecl _o__fpclass(double _X)
	{
		return __crt_state_management::wrapped_invoke(_fpclass, _X);
	}
#ifdef _M_X64
	_CRTIMP float __cdecl _o__scalbf(_In_ float _X, _In_ long _Y)
	{
		return __crt_state_management::wrapped_invoke(_scalbf, _X, _Y);
	}
#endif
	_CRTIMP int __cdecl _o___fpe_flt_rounds(void)
	{
		return __crt_state_management::wrapped_invoke(__fpe_flt_rounds);
	}
	_CRTIMP int __cdecl _o_isalnum(int _C)
	{
		return __crt_state_management::wrapped_invoke(isalnum, _C);
	}
	_CRTIMP int __cdecl _o_isalpha(int _C)
	{
		return __crt_state_management::wrapped_invoke(isalpha, _C);
	}
	_CRTIMP int __cdecl _o_isblank(int _C)
	{
		return __crt_state_management::wrapped_invoke(isblank, _C);
	}
	_CRTIMP int __cdecl _o_iscntrl(int _C)
	{
		return __crt_state_management::wrapped_invoke(iscntrl, _C);
	}
	_CRTIMP int __cdecl _o_isdigit(int _C)
	{
		return __crt_state_management::wrapped_invoke(isdigit, _C);
	}
	_CRTIMP int __cdecl _o_isgraph(int _C)
	{
		return __crt_state_management::wrapped_invoke(isgraph, _C);
	}
	_CRTIMP int __cdecl _o_isleadbyte(int _C)
	{
		return __crt_state_management::wrapped_invoke(isleadbyte, _C);
	}
	_CRTIMP int __cdecl _o__isleadbyte_l(int _C, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_isleadbyte_l, _C, _Locale);
	}
	_CRTIMP int __cdecl _o_islower(int _C)
	{
		return __crt_state_management::wrapped_invoke(islower, _C);
	}
	_CRTIMP int __cdecl _o__ismbbalnum(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_ismbbalnum, _C);
	}
	_CRTIMP int __cdecl _o__ismbbalnum_l(unsigned int _C, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbbalnum_l, _C, _Locale);
	}
	_CRTIMP int __cdecl _o__ismbbalpha(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_ismbbalpha, _C);
	}
	_CRTIMP int __cdecl _o__ismbbalpha_l(unsigned int _C, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbbalpha_l, _C, _Locale);
	}
	_CRTIMP int __cdecl _o__ismbbblank(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_ismbbblank, _C);
	}
	_CRTIMP int __cdecl _o__ismbbblank_l(unsigned int _C, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbbblank_l, _C, _Locale);
	}
	_CRTIMP int __cdecl _o__ismbbgraph(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_ismbbgraph, _C);
	}
	_CRTIMP int __cdecl _o__ismbbgraph_l(unsigned int _C, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbbgraph_l, _C, _Locale);
	}
	_CRTIMP int __cdecl _o__ismbbkalnum(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_ismbbkalnum, _C);
	}
	_CRTIMP int __cdecl _o__ismbbkalnum_l(unsigned int _C, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbbkalnum_l, _C, _Locale);
	}
	_CRTIMP int __cdecl _o__ismbbkana(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_ismbbkana, _C);
	}
	_CRTIMP int __cdecl _o__ismbbkana_l(unsigned int _C, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbbkana_l, _C, _Locale);
	}
	_CRTIMP int __cdecl _o__ismbbkprint(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_ismbbkprint, _C);
	}
	_CRTIMP int __cdecl _o__ismbbkprint_l(unsigned int _C, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbbkprint_l, _C, _Locale);
	}
	_CRTIMP int __cdecl _o__ismbbkpunct(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_ismbbkpunct, _C);
	}
	_CRTIMP int __cdecl _o__ismbbkpunct_l(unsigned int _C, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbbkpunct_l, _C, _Locale);
	}
	_CRTIMP int __cdecl _o__ismbblead(unsigned int _Ch)
	{
		return __crt_state_management::wrapped_invoke(_ismbblead, _Ch);
	}
	_CRTIMP int __cdecl _o__ismbblead_l(unsigned int _Ch, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbblead_l, _Ch, _Locale);
	}
	_CRTIMP int __cdecl _o__ismbbprint(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_ismbbprint, _C);
	}
	_CRTIMP int __cdecl _o__ismbbprint_l(unsigned int _C, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbbprint_l, _C, _Locale);
	}
	_CRTIMP int __cdecl _o__ismbbpunct(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_ismbbpunct, _C);
	}
	_CRTIMP int __cdecl _o__ismbbpunct_l(unsigned int _C, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbbpunct_l, _C, _Locale);
	}
	_CRTIMP int __cdecl _o__ismbbtrail(unsigned int _Ch)
	{
		return __crt_state_management::wrapped_invoke(_ismbbtrail, _Ch);
	}
	_CRTIMP int __cdecl _o__ismbbtrail_l(unsigned int _Ch, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_ismbbtrail_l, _Ch, _Locale);
	}
	_CRTIMP int __cdecl _o__ismbcl0(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_ismbcl0, _C);
	}
	_CRTIMP int __cdecl _o__ismbcl1(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_ismbcl1, _C);
	}
	_CRTIMP int __cdecl _o__ismbclegal(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_ismbclegal, _C);
	}
	_CRTIMP int __cdecl _o__ismbcsymbol(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_ismbcsymbol, _C);
	}
	_CRTIMP int __cdecl _o__ismbslead(unsigned char const * _String, unsigned char const * _Pos)
	{
		return __crt_state_management::wrapped_invoke(_ismbslead, _String, _Pos);
	}
	_CRTIMP int __cdecl _o_isprint(int _C)
	{
		return __crt_state_management::wrapped_invoke(isprint, _C);
	}
	_CRTIMP int __cdecl _o_ispunct(int _C)
	{
		return __crt_state_management::wrapped_invoke(ispunct, _C);
	}
	_CRTIMP int __cdecl _o_isspace(int _C)
	{
		return __crt_state_management::wrapped_invoke(isspace, _C);
	}
	_CRTIMP int __cdecl _o_isupper(int _C)
	{
		return __crt_state_management::wrapped_invoke(isupper, _C);
	}
	_CRTIMP int __cdecl _o_iswalnum(wint_t _C)
	{
		return __crt_state_management::wrapped_invoke(iswalnum, _C);
	}
	_CRTIMP int __cdecl _o_iswalpha(wint_t _C)
	{
		return __crt_state_management::wrapped_invoke(iswalpha, _C);
	}
	_CRTIMP int __cdecl _o_iswascii(wint_t _C)
	{
		return __crt_state_management::wrapped_invoke(iswascii, _C);
	}
	_CRTIMP int __cdecl _o_iswblank(wint_t _C)
	{
		return __crt_state_management::wrapped_invoke(iswblank, _C);
	}
	_CRTIMP int __cdecl _o_iswcntrl(wint_t _C)
	{
		return __crt_state_management::wrapped_invoke(iswcntrl, _C);
	}
	_CRTIMP int __cdecl _o_iswdigit(wint_t _C)
	{
		return __crt_state_management::wrapped_invoke(iswdigit, _C);
	}
	_CRTIMP int __cdecl _o_iswgraph(wint_t _C)
	{
		return __crt_state_management::wrapped_invoke(iswgraph, _C);
	}
	_CRTIMP int __cdecl _o_iswlower(wint_t _C)
	{
		return __crt_state_management::wrapped_invoke(iswlower, _C);
	}
	_CRTIMP int __cdecl _o_iswprint(wint_t _C)
	{
		return __crt_state_management::wrapped_invoke(iswprint, _C);
	}
	_CRTIMP int __cdecl _o_iswpunct(wint_t _C)
	{
		return __crt_state_management::wrapped_invoke(iswpunct, _C);
	}
	_CRTIMP int __cdecl _o_iswspace(wint_t _C)
	{
		return __crt_state_management::wrapped_invoke(iswspace, _C);
	}
	_CRTIMP int __cdecl _o_iswupper(wint_t _C)
	{
		return __crt_state_management::wrapped_invoke(iswupper, _C);
	}
	_CRTIMP int __cdecl _o_iswxdigit(wint_t _C)
	{
		return __crt_state_management::wrapped_invoke(iswxdigit, _C);
	}
	_CRTIMP int __cdecl _o_isxdigit(int _C)
	{
		return __crt_state_management::wrapped_invoke(isxdigit, _C);
	}
	_CRTIMP double __cdecl _o__logb(double _X)
	{
		return __crt_state_management::wrapped_invoke(_logb, _X);
	}
	_CRTIMP unsigned int __cdecl _o__mbbtombc(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_mbbtombc, _C);
	}
	_CRTIMP void __cdecl _o__mbccpy(unsigned char * _Dst, unsigned char const * _Src)
	{
		return __crt_state_management::wrapped_invoke_void(_mbccpy, _Dst, _Src);
	}
	_CRTIMP errno_t __cdecl _o__mbccpy_s(unsigned char * _Dst, size_t _SizeInBytes, int * _PCopied, unsigned char const * _Src)
	{
		return __crt_state_management::wrapped_invoke(_mbccpy_s, _Dst, _SizeInBytes, _PCopied, _Src);
	}
	_CRTIMP unsigned int __cdecl _o__mbcjistojms(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_mbcjistojms, _C);
	}
	_CRTIMP unsigned int __cdecl _o__mbcjmstojis(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_mbcjmstojis, _C);
	}
	_CRTIMP unsigned int __cdecl _o__mbctokata(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_mbctokata, _C);
	}
	_CRTIMP unsigned int __cdecl _o__mbctolower(unsigned int _Ch)
	{
		return __crt_state_management::wrapped_invoke(_mbctolower, _Ch);
	}
	_CRTIMP unsigned int __cdecl _o__mbctombb(unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_mbctombb, _C);
	}
	_CRTIMP unsigned int __cdecl _o__mbctoupper(unsigned int _Ch)
	{
		return __crt_state_management::wrapped_invoke(_mbctoupper, _Ch);
	}
	_CRTIMP errno_t __cdecl _o__mbscat_s(unsigned char * _Dst, size_t _SizeInBytes, unsigned char const * _Src)
	{
		return __crt_state_management::wrapped_invoke(_mbscat_s, _Dst, _SizeInBytes, _Src);
	}
	_CRTIMP const unsigned char * __cdecl _o__mbschr(unsigned char const * _Str, unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_mbschr, _Str, _C);
	}
	_CRTIMP int __cdecl _o__mbscmp(unsigned char const * _Str1, unsigned char const * _Str2)
	{
		return __crt_state_management::wrapped_invoke(_mbscmp, _Str1, _Str2);
	}
	_CRTIMP int __cdecl _o__mbscoll(unsigned char const * _Str1, unsigned char const * _Str2)
	{
		return __crt_state_management::wrapped_invoke(_mbscoll, _Str1, _Str2);
	}
	_CRTIMP errno_t __cdecl _o__mbscpy_s(unsigned char * _Dst, size_t _SizeInBytes, unsigned char const * _Src)
	{
		return __crt_state_management::wrapped_invoke(_mbscpy_s, _Dst, _SizeInBytes, _Src);
	}
	_CRTIMP size_t __cdecl _o__mbscspn(unsigned char const * _String, unsigned char const * _Control)
	{
		return __crt_state_management::wrapped_invoke(_mbscspn, _String, _Control);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsdec(unsigned char const * _Start, unsigned char const * _Pos)
	{
		return __crt_state_management::wrapped_invoke(_mbsdec, _Start, _Pos);
	}
	_CRTIMP int __cdecl _o__mbsicmp(unsigned char const * _Str1, unsigned char const * _Str2)
	{
		return __crt_state_management::wrapped_invoke(_mbsicmp, _Str1, _Str2);
	}
	_CRTIMP int __cdecl _o__mbsicoll(unsigned char const * _Str1, unsigned char const * _Str2)
	{
		return __crt_state_management::wrapped_invoke(_mbsicoll, _Str1, _Str2);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsinc(unsigned char const * _Ptr)
	{
		return __crt_state_management::wrapped_invoke(_mbsinc, _Ptr);
	}
	_CRTIMP size_t __cdecl _o__mbslen(unsigned char const * _String)
	{
		return __crt_state_management::wrapped_invoke(_mbslen, _String);
	}
	_CRTIMP errno_t __cdecl _o__mbslwr_s(unsigned char * _String, size_t _SizeInBytes)
	{
		return __crt_state_management::wrapped_invoke(_mbslwr_s, _String, _SizeInBytes);
	}
	_CRTIMP errno_t __cdecl _o__mbsnbcat_s(unsigned char * _Dst, size_t _SizeInBytes, unsigned char const * _Src, size_t _MaxCount)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbcat_s, _Dst, _SizeInBytes, _Src, _MaxCount);
	}
	_CRTIMP errno_t __cdecl _o__mbsnbcat_s_l(unsigned char * _Dst, size_t _DstSizeInBytes, unsigned char const * _Src, size_t _MaxCount, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbcat_s_l, _Dst, _DstSizeInBytes, _Src, _MaxCount, _Locale);
	}
	_CRTIMP int __cdecl _o__mbsnbcmp(unsigned char const * _Str1, unsigned char const * _Str2, size_t _MaxCount)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbcmp, _Str1, _Str2, _MaxCount);
	}
	_CRTIMP size_t __cdecl _o__mbsnbcnt(unsigned char const * _String, size_t _MaxCount)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbcnt, _String, _MaxCount);
	}
	_CRTIMP int __cdecl _o__mbsnbcoll(unsigned char const * _Str1, unsigned char const * _Str2, size_t _MaxCount)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbcoll, _Str1, _Str2, _MaxCount);
	}
	_CRTIMP errno_t __cdecl _o__mbsnbcpy_s(unsigned char * _Dst, size_t _SizeInBytes, unsigned char const * _Src, size_t _MaxCount)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbcpy_s, _Dst, _SizeInBytes, _Src, _MaxCount);
	}
	_CRTIMP errno_t __cdecl _o__mbsnbcpy_s_l(unsigned char * _Dst, size_t _DstSizeInBytes, unsigned char const * _Src, size_t _MaxCount, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbcpy_s_l, _Dst, _DstSizeInBytes, _Src, _MaxCount, _Locale);
	}
	_CRTIMP int __cdecl _o__mbsnbicmp(unsigned char const * _Str1, unsigned char const * _Str2, size_t _MaxCount)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbicmp, _Str1, _Str2, _MaxCount);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsnbset(unsigned char * _String, unsigned int _Val, size_t _MaxCount)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbset, _String, _Val, _MaxCount);
	}
	_CRTIMP errno_t __cdecl _o__mbsnbset_s(unsigned char * _Dst, size_t _SizeInBytes, unsigned int _C, size_t _MaxCount)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbset_s, _Dst, _SizeInBytes, _C, _MaxCount);
	}
	_CRTIMP errno_t __cdecl _o__mbsnbset_s_l(unsigned char * _Dst, size_t _DstSizeInBytes, unsigned int _Ch, size_t _MaxCount, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbset_s_l, _Dst, _DstSizeInBytes, _Ch, _MaxCount, _Locale);
	}
	_CRTIMP errno_t __cdecl _o__mbsncat_s(unsigned char * _Dst, size_t _SizeInBytes, unsigned char const * _Src, size_t _MaxCount)
	{
		return __crt_state_management::wrapped_invoke(_mbsncat_s, _Dst, _SizeInBytes, _Src, _MaxCount);
	}
	_CRTIMP errno_t __cdecl _o__mbsncat_s_l(unsigned char * _Dst, size_t _DstSizeInBytes, unsigned char const * _Src, size_t _MaxCount, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_mbsncat_s_l, _Dst, _DstSizeInBytes, _Src, _MaxCount, _Locale);
	}
	_CRTIMP size_t __cdecl _o__mbsnccnt(unsigned char const * _Str, size_t _MaxCount)
	{
		return __crt_state_management::wrapped_invoke(_mbsnccnt, _Str, _MaxCount);
	}
	_CRTIMP int __cdecl _o__mbsncmp(unsigned char const * _Str1, unsigned char const * _Str2, size_t _MaxCount)
	{
		return __crt_state_management::wrapped_invoke(_mbsncmp, _Str1, _Str2, _MaxCount);
	}
	_CRTIMP int __cdecl _o__mbsncoll(unsigned char const * _Str1, unsigned char const * _Str2, size_t _MaxCount)
	{
		return __crt_state_management::wrapped_invoke(_mbsncoll, _Str1, _Str2, _MaxCount);
	}
	_CRTIMP errno_t __cdecl _o__mbsncpy_s(unsigned char * _Dst, size_t _SizeInBytes, unsigned char const * _Src, size_t _MaxCount)
	{
		return __crt_state_management::wrapped_invoke(_mbsncpy_s, _Dst, _SizeInBytes, _Src, _MaxCount);
	}
	_CRTIMP errno_t __cdecl _o__mbsncpy_s_l(unsigned char * _Dst, size_t _DstSizeInBytes, unsigned char const * _Src, size_t _MaxCount, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_mbsncpy_s_l, _Dst, _DstSizeInBytes, _Src, _MaxCount, _Locale);
	}
	_CRTIMP unsigned int __cdecl _o__mbsnextc(unsigned char const * _String)
	{
		return __crt_state_management::wrapped_invoke(_mbsnextc, _String);
	}
	_CRTIMP int __cdecl _o__mbsnicmp(unsigned char const * _Str1, unsigned char const * _Str2, size_t _MaxCount)
	{
		return __crt_state_management::wrapped_invoke(_mbsnicmp, _Str1, _Str2, _MaxCount);
	}
	_CRTIMP int __cdecl _o__mbsnicoll(unsigned char const * _Str1, unsigned char const * _Str2, size_t _MaxCount)
	{
		return __crt_state_management::wrapped_invoke(_mbsnicoll, _Str1, _Str2, _MaxCount);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsninc(unsigned char const * _String, size_t _Count)
	{
		return __crt_state_management::wrapped_invoke(_mbsninc, _String, _Count);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsnset(unsigned char * _String, unsigned int _Val, size_t _MaxCount)
	{
		return __crt_state_management::wrapped_invoke(_mbsnset, _String, _Val, _MaxCount);
	}
	_CRTIMP errno_t __cdecl _o__mbsnset_s(unsigned char * _Dst, size_t _SizeInBytes, unsigned int _Val, size_t _MaxCount)
	{
		return __crt_state_management::wrapped_invoke(_mbsnset_s, _Dst, _SizeInBytes, _Val, _MaxCount);
	}
	_CRTIMP errno_t __cdecl _o__mbsnset_s_l(unsigned char * _Dst, size_t _DstSizeInBytes, unsigned int _Val, size_t _MaxCount, _locale_t _Locale)
	{
		return __crt_state_management::wrapped_invoke(_mbsnset_s_l, _Dst, _DstSizeInBytes, _Val, _MaxCount, _Locale);
	}
	_CRTIMP const unsigned char * __cdecl _o__mbspbrk(unsigned char const * _String, unsigned char const * _Control)
	{
		return __crt_state_management::wrapped_invoke(_mbspbrk, _String, _Control);
	}
	_CRTIMP const unsigned char * __cdecl _o__mbsrchr(unsigned char const * _String, unsigned int _C)
	{
		return __crt_state_management::wrapped_invoke(_mbsrchr, _String, _C);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsrev(unsigned char * _String)
	{
		return __crt_state_management::wrapped_invoke(_mbsrev, _String);
	}
	_CRTIMP errno_t __cdecl _o__mbsset_s(unsigned char * _Dst, size_t _SizeInBytes, unsigned int _Val)
	{
		return __crt_state_management::wrapped_invoke(_mbsset_s, _Dst, _SizeInBytes, _Val);
	}
	_CRTIMP size_t __cdecl _o__mbsspn(unsigned char const * _Str, unsigned char const * _Control)
	{
		return __crt_state_management::wrapped_invoke(_mbsspn, _Str, _Control);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsspnp(unsigned char const * _Str1, unsigned char const * _Str2)
	{
		return __crt_state_management::wrapped_invoke(_mbsspnp, _Str1, _Str2);
	}
	_CRTIMP const unsigned char * __cdecl _o__mbsstr(unsigned char const * _Str, unsigned char const * _Substr)
	{
		return __crt_state_management::wrapped_invoke(_mbsstr, _Str, _Substr);
	}
	_CRTIMP unsigned char * __cdecl _o__mbstok_s(unsigned char * _Str, unsigned char const * _Delim, unsigned char ** _Context)
	{
		return __crt_state_management::wrapped_invoke(_mbstok_s, _Str, _Delim, _Context);
	}
	_CRTIMP errno_t __cdecl _o__mbsupr_s(unsigned char * _Str, size_t _SizeInBytes)
	{
		return __crt_state_management::wrapped_invoke(_mbsupr_s, _Str, _SizeInBytes);
	}
	_CRTIMP errno_t _o_memcpy_s(void * const _Destination, rsize_t const _DestinationSize, void const * const _Source, rsize_t const _SourceSize)
	{
		return __crt_state_management::wrapped_invoke(memcpy_s, _Destination, _DestinationSize, _Source, _SourceSize);
	}
	_CRTIMP double __cdecl _o__nextafter(double _X, double _Y)
	{
		return __crt_state_management::wrapped_invoke(_nextafter, _X, _Y);
	}
	_CRTIMP void __cdecl _o_qsort(void * _Base, size_t _NumOfElements, size_t _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction)
	{
		return __crt_state_management::wrapped_invoke_void(qsort, _Base, _NumOfElements, _SizeOfElements, _CompareFunction);
	}
	_CRTIMP void __cdecl _o_qsort_s(void * _Base, rsize_t _NumOfElements, rsize_t _SizeOfElements, _CoreCrtSecureSearchSortCompareFunction _CompareFunction, void * _Context)
	{
		return __crt_state_management::wrapped_invoke_void(qsort_s, _Base, _NumOfElements, _SizeOfElements, _CompareFunction, _Context);
	}
	_CRTIMP double __cdecl _o__scalb(double _X, long _Y)
	{
		return __crt_state_management::wrapped_invoke(_scalb, _X, _Y);
	}
	_CRTIMP int __cdecl _o__tolower(int _C)
	{
		return __crt_state_management::wrapped_invoke(_tolower, _C);
	}
	_CRTIMP int __cdecl _o__toupper(int _C)
	{
		return __crt_state_management::wrapped_invoke(_toupper, _C);
	}
	//mbs DEPRECATED
	_CRTIMP unsigned char * __cdecl _o__mbslwr(
		unsigned char *string
	)
	{
		return __crt_state_management::wrapped_invoke(_mbslwr, string);
	}
	_CRTIMP unsigned char * __cdecl _o__mbslwr_l(
		unsigned char *string,
		_locale_t plocinfo
	)
	{
		return __crt_state_management::wrapped_invoke(_mbslwr_l, string, plocinfo);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsnbcat(
		unsigned char *dst,
		const unsigned char *src,
		size_t cnt
	)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbcat, dst, src, cnt);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsnbcpy(
		unsigned char *dst,
		const unsigned char *src,
		size_t cnt
	)
	{
		return __crt_state_management::wrapped_invoke(_mbsnbcpy, dst, src, cnt);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsncat(
		unsigned char *dst,
		const unsigned char *src,
		size_t cnt
	)
	{
		return __crt_state_management::wrapped_invoke(_mbsncat, dst, src, cnt);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsncpy(
		unsigned char *dst,
		const unsigned char *src,
		size_t cnt
	)
	{
		return __crt_state_management::wrapped_invoke(_mbsncpy, dst, src, cnt);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsset(
		unsigned char *string,
		unsigned int val
	)
	{
		return __crt_state_management::wrapped_invoke(_mbsset, string, val);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsupr(
		unsigned char *string
	)
	{
		return __crt_state_management::wrapped_invoke(_mbsupr, string);
	}
	_CRTIMP unsigned char * __cdecl _o__mbsupr_l(
		unsigned char *string,
		_locale_t plocinfo
	)
	{
		return __crt_state_management::wrapped_invoke(_mbsupr_l, string, plocinfo);
	}

	//misc
	_CRTIMP int __cdecl _o__purecall(void)
	{
		return __crt_state_management::wrapped_invoke(_purecall);
	}
	_CRTIMP void* __cdecl _o_memset(void* _Dst, int _Val, size_t _Size)
	{
		return __crt_state_management::wrapped_invoke(memset, _Dst, _Val, _Size);
	}

	//math
#if defined _M_X64

	_CRTIMP float __cdecl _o__logbf(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(_logbf, _X);
	}
	_CRTIMP float __cdecl _o__nextafterf(_In_ float _X, _In_ float _Y)
	{
		return __crt_state_management::wrapped_invoke(_nextafterf, _X, _Y);
	}
	_CRTIMP int   __cdecl _o__finitef(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(_finitef, _X);
	}
	_CRTIMP int   __cdecl _o__isnanf(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(_isnanf, _X);
	}
	_CRTIMP int   __cdecl _o__fpclassf(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(_fpclassf, _X);
	}

	_CRTIMP int   __cdecl _o__set_FMA3_enable(_In_ int _Flag)
	{
		return __crt_state_management::wrapped_invoke(_set_FMA3_enable, _Flag);
	}
	_CRTIMP int   __cdecl _o__get_FMA3_enable(void)
	{
		return __crt_state_management::wrapped_invoke(_get_FMA3_enable);
	}

#elif defined _M_ARM || defined _M_ARM64 || defined _M_HYBRID_X86_ARM64

	_CRTIMP int   __cdecl _o__finitef(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(_finitef, _X);
	}
	_CRTIMP float __cdecl _o__logbf(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(_logbf, _X);
	}


#endif



#if defined _M_X64 || defined _M_ARM || defined _M_ARM64 || defined _M_HYBRID_X86_ARM64 || defined _CORECRT_BUILD_APISET


	_CRTIMP float __cdecl _o_acosf(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(acosf, _X);
	}
	_CRTIMP float __cdecl _o_asinf(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(asinf, _X);
	}
	_CRTIMP float __cdecl _o_atan2f(_In_ float _Y, _In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(atan2f, _Y, _X);
	}
	_CRTIMP float __cdecl _o_atanf(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(atanf, _X);
	}
	_CRTIMP float __cdecl _o_ceilf(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(ceilf, _X);
	}
	_CRTIMP float __cdecl _o_cosf(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(cosf, _X);
	}
	_CRTIMP float __cdecl _o_coshf(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(coshf, _X);
	}
	_CRTIMP float __cdecl _o_expf(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(expf, _X);
	}
#endif

#if defined _M_X64 || defined _M_ARM || defined _M_ARM64 || defined _M_HYBRID_X86_ARM64

	_CRTIMP float __cdecl _o_floorf(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(floorf, _X);
	}
	_CRTIMP float __cdecl _o_fmodf(_In_ float _X, _In_ float _Y)
	{
		return __crt_state_management::wrapped_invoke(fmodf, _X, _Y);
	}
#endif

#if defined _M_X64 || defined _M_ARM || defined _M_ARM64 || defined _M_HYBRID_X86_ARM64 || defined _CORECRT_BUILD_APISET

	_CRTIMP float  __cdecl _o_log10f(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(log10f, _X);
	}
	_CRTIMP float  __cdecl _o_logf(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(logf, _X);
	}
	_CRTIMP float  __cdecl _o_modff(_In_ float _X, _Out_ float *_Y)
	{
		return __crt_state_management::wrapped_invoke(modff, _X, _Y);
	}
	_CRTIMP float  __cdecl _o_sinf(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(sinf, _X);
	}
	_CRTIMP float  __cdecl _o_sinhf(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(sinhf, _X);
	}
	_CRTIMP float  __cdecl _o_sqrtf(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(sqrtf, _X);
	}
	_CRTIMP float  __cdecl _o_tanf(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(tanf, _X);
	}
	_CRTIMP float  __cdecl _o_tanhf(_In_ float _X)
	{
		return __crt_state_management::wrapped_invoke(tanhf, _X);
	}
#endif

#ifdef _M_IX86

	//stubs.c
	double CDECL _CIsin(double x);
	double CDECL _CIcos(double x);
	double CDECL _CItan(double x);
	double CDECL _CIsinh(double x);
	double CDECL _CIcosh(double x);
	double CDECL _CItanh(double x);
	double CDECL _CIasin(double x);
	double CDECL _CIacos(double x);
	double CDECL _CIatan(double x);
	double CDECL _CIatan2(double y, double x);
	double CDECL _CIexp(double x);
	double CDECL _CIlog(double x);
	double CDECL _CIlog10(double x);
	double CDECL _CIpow(double x, double y);
	double CDECL _CIsqrt(double x);
	double CDECL _CIfmod(double x, double y);

	/*
	 * @implemented
	 */
	_CRTIMP double	CDECL	_o__CIsin(double x)
	{
		return __crt_state_management::wrapped_invoke(_CIsin, x);
	}
	/*
	 * @implemented
	 */
	_CRTIMP double	CDECL	_o__CIcos(double x)
	{
		return __crt_state_management::wrapped_invoke(_CIcos, x);
	}
	/*
	 * @implemented
	 */
	_CRTIMP double	CDECL	_o__CItan(double x)
	{
		return __crt_state_management::wrapped_invoke(_CItan, x);
	}
	/*
	 * @implemented
	 */
	_CRTIMP double	CDECL	_o__CIsinh(double x)
	{
		return __crt_state_management::wrapped_invoke(_CIsinh, x);
	}
	/*
	 * @implemented
	 */
	_CRTIMP double	CDECL	_o__CIcosh(double x)
	{
		return __crt_state_management::wrapped_invoke(_CIcosh, x);
	}
	/*
	 * @implemented
	 */
	_CRTIMP double	CDECL	_o__CItanh(double x)
	{
		return __crt_state_management::wrapped_invoke(_CItanh, x);
	}
	/*
	 * @implemented
	 */
	_CRTIMP double	CDECL	_o__CIasin(double x)
	{
		return __crt_state_management::wrapped_invoke(_CIasin, x);
	}
	/*
	 * @implemented
	 */
	_CRTIMP double	CDECL	_o__CIacos(double x)
	{
		return __crt_state_management::wrapped_invoke(_CIacos, x);
	}
	/*
	 * @implemented
	 */
	_CRTIMP double	CDECL	_o__CIatan(double x)
	{
		return __crt_state_management::wrapped_invoke(_CIatan, x);
	}
	/*
	 * @implemented
	 */
	_CRTIMP double	CDECL	_o__CIatan2(double x, double y)
	{
		return __crt_state_management::wrapped_invoke(_CIatan2, x, y);
	}
	/*
	 * @implemented
	 */
	_CRTIMP double	CDECL	_o__CIexp(double x)
	{
		return __crt_state_management::wrapped_invoke(_CIexp, x);
	}
	/*
	 * @implemented
	 */
	_CRTIMP double	CDECL	_o__CIlog(double x)
	{
		return __crt_state_management::wrapped_invoke(_CIlog, x);
	}
	/*
	 * @implemented
	 */
	_CRTIMP double	CDECL	_o__CIlog10(double x)
	{
		return __crt_state_management::wrapped_invoke(_CIlog10, x);
	}
	/*
	 * @implemented
	 */
	_CRTIMP double	CDECL	_o__CIpow(double x, double y)
	{
		return __crt_state_management::wrapped_invoke(_CIpow, x, y);
	}
	/*
	 * @implemented
	 */
	_CRTIMP double	CDECL	_o__CIsqrt(double x)
	{
		return __crt_state_management::wrapped_invoke(_CIsqrt, x);
	}
	/*
	 * @implemented
	 */
	_CRTIMP double	CDECL	_o__CIfmod(double x, double y)
	{
		return __crt_state_management::wrapped_invoke(_CIfmod, x, y);
	}

	//sse2ÊýÑ§º¯Êý
	void __cdecl __libm_sse2_acos(void);
	void __cdecl _libm_sse2_acos_precise(void);
	void __cdecl __libm_sse2_acosf(void);
	void __cdecl __libm_sse2_asin(void);
	void __cdecl _libm_sse2_asin_precise(void);
	void __cdecl __libm_sse2_asinf(void);
	void __cdecl __libm_sse2_atan(void);
	void __cdecl _libm_sse2_atan_precise(void);
	void __cdecl __libm_sse2_atan2(void);
	void __cdecl __libm_sse2_atanf(void);
	void __cdecl __libm_sse2_cos(void);
	void __cdecl _libm_sse2_cos_precise(void);
	void __cdecl __libm_sse2_cosf(void);
	void __cdecl __libm_sse2_exp(void);
	void __cdecl _libm_sse2_exp_precise(void);
	void __cdecl __libm_sse2_expf(void);
	void __cdecl __libm_sse2_log(void);
	void __cdecl _libm_sse2_log_precise(void);
	void __cdecl __libm_sse2_log10(void);
	void __cdecl _libm_sse2_log10_precise(void);
	void __cdecl __libm_sse2_log10f(void);
	void __cdecl __libm_sse2_logf(void);
	void __cdecl __libm_sse2_pow(void);
	void __cdecl _libm_sse2_pow_precise(void);
	void __cdecl __libm_sse2_powf(void);
	void __cdecl __libm_sse2_sin(void);
	void __cdecl _libm_sse2_sin_precise(void);
	void __cdecl __libm_sse2_sinf(void);
	void __cdecl _libm_sse2_sqrt_precise(void);
	void __cdecl __libm_sse2_tan(void);
	void __cdecl _libm_sse2_tan_precise(void);
	void __cdecl __libm_sse2_tanf(void);

	_CRTIMP void __cdecl _o___libm_sse2_acos(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_acos);
	}
	_CRTIMP void __cdecl _o__libm_sse2_acos_precise(void)
	{
		return __crt_state_management::wrapped_invoke_void(_libm_sse2_acos_precise);
	}
	_CRTIMP void __cdecl _o___libm_sse2_acosf(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_acosf);
	}
	_CRTIMP void __cdecl _o___libm_sse2_asin(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_asin);
	}
	_CRTIMP void __cdecl _o__libm_sse2_asin_precise(void)
	{
		return __crt_state_management::wrapped_invoke_void(_libm_sse2_asin_precise);
	}
	_CRTIMP void __cdecl _o___libm_sse2_asinf(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_asinf);
	}
	_CRTIMP void __cdecl _o___libm_sse2_atan(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_atan);
	}
	_CRTIMP void __cdecl _o__libm_sse2_atan_precise(void)
	{
		return __crt_state_management::wrapped_invoke_void(_libm_sse2_atan_precise);
	}
	_CRTIMP void __cdecl _o___libm_sse2_atan2(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_atan2);
	}
	_CRTIMP void __cdecl _o___libm_sse2_atanf(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_atanf);
	}
	_CRTIMP void __cdecl _o___libm_sse2_cos(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_cos);
	}
	_CRTIMP void __cdecl _o__libm_sse2_cos_precise(void)
	{
		return __crt_state_management::wrapped_invoke_void(_libm_sse2_cos_precise);
	}
	_CRTIMP void __cdecl _o___libm_sse2_cosf(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_cosf);
	}
	_CRTIMP void __cdecl _o___libm_sse2_exp(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_exp);
	}
	_CRTIMP void __cdecl _o__libm_sse2_exp_precise(void)
	{
		return __crt_state_management::wrapped_invoke_void(_libm_sse2_exp_precise);
	}
	_CRTIMP void __cdecl _o___libm_sse2_expf(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_expf);
	}
	_CRTIMP void __cdecl _o___libm_sse2_log(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_log);
	}
	_CRTIMP void __cdecl _o__libm_sse2_log_precise(void)
	{
		return __crt_state_management::wrapped_invoke_void(_libm_sse2_log_precise);
	}
	_CRTIMP void __cdecl _o___libm_sse2_log10(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_log10);
	}
	_CRTIMP void __cdecl _o__libm_sse2_log10_precise(void)
	{
		return __crt_state_management::wrapped_invoke_void(_libm_sse2_log10_precise);
	}
	_CRTIMP void __cdecl _o___libm_sse2_log10f(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_log10f);
	}
	_CRTIMP void __cdecl _o___libm_sse2_logf(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_logf);
	}
	_CRTIMP void __cdecl _o___libm_sse2_pow(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_pow);
	}
	_CRTIMP void __cdecl _o__libm_sse2_pow_precise(void)
	{
		return __crt_state_management::wrapped_invoke_void(_libm_sse2_pow_precise);
	}
	_CRTIMP void __cdecl _o___libm_sse2_powf(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_powf);
	}
	_CRTIMP void __cdecl _o___libm_sse2_sin(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_sin);
	}
	_CRTIMP void __cdecl _o__libm_sse2_sin_precise(void)
	{
		return __crt_state_management::wrapped_invoke_void(_libm_sse2_sin_precise);
	}
	_CRTIMP void __cdecl _o___libm_sse2_sinf(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_sinf);
	}
	_CRTIMP void __cdecl _o__libm_sse2_sqrt_precise(void)
	{
		return __crt_state_management::wrapped_invoke_void(_libm_sse2_sqrt_precise);
	}
	_CRTIMP void __cdecl _o___libm_sse2_tan(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_tan);
	}
	_CRTIMP void __cdecl _o__libm_sse2_tan_precise(void)
	{
		return __crt_state_management::wrapped_invoke_void(_libm_sse2_tan_precise);
	}
	_CRTIMP void __cdecl _o___libm_sse2_tanf(void)
	{
		return __crt_state_management::wrapped_invoke_void(__libm_sse2_tanf);
	}
#endif



	//except
	_CRTIMP double __cdecl _except1(DWORD fpe, _FP_OPERATION_CODE op, double arg, double res, DWORD cw, void * unk);
	_CRTIMP double __cdecl _o__except1(DWORD fpe, _FP_OPERATION_CODE op, double arg, double res, DWORD cw, void * unk)
	{
		return __crt_state_management::wrapped_invoke(_except1, fpe, op, arg, res, cw, unk);
	}

	_CRTIMP void __cdecl _o___std_exception_copy(__std_exception_data const* _From, __std_exception_data* _To)
	{
		return __crt_state_management::wrapped_invoke_void(__std_exception_copy, _From, _To);
	}
	_CRTIMP void __cdecl _o___std_exception_destroy(__std_exception_data* _Data)
	{
		return __crt_state_management::wrapped_invoke_void(__std_exception_destroy, _Data);
	}

	//type_info
	_CRTIMP void __cdecl _o___std_type_info_destroy_list(__type_info_node* _RootNode)
	{
		return __crt_state_management::wrapped_invoke_void(__std_type_info_destroy_list, _RootNode);
	}
	_CRTIMP const char* __cdecl _o___std_type_info_name(__std_type_info_data* _Data, __type_info_node* _RootNod)
	{
		return __crt_state_management::wrapped_invoke(__std_type_info_name, _Data, _RootNod);
	}
}