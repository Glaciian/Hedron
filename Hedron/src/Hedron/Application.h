#pragma once

// Application definitions and structure.

#include "Hedron/Core.h"

namespace Hedron {

	class HEDRON_API Application
	{
	public:
		Application();
		virtual ~Application();
			
		void Run();
	};

	// The create application function is defined by the application.
	Application* CreateApplication();

}	