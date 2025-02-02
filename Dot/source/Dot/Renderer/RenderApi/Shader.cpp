#include "Shader.hpp"
#include "RendererApi.hpp"
#include "OpenGL/OpenGLShader.hpp"


dot::Shader* dot::Shader::Create(const std::string& Shader) { 
    dot::Shader* sh = nullptr;
    if (RendererApi::GetCurrentApi() == RendererApi::Api::OPENGL){
        OpenGLShader* shad = new OpenGLShader(Shader);
        sh = shad;
        return sh;
    }
            

    DOT_ENGINE_ASSERT( 0 , "Undefined Shader Api Implementation !");
    return nullptr;
} 