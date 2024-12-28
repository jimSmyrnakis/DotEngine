#include "Application.hpp"
#include <glad/glad.h>

#define BIND_EVENT_FUN(x) std::bind(&Application::x , this , std::placeholders::_1)

dot::Application::Application(void){
    m_Window = std::unique_ptr<Window>(Window::Create());
    m_Running = true;
    m_Window->SetEventCallBack(BIND_EVENT_FUN(OnEvent));

    uint32_t id;
    glGenVertexArrays(1 , &id);
}

dot::Application::~Application(void){
    
}

void dot::Application::Run(void){
    while(m_Running){
        
        for (auto it = m_LayersStack.Begin() ; it != m_LayersStack.End() ; it++)
            (*it)->OnUpdate();
        
        m_Window->OnUpdate();
    }
}

void dot::Application::OnEvent(Event& e){
    //DOT_ENGINE_INFO("{0}" , e);
    dot::EventDispatcher dispatcher(e);
    dispatcher.Dispatch<dot::WindowCloseEvent>(BIND_EVENT_FUN(OnWindowClose));

    for (auto it = m_LayersStack.End() ; it != m_LayersStack.Begin() ;){
        it--;
        (*it)->OnEvent(e);
        if (e.IsHandled())
            break;
    }
}

bool dot::Application::OnWindowClose(WindowCloseEvent& e){
    m_Running = false;
    return true;
}

void dot::Application::PushLayer(dot::Layer* layer){
    m_LayersStack.PushLayer(layer);
}

void dot::Application::PushOverlay(dot::Layer* layer){
    m_LayersStack.PushOverlay(layer);
}
