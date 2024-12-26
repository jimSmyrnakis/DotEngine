#pragma once
#include "../../Window.hpp"
#include <GLFW/glfw3.h>
#include <memory>

namespace dot{

    struct WindowData
    {
        std::string Title ;
        uint32_t    Width ;
        uint32_t    Height;
        bool        VSync ;
        EventCallBackFn* EventCallBack;
    };
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

            

            WindowData m_Data;
        private:
            static bool s_GLFWInitiallized;
    };

    // create glfw specific callbacks functions and pass the events
    void for_glfw_resize_event        (GLFWwindow* window , int width , int height );
    void for_glfw_close_event         (GLFWwindow* window);
    void for_glfw_key_events          (GLFWwindow* window , int key , int scancode , int action , int mode);
    void for_glfw_mouse_button_events (GLFWwindow* window , int key , int action , int mode);
    void for_glfw_mouse_scroll_event  (GLFWwindow* window , double xOffset , double yOffset);
    void for_glfw_mouse_moved_event   (GLFWwindow* window , double xPos , double yPos);
    void for_glfw_error_event (int error , const char* description);
}
