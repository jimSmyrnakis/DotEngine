
#include "Layer.hpp"

dot::Layer::Layer(const std::string& name ) : m_Name(name) {}
dot::Layer::~Layer(void){
    OnDetach();
}

void dot::Layer::OnAttach(void) {}
void dot::Layer::OnDetach(void) {}
void dot::Layer::OnUpdate(void) {}
void dot::Layer::OnEvent(Event& event) {}
void dot::Layer::OnImGuiRender(void) {}

const std::string& dot::Layer::GetName(void) const { return m_Name;}