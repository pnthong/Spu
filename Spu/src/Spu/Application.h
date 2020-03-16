#pragma once
#include "Core.h"

#include "Window.h"
#include "Spu/LayerStack.h"
#include "Spu/Events/ApplicationEvent.h"

#include "Spu/ImGui/ImGuiLayer.h"

namespace Spu {
	class SPU_API Application
	{
	public: 
		static Application& Get() { return *sInstance; }

		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *mWindow; };

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		static Application* sInstance;

		ImGuiLayer* mImGuiLayer;
		std::unique_ptr<Window> mWindow;
		bool mRunning = true;
		LayerStack mLayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
