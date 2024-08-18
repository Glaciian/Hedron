#pragma once

// Application definitions and structure.

#include "Hedron/Core.h"
#include "Events/Event.h"

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
	};

	// The create application function is defined by the application.
	// This allows for dynamic creation of application objects, potentially supporting different types of applications.
	Application* CreateApplication();

}	