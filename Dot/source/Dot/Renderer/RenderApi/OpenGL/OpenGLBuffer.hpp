#pragma once
#include "../Buffer.hpp"
#include <string>
#include <glad/glad.h>

namespace dot{

    GLenum ShaderDataTypeToOpenGLType(ShaderDataType type);

    class OpenGLVertexBuffer : public VertexBuffer{
        public:
            OpenGLVertexBuffer(float* vertexData , dotSize size);
            virtual ~OpenGLVertexBuffer(void);

            virtual void Bind(void) const override;
            virtual void Unbind(void) const override;

            virtual BufferLayout& GetLayout(void) override;
            virtual const BufferLayout& GetLayout(void) const override;
            virtual void SetLayout(const BufferLayout layout) override;

        private:
            uint32_t     m_ObjectId;
            BufferLayout m_Layout;
            
    };

    class OpenGLIndexBuffer : public IndexBuffer{
        public:
            OpenGLIndexBuffer(uint32_t* indexData , dotSize size);
            virtual ~OpenGLIndexBuffer(void);

            virtual uint32_t GetCount(void) const override;
            virtual void     Bind(void)     const override;
            virtual void     Unbind(void)   const override;
        private:
            uint32_t m_ObjectId;
            uint32_t m_Count;
    };

    class OpenGLVertexArray : public VertexArray{
        public:
            OpenGLVertexArray(void);
            ~OpenGLVertexArray(void);

            virtual void Bind(void) const override;
            virtual void Unbind(void) const override;
            virtual void AddVertexBuffer(const VertexBuffer& vo) override;
            virtual void SetIndexBuffer(const IndexBuffer& io) override;
            virtual IndexBuffer& GetIndexBuffer(void) const override;
            
        private:
            uint32_t                    m_ObjectId;
            std::vector<VertexBuffer*>  m_VElements;
            IndexBuffer*                m_IElement;
    };

}