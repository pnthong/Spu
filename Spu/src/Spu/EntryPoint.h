#pragma once

#ifdef SPU_PLATFORM_WINDOWS

extern Spu::Application* Spu::CreateApplication();

int main(int argc, char** argv) {
	Spu::Logger::Init();
	LogCoreWarn("Initialized Log!");
	int a = 5;
	LogInfo("Hello Client! Var={0}", a);

	auto pSandbox = Spu::CreateApplication();
	pSandbox->Run();
	return 1;
}

#endif