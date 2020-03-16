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

#ifdef SU_DEBUG
	#define SU_ENABLE_ASSERTS
#endif

#ifdef SU_ENABLE_ASSERT
	#define SPU_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SPU_CORE_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SPU_ASSERT(x, ...)
	#define SPU_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define SU_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)