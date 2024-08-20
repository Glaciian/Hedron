	// Precompiled header [hdepch.h] 
#include "hdepch.h"

	// Include necessary header files [Hedron/Application.h] [Hedron/Events/ApplicationEvent.h] and [Hedron/Log.h]
#include "Hedron/Application.h"
#include "Hedron/Events/ApplicationEvent.h"
#include "Hedron/Log.h"


/*////////////////////////////////////////////////*/
/* Application constuctor, destructor and methods */
/*////////////////////////////////////////////////*/


	// Define the Hedron namespace
namespace Hedron {

		// Application Constructor.
	Application::Application()
	{
			// Preprocessing Platform check for Application Window creation.
		#ifdef HDE_PLATFORM_WINDOWS
			m_Window = std::unique_ptr<Window>(Window::CreateWindowsWindow());
		
		#elif HDE_PLATFORM_MACOS
			m_Window = std::unique_ptr<Window>(Window::CreateMacOSWindow());
		#else
				// Log an error message indicating that the platform is unsupported for window creation.
			HDE_CORE_ERROR("Unsupported platform for window creation.");
		#endif

	}

		// Application Destructor.
	Application::~Application()
	{

	}

		// REFRENCE: Simple application loop, implemented for testing.
	void Application::Run()
	{

			// Continuously call the OnUpdate method on the window until m_Running becomes false.
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}

}