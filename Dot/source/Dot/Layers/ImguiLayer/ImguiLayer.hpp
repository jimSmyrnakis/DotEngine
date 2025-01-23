
#pragma once
#include "../../Layer/Layer.hpp"
#include "../../Events/Event.hpp"
#include "../../Events/MouseEvent.hpp"
#include "../../Events/KeyEvent.hpp"
#include "../../Events/ApplicationEvent.hpp"

namespace dot{
    class DOT_API ImguiLayer : public dot::Layer{
        public:
        ImguiLayer(void);
        ~ImguiLayer(void);

        void OnAttach(void) override; 
        void OnDetach(void) override; 
        void OnImGuiRender(void) override; 

        void Begin(void);
        void End(void);

        private:
            float m_Time = 0.0f;
        
        
    };


}