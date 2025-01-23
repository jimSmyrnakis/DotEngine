
#include "LayerStack.hpp"


dot::LayerStack::LayerStack(void){
    m_LastIndex = 0;
}

dot::LayerStack::~LayerStack(void){
    for (Layer *layer : m_Layers)
        delete layer;
}

void dot::LayerStack::PushLayer(dot::Layer* layer){
    m_Layers.emplace(m_Layers.begin() + m_LastIndex , layer);
    m_LastIndex++;
    layer->OnAttach();
}

void dot::LayerStack::PushOverlay(dot::Layer* overlay){
    m_Layers.emplace_back(overlay);
    overlay->OnAttach();
}

void dot::LayerStack::PopLayer(dot::Layer* layer){
    std::vector<Layer*>::iterator it = std::find(m_Layers.begin() , m_Layers.end() , layer);
    if (it == m_Layers.end())
        return;
    
    layer->OnDetach();
    m_Layers.erase(it);
    m_LastIndex--;

}

void dot::LayerStack::PopOverlay(dot::Layer* overlay){
    std::vector<Layer*>::iterator it = std::find(m_Layers.begin() , m_Layers.end() , overlay);
    if (it == m_Layers.end())
        return;

    (*it)->OnDetach();
    m_Layers.erase(it);
}

std::vector<dot::Layer*>::iterator dot::LayerStack::Begin(void) { return m_Layers.begin(); }

std::vector<dot::Layer*>::iterator dot::LayerStack::End(void) { return m_Layers.end(); }