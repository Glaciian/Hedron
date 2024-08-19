
// Application constuctor, destructor and methods.

#include "hdepch.h"

#include "Hedron/Application.h"
#include "Hedron/Events/ApplicationEvent.h"
#include "Hedron/Log.h"

namespace Hedron {

	// Application Constructor.
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
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
			//m_Window->OnUpdate();
		}
	}
}