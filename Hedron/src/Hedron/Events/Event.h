#pragma once

#include "Hedron/Core.h"

namespace Hedron {
	// Define an enumeration for different types of events that can occur in the system.
	// These include window-related events, application lifecycle events, and user input events.
	// TODO: Events are currently blocking and need to be buffered in an event bus and processed during the "event" update stage.

	// Describes the type of an event. 
	// Some Event types are speculated for future use.
	enum class EventType
	{
		None = 0,																// Represents no event type.
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,	// Window events.
		AppTick, AppUpdate, AppRender,											// Application lifecycle events.
		KeyPressed, KeyReleased, KeyTyped,										// Keyboard input events.
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled		// Mouse input events.
	};

	// Event filters by category.
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};
	
// Macro definitions to simplify the implementation of common functionalities in event classes.
// These macros generate boilerplate code for getting the event type, name, and category.
#define EVENT_CLASS_TYPE(type) \
	static EventType GetStaticType() { return EventType::type; }\
	virtual EventType GetEventType() const override { return GetStaticType(); }\
	virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
	 virtual int GetCategoryFlags() const override { return category; }

	// Base class for all events.
	// Provides a common interface for events, including methods for getting the event type, name, and category.
	// Also includes a method to check if an event has been handeled.
	class HEDRON_API Event {

		friend class EventDispatcher; // Allow EventDispatcher access to private members.
		public:
			// Pure virtual methods that must be overridden by derived classes.
			virtual EventType GetEventType() const = 0;
			virtual const char* GetName() const = 0; // TODO: GetName should be HDE_DEBUG only.
			virtual int GetCategoryFlags() const = 0;
			virtual std::string ToString() const { return GetName(); }

			// Checks if the event belongs to a specific category.
			inline bool IsInCategory(EventCategory category)
			{
				return GetCategoryFlags() & category;
			}
	protected:
		// Indicates whether the event has been handled.
		bool m_Handled = false;
	};

	// Handles the dispatching of events to their respective handlers.
	// Uses templates to support any type of event.
	class EventDispatcher {
		// Alias for a function pointer that takes a reference to an event and returns a boolean.
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		// Constructor initializes the dispatcher with a specific event.
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		// Dispatches the event to its handler.
		// Returns true if the event was handled, false otherwise.
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			// Checks if the event type matches the expected type.
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				// Calls the handler function with the event and sets the handled flag.
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		// Reference to the event being dispatched.
		Event& m_Event;
	};
}