#pragma once
#include "Spu/Window.h"
#include <GLFW/glfw3.h>

namespace Spu {
	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;
		uint GetWidth() const override { return mData.Width; }
		uint GetHeight() const override { return mData.Height; }

		// Set "callback" func that gets an event as input
		// so every time we receivce an event from the GLFW this callback will handle it
		void SetEventCallback(const EventCallbackFn& callback) override {
			mData.EventCallback = callback;
		};

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
		
		void* GetNativeWindow() const override { return mWindow; }

	private:
		// This func generates events which are dispatched and handled by the "callback" func
		void GenerateEvents();
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* mWindow;

		struct WindowData {
			std::string Title;
			uint Width, Height;
			bool VSync;

			// using EventCallbackFnc = std::function<void(Event&)>;
			EventCallbackFn EventCallback;
		};

		WindowData mData;
	};
}