#include "hdepch.h"

#include "MacOSWindow.h"

namespace Hedron {

	static bool s_GLFWInitialized = false;

	Window* Window::CreateMacOSWindow(const WindowProps& props)
	{
		return new MacOSWindow(props);
	}

	MacOSWindow::MacOSWindow(const WindowProps& props)
	{
		Init(props);
	}

	MacOSWindow::~MacOSWindow()
	{
		Shutdown();
	}

	void MacOSWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		HDE_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			HDE_CORE_ASSERT(success, "Could not initialize GLFW!");
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void MacOSWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void MacOSWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void MacOSWindow::SetVSync(bool enabled)
	{
	}

	bool MacOSWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}