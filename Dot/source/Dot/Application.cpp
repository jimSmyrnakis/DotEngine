#include "dotpch.h"

#include "Application.hpp"
#include "Window/Input.hpp"
#include "Renderer/RenderApi/OpenGL/OpenGLBuffer.hpp"
#include "Renderer/Renderer.hpp"
#include "Renderer/RenderCommand.hpp"
#include "Window/KeyCodes.hpp"
#include "TimeStep.hpp"
#include <glad/glad.h>

#define BIND_EVENT_FUN(x) std::bind(&Application::x , this , std::placeholders::_1)
dot::Input* in;
dot::Application* dot::Application::s_AppInstance = nullptr;

dot::Application& dot::Application::Get(void){
    return *s_AppInstance;
}




dot::Application::Application(void){
    DOT_ENGINE_ASSERT(s_AppInstance == nullptr , "Instance of the Application Already exist!");
    s_AppInstance = this;
    m_Window = std::unique_ptr<Window>(Window::Create());
    m_Running = true;
    m_Window->SetEventCallBack(BIND_EVENT_FUN(OnEvent));
    in = Input::Create();

    m_ImGuiLayer = new ImguiLayer();
    PushOverlay(m_ImGuiLayer);


    
}

dot::Application::~Application(void){
    
}

void dot::Application::Run(void){
    while(m_Running){
        float time = dot::GetTime();
        TimeStep timeS =time - m_LastFrameTime ;
        m_LastFrameTime = time;
        
        for (auto it = m_LayersStack.Begin() ; it != m_LayersStack.End() ; it++)
            (*it)->OnUpdate(timeS);

        m_ImGuiLayer->Begin();
        for (auto it = m_LayersStack.Begin() ; it != m_LayersStack.End() ; it++)
            (*it)->OnImGuiRender();
        m_ImGuiLayer->End();
        
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
