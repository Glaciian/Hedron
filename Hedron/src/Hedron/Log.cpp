#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Hedron {

	// Declare two static shared pointer variables, s_CoreLogger and s_ApplicationLogger, which will hold the logger instances.
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ApplicationLogger;


	// Initialize the Log class.
	void Log::Init()
	{ 
		// Set the logging pattern to include the timestamp, logger name, and log message.
		spdlog::set_pattern("%^[%T] %n: %v%$");
		
		// REFRENCE: The implementation of "spdlog::level::trace" should be properly abstracted.

		// Create a shared pointer to the core logger instance. 
		s_CoreLogger = spdlog::stdout_color_mt("CORE");
		s_CoreLogger->set_level(spdlog::level::trace); 


		// Create a shared pointer to the application logger instance.
		s_ApplicationLogger = spdlog::stdout_color_mt("APP");
		s_ApplicationLogger->set_level(spdlog::level::trace);
	}

}