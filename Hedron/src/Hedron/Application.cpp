
// Application constuctor, destructor and methods.

#include "hdepch.h"

#include "Hedron/Application.h"
#include "Hedron/Events/ApplicationEvent.h"
#include "Hedron/Log.h"

namespace Hedron {

	// Application Constructor.
	Application::Application()
	{

	}

	// Application Destructor.
	Application::~Application()
	{

	}

	// REFRENCE: Simple application loop, implemented for testing.
	void Application::Run()
	{
		// Test Logging a dummy event.
		WindowResizeEvent e(1280, 720);
		HDE_APP_TRACE(e.ETS);

		while (true);
	}

}