
// Application constuctor, destructor and methods.

#include "hdepch.h"

#include "Hedron/Application.h"
#include "Hedron/Events/ApplicationEvent.h"
#include "Hedron/Log.h"

namespace Hedron {

	// Application Constructor.
	Application::Application()
	{
		#ifdef HDE_PLATFORM_WINDOWS
			m_Window = std::unique_ptr<Window>(Window::CreateWindowsWindow());
		
		#elif HDE_PLATFORM_MACOS
			m_Window = std::unique_ptr<Window>(Window::CreateMacOSWindow());
		#else
			HDE_CORE_ERROR("Unsupported platform fo window creation.");
		#endif


	}

	// Application Destructor.
	Application::~Application()
	{

	}

	// REFRENCE: Simple application loop, implemented for testing.
	void Application::Run()
	{

		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}