#include "Renderer.hpp"
#include "RenderCommand.hpp"

dot::Camera* dot::Renderer::s_Camera = nullptr;


void dot::Renderer::BeginScene(const dot::Camera* camera) {
    if ( s_Camera != nullptr )
        delete s_Camera;

    
    switch(camera->GetType()){
        case dot::Camera::CameraType::NONE          : DOT_ENGINE_ASSERT(0 , "Undefined camera type !"); return;
        case dot::Camera::CameraType::ORTHOGRAPHIC  : 
            s_Camera = new dot::OrthographicCamera(*(dot::OrthographicCamera*)camera); break;
        case dot::Camera::CameraType::PERSPECTIVE  : 
            s_Camera = new dot::PerspectiveCamera(*(dot::PerspectiveCamera*)camera);   break;
    }

    
} 
void dot::Renderer::EndScene(void) {}   // TODO
void dot::Renderer::Submit(VertexArray& va){
    RenderCommand::DrawIndexed(va);
}

