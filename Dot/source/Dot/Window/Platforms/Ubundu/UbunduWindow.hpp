
#pragma once

#include "../../Window.hpp"
#include "../../../Renderer/RenderApi/OpenGL/OpenGLContext.hpp"

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
            void* GetNativeWindow(void) const override;

        private:
            virtual void Init(const WindowProps& props);
            virtual void Shutdown(void);
        private:
            void* m_Window;

            struct WindowData
            {
                std::string Title ;
                uint32_t    Width ;
                uint32_t    Height;
                bool        VSync ;
                EventCallBackFn EventCallBack;
            };

            WindowData     m_Data;
            OpenGLContext* m_Context;

        private:
            static bool s_GLFWInitiallized;
            // create glfw specific callbacks functions and pass the events
            static void for_glfw_resize_event        (void* window , int width , int height );
            static void for_glfw_close_event         (void* window);
            static void for_glfw_key_events          (void* window , int key , int scancode , int action , int mode);
            static void for_glfw_key_typed_event     (void* window , unsigned int character);
            static void for_glfw_mouse_button_events (void* window , int key , int action , int mode);
            static void for_glfw_mouse_scroll_event  (void* window , double xOffset , double yOffset);
            static void for_glfw_mouse_moved_event   (void* window , double xPos , double yPos);
            static void for_glfw_error_event (int error , const char* description);
    };

    
}
