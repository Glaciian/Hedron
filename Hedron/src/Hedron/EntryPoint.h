#pragma once 

// Hedron Engine's entry point for applications.

// Preproccessor check for Windows platforms
#ifdef HDE_PLATFORM_WINDOWS

// Function prototype defined by sandBox for creating an application instance.
extern Hedron::Application* Hedron::CreateApplication();

// Entry Point of Applications
int main(int argc, char** argv)
{
	// Application creation, execution and cleanup.
	auto app = Hedron::CreateApplication();
	app->Run();
	delete app;	
}

#endif	0