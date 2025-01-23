#pragma once
#include "../../../Core.hpp"
#include <string>
#include <glm/glm.hpp>

namespace dot{
    class OpenGLShader{
        public:
            OpenGLShader(const std::string& VertexShader , const std::string& FragmentShader);
            ~OpenGLShader(void);

            void Bind(void);
            void Unbind(void);

            int  GetUniformLocation(const std::string& name);
            void SetUniformMatrix4f(const std::string& name , const glm::mat4& matrix);
            void SetUniform1i(const std::string& name , int value);
            void SetUniform1f(const std::string& name , float value);
            void SetUniform2f(const std::string& name , float v0 , float v1 );
            void SetUniform4f(const std::string& name , float v0 , float v1 , float v2 , float v3);

        private:
            std::unordered_map<std::string , int>  m_UniformLocationCache  ;
            uint32_t m_RendererId;
    };
}