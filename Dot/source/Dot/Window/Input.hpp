
#pragma once

#include "../Core.hpp"
#include "Window.hpp"

namespace dot{
    struct Vec2{
        double x;
        double y;
    };
    
    

    class DOT_API Input{
        public:
           
            virtual ~Input(void) {}
        public:
            static Input* Create(void);
            static inline Input& Get(void) {return *s_InputInstance;}
            static inline bool IsKeyPressed(uint32_t keyCode) {return s_InputInstance->VirtIsKeyPressed(keyCode);}
            static inline bool IsMouseButtonPressed(uint32_t button) {return s_InputInstance->VirtIsMouseButtonPressed(button);};
            static inline Vec2 GetMousePos(void) { return s_InputInstance->VirtGetMousePos();}
            
        protected:
            virtual bool VirtIsKeyPressed(uint32_t keyCode) const = 0;
            virtual bool VirtIsMouseButtonPressed(uint32_t button) const = 0;
            virtual Vec2 VirtGetMousePos(void) const = 0;
            
        public:
            static Input* s_InputInstance ;
            
    };

    

   
}