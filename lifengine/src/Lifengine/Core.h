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