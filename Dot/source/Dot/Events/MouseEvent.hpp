
#pragma once
#include "Event.hpp"
#include <sstream>
#include <stdint.h>
#include <stddef.h>


namespace dot{

    class DOT_API MouseMovedEvent : public Event 
    {
        public:
            MouseMovedEvent(float x , float y) : Event() , m_MouseX(x) , m_MouseY(y) {}
            ~MouseMovedEvent(void) = default;

            inline float GetX(void) const { return m_MouseX; }
            inline float GetY(void) const { return m_MouseY; }

            std::string ToString(void)const override 
            {
                std::stringstream ss;
                ss << "Mouse Moved Event [ x pos , y pos ] : [ " << m_MouseX << " , " << m_MouseY << " ] " ;
                return ss.str();
            }

            EVENT_CLASS_TYPE(MouseMoved)
            EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

        private:
            float m_MouseX , m_MouseY ; // mouse new position on the window space 

    };

    class DOT_API MouseScrolledEvent : public Event 
    {
        public:
            MouseScrolledEvent(float xOffset , float yOffset) : Event() , m_XOffset(xOffset) , m_YOffset(yOffset) {}
            ~MouseScrolledEvent(void) = default;

            inline float GetXOffset(void) const { return m_XOffset; }
            inline float GetYOffset(void) const { return m_YOffset; }

            std::string ToString(void)const override 
            {
                std::stringstream ss;
                ss << "Mouse Scrolled Event [ x offset , y offset ] : [ " << m_XOffset << " , " << m_YOffset << " ] " ;
                return ss.str();
            }

            EVENT_CLASS_TYPE(MouseScrolled)
            EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

        private:
            float m_XOffset , m_YOffset ; // mouse new position on the window space 

    };

    class DOT_API MouseButtonEvent : public Event
    {
        public:

            inline uint8_t GetButton(void) const { return m_Button; }
            EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryInput)
                        
        protected:
            MouseButtonEvent(uint8_t button) : Event() , m_Button(button) {}
            virtual ~MouseButtonEvent(void) = default;
            uint8_t m_Button;
    };

    class DOT_API MouseButtonPressedEvent : public MouseButtonEvent
    {
        public:
            MouseButtonPressedEvent(uint8_t button , uint32_t repeatCount) : MouseButtonEvent(button) , m_Repeats(repeatCount) {}
            ~MouseButtonPressedEvent(void) = default;
            
            std::string ToString(void) const override {
                std::stringstream ss;
                ss << GetName() << " [ button , repeats ] :  [ " << (int)m_Button << " , " << m_Repeats << " ] " ;
                return ss.str(); 
            }

            inline uint32_t GetRepeats(void) const { return m_Repeats; }
            
            EVENT_CLASS_TYPE(MouseButtonPressed)
        private:
            uint32_t m_Repeats;
    };

    class DOT_API MouseButtonReleasedEvent: public MouseButtonEvent
    {
        public:
            MouseButtonReleasedEvent(uint8_t button) : MouseButtonEvent(button) {}
            ~MouseButtonReleasedEvent(void) = default;

            std::string ToString(void) const override {
                std::stringstream ss;
                ss << GetName() << " [ button ] : [ " << (int)m_Button << " ] " ;
                return ss.str(); 
            }

            EVENT_CLASS_TYPE(MouseButtonReleased)
    };



}