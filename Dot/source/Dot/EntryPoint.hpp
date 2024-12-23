#pragma once

#include "Application.hpp"
#include "Logger.hpp"

namespace dot{
    extern dot::Application* CreateApplication(void);
}


int main(int argc , char** argv){
    dot::Logger::Init();

    DOT_ENGINE_INFO(" Dot Game Engine logger ");
    DOT_ENGINE_ERROR(" Dot Game Engine logger ");
    DOT_ENGINE_TRACE(" Dot Game Engine logger ");
    DOT_ENGINE_WARN(" Dot Game Engine logger ");
    DOT_ENGINE_FATAL(" Dot Game Engine logger ");

    DOT_INFO("Initiallize Application Client logger ");
    DOT_ERROR("Initiallize Application Client logger ");
    DOT_TRACE("Initiallize Application Client logger ");
    DOT_WARN("Initiallize Application Client logger ");
    DOT_FATAL("Initiallize Application Client logger ");

    dot::Application* application = dot::CreateApplication();

    application->Run();

    delete application;

    return 0;
}

