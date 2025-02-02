#pragma once
#include "../Texture.hpp"
#include <glad/glad.h>

namespace dot{

    class OpenGLTexture2D : public Texture2D {

        public:
            OpenGLTexture2D(
                void*    PixelBuffer = nullptr ,
                uint32_t width = 0 ,
                uint32_t height= 0,
                Filter   Magn  = Filter::LINEAR,
                Filter   Mini  = Filter::LINEAR,
                Format   Form  = Format::RGB8  
            ) : Texture2D( PixelBuffer , width , height , Magn , Mini , Form ) {
                glCreateTextures(GL_TEXTURE_2D , 1 , &m_OId);
            }

            virtual ~OpenGLTexture2D(void) { 
                glDeleteTextures(1 , &m_OId);
            }

            virtual void InitTexture(void) override ;

            virtual void Bind(uint16_t Slot = 0) override ;
            virtual void Unbind(void) override ;

        private:
            uint32_t m_OId;
        private:
            GLenum GetOpenGLFormat(Format format); // GL_RGB8 , GL_RGBA8 
            GLint GetOpenGLFilter(Filter filter); // GL_LINEAR , GL_NEAREST 

    };

}