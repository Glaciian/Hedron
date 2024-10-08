#pragma once 

// Hedron Engine's entry point for applications.

// Preproccessor check for Windows platforms.
#ifdef HDE_PLATFORM_WINDOWS

// Function prototype defined by sandBox for creating a Windows application instance.
extern Hedron::Application* Hedron::CreateApplication();

// Entry Point for Applications
int main(int argc, char** argv)
{
	// Initialization of the logger.
	// TODO: Should be moved to an initialization function.
	Hedron::Log::Init();
	HDE_CORE_INFO("Core Logger Initialized.");
	HDE_APP_INFO("Application Logger Initialized.");
	HDE_APP_INFO("Windows users not forgotten");

	// Application creation, execution and cleanup.
	auto app = Hedron::CreateApplication();
	app->Run();
	delete app;	
}

// Preproccessor check for MacOS platforms.
#elif defined(HDE_PLATFORM_MACOS)
	
// Function prototype defined by sandBox for creating a MacOS application instance.
extern Hedron::Application* Hedron::CreateApplication();

// Entry Point for Applications
int main(int argc, char** argv)
{
	// Initialization of the logger.
	// TODO: Should be moved to an initialization function.
	Hedron::Log::Init();
	HDE_CORE_INFO("Core Logger Initialized just because.");
	HDE_APP_INFO("Application Logger Initialized.");
	HDE_APP_INFO("Ain't this all cool!!");
	HDE_APP_INFO("App Update Test");

	// Application creation, execution and cleanup.
	auto app = Hedron::CreateApplication();
	app->Run();
	delete app;
}

#endif
