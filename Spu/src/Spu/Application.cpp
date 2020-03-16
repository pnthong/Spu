#include "supch.h"
#include "Application.h"
#include "Spu/Logger.h"

#include <glad/glad.h>

#include "Input.h"

namespace Spu {

// fix the 1st argument to this and the 2nd argument, e.g. an event, will be set by a clients
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::sInstance = nullptr;

	Application::Application() {
		SPU_CORE_ASSERT(!sInstance, "Application already exists");
		sInstance = this;

		mWindow = std::unique_ptr<Window>(Window::Create());
		mWindow->SetEventCallback(BIND_EVENT_FN(OnEvent));

		mImGuiLayer = new ImGuiLayer();
		PushOverlay(mImGuiLayer);
	}

	Application::~Application() {}

	void Application::PushLayer(Layer* layer) {
		mLayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer) {
		mLayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e)	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = mLayerStack.end(); it != mLayerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.mHandled) {
				break;
			}
		}
	}

	void Application::Run() {
		while (mRunning) {
			glClearColor(0, 1, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : mLayerStack) {
				layer->OnUpdate();
			}

			mImGuiLayer->Begin();
				for (Layer* layer : mLayerStack) {
					layer->OnImGuiRender();
				}
			mImGuiLayer->End();

			mWindow->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		mRunning = false;
		return true;
	}
}