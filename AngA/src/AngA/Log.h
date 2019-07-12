#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace AngA {
	class ANGA_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core Log Macros
#define ANGA_CORE_TRACE(...) ::AngA::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ANGA_CORE_INFO(...) ::AngA::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ANGA_CORE_WARN(...) ::AngA::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ANGA_CORE_ERROR(...) ::AngA::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ANGA_CORE_FATAL(...) ::AngA::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define ANGA_TRACE(...) ::AngA::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ANGA_INFO(...) ::AngA::Log::GetClientLogger()->info(__VA_ARGS__)
#define ANGA_WARN(...) ::AngA::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ANGA_ERROR(...) ::AngA::Log::GetClientLogger()->error(__VA_ARGS__)
#define ANGA_FATAL(...) ::AngA::Log::GetClientLogger()->fatal(__VA_ARGS__)