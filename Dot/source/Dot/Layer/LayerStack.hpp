#pragma once 

#include "Layer.hpp"

#include <vector>

namespace dot {
    class DOT_API LayerStack{
        public:
            LayerStack(void);
            ~LayerStack(void);

            void PushLayer(Layer* layer);
            void PushOverlay(Layer* overlay);
            void PopLayer(Layer* layer);
            void PopOverlay(Layer* overlay);

            std::vector<Layer*>::iterator Begin(void);
            std::vector<Layer*>::iterator End(void);

        private:
            std::vector<Layer*>           m_Layers;
            std::vector<Layer*>::iterator m_Last;
    };
}