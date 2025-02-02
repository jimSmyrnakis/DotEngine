#type vertex


#version 330 core

layout(location = 0) in vec3 a_Vertex;
layout(location = 1) in vec2 a_TextCoord; 
out vec2 v_TextCoord;
uniform mat4 u_pv;
uniform mat4 u_model;

void main(){
    
    v_TextCoord = a_TextCoord; 
    gl_Position = u_pv*u_model*vec4(a_Vertex , 1.0);
}









#type fragment
#version 330 core 

layout(location = 0) out vec4 v_color;

in vec2 v_TextCoord;

uniform sampler2D u_Texture;

void main(){
    v_color = texture(u_Texture , v_TextCoord);
}
