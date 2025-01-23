
#include "Logger.hpp"


std::shared_ptr<spdlog::logger> dot::Logger::s_EngineLogger;
std::shared_ptr<spdlog::logger> dot::Logger::s_ClientLogger;

std::shared_ptr<spdlog::logger>& dot::Logger::GetEngineLogger(void){ return Logger::s_EngineLogger; }
std::shared_ptr<spdlog::logger>& dot::Logger::GetClientLogger(void){ return Logger::s_ClientLogger; }

void dot::Logger::Init(void){
    // logger format 
    // %l log level message (info , debbug , error , warning etc)
    // %c full date and time repersetation
    // %v the actual text message
    // %^ start color text range
    // %$ end color text range

    spdlog::set_pattern("%^%l [%n] : \"%v\" %c %$");

    // create a console for our engine with name Dot -> name of our engine
    Logger::s_EngineLogger = spdlog::stdout_color_mt("Dot Engine");
    Logger::s_EngineLogger->set_level(spdlog::level::trace);
    // create a console for our client(like sandbox) -> client
    Logger::s_ClientLogger = spdlog::stdout_color_mt("Application");
    Logger::s_ClientLogger->set_level(spdlog::level::trace);
}
