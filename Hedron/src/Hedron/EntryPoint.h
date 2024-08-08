#pragma once

#ifdef HDE_PLATFORM_WINDOWS

extern Hedron::Application* Hedron::CreateApplication();

int main(int argc, char** argv)
{

	auto app = Hedron::CreateApplication();
	app->Run();
	delete app;	
}

#endif	0