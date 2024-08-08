#pragma once

// Core Build Architecture.

// Definitions for Windows platforms.
#ifdef HDE_PLATFORM_WINDOWS
	#ifdef HDE_BUILD_DLL
		// If HDE_BUILD_DLL is defined as HDE_PLATFORM_WINDOWS, define HEDRON_API as __declspec(dllimport).
		// Symbols following this macro are being exported from the DLL.
		#define HEDRON_API __declspec(dllexport) 
	#else
		// If HDE_BUILD_DLL is not defined, define HEDRON_API as __declspec(dllimport).
		// Symbols following this macro are being imported from the DLL.
		#define HEDRON_API __declspec(dllimport)
	#endif
#else
	// Compile-time error if Hedron doesn't support the current system architecture.
	#error Hedron doesn't support the current system architecture.
#endif

