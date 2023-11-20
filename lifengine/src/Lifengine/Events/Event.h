#pragma once

#include "lgpch.h"
#include "Lifengine/Core.h"

namespace Lifengine {
	//The currently implemented event system is blocking in nature, which means
	//whenever a window event occur, the control immediately goes to a callback
	//function. Until the callback function completes its processing, theapplication
	//logic as well as event detection logic are blocked, which means any application
	//events during that interval will be ignored. Better approach will be to store the
	//continuously incoming events into a buffer (queue), then deal with these events in the
	//event handling stage (no callback) by popping out the entries. The later approach 
	//can help to stabalize the frame rate, by allowing only a fixed number (or lesser
	// than that) of events to be handled per frame.

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	//EventCategory enum is used to filter out the events. Instead of assigning integer values
	//to the elements we are using bit fields so that an event can be a part of multiple categories.

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication		= BIT(0),
		EventCategoryInput				= BIT(1),
		EventCategoryKeyboard			= BIT(2),
		EventCategoryMouse				= BIT(3),
		EventCategoryMouseButton		= BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
                               virtual EventType GetEventType() const override { return GetStaticType(); }\
							   virtual const char* GetName() const override { return #type; }
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category; }

	class LIFENGINE_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>; //EventFn is an alias of std::function<bool(T&)>
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{

		}
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled |= func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	//operator overloading of '<<' as needed by spdlog logger (spdlog/fmt/ostr.h)
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}