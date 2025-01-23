
#pragma once
#include "../../Core.hpp"

namespace dot{

    enum class WindowApiImpl{
        GLFW_UBUNDU ,
        NONE 
    };

    class GraphicsContext{
        public:
            GraphicsContext(WindowApiImpl impl = WindowApiImpl::GLFW_UBUNDU);
            virtual ~GraphicsContext(void) = default;

            virtual void Init(void) = 0;
            virtual void SwapBuffers(void) = 0;

        protected:
            WindowApiImpl m_WinImpl;
    };
    
}