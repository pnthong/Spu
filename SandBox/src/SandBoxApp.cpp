#include <Spu.h>

class Sandbox: public Spu::Application {
public:
	Sandbox() {};
	~Sandbox() {};
};

Spu::Application* Spu::CreateApplication() {
	return new Sandbox();
}