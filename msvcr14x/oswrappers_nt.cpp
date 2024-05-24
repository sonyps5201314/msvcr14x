#include <corecrt_internal.h>

#ifdef __cplusplus
extern "C++"
{
	namespace __crt_state_management
	{
		ULONGLONG* get_teb_data_address()
		{
			return &NtCurrentTeb()->ReservedForCrt;
		}

		ULONGLONG get_teb_data_value()
		{
			return NtCurrentTeb()->ReservedForCrt;
		}
	}
}
#endif