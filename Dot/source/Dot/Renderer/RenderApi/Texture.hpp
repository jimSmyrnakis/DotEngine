#pragma once 

#include <stdint.h>
#include <stddef.h>


namespace dot{


    class Texture{

        public:
            Texture(void) = default;
            virtual ~Texture(void) = default; 

            virtual void InitTexture(void) = 0 ;
            virtual void Bind(uint16_t slot = 0) = 0;
            virtual void Unbind(void) = 0;

            virtual uint16_t GetSlot(void) const { return m_Slot; }
        protected:
            uint16_t m_Slot;

    };

    class Texture2D : public Texture {
        public:
            enum class Filter{
                LINEAR , NEAREST
            };
            enum class Format{
                RGB8 , RGBA8 
            };
            
        public :
            Texture2D(  void* pixelBuffer = nullptr,
                        uint32_t width = 0 ,
                        uint32_t height= 0,
                        Filter   Magn  = Filter::LINEAR,
                        Filter   Mini  = Filter::LINEAR,
                        Format   Form  = Format::RGB8  ): 
                        m_PixelBuffer(pixelBuffer) ,
                        m_Width(width) , m_Height(height) , 
                        m_MagnificationFilter(Magn) , m_MinificationFilter(Mini) ,
                        m_TextureFormat(Form) {};
            
            virtual ~Texture2D(void) = default; // pixel buffer is not for deletion over here 

            inline virtual uint32_t GetWidth(void) const { return m_Width; }
            inline virtual uint32_t GetHeight(void) const { return m_Height; }
            inline virtual Filter   GetMagnificationFilter(void) const { return m_MagnificationFilter; }
            inline virtual Filter   GetMinigicationFilter(void) const { return m_MinificationFilter ;}
            inline virtual Format   GetFormat(void) const { return m_TextureFormat; }
            inline virtual void*    GetPixelBuffer(void) const { return m_PixelBuffer; }

            inline virtual void     SetWidth(uint32_t width)              { m_Width = width;}
            inline virtual void     SetHeight(uint32_t height)            { m_Height = height; }
            inline virtual void     SetMagnificationFilter(Filter filter) { m_MagnificationFilter = filter;}
            inline virtual void     SetMinificationFilter (Filter filter) { m_MinificationFilter  = filter;}
            inline virtual void     SetFormat(Format format)              { m_TextureFormat = format; }
            inline virtual void     SetPixelBuffer(void* PixelBuffer)     { m_PixelBuffer = PixelBuffer ;}

            static Texture2D* Create(
                void* pixelBuffer = nullptr , 
                uint32_t width = 0, 
                uint32_t height = 0, 
                Filter Magn = Filter::LINEAR, 
                Filter Mini = Filter::LINEAR, 
                Format format = Format::RGB8
            );
        protected:
            uint32_t    m_Width;
            uint32_t    m_Height;
            Filter      m_MagnificationFilter;
            Filter      m_MinificationFilter ;
            Format      m_TextureFormat;
            void*       m_PixelBuffer;
    };


}