
#pragma once
#include "../GraphicsContext.hpp"

namespace dot{

    class OpenGLContext : public GraphicsContext {
        public:
            OpenGLContext(void* nativeWindowPointer);
            ~OpenGLContext(void);
            void Init(void) override;
            void SwapBuffers(void) override;
            
        private:
            void* m_NativeWindowPointer; 
    };

}