#include "LayerStack.hpp"


dot::LayerStack::LayerStack(void){
    m_Last = m_Layers.begin();
}

dot::LayerStack::~LayerStack(void){
    for (Layer *layer : m_Layers)
        delete layer;
}

void dot::LayerStack::PushLayer(dot::Layer* layer){
    m_Last = m_Layers.emplace(m_Last , layer);
}

void dot::LayerStack::PushOverlay(dot::Layer* overlay){
    m_Layers.emplace_back(overlay);
}

void dot::LayerStack::PopLayer(dot::Layer* layer){
    std::vector<Layer*>::iterator it = std::find(m_Layers.begin() , m_Layers.end() , layer);
    if (it == m_Layers.end())
        return;
    
    m_Layers.erase(it);
    m_Last--;
}

void dot::LayerStack::PopOverlay(dot::Layer* overlay){
    std::vector<Layer*>::iterator it = std::find(m_Layers.begin() , m_Layers.end() , overlay);
    if (it == m_Layers.end())
        return;
    
    m_Layers.erase(it);
}

std::vector<dot::Layer*>::iterator dot::LayerStack::Begin(void) { return m_Layers.begin(); }

std::vector<dot::Layer*>::iterator dot::LayerStack::End(void) { return m_Layers.end(); }