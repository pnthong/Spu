#pragma once

#ifdef SPU_PLATFORM_WINDOWS
	#ifdef BUILD_DLL
		#define SPU_API __declspec(dllexport)
	#else
		#define SPU_API __declspec(dllimport)
	#endif
#else
	#error Spu only support Windows!
#endif // SPU_PLATFORM_WINDOWS
