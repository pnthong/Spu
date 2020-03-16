#pragma once

#include "Spu/Core.h"

namespace Spu {
	class SPU_API Input {
	public:
		static bool IsKeyPressed(int keycode) { return sInstance->IsKeyPressedImpl(keycode); }
		static bool IsMouseButtonPressed(int button) { return sInstance->IsMouseButtonPressedImpl(button); }
		static std::pair<float, float> GetMousePosition() { return sInstance->GetMousePositionImpl(); }
		static float GetMouseY() { return sInstance->GetMouseXImpl();}
		static float GetMouseX() { return sInstance->GetMouseYImpl();}

	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;

	protected:
		static Input* sInstance;
	};
}