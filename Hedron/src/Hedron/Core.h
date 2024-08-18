#pragma once

// Core Build Architecture.

#if defined(HDE_PLATFORM_WINDOWS)
#if defined(HDE_BUILD_DLL)
    // Symbols following this macro are being exported from the DLL.
    #define HEDRON_API __declspec(dllexport)
#else
    // Symbols following this macro are being imported from the DLL.
    #define HEDRON_API __declspec(dllimport)
#endif
#elif defined(HDE_PLATFORM_MACOS)
#if defined(HDE_BUILD_DLL)
    // Symbols following this macro are being exported from the DLL.
    #define HEDRON_API __attribute__((visibility("default")))
#endif
#else
    // Compile-time error if Hedron doesn't support the current system architecture.
    #error "Hedron doesn't support the current system architecture."
#endif

// Definition shorten the use of to_string for event types.
#define ETS ToString()

// Bit field for applying multiple event categories to a single event type. 
#define BIT(x) (1 << x)