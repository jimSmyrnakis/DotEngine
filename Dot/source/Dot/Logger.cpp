#include "Logger.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>


static std::shared_ptr<spdlog::logger> s_EngineLogger;
static std::shared_ptr<spdlog::logger> s_ClientLogger; 

void dot::Logger::Init(void){
    // logger format 
    // %l log level message (info , debbug , error , warning etc)
    // %c full date and time repersetation
    // %v the actual text message
    // %^ start color text range
    // %$ end color text range

    spdlog::set_pattern("%^%l [%n] : \"%v\" %c %$");

    // create a console for our engine with name Dot -> name of our engine
    s_EngineLogger = spdlog::stdout_color_mt("Dot Engine");
    // create a console for our client(like sandbox) -> client
    s_ClientLogger = spdlog::stdout_color_mt("Application");

    s_EngineLogger->set_level(spdlog::level::trace);
    s_ClientLogger->set_level(spdlog::level::trace);

            
}

void dot::Logger::setEngineFatalToLogger(const char* msg){
    s_EngineLogger->error(msg);
}
void dot::Logger::setEngineErrorToLogger(const char* msg){
    s_EngineLogger->error(msg);
}
void dot::Logger::setEngineWarnToLogger(const char* msg){
    s_EngineLogger->warn(msg);
}
void dot::Logger::setEngineInfoToLogger(const char* msg){
    s_EngineLogger->info(msg);
}
void dot::Logger::setEngineTraceToLogger(const char* msg){
    s_EngineLogger->trace(msg);
}

void dot::Logger::setClientFatalToLogger(const char* msg){
    s_ClientLogger->error(msg);
}
void dot::Logger::setClientErrorToLogger(const char* msg){
    s_ClientLogger->error(msg);
}
void dot::Logger::setClientWarnToLogger(const char* msg){
    s_ClientLogger->warn(msg);
}
void dot::Logger::setClientInfoToLogger(const char* msg){
    s_ClientLogger->info(msg);
}
void dot::Logger::setClientTraceToLogger(const char* msg){
    s_ClientLogger->trace(msg);
}