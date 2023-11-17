#pragma once

#ifdef LG_PLATFORM_WINDOWS
	#ifdef LG_BUILD_DLL
		#define LIFENGINE_API __declspec(dllexport)
	#else
		#define LIFENGINE_API __declspec(dllimport)
	#endif
#else
	#error Lifengine only support Windows!
#endif

/*__debugbreak() is an intrinsic function of Visual Studio, which gets compiled to appropriate
  machine instruction based on the system architecture */
#ifdef LG_ENABLE_ASSERTS
	#define LG_ASSERT(X, ...) { if(!(X)) { LG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define LG_CORE_ASSERT(X, ...) { if(!(X)) { LG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define LG_ASSERT(x, ...)
#define LG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1<<x)