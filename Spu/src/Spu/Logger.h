#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Spu {
	class SPU_API Logger
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
			return s_CoreLogger;
		}

		static std::shared_ptr<spdlog::logger>& GetClientLogger() {
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define SU_CORE_TRACE(...) ::Spu::Logger::GetCoreLogger()->trace(__VA_ARGS__) 
#define SU_CORE_INFO(...) ::Spu::Logger::GetCoreLogger()->info(__VA_ARGS__) 
#define SU_CORE_WARN(...) ::Spu::Logger::GetCoreLogger()->warn(__VA_ARGS__) 
#define SU_CORE_ERROR(...) ::Spu::Logger::GetCoreLogger()->error(__VA_ARGS__) 
#define SU_CORE_FATAL(...) ::Spu::Logger::GetCoreLogger()->fatal(__VA_ARGS__)

#define SU_TRACE(...) ::Spu::Logger::GetClientLogger()->trace(__VA_ARGS__) 
#define SU_INFO(...) ::Spu::Logger::GetClientLogger()->info(__VA_ARGS__) 
#define SU_WARN(...) ::Spu::Logger::GetClientLogger()->warn(__VA_ARGS__) 
#define SU_ERROR(...) ::Spu::Logger::GetClientLogger()->error(__VA_ARGS__) 
#define SU_FATAL(...) ::Spu::Logger::GetClientLogger()->fatal(__VA_ARGS__) 