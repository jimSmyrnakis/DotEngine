#pragma once

#include "Application.hpp"
#include "Logger/Logger.hpp"

namespace dot{
    extern dot::Application* CreateApplication(void);
}


int main(int argc , char** argv){
    dot::Logger::Init();

    DOT_ENGINE_INFO(" Dot Game Engine => Hello World !!!");

    DOT_INFO("Client logger  => Hello World !!!");

    dot::Application* application = dot::CreateApplication();

    application->Run();

    delete application;

    return 0;
}

