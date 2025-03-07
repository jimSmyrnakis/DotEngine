#include "SandBox.hpp"
#include "stb_image.h"
#include <fstream>
#include <string>
dot::Application* dot::CreateApplication(void){
    return new SandBox();
}

#define BASE_T 1.0f/6.0f

static float CubeVertexBuffer[] = {
     /*   VERTICES                               TEXTURE COORDINATES */
    // 8 μοναδικά σημεία
    -0.5f,  -0.5f, +0.5f,   0.5f, 0.0f,  // 0: Κάτω-Αριστερά-Μπροστά
    +0.5f,  -0.5f, +0.5f,   1.0f, 0.0f,  // 1: Κάτω-Δεξιά-Μπροστά
    -0.5f,  +0.5f, +0.5f,   0.5f, 0.5f,  // 2: Πάνω-Αριστερά-Μπροστά
    +0.5f,  +0.5f, +0.5f,   1.0f, 0.5f,  // 3: Πάνω-Δεξιά-Μπροστά

    -0.5f,  -0.5f, -0.5f,   0.0f, 0.0f,  // 4: Κάτω-Αριστερά-Πίσω
    +0.5f,  -0.5f, -0.5f,   0.5f, 0.0f,  // 5: Κάτω-Δεξιά-Πίσω
    -0.5f,  +0.5f, -0.5f,   0.0f, 0.5f,  // 6: Πάνω-Αριστερά-Πίσω
    +0.5f,  +0.5f, -0.5f,   0.5f, 0.5f,  // 7: Πάνω-Δεξιά-Πίσω

    
};

static uint32_t CubeIndeces[] = {
    //front rectangle
    0 , 1 , 2 ,
    1 , 3 , 2 ,


    //right rectangle
    1 , 5 , 3 ,
    5 , 7 , 3 ,

    //left  rectangle
    0 , 2 , 4 ,
    4 , 2 , 6 ,

    //back  rectangle
    6 , 5 , 4 ,
    6 , 7 , 5 ,

    //down Rectangle
    0 , 4 , 1 , 
    1 , 4 , 5 ,

    //up Rectangle
    2 , 3 , 6 ,
    6 , 3 , 7

};

static float FloorVertexBuffer[] = {
    -100.0f,  0.0f, +100.0f,      0.0f, 0.0f,  // 0: Κάτω-Αριστερά-Μπροστά
    +100.0f,  0.0f, +100.0f,      1.0f, 0.0f,  // 1: Κάτω-Δεξιά-Μπροστά
    -100.0f,  0.0f, -100.0f,      0.0f, 1.0f,  // 2: Πάνω-Αριστερά-Μπροστά
    +100.0f,  0.0f, -100.0f,      1.0f, 1.0f  // 3: Πάνω-Δεξιά-Μπροστά

};

static uint32_t FloorIndicesBuffer[] = {
    0 , 1 , 2 ,
    2 , 1 , 3
};

static float PyramidVertexBuffer[] = {
    /*   VERTICES                               TEXTURE COORDINATES */
    // Base (τετράγωνο)
    -0.5f, -0.5f, 0.0f,    0.0f, 0.0f,
     0.5f, -0.5f, 0.0f,    1.0f, 0.0f,
     0.5f,  0.5f, 0.0f,    1.0f, 1.0f,
    -0.5f,  0.5f, 0.0f,    0.0f, 1.0f,
    
    // Apex (κορυφή)
     0.0f,  0.0f, 1.0f,    0.5f, 0.5f,
};

static uint32_t PyramidIndices[] = {
    // Base (τετράγωνο) (Counter Clock Wise για Front Face)
    0, 2, 1,
    0, 3, 2,
    
    // Side 1 (Counter Clock Wise)
    0, 4, 1,
    
    // Side 2 (Counter Clock Wise)
    1, 4, 2,
    
    // Side 3 (Counter Clock Wise)
    2, 4, 3,
    
    // Side 4 (Counter Clock Wise)
    3, 4, 0,
};

