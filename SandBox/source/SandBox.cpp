#include "SandBox.hpp"

SandBox::SandBox(void): dot::Application::Application() {
    this->PushLayer(new ExambleLayer());
    this->PushOverlay(new dot::ImguiLayer());
}

SandBox::~SandBox(void){

}

dot::Application* dot::CreateApplication(void){
    return new SandBox();
}

