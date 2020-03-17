#pragma once

#include "supch.h"
#include "Core.h"
#include "Events/Event.h"

namespace Spu {
	struct WindowProps {
		std::string Title;
		uint Width, Height;

		WindowProps(const std::string& title = "Spu Engine",
					uint w = 1280, 
					uint h = 720)
			: Title(title), Width(w), Height(h) {}
	};

	class SPU_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual uint GetWidth() const noexcept = 0;
		virtual uint GetHeight() const noexcept = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const noexcept = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}