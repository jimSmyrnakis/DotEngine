#include "Buffer.hpp"
#include "RendererApi.hpp"
#include "OpenGL/OpenGLBuffer.hpp"

uint32_t dot::SizeOfShaderDataType(ShaderDataType type){

    switch(type){
        case ShaderDataType::Float  : return 1*sizeof(float);
        case ShaderDataType::Float2 : return 2*sizeof(float);
        case ShaderDataType::Float3 : return 3*sizeof(float);
        case ShaderDataType::Float4 : return 4*sizeof(float);
        case ShaderDataType::Mat3   : return 3*3*sizeof(float);
        case ShaderDataType::Mat4   : return 4*4*sizeof(float);
        case ShaderDataType::Int    : return 1*sizeof(int);
        case ShaderDataType::Int2   : return 2*sizeof(int);
        case ShaderDataType::Int3   : return 3*sizeof(int);
        case ShaderDataType::Int4   : return 4*sizeof(int);
        case ShaderDataType::Bool   : return 1*sizeof(bool);
    };
    DOT_ENGINE_ASSERT(0 , "Unknown Shader Data Type !");
    return 0;
}



dot::BufferElement::BufferElement(const std::string& name , ShaderDataType type , bool Norm)
    :   Name(name) , Type(type) , Size(0) , Offs(0) , Normallized(Norm) {
    Size = SizeOfShaderDataType(Type);

}
uint32_t dot::BufferElement::GetComponentCount(void) const{

    switch(Type){
        case ShaderDataType::Float  : return 1  ;
        case ShaderDataType::Float2 : return 2  ;
        case ShaderDataType::Float3 : return 3  ;
        case ShaderDataType::Float4 : return 4  ;
        case ShaderDataType::Mat3   : return 3*3;
        case ShaderDataType::Mat4   : return 4*4;
        case ShaderDataType::Int    : return 1  ;
        case ShaderDataType::Int2   : return 2  ;
        case ShaderDataType::Int3   : return 3  ;
        case ShaderDataType::Int4   : return 4  ;
        case ShaderDataType::Bool   : return 1  ;
    };
    DOT_ENGINE_ASSERT(0 , "Unknown Shader Data Type !");
    return 0;
}






dot::BufferLayout::BufferLayout(const std::initializer_list<BufferElement>& elements) : m_Elements(elements) {
    CalculateOffsetsAndStride();
}

const std::vector<dot::BufferElement>& dot::BufferLayout::GetElements(void) const { return m_Elements; }

void dot::BufferLayout::CalculateOffsetsAndStride(void){
    DOT_ENGINE_ASSERT(m_Elements.size() , "BufferLayout has not initiallized with Buffer Elements!");
    uint32_t Offset = 0;
    for (BufferElement& element : m_Elements){
        element.Offs = Offset;
        Offset += element.Size;
    }
    m_Stride = Offset;

}

std::vector<dot::BufferElement>::iterator dot::BufferLayout::begin(void) { return m_Elements.begin(); }
std::vector<dot::BufferElement>::iterator dot::BufferLayout::end(void)   { return m_Elements.end();}





dot::IndexBuffer::IndexBuffer(void){}
dot::VertexBuffer::VertexBuffer(void){}
dot::IndexBuffer::~IndexBuffer(void){}
dot::VertexBuffer::~VertexBuffer(void){}

dot::IndexBuffer*  dot::IndexBuffer::Create(uint32_t* indexData , dotSize count){
    dot::IndexBuffer* ib = nullptr;
    if (dot::RendererApi::GetCurrentApi() == dot::RendererApi::Api::OPENGL)
    {
        ib = new OpenGLIndexBuffer(indexData , count); 
    }
    return ib;
}

dot::VertexBuffer* dot::VertexBuffer::Create(float* vertexData , dotSize count){
    dot::VertexBuffer* vb = nullptr;
    if (dot::RendererApi::GetCurrentApi() == dot::RendererApi::Api::OPENGL)
    {
        vb = new OpenGLVertexBuffer(vertexData , count); 
    }
    return vb;
}

dot::VertexArray* dot::VertexArray::Create(void){
    dot::VertexArray* vao = nullptr;
    if (dot::RendererApi::GetCurrentApi() == dot::RendererApi::Api::OPENGL)
    {
        vao = new OpenGLVertexArray();
    }
    return vao;
}