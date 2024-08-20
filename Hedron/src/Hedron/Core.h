    // Ensure the header file is included only once during compilation.
#pragma once


/*/////////////////////////*/
/* Core build architecture */
/*/////////////////////////*/

    // Preprocessor check for Windows Platforms
#if defined(HDE_PLATFORM_WINDOWS)
#if defined(HDE_BUILD_DLL)
    // Symbols following this macro are being exported from the DLL.
    #define HEDRON_API __declspec(dllexport)
#else
    // Symbols following this macro are being imported from the DLL.
    #define HEDRON_API __declspec(dllimport)
#endif

    // Preprocessor check for Windows Platforms
#elif defined(HDE_PLATFORM_MACOS)
#if defined(HDE_BUILD_DLL)
    // Symbols following this macro are being exported from the DLL.
    #define HEDRON_API __attribute__((visibility("default")))
#endif

#else
    // Compile-time error if Hedron doesn't support the current system architecture.
    #error "Hedron doesn't support the current system architecture."
#endif

    // Defines assert macros for error checking.
#ifdef HDE_ENABLE_ASSERTS
    #define HDE_ASSERT(x, ...) { if(!(x)) { HDE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define HDE_CORE_ASSERT(x, ...) { if(!(x)) { HDE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define HDE_ASSERT(x, ...)
    #define HDE_CORE_ASSERT(x, ...)
#endif

    // TODO: This should be handled by the Event system.
    // Definition shorten the use of to_string for event types.
#define ETS ToString()

    // Bit field for applying multiple event categories to a single event type. 
#define BIT(x) (1 << x)