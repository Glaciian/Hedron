	// Ensure header files are included only once
#pragma once

	// Include necessary header files [Hedron/Window.h] and [GLFW/glfw3.h]
#include "Hedron/Window.h"
#include <GLFW/glfw3.h>


/*////////////////////////////////////*/
/* MacOS Window Extension Header File */
/*////////////////////////////////////*/


	// Define the Hedron namespace
namespace Hedron {

		// MacOSWindow class definition, derived from the base Window class
	class MacOSWindow : public Window
	{
	public:
			// Constructor for MacOSWindow, taking window properties as input
		MacOSWindow(const WindowProps& props);
		
			// Virtual destructor to properly clean up resources
		virtual ~MacOSWindow();
		
			// Override the OnUpdate method from the base class
		void OnUpdate() override;

			// Getter methods for window dimensions
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

			// Setter method for event callback
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }

			// Methods to control VSync
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
			// Initialization method for the window
		virtual void Init(const WindowProps& props);
			// Cleanup method for the window
		virtual void Shutdown();

	private:
			// Pointer to the GLFW window
		GLFWwindow* m_Window;

			// Struct to hold window data
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

			// Instance of WindowData to store window properties
		WindowData m_Data;

	};

}