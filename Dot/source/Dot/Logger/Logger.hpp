#pragma once

#include "../Core.hpp"
#include <memory>
#include <ostream>
#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

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

#define DOT_ENGINE_FATAL(...)     ::dot::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define DOT_ENGINE_ERROR(...)     ::dot::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define DOT_ENGINE_WARN(...)      ::dot::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define DOT_ENGINE_INFO(...)      ::dot::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define DOT_ENGINE_TRACE(...)     ::dot::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define DOT_FATAL(...)            ::dot::Logger::GetClientLogger()->info(__VA_ARGS__)
#define DOT_ERROR(...)            ::dot::Logger::GetClientLogger()->info(__VA_ARGS__)
#define DOT_WARN(...)             ::dot::Logger::GetClientLogger()->info(__VA_ARGS__)
#define DOT_INFO(...)             ::dot::Logger::GetClientLogger()->info(__VA_ARGS__)
#define DOT_TRACE(...)            ::dot::Logger::GetClientLogger()->info(__VA_ARGS__)
