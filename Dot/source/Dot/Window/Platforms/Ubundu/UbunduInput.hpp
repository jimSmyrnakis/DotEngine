#pragma once

#include "../../Input.hpp"

namespace dot{
    class DOT_API UbunduInput : public Input{
        public:
            ~UbunduInput(void) {}
        protected:
            bool VirtIsKeyPressed(uint32_t keyCode)         const override;
            bool VirtIsMouseButtonPressed(uint32_t button)  const override;
            Vec2 VirtGetMousePos(void)                      const override;
            
    };
}