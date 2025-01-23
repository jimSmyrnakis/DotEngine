
#pragma once
#include "../Core.hpp"
#include "../Logger/Logger.hpp"


namespace dot{

    enum class EventType{
        None = 0            ,

        /*Graphical Window Events */
        WindowClose         ,
        WindowResize        ,
        WindowFocus         ,
        WindowLostFocus     ,
        WindowMoved         ,

        /*Application Special Events (it's like a category of application with window event's too
          -- not sure what these are for yet , i will learn on the feature */
        AppTick             ,
        AppUpdate           ,
        AppRender           ,

        /*Keyboard input Events*/
        KeyPressed          ,
        KeyTyped            ,
        KeyReleased         ,

        /*Mouse Input Events*/
        MouseButtonPressed  ,
        MouseButtonReleased ,
        MouseMoved          ,
        MouseScrolled       

    };
    

    /*Each value represents a set of events , somathing like a very basic filter for our event handlerer */
    enum EventCategory{
        EventCategoryNone = 0 ,
        EventCategoryApplication         = DOT_BIT_SET(0) ,      /*Window and App events */
        EventCategoryKeyboard            = DOT_BIT_SET(1) ,      /**/
        EventCategoryMouse               = DOT_BIT_SET(2) ,
        EventCategoryMouseButton         = DOT_BIT_SET(3) ,
        EventCategoryInput               = DOT_BIT_SET(4) 
    };


#define EVENT_CLASS_TYPE(type)          static EventType GetStaticType(void)                { return EventType::type; };\
                                        virtual EventType GetEventType(void) const override { return GetStaticType();   };\
                                        virtual const char* GetName(void)    const override { return #type;             };

#define EVENT_CLASS_CATEGORY(category)  virtual int GetCategoryFlags(void)   const override { return (category);        }

    //extern class EventDispatcher;
    class DOT_API Event{

            
        public:
            Event(void) : m_Handled(false) {}
            virtual ~Event(void) = default;

            virtual EventType   GetEventType(void)      const = 0;
            virtual const char* GetName(void)           const = 0;
            virtual int         GetCategoryFlags(void)  const = 0;
            virtual inline std::string ToString(void)          const { return this->GetName() ; }
            
            inline bool IsInCategory(EventCategory category){
                return this->GetCategoryFlags() & category ; 
            } 

            inline bool IsHandled(void) const { return m_Handled; }

            


        protected:
            bool m_Handled;
        
        private:
            friend class EventDispatcher;
    };

    class EventDispatcher 
    {
        template<typename T>
        using EventFn = std::function<bool(T&)>;
        public:
            EventDispatcher(Event& event) : m_Event(event) {}
            ~EventDispatcher(void) = default;

            template<typename T>
            bool Dispatch(EventFn<T> function){
                if (m_Event.GetEventType() == T::GetStaticType())
                {
                    m_Event.m_Handled = function(*(T*)&m_Event);
                    return true;
                }
                return false;
            }

        private:
            Event& m_Event;
    };


    inline std::string format_as(const dot::Event& e){
        return e.ToString();
    };


};

