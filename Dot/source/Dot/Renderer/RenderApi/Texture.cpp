#include "Texture.hpp"
#include "../../Core.hpp"
#include "RendererApi.hpp"
#include "OpenGL/OpenGLTexture.hpp"
dot::Texture2D* dot::Texture2D::Create(
    void* data , 
    uint32_t width , 
    uint32_t height , 
    dot::Texture2D::Filter Magn , 
    dot::Texture2D::Filter Mini ,
    dot::Texture2D::Format format 
){
    dot::Texture2D* t2d = nullptr;
    if (RendererApi::GetCurrentApi() == RendererApi::Api::OPENGL){
        
        return new OpenGLTexture2D(data , width , height , Magn , Mini , format);
    }
            

    DOT_ENGINE_ASSERT( 0 , "Undefined Api Implementation !");
    return nullptr;
}

