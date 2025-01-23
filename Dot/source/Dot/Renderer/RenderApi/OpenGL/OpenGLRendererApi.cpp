#include "OpenGLRendererApi.hpp"
#include <glad/glad.h>

void dot::OpenGLRendererApi::SetClearColor(const glm::vec4& color){
    glClearColor(color.r , color.g , color.b , color.a);
}

void dot::OpenGLRendererApi::Clear(void){
    glClear(GL_COLOR_BUFFER_BIT);
}

void dot::OpenGLRendererApi::DrawIndexed(const dot::VertexArray& va){
    va.Bind();
    //glEnable(GL_DEPTH_TEST);
    glDrawElements(GL_TRIANGLES , va.GetIndexBuffer().GetCount() , GL_UNSIGNED_INT , nullptr);
}