#include "SandBox.hpp"

SandBox::SandBox(void): dot::Application::Application() {

}

SandBox::~SandBox(void){

}

dot::Application* dot::CreateApplication(void){
    return new SandBox();
}

