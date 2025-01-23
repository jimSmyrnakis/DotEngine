
#include "OpenGLContext.hpp"
#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../../../Logger/Logger.hpp"

void InitForGLFW(GLFWwindow* Glfw_WindowPointer);
void SwapBufferForGLFW(GLFWwindow* Glfw_WindowPointer);

dot::OpenGLContext::OpenGLContext(void* nativeWindowPointer) : GraphicsContext(dot::WindowApiImpl::GLFW_UBUNDU) {
    DOT_ENGINE_ASSERT(nativeWindowPointer != nullptr , "No Native Window Pointer is Given for implemating window contex for the render api");
    m_NativeWindowPointer = nativeWindowPointer;
}

dot::OpenGLContext::~OpenGLContext(void){

}

void dot::OpenGLContext::Init(void) {
    if (m_WinImpl == dot::WindowApiImpl::GLFW_UBUNDU)
        InitForGLFW((GLFWwindow*)m_NativeWindowPointer);
}

void dot::OpenGLContext::SwapBuffers(void) {
    if (m_WinImpl == dot::WindowApiImpl::GLFW_UBUNDU)
        SwapBufferForGLFW((GLFWwindow*)m_NativeWindowPointer);
}

void InitForGLFW(GLFWwindow* Glfw_WindowPointer){
    glfwMakeContextCurrent(Glfw_WindowPointer);
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    DOT_ENGINE_ASSERT(status , "Failed to initiallize Glad!");
    //glGetString()
    DOT_ENGINE_INFO("Vendor   ( {0} ) " , (char*)glGetString(GL_VENDOR  ));
    DOT_ENGINE_INFO("Renderer ( {0} ) " , (char*)glGetString(GL_RENDERER));
    DOT_ENGINE_INFO("Version  ( {0} ) " , (char*)glGetString(GL_VERSION ));
}

void SwapBufferForGLFW(GLFWwindow* Glfw_WindowPointer){
    glfwSwapBuffers(Glfw_WindowPointer);
}

