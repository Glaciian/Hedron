#pragma once

// Application definitions and structure.

#include "Hedron/Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Hedron {

	class HEDRON_API Application
	{
	public:
		// Constructor for the Application class.
		Application();
		// Virtual destructor to ensure proper cleanup of resources.
		virtual ~Application();
		
		// Main run loop for the application.
		// This method is responsible for starting the application and managing its lifecycle.
		void Run();

	private:
		// TODO: This is platform independent.
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};

	// The create application function is defined by the application.
	// This allows for dynamic creation of application objects, potentially supporting different types of applications.
	Application* CreateApplication();

}	