#pragma once

#include "Event.h"

namespace Spu {
	class SPU_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y) noexcept
			: mMouseX(x), mMouseY(y) {}

		float GetX() const noexcept { return mMouseX; }
		float GetY() const noexcept { return mMouseY; }

		std::string ToString() const noexcept override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << mMouseX << ", " << mMouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float mMouseX, mMouseY;
	};

	class SPU_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xOffset, float yOffset) noexcept
			: mXOffset(yOffset), mYOffset(yOffset) {}

		float GetXOffset() const noexcept { return mXOffset; }
		float GetYOffset() const noexcept { return mYOffset; }

		std::string ToString() const noexcept override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << mXOffset << ", " << mYOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float mXOffset, mYOffset;
	};

	class SPU_API MouseButtonEvent : public Event {
	public:
		int GetMouseButton() const noexcept { return mButton; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int btn) noexcept
			: mButton(btn) {}
		
		int mButton;
	};

	class SPU_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int btn) noexcept
			:MouseButtonEvent(btn) {}

		std::string ToString() const noexcept override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << mButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class SPU_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int btn) noexcept
			:MouseButtonEvent(btn) {}

		std::string ToString() const noexcept override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << mButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}