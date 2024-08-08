#pragma once

#ifdef HDE_PLATFORM_WINDOWS
	#ifdef HDE_BUILD_DLL
		#define HEDRON_API __declspec(dllexport)
	#else
		#define HEDRON_API __declspec(dllimport)
	#endif
#else
	#error Hedron doesn't support the current system architecture.
#endif

