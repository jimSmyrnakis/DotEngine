#pragma once

#include "Application.hpp"

namespace dot{
    extern dot::Application* CreateApplication(void);
}


int main(int argc , char** argv){
    dot::Application* application = dot::CreateApplication();

    application->Run();

    delete application;

    return 0;
}