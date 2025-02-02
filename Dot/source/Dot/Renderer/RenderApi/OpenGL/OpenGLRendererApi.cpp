#include "OpenGLRendererApi.hpp"
#include <glad/glad.h>

void dot::OpenGLRendererApi::SetClearColor(const glm::vec4& color){
    glClearColor(color.r , color.g , color.b , color.a);
}

void dot::OpenGLRendererApi::Clear(void){
    glClear(GL_COLOR_BUFFER_BIT);
}



void SetSettings(dot::MeshSettings set){

    if (set.binding.Enable == false){
        glDisable(GL_CULL_FACE);
        return;
    }

    glEnable(GL_CULL_FACE);

    if (set.binding.FrontFace == dot::Binding::Face::COUNTER_CLOCK_WISE){
        glFrontFace(GL_CCW); // front facing triangles are in order Counter Clock Wise 
        glCullFace(GL_FRONT); // cull the back facing triangles
    }
    else {
        glFrontFace(GL_CW);
        glCullFace(GL_FRONT); // cull the back facing triangles
    }
        
    if (set.blending.Enable){
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA);
    }
    
}

void ClearSettings(void){
    glDisable(GL_CULL_FACE);
    glDisable(GL_BLEND);
}

void dot::OpenGLRendererApi::DrawIndexed(const dot::VertexArray& va , MeshSettings settings ){
    va.Bind();
    //glEnable(GL_DEPTH_TEST);

    glPolygonMode(GL_FRONT_AND_BACK , GL_FILL); // draw the triangle with fill all the inside's
    
    SetSettings(settings);

    glDrawElements(GL_TRIANGLES , va.GetIndexBuffer().GetCount() , GL_UNSIGNED_INT , nullptr);

    ClearSettings();
}


