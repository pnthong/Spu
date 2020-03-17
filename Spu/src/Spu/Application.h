#pragma once
#include "Core.h"

#include "Window.h"
#include "Spu/LayerStack.h"
#include "Spu/Events/ApplicationEvent.h"

#include "Spu/Renderer/Buffer.h"
#include "Spu/Renderer/Shader.h"

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

		uint mVAO;
		std::unique_ptr<Shader> mShader;
		std::unique_ptr<VertexBuffer> mVB;
		std::unique_ptr<IndexBuffer> mIB;

		ImGuiLayer* mImGuiLayer;
		std::unique_ptr<Window> mWindow;
		bool mRunning = true;
		LayerStack mLayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
