#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>

namespace Spu {
	class SPU_API Logger
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// log macros for the engine
#define LogCoreTrace(...)	Spu::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define LogCoreInfo(...)	Spu::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define LogCoreWarn(...)	Spu::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define LogCoreError(...)	Spu::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define LogCoreFatal(...)	Spu::Logger::GetCoreLogger()->fatal(__VA_ARGS__)

// log macros for clients
#define LogTrace(...)	Spu::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define LogInfo(...)	Spu::Logger::GetClientLogger()->info(__VA_ARGS__)
#define LogWarn(...)	Spu::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define LogError(...)	Spu::Logger::GetClientLogger()->error(__VA_ARGS__)
#define LogFatal(...)	Spu::Logger::GetClientLogger()->fatal(__VA_ARGS__)