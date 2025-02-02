#pragma once

#include <glm/glm.hpp>
#include <string>


namespace dot{
    class Shader{
        public:
            virtual void Bind(void) const  = 0;
            virtual void Unbind(void) const  = 0;

            virtual void SetUniformMatrix4f(const std::string& name , const glm::mat4& matrix) = 0;
            virtual void SetUniform1i(const std::string& name , int value) = 0;
            virtual void SetUniform1f(const std::string& name , float value) = 0;
            virtual void SetUniform2f(const std::string& name , float v0 , float v1 ) = 0;
            virtual void SetUniform4f(const std::string& name , float v0 , float v1 , float v2 , float v3) = 0;

        public:
            static Shader* Create(const std::string& Shader);

    };

    

}