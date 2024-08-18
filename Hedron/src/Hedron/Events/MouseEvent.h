#pragma once

#include "Event.h"

#include <sstream>

namespace Hedron {

	// Event class for handling mouse movement events.
	// It carries the new position of the mouse cursor.
	class HEDRON_API MouseMovedEvent : public Event
	{
	public:
		// Constructor that initializes the new X and Y coordinates of the mouse cursor.
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}

		// Methods to retrieve the new X and Y coordinates of the mouse cursor.
		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		// Override the ToString method to provide a custom string representation of the event.
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		// Macros to specify the type and category of this event.
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		// Member variables storing the new X and Y coordinates of the mouse cursor.
		float m_MouseX, m_MouseY;
	};

	// Event class for handling mouse scroll wheel events.
	// It carries the amount of horizontal and vertical scrolling
	class HEDRON_API MouseScrolledEvent : public Event
	{
	public:
		// Constructor that initializes the amount of horizontal and vertical scrolling.
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		// Methods to retrieve the amount of horizontal and vertical scrolling.
		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		// Override the ToString method to provide a custom string representation of the event.
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		// Macros to specify the type and category of this event.
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput) 

	private:
		// Member variables storing the amount of horizontal and vertical scrolling.
		float m_XOffset, m_YOffset;
	};

	// Base class for all mouse button events.
	// It carries the ID of the mouse button involved in the event.
	class HEDRON_API MouseButtonEvent : public Event
	{
	public:
		// Method to retrieve the ID of the mouse button.
		inline int GetMouseButton() const { return m_Button; }

		// Macros to specify the category of this event.
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		// Constructor that initializes the ID of the mouse button.
		MouseButtonEvent(int button)
			: m_Button(button) {}

		// Member variable storing the ID of the mouse button.
		int m_Button;
	};

	// Event class for handling mouse button press events.
	// It specifies that a mouse button has been pressed.
	class HEDRON_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		// Constructor that initializes the ID of the mouse button.
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		// Override the ToString method to provide a custom string representation of the event.
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		// Macros to specify the type of this event.
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	// Event class for handling mouse button release events.
	// It specifies that a mouse button has been released.
	class HEDRON_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		// Constructor that initializes the ID of the mouse button.
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		// Override the ToString method to provide a custom string representation of the event.
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		// Macros to specify the type of this event.
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}