
#include "Application.hpp"
#include "Window/Input.hpp"
#include "Renderer/RenderApi/OpenGL/OpenGLBuffer.hpp"
#include "Renderer/Renderer.hpp"
#include "Renderer/RenderCommand.hpp"
#include "Window/KeyCodes.hpp"
#include <glad/glad.h>

#include <chrono>

long long current_time_in_ms() {
    // Παίρνουμε τον τρέχοντα χρόνο από την εποχή (epoch) σε milliseconds
    auto now = std::chrono::steady_clock::now();
    
    // Μετατρέπουμε το χρόνο σε milliseconds
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
    
    // Επιστρέφουμε το αποτέλεσμα ως long long
    return duration.count();
}

#define BIND_EVENT_FUN(x) std::bind(&Application::x , this , std::placeholders::_1)
dot::Input* in;
dot::Application* dot::Application::s_AppInstance = nullptr;

dot::Application& dot::Application::Get(void){
    return *s_AppInstance;
}

static float CubeVertexBuffer[] = {
    0.0f, 0.0f, 0.1f,  // κάτω-αριστερά
    1.0f, 0.0f, 0.1f,  // κάτω-δεξιά
    0.0f,  1.0f, 0.1f,  // πάνω-αριστερά
    1.0f,  1.0f, 0.1f   // πάνω-δεξιά
};

static uint32_t CubeIndeces[] = {
    0 , 1 , 2 ,
    1 , 3 , 2
};


dot::Application::Application(void){
    DOT_ENGINE_ASSERT(s_AppInstance == nullptr , "Instance of the Application Already exist!");
    s_AppInstance = this;
    m_Window = std::unique_ptr<Window>(Window::Create());
    m_Running = true;
    m_Window->SetEventCallBack(BIND_EVENT_FUN(OnEvent));
    in = Input::Create();

    m_ImGuiLayer = new ImguiLayer();
    PushOverlay(m_ImGuiLayer);


    m_VAOCube       = dot::VertexArray::Create();
    m_VOCube        = dot::VertexBuffer::Create(CubeVertexBuffer , sizeof(CubeVertexBuffer));
    m_IOCube        = dot::IndexBuffer::Create(CubeIndeces , sizeof(CubeIndeces) / sizeof(float));
    BufferLayout layout2 = {
        {"a_Vertex" , ShaderDataType::Float3 }
    };
    m_VOCube->SetLayout(layout2);

    m_VAOCube->AddVertexBuffer(*m_VOCube);
    m_VAOCube->SetIndexBuffer(*m_IOCube);
    
    std::string vertexSource = 
R"(#version 330 core 
layout(location = 0) in vec3 a_Vertex;
uniform mat4 u_mvp;
vec4 pos;
void main(){
    pos = u_mvp*vec4(a_Vertex , 1.0);
    gl_Position = pos;
}

)";

    std::string fragmentSource =
R"(#version 330 core 
layout(location = 0) out vec4 v_color;
void main(){
    v_color = vec4(1,1,1, 1.0);
}

)";
    m_CubeShader = new OpenGLShader(vertexSource , fragmentSource);

    m_Camera = new dot::PerspectiveCamera();
    m_Camera->m_AspectRatio = (float)m_Window->GetWidth() / (float)m_Window->GetHeight();
    m_Camera->m_Position = glm::vec3( 0 , 0 , 0);
    
    
}

dot::Application::~Application(void){
    
}

void dot::Application::Run(void){
    while(m_Running){

        //glViewport(0, 0, m_Window->GetWidth() , m_Window->GetHeight());
        
        
        glm::vec4 color;
        color.r = color.g = color.b = 0.1f;
        color.a = 1.0f;
        RenderCommand::ClearColor(color);
        RenderCommand::Clear();



        float deltaTime = (float)current_time_in_ms();
        Renderer::BeginScene(m_Camera);
        m_CubeShader->Bind();
        m_CubeShader->SetUniformMatrix4f("u_mvp" , m_Camera->GetProjectionViewMatrix());
        Renderer::Submit(*m_VAOCube);
        Renderer::EndScene();
        deltaTime = ((float)current_time_in_ms()) - deltaTime;
        if (deltaTime < (1.0f/240.0f))
            deltaTime = 1.0f/240.0f;

        if (Input::IsKeyPressed(DOT_KEY_A))
            m_Camera->m_Position.x += 10 * 0.016f;
        if (Input::IsKeyPressed(DOT_KEY_D))
            m_Camera->m_Position.x -= 10 * 0.016f;
        if (Input::IsKeyPressed(DOT_KEY_S))
            m_Camera->m_Position.z -= 10 * 0.016f;
        if (Input::IsKeyPressed(DOT_KEY_W))
            m_Camera->m_Position.z += 10 * 0.016f;

        if (Input::IsKeyPressed(DOT_KEY_LEFT))
            m_Camera->m_Rotation.y -= 90 * 0.016f;
        if (Input::IsKeyPressed(DOT_KEY_RIGHT))
            m_Camera->m_Rotation.y += 90 * 0.016f;

        if (Input::IsKeyPressed(DOT_KEY_UP))
            m_Camera->m_Rotation.x -= 90 * 0.016f;
        if (Input::IsKeyPressed(DOT_KEY_DOWN))
            m_Camera->m_Rotation.x += 90 * 0.016f;

        DOT_ENGINE_INFO("Time : {0} ms\n", deltaTime);
        
        for (auto it = m_LayersStack.Begin() ; it != m_LayersStack.End() ; it++)
            (*it)->OnUpdate();

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
