#pragma once
#include "supch.h"
#include "Spu/Core.h"

namespace Spu {
	
	enum class EventType {
		None = 0,
		WindowClosed, WindowResized, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed,	MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class SPU_API Event {

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { 
			return GetName(); 
		};

		bool IsInCategory(EventCategory category) const {
			return GetCategoryFlags() & category;
		}

		bool mHandled = false;
	};

	class EventDispatcher {
		// A function takes a window resize event (T) and return a boolean
		template<typename T> // T is an event type
		using EventFn = std::function<bool>(T&);

	public:
		EventDispatcher(Event& event) 
			: mEvent(event) {}

		// If the event we wanna dispatch matches the type of this function (T), we run that function 
		/*template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (mEvent.GetEventType() == T::GetStaticType()) {
				mEvent.mHandled = func(*(T*)&mEvent);
				return true;
			}
			return false;
		}*/

		template<typename T, typename F>
		bool Dispatch(const F& func) {
			if (mEvent.GetEventType() == T::GetStaticType()) {
				mEvent.mHandled = func(static_cast<T&>(mEvent));
				return true;
			}
			return false;
		}

	private:
		Event& mEvent;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}