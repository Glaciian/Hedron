#pragma once

#include "Event.h"

#include <sstream>

namespace Hedron {

	// Class for keyboard events.
	// Contains a key code to identify which key triggered the event.
	class HEDRON_API KeyEvent : public Event
	{
	public:
		// Getter for the key code associated with the event.
		inline int GetKeyCode() const { return m_KeyCode; }

		// Specifies that this event belongs to the keyboard and input categories.
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		// Constructor initializing the key code.
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		// Stores the key code of the event.
		int m_KeyCode;
	};

	// Specific event for when a key is pressed.
	// Extends KeyEvent with additional information about the number of times the key was repeated.
	class HEDRON_API KeyPressedEvent : public KeyEvent
	{
	public:
		// Constructor initializing the key code and repeat count.
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		// Getter for the repeat count of the key press event.
		inline int GetRepeatCount() const { return m_RepeatCount; }

		// Custom string representation of the event, including key code and repeat count.
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		// Specifies the type of this event as 'KeyPressed'.
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		// Stores the number of times the key was repeated.
		int m_RepeatCount;
	};

	// Specific event for when a key is released.
	// Extends KeyEvent with basic functionality for key release events.
	class HEDRON_API KeyReleasedEvent : public KeyEvent
	{
	public:
		// Constructor initializing the key code.
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		// Custom string representation of the event, including key code.
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		// Specifies the type of this event as 'KeyReleased'.
		EVENT_CLASS_TYPE(KeyReleased)

	};
}