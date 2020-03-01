#pragma once

#ifdef SPU_PLATFORM_WINDOWS

extern Spu::Application* Spu::CreateApplication();

int main(int argc, char** argv) {
	auto pSandbox = Spu::CreateApplication();
	pSandbox->Run();
	return 1;
}

#endif