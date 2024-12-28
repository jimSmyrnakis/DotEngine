#pragma once
#include "Core.hpp"

#include "Events/Event.hpp"
#include "Events/KeyEvent.hpp"
#include "Events/MouseEvent.hpp"
#include "Events/ApplicationEvent.hpp"
#include "Logger/Logger.hpp"
#include "Window/Window.hpp"
#include "Layer/Layer.hpp"
#include "Layer/LayerStack.hpp"
#include <memory>


namespace dot{
    class DOT_API Application{

        public:
            Application(void);
            virtual ~Application(void);

            void Run(void);

            void OnEvent(Event& e);

            void PushLayer(Layer* layer);
            void PushOverlay(Layer* layer);

        private:
            bool OnWindowClose(WindowCloseEvent& e);

        private:
            std::unique_ptr<dot::Window> m_Window;
            bool                         m_Running;
            LayerStack                   m_LayersStack;
    };
}