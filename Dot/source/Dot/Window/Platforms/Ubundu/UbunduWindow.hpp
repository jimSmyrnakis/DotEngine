#pragma once
#include "../../Window.hpp"
#include <GLFW/glfw3.h>

namespace dot{

    class DOT_API UbunduWindow : public dot::Window{

        public:
            UbunduWindow(const WindowProps& props);
            ~UbunduWindow(void);

            void OnUpdate(void) override;

            uint32_t GetWidth(void)  const override;
            uint32_t GetHeight(void) const override;

            void SetEventCallBack(const EventCallBackFn& callback) override;
            void SetVSync(bool enabled) override;
            bool IsVSync() const override;

        private:
            virtual void Init(const WindowProps& props);
            virtual void Shutdown(void);
        private:
            GLFWwindow* m_Window;

            struct WindowData
            {
                std::string Title ;
                uint32_t    Width ;
                uint32_t    Height;
                bool        VSync ;

                EventCallBackFn EventCallBack;
            };

            WindowData m_Data;
        private:
            static bool s_GLFWInitiallized;
    };



    
}
