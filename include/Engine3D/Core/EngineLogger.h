#pragma once
#include <memory>
#include <Engine3D/Core/core.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Engine3D{

	class ENGINE_API EngineLogger{
	public:
		EngineLogger() = default;
		~EngineLogger() = default;

		static void Init();

		// @note Checking if the current instance of the logger has been instanced.
		static bool isInit(){
			return (coreLogger == nullptr || clientLogger == nullptr);
		}

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger(){
			if(EngineLogger::isInit()){
				spdlog::log(spdlog::level::critical, "EngineLogger::Init() needs to be called!\n");
				std::terminate();
			}

			return coreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& getClientLogger(){
			if(EngineLogger::isInit()){
				spdlog::log(spdlog::level::critical, "EngineLogger::Init() needs to be called!\n");
				std::terminate();
			}

			return clientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
};

template<typename... T>
inline void coreLogTrace(spdlog::format_string_t<T...> fmt, T&&... args){
	return Engine3D::EngineLogger::getCoreLogger()->trace(fmt, std::forward<T>(args)...);
}

template<typename... T>
inline void coreLogInfo(spdlog::format_string_t<T...> fmt, T&&... args){
	return Engine3D::EngineLogger::getCoreLogger()->info(fmt, std::forward<T>(args)...);
}

template<typename... T>
inline void coreLogWarn(spdlog::format_string_t<T...> fmt, T&&... args){
	return Engine3D::EngineLogger::getCoreLogger()->warn(fmt, std::forward<T>(args)...);
}

template<typename... T>
inline void coreLogError(spdlog::format_string_t<T...> fmt, T&&... args){
	return Engine3D::EngineLogger::getCoreLogger()->error(fmt, std::forward<T>(args)...);
}

template<typename... T>
inline void coreLogFatal(spdlog::format_string_t<T...> fmt, T&&... args){
	return Engine3D::EngineLogger::getCoreLogger()->critical(fmt, std::forward<T>(args)...);
}

//@note ------------ Client logs ------------
template<typename... T>
inline void clientLogTrace(spdlog::format_string_t<T...> fmt, T &&...args) {
    Engine3D::EngineLogger::getClientLogger()->trace(fmt, std::forward<T>(args)...);
}

template<typename... T>
inline void clientLogInfo(spdlog::format_string_t<T...> fmt, T &&...args) {
    Engine3D::EngineLogger::getClientLogger()->info(fmt, std::forward<T>(args)...);
}

template<typename... T>
inline void clientLogWarn(spdlog::format_string_t<T...> fmt, T &&...args) {
    Engine3D::EngineLogger::getClientLogger()->warn(fmt, std::forward<T>(args)...);
}

template<typename... T>
inline void clientLogError(spdlog::format_string_t<T...> fmt, T &&...args) {
    Engine3D::EngineLogger::getClientLogger()->error(fmt, std::forward<T>(args)...);
}

template<typename... T>
inline void clientLogFatal(spdlog::format_string_t<T...> fmt, T &&...args) {
    Engine3D::EngineLogger::getClientLogger()->critical(fmt, std::forward<T>(args)...);
}
