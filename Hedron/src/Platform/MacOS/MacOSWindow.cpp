	// Precompiled header [hdepch.h] 
#include "hdepch.h"

	// Include necessary header files [MacOSWindow.h]
#include "MacOSWindow.h"


/*//////////////////////////////*/
/* MacOS Window Class Extension */
/*//////////////////////////////*/


	// Define the Hedron namespace
namespace Hedron {

		// Static variable to track GLFW initialization status
	static bool s_GLFWInitialized = false;
	
		// Factory method to create a MacOSWindow instance
	Window* Window::CreateMacOSWindow(const WindowProps& props)
	{
		return new MacOSWindow(props);
	}

		// MacOSWindow constructor
	MacOSWindow::MacOSWindow(const WindowProps& props)
	{
		Init(props);
	}
		// MacOSWindow deconstructor
	MacOSWindow::~MacOSWindow()
	{
		Shutdown();
	}

		// Initialize the MacOSWindow with given properties
	void MacOSWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		
			// Log the creation of the window
		HDE_CORE_INFO("Application Window Created: {0} ({1}, {2})", props.Title, props.Width, props.Height);

			// Initialize GLFW if not already initialized
		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			HDE_CORE_ASSERT(success, "Could not initialize GLFW!");
			s_GLFWInitialized = true;
		}

			// Create a GLFW window with the specified width, height, and title
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		
			// Set the newly created window as the current context
		glfwMakeContextCurrent(m_Window);

			// Associate window properties with the window
		glfwSetWindowUserPointer(m_Window, &m_Data);
	}

		// Cleanup resources associated with the MacOSWindow
	void MacOSWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

		// Handle window updates
	void MacOSWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

		// Method to toggle VSync
	void MacOSWindow::SetVSync(bool enabled)
	{
	}

		// Check if VSync is currently enabled
	bool MacOSWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

}