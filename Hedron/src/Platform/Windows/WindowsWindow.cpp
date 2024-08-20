	// Precompiled header [hdepch.h] 
#include "hdepch.h"

	// Include necessary header files [WindowsWindow.h]
#include "WindowsWindow.h"


/*////////////////////////////////*/
/* Windows Window Class Extension */
/*////////////////////////////////*/


	// Define the Hedron namespace
namespace Hedron {

		// Static variable to track GLFW initialization status
	static bool s_GLFWInitialized = false;

		// Factory method to create a WindowsWindow instance
	Window* Window::CreateWindowsWindow(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

		// WindowsWindow constructor
	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

		// MacOSWindow deconstructor
	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

		// Initialize the WindowsWindow with given properties
	void WindowsWindow::Init(const WindowProps& props)
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
		SetVSync(true);
	}

		// Cleanup resources associated with the WindowsWindow
	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

		// Handle window updates
	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

		// Method to toggle VSync
	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

		// Check if VSync is currently enabled
	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}
