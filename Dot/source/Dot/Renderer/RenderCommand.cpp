#include "RenderCommand.hpp"
#include "RenderApi/OpenGL/OpenGLRendererApi.hpp"

dot::RendererApi* dot::RenderCommand::s_RendererApi = new dot::OpenGLRendererApi();

void dot::RenderCommand::DrawIndexed(VertexArray& va){
    
    s_RendererApi->DrawIndexed(va);
}

void dot::RenderCommand::ClearColor(const glm::vec4& color){
    s_RendererApi->SetClearColor(color);
}

void dot::RenderCommand::Clear(void){
    s_RendererApi->Clear();
}