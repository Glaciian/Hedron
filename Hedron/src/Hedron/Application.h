	// Ensure the header file is included only once during compilation.
#pragma once


/*//////////////////////////////////*/
/* Application lifecycle management */
/*//////////////////////////////////*/


	// Include necessary header files [Hedron/Core.h] [Events/Event.h] and [Window.h]
#include "Hedron/Core.h"
#include "Events/Event.h"
#include "Window.h"

	// Define the Hedron namespace
namespace Hedron {

		// The base class for applications
	class HEDRON_API Application
	{
	public:
			// Constructor for the Application class.
		Application();
			// Virtual destructor to ensure proper cleanup of resources.
		virtual ~Application();
		
			// Main run loop for applications.
			// This method is responsible for starting applications and managing their lifecycle.
		void Run();

	private:
				// Unique pointer to a Window object
				// Manages the application's window, ensuring it is properly created and destroyed
			std::unique_ptr<Window> m_Window;

				// Boolean flag to indicate whether if an application is running.
			bool m_Running = true;

	};

		// The create application function is defined by the application.
		// This allows for dynamic creation of application objects, potentially supporting different types of applications.
	Application* CreateApplication();

}	