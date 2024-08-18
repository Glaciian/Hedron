#pragma once

#include "Event.h"

#include <sstream>

namespace Hedron {

	// Event class for handling window resize events.
	// It carries the new dimensions of the window after resizing.
	class HEDRON_API WindowResizeEvent : public Event
	{
	public:
		// Constructor that initializes the new width and height of the window.
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		// Methods to retrieve the new width and height of the window.
		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		// Override the ToString method to provide a custom string representation of the event.
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		// Macros to specify the type and category of this event.
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		// Member variables storing the new width and height of the window.
		unsigned int m_Width, m_Height;
	};

	// Event class for handling window close events.
	// It signifies that the window has been requested to close.
	class HEDRON_API WindowCloseEvent : public Event
	{
	public:
		// Default constructor.
		WindowCloseEvent() {}

		// Macros to specify the type and category of this event.
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	// Event class for handling application tick events.
	// It signifies that one frame has been completed.
	class HEDRON_API AppTickEvent : public Event
	{
	public:
		// Default constructor.
		AppTickEvent() {}

		// Macros to specify the type and category of this event.
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	// Event class for handling application update events.
	// It signifies that the application state needs to be updated.
	class HEDRON_API AppUpdateEvent : public Event
	{
	public:
		// Default constructor.
		AppUpdateEvent() {}

		// Macros to specify the type and category of this event.
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	// Event class for handling application render events.
	// It signifies that the application needs to render a frame.
	class HEDRON_API AppRenderEvent : public Event
	{
	public:
		// Default constructor.
		AppRenderEvent() {}

		// Macros to specify the type and category of this event.
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}