#pragma once
#include "Core.hpp"

#include "Events/Event.hpp"
#include "Events/KeyEvent.hpp"
#include "Events/MouseEvent.hpp"
#include "Events/ApplicationEvent.hpp"
#include "Logger/Logger.hpp"
#include "Window/Window.hpp"
#include <memory>


namespace dot{
    class DOT_API Application{

        public:
            Application(void);
            virtual ~Application(void);

            void Run(void);

        private:
            std::unique_ptr<dot::Window> m_Window;
            bool                         m_Running;
    };
}