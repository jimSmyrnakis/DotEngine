
#pragma once

#include "Application.hpp"
#include "Logger/Logger.hpp"

namespace dot{
    extern dot::Application* CreateApplication(void);
}


int main(int argc , char** argv){
    dot::Logger::Init();

    dot::Application* application = dot::CreateApplication();

    application->Run();

    delete application;

    return 0;
}

