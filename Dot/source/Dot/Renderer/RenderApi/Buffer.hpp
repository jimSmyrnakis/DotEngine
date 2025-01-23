#pragma once
#include "../../Core.hpp"
#include <vector>
#include <string>

namespace dot{

    enum class ShaderDataType{
        Float,
        Float2,
        Float3,
        Float4,
        Mat3  ,
        Mat4  ,
        Int   ,
        Int2  ,
        Int3  ,
        Int4  ,
        Bool 
    };

    uint32_t SizeOfShaderDataType(ShaderDataType type);

    struct BufferElement{
        std::string     Name;
        ShaderDataType  Type;
        uint32_t        Size;
        uint32_t        Offs;
        bool            Normallized;

        BufferElement(const std::string& name , ShaderDataType type , bool Norm = true);

        uint32_t GetComponentCount(void) const;
    };

    class BufferLayout{
        public:
            BufferLayout(const std::initializer_list<BufferElement>& elements);

            const std::vector<BufferElement>& GetElements(void) const ;
            std::vector<BufferElement>::iterator begin(void) ;
            std::vector<BufferElement>::iterator end(void) ;

            inline uint32_t GetStride(void) const { return m_Stride;}
        private:
            std::vector<BufferElement> m_Elements;
            uint32_t                   m_Stride  ;
        private:
            void CalculateOffsetsAndStride(void);
    };

    class IndexBuffer{

    public:
        IndexBuffer(void);
        virtual ~IndexBuffer(void);

        virtual uint32_t GetCount(void) const = 0;
        virtual void Bind(void) const = 0;
        virtual void Unbind(void) const = 0;
        static IndexBuffer* Create(uint32_t* indexData , dotSize count);
    };



    class VertexBuffer{

    public:
        VertexBuffer(void);
        virtual ~VertexBuffer(void);

        virtual void Bind(void) const = 0;
        virtual void Unbind(void) const = 0;
        virtual BufferLayout& GetLayout(void) = 0;
        virtual const BufferLayout& GetLayout(void) const = 0;
        virtual void SetLayout(const BufferLayout layout) = 0;
        
        static VertexBuffer* Create(float* vertexData , dotSize count);
    };

    class VertexArray{

    public:
        VertexArray(void) = default;
        virtual ~VertexArray(void) = default;

        virtual void Bind(void) const = 0;
        virtual void Unbind(void) const = 0;

        virtual void AddVertexBuffer(const VertexBuffer& buffer) = 0;
        virtual void SetIndexBuffer (const IndexBuffer&  index)  = 0;   

        virtual IndexBuffer& GetIndexBuffer(void) const = 0;     
        
        static VertexArray* Create(void);
    };

}