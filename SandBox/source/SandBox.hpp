#pragma once
#define DOT_STATIC_LINK
#include <Dot.hpp>

class ExambleLayer : public dot::Layer {

    public:

        ExambleLayer(void) ;
        ~ExambleLayer(void) = default;

        void OnUpdate(dot::TimeStep time) override;

        void OnEvent(dot::Event& e) override ;

    private:
        bool m_IsResized = false;
        dot::FirstPersonCamera*              m_Camera;
        

        dot::Shader*                         m_CubeShader;
        dot::VertexBuffer*                   m_VOCube;
        dot::VertexArray*                    m_VAOCube;
        dot::IndexBuffer*                    m_IOCube;
        dot::Model3D*                        m_CubeModel;
        dot::Texture2D*                      m_CubeTexture;

        dot::Shader*                         m_FloorShader;
        dot::VertexBuffer*                   m_VOFloor;
        dot::VertexArray*                    m_VAOFloor;
        dot::IndexBuffer*                    m_IOFloor;
        dot::Model3D*                        m_FloorModel;
        dot::Texture2D*                      m_FloorTexture;
};

class SandBox : public dot::Application {
    public:
        SandBox(void);
        ~SandBox(void);

};