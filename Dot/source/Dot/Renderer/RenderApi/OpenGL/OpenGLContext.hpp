
#pragma once
#include "../Context.hpp"

namespace dot{

    class OpenGLContext : public Context {
        public:
            OpenGLContext(void* nativeWindowPointer);
            ~OpenGLContext(void);
            void Init(void) override;
            void SwapBuffers(void) override;
            
        private:
            void* m_NativeWindowPointer; 
    };

}