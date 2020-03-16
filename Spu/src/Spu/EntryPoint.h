#pragma once

#ifdef SPU_PLATFORM_WINDOWS

extern Spu::Application* Spu::CreateApplication();

int main(int argc, char** argv) {
	Spu::Logger::Init();
	SU_CORE_WARN("Initialized Log!");
	int a = 5;
	SU_INFO("Hello Client! Var={0}", a);

	auto pSandbox = Spu::CreateApplication();
	pSandbox->Run();
	delete pSandbox;
	return 1;
}

#endif