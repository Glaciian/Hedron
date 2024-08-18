#include "hdepch.h"

#include <Hedron.h>

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

Hedron::Application* Hedron::CreateApplication()
{
	// Create a new instance of the Sandbox class and return a pointer to it.
	return new Sandbox();
}