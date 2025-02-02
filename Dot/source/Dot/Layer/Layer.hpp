
#pragma once 
#include "../Core.hpp"
#include "../Events/Event.hpp"
#include "../TimeStep.hpp"

namespace dot{
    class DOT_API Layer{
        public:
            Layer(const std::string& name = "Layer");
            virtual ~Layer(void);

            virtual void OnAttach(void); // when the layer is push in the stack trigger this method
            virtual void OnDetach(void); // when the layer is removed from the stack trigger this method
            virtual void OnUpdate(TimeStep time); // every time that infinite loops where the layer is , trigger this method
            virtual void OnEvent(Event& event); // whenever a event is parse to a layer trigger this method
            virtual void OnImGuiRender(void); // for the UI Rendering , this is where you create button panels , checkboxes for a given layer
            const std::string& GetName(void) const; 

            // For exambe lets say u have a scene u want to render , then the On


        protected:
            std::string m_Name;
    };
}