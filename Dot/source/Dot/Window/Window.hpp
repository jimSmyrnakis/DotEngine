
#pragma once
#include "../Core.hpp"
#include "../Events/Event.hpp"

namespace dot{

    struct WindowProps
    {
        public:
        WindowProps(const std::string&  title  = "Dot Engine",
                    uint32_t            width  = 1280        ,
                    uint32_t            height = 720         ) 
                    : Title(title) , Width(width) , Height(height) {}
    

        std::string Title ;
        uint32_t    Width ;
        uint32_t    Height;

        
    };
    

    // A abstranction of a window for varius implementations
    class DOT_API Window
    {
        public:
            Window(void) = default;
            virtual ~Window(void) = default;
            using EventCallBackFn = std::function<void (Event&)>;
            
            virtual void OnUpdate(void) = 0;

            virtual uint32_t GetWidth(void)  const = 0;
            virtual uint32_t GetHeight(void) const = 0;

            virtual void SetEventCallBack(const EventCallBackFn& callback) = 0;
            virtual void SetVSync(bool enabled) = 0;
            virtual bool IsVSync() const = 0;

            virtual void* GetNativeWindow(void) const = 0;

            static Window* Create(const WindowProps& props = WindowProps()); 
            /*This implemented in Window Specific file */
    };
}