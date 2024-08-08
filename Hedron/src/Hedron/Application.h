#pragma once

#include "Hedron/Core.h"

namespace Hedron {

	class HEDRON_API Application
	{
	public:
		Application();
		virtual ~Application();
			
		void Run();
	};

	//to be defined by clients sandbox
	Application* CreateApplication();


}	