ExambleLayer::ExambleLayer(void) : Layer("Examble") {

    m_VAOCube       = dot::VertexArray::Create();
    m_VOCube        = dot::VertexBuffer::Create(CubeVertexBuffer , sizeof(CubeVertexBuffer));
    m_IOCube        = dot::IndexBuffer::Create(CubeIndeces , sizeof(CubeIndeces) / sizeof(uint32_t));

    m_VAOFloor       = dot::VertexArray::Create();
    m_VOFloor       = dot::VertexBuffer::Create(FloorVertexBuffer , sizeof(FloorVertexBuffer));
    m_IOFloor        = dot::IndexBuffer::Create(FloorIndicesBuffer , sizeof(FloorIndicesBuffer) / sizeof(uint32_t));
    
    dot::VertexLayout Cubelayout = {
        {"a_Vertex" , dot::ShaderDataType::Float3 } ,
        {"a_TextCoord" , dot::ShaderDataType::Float2 }
    };
    m_VOCube->SetLayout(Cubelayout);
    m_VAOCube->AddVertexBuffer(*m_VOCube);
    m_VAOCube->SetIndexBuffer(*m_IOCube);

    dot::VertexLayout FloorLayout = {
        {"a_Vertex" , dot::ShaderDataType::Float3 } ,
        {"a_TextCoord" , dot::ShaderDataType::Float2 }
    };
    m_VOFloor->SetLayout(FloorLayout);
    m_VAOFloor->AddVertexBuffer(*m_VOFloor);
    m_VAOFloor->SetIndexBuffer(*m_IOFloor);
    
    const std::string ShaderPath = "./SandBox/executable/Assets/Shaders/Shader1.glsl" ;
    std::ifstream ShaderFile(ShaderPath, std::ios::in | std::ios::binary);
    if (!ShaderFile)
        DOT_ASSERT(0 , "Shader File \'{0}\' can not be loaded !!!" , ShaderPath.c_str());
    std::string ShaderCode;
    ShaderFile.seekg(0 , std::ios::end);
    ShaderCode.resize(ShaderFile.tellg());
    ShaderFile.seekg(0 , std::ios::beg);
    ShaderFile.read(&ShaderCode[0] , ShaderCode.size());
    ShaderFile.close();

    m_CubeShader = dot::Shader::Create(ShaderCode);
    m_FloorShader = dot::Shader::Create(ShaderCode);


    m_Camera = new dot::FirstPersonCamera(glm::vec3( 0 , 1.0f , 0.0f) , glm::vec3(0.0f , 0.0f ,-0.1f) ,glm::vec3(0.0f , 3.0f , -20.0f) );
    m_Camera->SetProjection(1.0f,1000.0f,0.1f,45);
    //m_Camera->SetPosition(glm::vec3( 0 , 3.0f , -0.0f));
    

    m_CubeModel = new dot::Model3D();
    m_CubeModel->SetPosition(glm::vec3(0.0f , 3.0f , -20.0f));

    m_FloorModel = new dot::Model3D();
    m_FloorModel->SetPosition(glm::vec3(0.0f,0.0f,0.0f));

    int TextWidth , TextHeight ;
    int channels;
    stbi_set_flip_vertically_on_load(1);
    stbi_uc* PixelBuffer = stbi_load("./SandBox/executable/Assets/Textures/Goodies.png", &TextWidth , &TextHeight , &channels , 0  );
    DOT_INFO("Channels {0} , width {1} , height {2} ", channels , TextWidth , TextHeight);
    DOT_ASSERT(PixelBuffer , "Failed to open png file !");
    dot::Texture2D::Format CubeFormat ;
    if (channels == 3)
        CubeFormat = dot::Texture2D::Format::RGB8;
    else if (channels == 4)
        CubeFormat = dot::Texture2D::Format::RGBA8;
    else 
        DOT_ASSERT(0 , " AAAAAAAAAAAAAAAA!!!!!!!!!!!");
    
    dot::Texture2D::Filter CubeFilter = dot::Texture2D::Filter::LINEAR;
    m_CubeTexture = dot::Texture2D::Create(PixelBuffer , TextWidth , TextHeight , CubeFilter , CubeFilter , CubeFormat);
    m_CubeTexture->InitTexture();
    m_CubeTexture->Bind();
    stbi_image_free(PixelBuffer);

    stbi_set_flip_vertically_on_load(1);
    PixelBuffer = stbi_load("./SandBox/executable/Assets/Textures/sand.png", &TextWidth , &TextHeight , &channels , 0  );
    DOT_INFO("Channels {0} , width {1} , height {2} ", channels , TextWidth , TextHeight);
    DOT_ASSERT(PixelBuffer , "Failed to open png file !");
    dot::Texture2D::Format FloorFormat ;
    if (channels == 3)
        FloorFormat = dot::Texture2D::Format::RGB8;
    else if (channels == 4)
        FloorFormat = dot::Texture2D::Format::RGBA8;
    else 
        DOT_ASSERT(0 , " AAAAAAAAAAAAAAAA!!!!!!!!!!!");
    
    dot::Texture2D::Filter FloorFilter = dot::Texture2D::Filter::LINEAR;
    m_FloorTexture = dot::Texture2D::Create(PixelBuffer , TextWidth , TextHeight , FloorFilter , FloorFilter , FloorFormat);
    m_FloorTexture->InitTexture();
    m_FloorTexture->Bind(1);
    stbi_image_free(PixelBuffer);

}

