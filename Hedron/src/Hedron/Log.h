#pragma once

// The Log class is responsible for initializing and managing the logging system.

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Hedron {

	class HEDRON_API Log
	{
	public:

		// Initializes the logging system.
		static void Init();

		// Returns a reference to the shared pointer of the Core and application logger.
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetApplicationLogger() { return s_ApplicationLogger; }

	private:

		// Shared pointer to to the core and application logger.
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ApplicationLogger;
		
	};
	
}

// Definitions of logging severity.

// CRITICAL :	Indicates that at least one core system component is inoperable which is causing a fatal error within one of the larger systems.
// ERROR	:	Notes that at least one system component is inoperable and is interfering with the operability of other functionalities.
// WARN		:	Indicates that an unexpected event has occurred in an application that may disrupt or delay other processes.
// INFO		:	Captures an event that has occurred. These alerts usually can be ignored, assuming the rest of the system continues to operate normally.
// DEBUG    :   Captures relevant detail of events that may be useful during software debugging or troubleshooting within the test environment.

// Core Logging Definitions.
#define HDE_CORE_CRITICAL(...)	::Hedron::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define HDE_CORE_ERROR(...)		::Hedron::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HDE_CORE_WARN(...)		::Hedron::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HDE_CORE_INFO(...)		::Hedron::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HDE_CORE_DEBUG(...)		::Hedron::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define HDE_CORE_TRACE(...)		::Hedron::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Application Logging Definitions.
#define HDE_APP_ERROR(...)		::Hedron::Log::GetApplicationLogger()->error(__VA_ARGS__)
#define HDE_APP_WARN(...)		::Hedron::Log::GetApplicationLogger()->warn(__VA_ARGS__)
#define HDE_APP_INFO(...)		::Hedron::Log::GetApplicationLogger()->info(__VA_ARGS__)
#define HDE_APP_DEBUG(...)		::Hedron::Log::GetApplicationLogger()->debug(__VA_ARGS__)
#define HDE_APP_TRACE(...)		::Hedron::Log::GetApplicationLogger()->trace(__VA_ARGS__)