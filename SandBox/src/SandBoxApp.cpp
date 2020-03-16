#include <Spu.h>

class ExLayer : public Spu::Layer {
public:
	ExLayer() 
		: Layer("Example") {}

	void OnUpdate() override {
		if (Spu::Input::IsKeyPressed(SU_KEY_TAB)) {
			SU_TRACE("Tab key is pressed (poll)!");
		}
	}

	void OnEvent(Spu::Event& e) override {
		if (e.GetEventType() == Spu::EventType::KeyPressed) {
			Spu::KeyPressedEvent& event = (Spu::KeyPressedEvent&)e;
			if (event.GetKeyCode() == SU_KEY_TAB) {
				SU_TRACE("Tab key is pressed (event)!");
			}

			SU_TRACE("{0}", (char)event.GetKeyCode());
		}
	}
};

class Sandbox: public Spu::Application {
public:
	Sandbox() {
		PushLayer(new ExLayer());
		PushOverlay(new Spu::ImGuiLayer());
	};
	~Sandbox() {};
};

Spu::Application* Spu::CreateApplication() {
	return new Sandbox();
}