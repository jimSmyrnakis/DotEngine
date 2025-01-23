
#pragma once
#include "Event.hpp"

namespace dot{

     

    class DOT_API KeyEvent : public Event
    {
        public:
            inline uint32_t GetKeyCode(void) const { return m_KeyCode; }

            EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);

        protected:
            KeyEvent(uint16_t keyCode) :Event() , m_KeyCode(keyCode) {}
            virtual ~KeyEvent(void) = default;
            uint32_t m_KeyCode;
    };

    class DOT_API KeyPressedEvent : public KeyEvent 
    {
        public:
            KeyPressedEvent(uint32_t keyCode , uint32_t repeatCount) : KeyEvent(keyCode) , m_Repeats(repeatCount) {}
            ~KeyPressedEvent(void) = default;

            inline uint32_t GetRepeatCount(void) const { return m_Repeats; }

            std::string ToString(void) const override 
            {
                std::stringstream ss;
                ss << "KeyPressed [ keyCode , Repeats ] : [ " << m_KeyCode << " , " << m_Repeats << " ] " ;
                return ss.str();
            }

            EVENT_CLASS_TYPE(KeyPressed)



        private:
            uint32_t m_Repeats;

    };

    class DOT_API KeyReleasedEvent : public KeyEvent
    {
        public:
            KeyReleasedEvent(uint16_t keyCode ) : KeyEvent(keyCode) {}
            ~KeyReleasedEvent(void) = default;

            std::string ToString(void) const override 
            {
                std::stringstream ss;
                ss << "KeyReleased [ keyCode ] : [ " << m_KeyCode << " ] " ;
                return ss.str();
            }

            EVENT_CLASS_TYPE(KeyReleased)

    };

    class DOT_API KeyTypedEvent : public KeyEvent 
    {
        public:
            KeyTypedEvent(uint32_t character ) : KeyEvent(character) {}
            ~KeyTypedEvent(void) = default;

            inline uint32_t GetChar(void) const {return m_KeyCode; }

            std::string ToString(void) const override 
            {
                std::stringstream ss;
                ss << "KeyTyped [ keyCode , Repeats ] : [ " << m_KeyCode <<" ] " ;
                return ss.str();
            }

            EVENT_CLASS_TYPE(KeyTyped)



        private:
            

    };



}