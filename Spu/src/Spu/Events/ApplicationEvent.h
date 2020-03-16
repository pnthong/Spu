#pragma once

#include "Event.h"

namespace Spu {
	class SPU_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(uint width, uint height)
			: mWidth(width), mHeight(height) {};

		uint GetWidth() const {
			return mWidth;
		}

		uint GetHeight() const {
			return mHeight;
		}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizedEvent: " << mWidth << ", " << mHeight;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResized)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		uint mWidth, mHeight;
	};

	class SPU_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClosed)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class SPU_API AppTickEvent : public Event {
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class SPU_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class SPU_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}