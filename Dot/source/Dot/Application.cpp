#include "Application.hpp"


dot::Application::Application(void){
    m_Window = std::unique_ptr<Window>(Window::Create());
    m_Running = true;
}

dot::Application::~Application(void){
    
}

void dot::Application::Run(void){
    while(m_Running){
        
        m_Window->OnUpdate();
    }
}