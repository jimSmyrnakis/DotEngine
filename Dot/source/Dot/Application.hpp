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
#include "Layers/ImguiLayer/ImguiLayer.hpp"
#include "Renderer/RenderApi/OpenGL/OpenGLShader.hpp"
#include "Renderer/RenderApi/Buffer.hpp"
#include "Renderer/Camera.hpp"

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

            inline Window& GetWindow(void) const {return *m_Window;}

            static Application& Get(void); 

        private:
            bool OnWindowClose(WindowCloseEvent& e);

        private:
            static dot::Application*        s_AppInstance;
            std::unique_ptr<dot::Window>    m_Window;
            dot::ImguiLayer*                m_ImGuiLayer;
            bool                            m_Running;
            LayerStack                      m_LayersStack;
            float                           m_LastFrameTime;
            
    };
}