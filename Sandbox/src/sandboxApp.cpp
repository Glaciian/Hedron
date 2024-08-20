	// Precompiled header [hdepch.h] 
#include "hdepch.h"

/*/////////////////////*/
/* Sandbox Application */
/*/////////////////////*/

	// Include necessary header files [Hedron.h]
#include <Hedron.h>

	// Sandbox Class.
class Sandbox : public Hedron::Application
{
public:
		// Sandbox Constructor.
	Sandbox()
	{

	}

		// Sandbox Destructor.
	~Sandbox()
	{

	}
};

	// Create Application.
Hedron::Application* Hedron::CreateApplication()
{
		// Create a new instance of the Sandbox class and return a pointer to it.
	return new Sandbox();
}