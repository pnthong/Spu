#pragma once

#include "Event.h"

namespace Spu {
	class SPU_API KeyEvent : public Event {
	public:
		int GetKeyCode() const noexcept {
			return mKeyCode;
		}

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(int keycode) noexcept
			: mKeyCode(keycode) {}

		int mKeyCode;
	};

	class SPU_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatCount) noexcept
			: KeyEvent(keycode), mRepeatCount(repeatCount) {}

		int GetRepeatCount() const {
			return mRepeatCount;
		}

		std::string ToString() const noexcept override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << mKeyCode << "(" << mRepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int mRepeatCount;
	};

	class SPU_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keycode) noexcept
			: KeyEvent(keycode) {}

		std::string ToString() const noexcept override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << mKeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class SPU_API KeyTypedEvent : public KeyEvent {
	public:
		KeyTypedEvent(int keycode) noexcept
			: KeyEvent(keycode) {}

		std::string ToString() const noexcept override {
			std::stringstream ss;
			ss << "KeyTypedEvent: " << mKeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}