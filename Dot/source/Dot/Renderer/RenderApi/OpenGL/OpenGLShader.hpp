#pragma once
#include "../../../Core.hpp"
#include "../Shader.hpp"
#include <string>
#include <glm/glm.hpp>
#include <stdint.h>
#include <stddef.h>

namespace dot{
    class OpenGLShader : public Shader{
        public:
            OpenGLShader(const std::string& Shader);
            ~OpenGLShader(void);

            virtual void Bind(void)     const override;
            virtual void Unbind(void)   const override;

            virtual int  GetUniformLocation(const std::string& name);
            virtual void SetUniformMatrix4f(const std::string& name , const glm::mat4& matrix) override;
            virtual void SetUniform1i(const std::string& name , int value) override;
            virtual void SetUniform1f(const std::string& name , float value) override;
            virtual void SetUniform2f(const std::string& name , float v0 , float v1 ) override;
            virtual void SetUniform4f(const std::string& name , float v0 , float v1 , float v2 , float v3) override;

        private:
            std::unordered_map<std::string , int>  m_UniformLocationCache  ;
            uint32_t m_RendererId;
    };
}