#pragma once
#include <memory>
#include <Engine3DLinux/Core/core.h>
#include <spdlog/spdlog.h>
#include <fmt/core.h>
#include <spdlog/fmt/ostr.h>
#include <cstdarg>

namespace Engine3DLinux{

    class ENGINE_API EngineLogger{
    public:
        EngineLogger();
        ~EngineLogger();

        static void Init();

        // If either coreLogger or clientLogger is nullptr
        // Then we should automatically terminate the app.
        // This is because if we continue, we will segfault due to the coreLogger/clientLogger not being initialized
        static bool isLoggerInit() {
            return (coreLogger == nullptr || clientLogger == nullptr);
        }

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger(){
            if(EngineLogger::isLoggerInit()){
                // spdlog::fatal("EngineLogger::Init() needs to be called!\nEngineLogger::Init() returns a nullptr");
                spdlog::log(spdlog::level::critical, "EngineLogger::Init() needs to be called!\n");
                std::terminate();
            }
            return coreLogger;
        }

        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
            if(EngineLogger::isLoggerInit()){
                // Logger::fatal("EngineLogger::Init() needs to be called!\n");
                spdlog::log(spdlog::level::critical, "EngineLogger::Init() needs to be called!\n");
                std::terminate();
            }
            
            return clientLogger;
        }

    private:
        // static std::shared_ptr<Logger::Log> coreLogger;
        // static std::shared_ptr<Logger::Log> clientLogger;
        static std::shared_ptr<spdlog::logger> coreLogger;
        static std::shared_ptr<spdlog::logger> clientLogger;
    };
};

// ------------ core logs ------------

#define CORE_TRACE(...) Engine3DLinux::EngineLogger::GetCoreLogger()->trace(__VA_ARGS__);

template<typename... T>
inline void coreLogTrace2(fmt::format_string<T...> fmt, T&&... args) {
    Engine3DLinux::EngineLogger::GetCoreLogger()->trace(fmt, std::forward<T>(args)...);
}

template<typename... T>
inline void coreLogTrace(fmt::format_string<T...> fmt, T&&... args) {
    Engine3DLinux::EngineLogger::GetCoreLogger()->trace(fmt, std::forward<T>(args)...);
}

template<typename... T>
inline void coreLogInfo(fmt::format_string<T...> fmt, T&&... args) {
    Engine3DLinux::EngineLogger::GetCoreLogger()->info(fmt, std::forward<T>(args)...);
}

template<typename... T>
inline void coreLogWarn(fmt::format_string<T...> fmt, T &&...args) {
    Engine3DLinux::EngineLogger::GetCoreLogger()->warn(fmt, std::forward<T>(args)...);
}

template<typename... T>
inline void coreLogError(fmt::format_string<T...> fmt, T &&...args) {
    Engine3DLinux::EngineLogger::GetCoreLogger()->error(fmt, std::forward<T>(args)...);
}

template<typename... T>
inline void coreLogFatal(fmt::format_string<T...> fmt, T &&...args) {
    // Engine3DLinux::EngineLogger::GetCoreLogger()->fatal(fmt, std::forward<T>(args)...);
    Engine3DLinux::EngineLogger::GetCoreLogger()->critical(fmt, std::forward<T>(args)...);
}

// ------------ Client logs ------------
template<typename... T>
inline void clientLogTrace(fmt::format_string<T...> fmt, T &&...args) {
    Engine3DLinux::EngineLogger::GetClientLogger()->trace(fmt, std::forward<T>(args)...);
}

template<typename... T>
inline void clientLogInfo(fmt::format_string<T...> fmt, T &&...args) {
    Engine3DLinux::EngineLogger::GetClientLogger()->info(fmt, std::forward<T>(args)...);
}

template<typename... T>
inline void clientLogWarn(fmt::format_string<T...> fmt, T &&...args) {
    Engine3DLinux::EngineLogger::GetClientLogger()->warn(fmt, std::forward<T>(args)...);
}

template<typename... T>
inline void clientLogError(fmt::format_string<T...> fmt, T &&...args) {
    Engine3DLinux::EngineLogger::GetClientLogger()->error(fmt, std::forward<T>(args)...);
}

template<typename... T>
inline void clientLogFatal(fmt::format_string<T...> fmt, T &&...args) {
    Engine3DLinux::EngineLogger::GetClientLogger()->critical(fmt, std::forward<T>(args)...);
}
