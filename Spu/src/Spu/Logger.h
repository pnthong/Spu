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

// for the engine
template<typename ...Args>
inline void LogCoreTrace(const char* format, Args...args) {
	Spu::Logger::GetCoreLogger()->trace(format, std::forward<Args>(args)...);
}

template<typename ...Args>
inline void LogCoreInfo(const char* format, Args...args) {
	Spu::Logger::GetCoreLogger()->info(format, std::forward<Args>(args)...);
}

template<typename ...Args>
inline void LogCoreWarn(const char* format, Args...args) {
	Spu::Logger::GetCoreLogger()->warn(format, std::forward<Args>(args)...);
}

template<typename ...Args>
inline void LogCoreError(const char* format, Args...args) {
	Spu::Logger::GetCoreLogger()->error(format, std::forward<Args>(args)...);
}

template<typename ...Args>
inline void LogCoreFatal(const char* format, Args...args) {
	Spu::Logger::GetCoreLogger()->fatal(format, std::forward<Args>(args)...);
}

// For clients
template<typename ...Args>
inline void LogTrace(const char* format, Args...args) {
	Spu::Logger::GetClientLogger()->trace(format, std::forward<Args>(args)...);
}

template<typename ...Args>
inline void LogInfo(const char* format, Args...args) {
	Spu::Logger::GetClientLogger()->info(format, std::forward<Args>(args)...);
}

template<typename ...Args>
inline void LogWarn(const char* format, Args...args) {
	Spu::Logger::GetClientLogger()->warn(format, std::forward<Args>(args)...);
}

template<typename ...Args>
inline void LogError(const char* format, Args...args) {
	Spu::Logger::GetClientLogger()->error(format, std::forward<Args>(args)...);
}

template<typename ...Args>
inline void LogFatal(const char* format, Args...args) {
	Spu::Logger::GetClientLogger()->fatal(format, std::forward<Args>(args)...);
}