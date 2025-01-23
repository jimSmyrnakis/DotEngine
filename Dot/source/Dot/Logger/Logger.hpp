
#pragma once
#include "../Core.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace dot{


    class Logger{

        public:

        static void Init(void);

        static std::shared_ptr<spdlog::logger>& GetEngineLogger(void);
        static std::shared_ptr<spdlog::logger>& GetClientLogger(void);
        
        private:
        static std::shared_ptr<spdlog::logger> s_EngineLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger; 

    };
};

//Engine Core Log message for errors , warnings , info , trace ...
#define DOT_ENGINE_FATAL(...)     ::dot::Logger::GetEngineLogger()->error(__VA_ARGS__)
#define DOT_ENGINE_ERROR(...)     ::dot::Logger::GetEngineLogger()->error(__VA_ARGS__)
#define DOT_ENGINE_WARN(...)      ::dot::Logger::GetEngineLogger()->warn(__VA_ARGS__)
#define DOT_ENGINE_INFO(...)      ::dot::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define DOT_ENGINE_TRACE(...)     ::dot::Logger::GetEngineLogger()->trace(__VA_ARGS__)
//Clieant Application Log message for errors , warnings , info , trace ...
#define DOT_FATAL(...)            ::dot::Logger::GetClientLogger()->error(__VA_ARGS__)
#define DOT_ERROR(...)            ::dot::Logger::GetClientLogger()->error(__VA_ARGS__)
#define DOT_WARN(...)             ::dot::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define DOT_INFO(...)             ::dot::Logger::GetClientLogger()->info(__VA_ARGS__)
#define DOT_TRACE(...)            ::dot::Logger::GetClientLogger()->trace(__VA_ARGS__)
