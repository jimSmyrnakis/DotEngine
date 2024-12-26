#include "Application.hpp"

void OnEventWrapper(dot::Event& e){
    DOT_ENGINE_INFO("{0}" , e);
}

dot::Application::Application(void){
    m_Window = std::unique_ptr<Window>(Window::Create());
    m_Running = true;
    m_Window->SetEventCallBack(OnEventWrapper);
}

dot::Application::~Application(void){
    
}

void dot::Application::Run(void){
    while(m_Running){
        
        m_Window->OnUpdate();
    }
}

void dot::Application::OnEvent(Event& e){
    DOT_ENGINE_INFO("{0}" , e);
}

