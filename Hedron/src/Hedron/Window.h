	// Ensure header files are included only once
#pragma once

	// Precompiled header [hdepch.h] 
#include "hdepch.h"

	// Include necessary header files [Hedron/Core.h] and [Events/Event.h]
#include "Hedron/Core.h"
#include "Hedron/Events/Event.h"


/*////////////////////////////////*/
/* Base Window class and stucture */
/*////////////////////////////////*/


	// Define the Hedron namespace
namespace Hedron {

		// Structure to hold properties for creating a window
	struct WindowProps
	{
			// Properties
		std::string Title;
		unsigned int Width;
		unsigned int Height;

			// Default constructor with default values
		WindowProps(const std::string& title = "Hedron Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

		// Abstract base class for a desktop system-based window
		// This class will be inherited by the platform-specific window
	class HEDRON_API Window
	{
	public:
			// Type alias for event callback function
		using EventCallbackFn = std::function<void(Event&)>;

			// Virtual destructor
		virtual ~Window() {}

			// Pure virtual methods to be overridden by derived classes
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

			// Methods to set and query window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

			// Factory methods to create windows for different platforms
		static Window* CreateWindowsWindow(const WindowProps& props = WindowProps());
		static Window* CreateMacOSWindow(const WindowProps& props = WindowProps());

	};
}