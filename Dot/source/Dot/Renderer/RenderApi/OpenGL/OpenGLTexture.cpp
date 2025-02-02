#include "OpenGLTexture.hpp"
#include "../../../Core.hpp"

GLenum GetOpenGL2DInternalFormat(GLenum format){
    switch(format){
        case GL_RGB : return GL_RGB8;
        case GL_RGBA: return GL_RGBA8;
        default     : DOT_ENGINE_ASSERT(0 , "Format not Supported !"); 
    }

    return 0;
}

void dot::OpenGLTexture2D::InitTexture(void) {
    DOT_ENGINE_ASSERT( m_Width && m_Height , "Width or/and Height of the pixelBuffer is not set !");
    DOT_ENGINE_ASSERT( m_PixelBuffer , "Pixel Buffer is nullptr !");

    glTextureStorage2D(m_OId , 1 , GetOpenGL2DInternalFormat(GetOpenGLFormat(m_TextureFormat)) , m_Width , m_Height);

    glTextureParameteri(m_OId , GL_TEXTURE_MIN_FILTER , GetOpenGLFilter(m_MinificationFilter)); //GL_LINEAR , GL_NEAREST
    glTextureParameteri(m_OId , GL_TEXTURE_MAG_FILTER , GetOpenGLFilter(m_MagnificationFilter)); //GetOpenGLFormat(m_TextureFormat)
    glTextureSubImage2D(m_OId , 0 , 0 , 0 , m_Width , m_Height , GetOpenGLFormat(m_TextureFormat)  , GL_UNSIGNED_BYTE , m_PixelBuffer );
}



GLenum dot::OpenGLTexture2D::GetOpenGLFormat(dot::Texture2D::Format format){
    switch(format){
        case dot::Texture2D::Format::RGB8 : return GL_RGB ;
        case dot::Texture2D::Format::RGBA8: return GL_RGBA;
        default:
            DOT_ENGINE_ASSERT(0 , "Undefined 2D Texture Format !");
    }
    return 0;
} // GL_RGB8 , GL_RGBA8 

GLint  dot::OpenGLTexture2D::GetOpenGLFilter(dot::Texture2D::Filter filter){
    switch(filter){
        case dot::Texture2D::Filter::LINEAR : return GL_LINEAR ;
        case dot::Texture2D::Filter::NEAREST: return GL_NEAREST;
        default :
            DOT_ENGINE_ASSERT(0 , "Undefined 2D Texture Filter !");
    }
    return 0;
} // GL_LINEAR , GL_NEAREST

void dot::OpenGLTexture2D::Bind(uint16_t Slot) {
    if (Slot > 32)
        DOT_ENGINE_ASSERT(0, "Slot is bigger than the maximum number of slots (32) !");
    m_Slot = Slot;

    glBindTextureUnit(Slot , m_OId);
}



void dot::OpenGLTexture2D::Unbind(void) {
    glBindTextureUnit(m_Slot , 0);
}