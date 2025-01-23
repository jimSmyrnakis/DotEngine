
#include "UbunduInput.hpp"
#include "../../Window.hpp"
#include "../../../Application.hpp"
#include "UbunduKeyCodes.hpp"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

dot::Input* dot::Input::s_InputInstance = nullptr;

dot::Input* dot::Input::Create(void){
    DOT_ENGINE_ASSERT(s_InputInstance == nullptr , "Instance of the Input Already exist!");
    dot::Input::s_InputInstance = new UbunduInput();
    return dot::Input::s_InputInstance;
}


bool dot::UbunduInput::VirtIsKeyPressed(uint32_t keyCode) const{
    auto window = (GLFWwindow*)dot::Application::Get().GetWindow().GetNativeWindow();

    int val = glfwGetKey(window , DotToGlfwKey(keyCode));
    return (val == GLFW_PRESS) || (val == GLFW_REPEAT);
    
}

bool dot::UbunduInput::VirtIsMouseButtonPressed(uint32_t button) const{
    auto window = (GLFWwindow*)dot::Application::Get().GetWindow().GetNativeWindow();
    int val = glfwGetMouseButton(window ,DotToGlfwMouseButton(button));
    return (val == GLFW_PRESS) ;
}

dot::Vec2 dot::UbunduInput::VirtGetMousePos(void) const{
    auto window = (GLFWwindow*)dot::Application::Get().GetWindow().GetNativeWindow();
    Vec2 mousePosition;
    glfwGetCursorPos(window , &mousePosition.x , &mousePosition.y);
    return mousePosition;
}
