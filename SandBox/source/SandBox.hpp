#pragma once
#define DOT_STATIC_LINK
#include <Dot.hpp>

class ExambleLayer : public dot::Layer {

    public:

        ExambleLayer(void) : Layer("Examble") {}
        ~ExambleLayer(void) = default;

        void OnUpdate(void) override {
            //DOT_INFO("Examble Layer ==> Update");
            if (m_IsResized)
                DOT_INFO("Stop Resizing the window :( !!!");
        }

        void OnEvent(dot::Event& e) override {
            m_IsResized = false;
            if (e.GetEventType() == dot::EventType::WindowResize)
                m_IsResized = true;
        }

    private:
        bool m_IsResized = false;
};

class SandBox : public dot::Application {
    public:
        SandBox(void);
        ~SandBox(void);

};