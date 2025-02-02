
#pragma once
#include "Event.hpp"
#include <sstream>
#include <stdint.h>
#include <stddef.h>

namespace dot{

    class DOT_API WindowResizeEvent : public Event
    {
        public:
            WindowResizeEvent(uint32_t width , uint32_t height) : Event() ,  m_Width(width) , m_Height(height) {}
            ~WindowResizeEvent(void) = default;

            inline uint32_t GetWidth(void)  const { return m_Width; }
            inline uint32_t GetHeight(void) const { return m_Height;}

            std::string ToString(void) const override {
                std::stringstream ss;
                ss << "Window Resize Event: " << m_Width << " , " << m_Height ;
                return ss.str();
            }

            EVENT_CLASS_TYPE(WindowResize)
            EVENT_CLASS_CATEGORY(EventCategoryApplication)

        private:
            uint32_t m_Width , m_Height; 
    };

    class DOT_API WindowCloseEvent : public Event 
    {
        public:
            WindowCloseEvent(void) : Event() {}
            ~WindowCloseEvent(void) = default;

            EVENT_CLASS_CATEGORY(EventCategoryApplication)
            EVENT_CLASS_TYPE(WindowClose)

    };

    class DOT_API AppTickEvent : public Event 
    {
        public:
            AppTickEvent(void) : Event() {}
            ~AppTickEvent(void) = default;

            EVENT_CLASS_CATEGORY(EventCategoryApplication)
            EVENT_CLASS_TYPE(AppTick)

    };

    class DOT_API AppUpdateEvent : public Event 
    {
        public:
            AppUpdateEvent(void) : Event() {}
            ~AppUpdateEvent(void) = default;

            EVENT_CLASS_CATEGORY(EventCategoryApplication)
            EVENT_CLASS_TYPE(AppUpdate)

    };

    class DOT_API AppRenderEvent : public Event 
    {
        public:
            AppRenderEvent(void) : Event() {}
            ~AppRenderEvent(void) = default;

            EVENT_CLASS_CATEGORY(EventCategoryApplication)
            EVENT_CLASS_TYPE(AppRender)

    };

}