#pragma once
#include "../../Layer/Layer.hpp"

namespace dot{
    class DOT_API ImguiLayer : public dot::Layer{
        public:
        ImguiLayer(void);
        ~ImguiLayer(void);

        void OnAttach(void) override; 
        void OnDetach(void) override; 
        void OnUpdate(void) override; 
        void OnEvent(Event& event) override; 

        private:
            float m_Time = 0.0f;
    };


}