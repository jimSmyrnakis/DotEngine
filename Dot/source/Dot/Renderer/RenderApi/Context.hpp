
#pragma once
#include "../../Core.hpp"

namespace dot{

    enum class WindowApiImpl{
        GLFW_UBUNDU ,
        NONE 
    };

    class Context{
        public:
            Context(WindowApiImpl impl = WindowApiImpl::GLFW_UBUNDU);
            virtual ~Context(void) = default;

            virtual void Init(void) = 0;
            virtual void SwapBuffers(void) = 0;

        protected:
            WindowApiImpl m_WinImpl;
    };
    
}