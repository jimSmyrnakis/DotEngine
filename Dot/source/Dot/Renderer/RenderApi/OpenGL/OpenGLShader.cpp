#include "OpenGLShader.hpp"
#include <glad/glad.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>

uint32_t CompileAndCreateProgram(const std::string& vsrc , const std::string& fsrc){

    uint32_t m_RendererId;

    // Create an empty vertex shader handle
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    // Send the vertex shader source code to GL
    // Note that std::string's .c_str is NULL character terminated.
    const char *source = (const char *)vsrc.c_str();
    glShaderSource(vertexShader, 1, &source, 0);

    // Compile the vertex shader
    glCompileShader(vertexShader);

    GLint isCompiled = 0;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
    if(isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);
        
        // We don't need the shader anymore.
        glDeleteShader(vertexShader);

        // Use the infoLog as you see fit.
        DOT_ENGINE_ERROR("Vertex Shader Failed : {0}" , infoLog.data());
        DOT_ENGINE_ASSERT(0 , "Shader Failed !");
        
        // In this simple program, we'll just leave
        return 0;
    }

    // Create an empty fragment shader handle
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    // Send the fragment shader source code to GL
    // Note that std::string's .c_str is NULL character terminated.
    source = (const GLchar *)fsrc.c_str();
    glShaderSource(fragmentShader, 1, &source, 0);

    // Compile the fragment shader
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);
        
        // We don't need the shader anymore.
        glDeleteShader(fragmentShader);
        // Either of them. Don't leak shaders.
        glDeleteShader(vertexShader);

        // Use the infoLog as you see fit.
        DOT_ENGINE_ERROR("Fragment Shader Failed : {0}" , infoLog.data());
        DOT_ENGINE_ASSERT(0 , "Fragment Failed !");
        // In this simple program, we'll just leave
        return 0;
    }

    // Vertex and fragment shaders are successfully compiled.
    // Now time to link them together into a program.
    // Get a program object.
    GLuint program = glCreateProgram();
    m_RendererId = program;

    // Attach our shaders to our program
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    // Link our program
    glLinkProgram(program);

    
    GLint isLinked = 0;
    glGetProgramiv(program, GL_LINK_STATUS, (int *)&isLinked);
    if (isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);
        
        // We don't need the program anymore.
        glDeleteProgram(program);
        // Don't leak shaders either.
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        // Use the infoLog as you see fit.
        DOT_ENGINE_ERROR("Linking Shaders Objects Failed : {0}" , infoLog.data());
        DOT_ENGINE_ASSERT(0 , "Linking Shaders Objects Failed !");
        // In this simple program, we'll just leave
        return 0;
    }

    // Always detach shaders after a successful link.
    glDetachShader(program, vertexShader);
    glDetachShader(program, fragmentShader);
    
    // and delete the shaders object 
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return m_RendererId;
}

GLenum ShaderTypeFromString(const std::string& type){
    if (type == "vertex")
        return GL_VERTEX_SHADER;
    if (type == "fragment")
        return GL_FRAGMENT_SHADER;
    DOT_ENGINE_ERROR(type.c_str());
    DOT_ENGINE_ASSERT(0 , "Undefined Shader Type " );

    return 0;
}

std::unordered_map<GLenum , std::string> SplitShader(const std::string& ShaderSource){
    std::unordered_map<GLenum , std::string> spliter;
    const char* typeToken = "#type";
    size_t typeTokenSize = strlen(typeToken);
    size_t pos = ShaderSource.find(typeToken , 0);
    DOT_ENGINE_INFO(ShaderSource.c_str());

    while(pos != std::string::npos){

        size_t eol = ShaderSource.find_first_of("\r\n", pos);
        DOT_ENGINE_ASSERT(eol != std::string::npos , "Syntax error");
        size_t begin = pos + typeTokenSize + 1;
        std::string type = ShaderSource.substr(begin , eol - begin );
        DOT_ENGINE_ASSERT(ShaderTypeFromString(type),"Invalid Shader Type !");
        DOT_INFO(type.c_str());

        size_t nextLinePos = ShaderSource.find_first_not_of("\r\n" , eol);
        pos = ShaderSource.find(typeToken , nextLinePos);
        
        spliter[ShaderTypeFromString(type)] = ShaderSource.substr(nextLinePos , 
        pos - 
        ((nextLinePos == std::string::npos) ? (ShaderSource.size() -1) : (nextLinePos))
        );

        if (nextLinePos == std::string::npos)
            break;
        
        
    }


    return spliter;
}

dot::OpenGLShader::OpenGLShader(const std::string& Shader){

    std::unordered_map<GLenum , std::string> shads = SplitShader(Shader);

    
    m_RendererId = CompileAndCreateProgram(shads[GL_VERTEX_SHADER] , shads[GL_FRAGMENT_SHADER]);
}



dot::OpenGLShader::~OpenGLShader(void){
    glDeleteProgram(m_RendererId);
}

void dot::OpenGLShader::Bind(void) const {
    glUseProgram(m_RendererId);
}

void dot::OpenGLShader::Unbind(void) const{
    glUseProgram(0);
}

void dot::OpenGLShader::SetUniform4f(const std::string& name , float v0 , float v1 , float v2 , float v3){
    glUniform4f( this->GetUniformLocation(name) , v0 , v1 , v2 , v3) ;
}

void dot::OpenGLShader::SetUniform2f(const std::string& name , float v0 , float v1 ){
    glUniform2f( this->GetUniformLocation(name) , v0 , v1 ) ;
}

void dot::OpenGLShader::SetUniform1f(const std::string& name , float value){
    glUniform1f( this->GetUniformLocation(name) , value) ;
}

void dot::OpenGLShader::SetUniform1i(const std::string& name , int value){
    glUniform1i( this->GetUniformLocation(name) , value) ;
}

void dot::OpenGLShader::SetUniformMatrix4f(const std::string& name , const glm::mat4& matrix){
    glUniformMatrix4fv(this->GetUniformLocation(name) , 1, GL_FALSE , &matrix[0][0]);
}

int dot::OpenGLShader::GetUniformLocation(const std::string& name){
    GLint location;

    if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
        return m_UniformLocationCache[name];
    
        

    location = glGetUniformLocation(m_RendererId , name.c_str()) ;
    if (location == -1){
        std::stringstream ss;
        ss << "Warning : Uniform Variable \"" << name << "\" doesn't exist on the shader " << std::endl;
        DOT_ENGINE_WARN( ss.str() );
    }
    m_UniformLocationCache[name] = location;
    return location;
}