void ExambleLayer::OnEvent(dot::Event& e) {
            
}

void ExambleLayer::OnUpdate(dot::TimeStep time) {
    
    //glViewport(0, 0, m_Window->GetWidth() , m_Window->GetHeight());
    dot::Window& win = dot::Application::Get().GetWindow();
    m_Camera->SetProjection(m_Camera->GetZNear() , m_Camera->GetZFar() , 1280 / 720.0f , m_Camera->GetFov());
    DOT_INFO("Frame Time : {0} ms , width {1} , height {2}" , time.GetMills() , win.GetWidth() , win.GetHeight());
    glm::vec4 color;
    color.r = color.g = color.b = 0.1f;
    color.a = 1.0f;
    dot::RenderCommand::ClearColor(color);
    dot::RenderCommand::Clear();



    dot::Renderer::BeginScene(m_Camera);
    m_CubeShader->Bind();
    m_CubeTexture->Bind();
    m_CubeShader->SetUniformMatrix4f("u_projection" , m_Camera->GetProjectionMatrix());
    m_CubeShader->SetUniformMatrix4f("u_view" , m_Camera->GetViewMatrix());
    m_CubeShader->SetUniform1i("u_Texture" , m_CubeTexture->GetSlot());
    m_CubeShader->SetUniformMatrix4f("u_model" , m_CubeModel->GetModelMatrix());
    dot::MeshSettings CubeSet;
    CubeSet.blending.Enable = false;
    CubeSet.primitive.Type  = dot::Primitive::Primitives::TRIANGLES;
    CubeSet.primitive.Draw  = dot::Primitive::Drawing::FILL;
    CubeSet.binding.Enable  = true;
    CubeSet.binding.FrontFace = dot::Binding::Face::COUNTER_CLOCK_WISE;
    dot::Renderer::Submit(*m_VAOCube , CubeSet);
    m_FloorShader->Bind();
    m_FloorTexture->Bind();
    m_FloorShader->SetUniformMatrix4f("u_projection" , m_Camera->GetProjectionMatrix());
    m_FloorShader->SetUniformMatrix4f("u_view" , m_Camera->GetViewMatrix());
    m_FloorShader->SetUniform1i("u_Texture" , m_FloorTexture->GetSlot());
    m_FloorShader->SetUniformMatrix4f("u_model" , m_FloorModel->GetModelMatrix());
    dot::MeshSettings FloorSet;
    FloorSet.blending.Enable = false;
    FloorSet.primitive.Type  = dot::Primitive::Primitives::TRIANGLES;
    FloorSet.primitive.Draw  = dot::Primitive::Drawing::FILL;
    FloorSet.binding.Enable  = false;
    dot::Renderer::Submit(*m_VAOFloor , FloorSet);
    dot::Renderer::EndScene();
      

    if (dot::Input::IsKeyPressed(DOT_KEY_A))
        m_Camera->MoveLeft(10 * time);
    if (dot::Input::IsKeyPressed(DOT_KEY_D))
        m_Camera->MoveRight(10 * time);
    if (dot::Input::IsKeyPressed(DOT_KEY_S))
        m_Camera->MoveBack(10 * time);
    if (dot::Input::IsKeyPressed(DOT_KEY_W))
        m_Camera->MoveFront(10 * time);
    if (dot::Input::IsKeyPressed(DOT_KEY_SPACE))
        m_Camera->MoveUp(10 * time);
    if (dot::Input::IsKeyPressed(DOT_KEY_LEFT_CONTROL))
        m_Camera->MoveDown(10 * time);    

    if (dot::Input::IsKeyPressed(DOT_KEY_LEFT))
        m_Camera->RotateLeft( 90 * time);
    if (dot::Input::IsKeyPressed(DOT_KEY_RIGHT))
        m_Camera->RotateRight( 90 * time);
    if (dot::Input::IsKeyPressed(DOT_KEY_UP))
        m_Camera->RotateUp( 90 * time);
    if (dot::Input::IsKeyPressed(DOT_KEY_DOWN))
        m_Camera->RotateDown( 90 * time);

    glm::vec3 CubRot = m_CubeModel->GetRotation();

    if (dot::Input::IsKeyPressed(DOT_KEY_J))
        CubRot.x -= 360 * time;
    if (dot::Input::IsKeyPressed(DOT_KEY_L))
        CubRot.x += 360 * time;
    if (dot::Input::IsKeyPressed(DOT_KEY_I))
        CubRot.y += 360 * time;
    if (dot::Input::IsKeyPressed(DOT_KEY_K))
        CubRot.y -= 360 * time;
    if (dot::Input::IsKeyPressed(DOT_KEY_O))
        CubRot.z += 360 * time;
    if (dot::Input::IsKeyPressed(DOT_KEY_U))
        CubRot.z -= 360 * time;

    glm::vec3 sc = m_CubeModel->GetScaling();

    if (dot::Input::IsKeyPressed(DOT_KEY_F)){
    
        sc.x -= time*0.6f;
        if (sc.x <= 0)
            sc.x = 0.001f;
        sc.y -= time*0.6f;
        if (sc.y <= 0)
            sc.y = 0.001f;
        sc.z -= time*0.6f;
        if (sc.z <= 0)
            sc.z = 0.001f;
    }
        
    if (dot::Input::IsKeyPressed(DOT_KEY_G)){
        sc.x += time*0.6f;
        sc.y += time*0.6f;
        sc.z += time*0.6f;
    }
        
        
    m_CubeModel->SetScale(sc);
    m_CubeModel->SetRotation(CubRot);

    //DOT_INFO("Camera Position : {0},{1},{2} (x,y,z)", m_Camera->m_Position.x , m_Camera->m_Position.y , m_Camera->m_Position.z);
    //DOT_INFO("Camera Rotation : {0},{1} (ThetaX , ThetaY)", m_Camera->m_Rotation.x , m_Camera->m_Rotation.y );

}

SandBox::SandBox(void): dot::Application::Application() {
    this->PushLayer(new ExambleLayer());
}

SandBox::~SandBox(void){

}



