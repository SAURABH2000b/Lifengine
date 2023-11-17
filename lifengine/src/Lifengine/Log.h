#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Lifengine {

	class LIFENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
//:: in front of identifiers tells compiler to use the following identifiers from global scope
#define LG_CORE_TRACE(...)		::Lifengine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LG_CORE_INFO(...)		::Lifengine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LG_CORE_WARN(...)		::Lifengine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LG_CORE_ERROR(...)		::Lifengine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LG_CORE_FATAL(...)		::Lifengine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Clent log macros
#define LG_TRACE(...)		    ::Lifengine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LG_INFO(...)		    ::Lifengine::Log::GetClientLogger()->info(__VA_ARGS__)
#define LG_WARN(...)		    ::Lifengine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LG_ERROR(...)		    ::Lifengine::Log::GetClientLogger()->error(__VA_ARGS__)
#define LG_FATAL(...)		    ::Lifengine::Log::GetClientLogger()->fatal(__VA_ARGS__)