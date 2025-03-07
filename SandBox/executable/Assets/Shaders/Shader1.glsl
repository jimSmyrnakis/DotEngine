#type vertex


#version 330 core

layout(location = 0) in vec3 v_Vertex;
layout(location = 1) in vec2 v_TextCoord; 
out vec2 v_TextCoordOut;
vec4 v_Vertices;
uniform mat4 u_projection;
uniform mat4 u_view;
uniform mat4 u_model;

void main(){
    
    v_TextCoordOut = v_TextCoord;
    v_Vertices =  u_projection*u_view*u_model*vec4(v_Vertex , 1.0);
    gl_Position = v_Vertices;
}









#type fragment
#version 330 core 
layout(early_fragment_tests) in;  // Αναγκαστικό Early-Z
 
in vec4 v_Vertices;
in vec2 v_TextCoordOut;
layout(location = 0 ) out vec4 v_FragColor; // the color buffer attachment 0
uniform sampler2D u_Texture;

void main(){
    	vec4 color = texture(u_Texture, v_TextCoordOut);  // Δείγμα από το texture

    	v_FragColor = vec4(color.rgb, 1.0); // Τελικό χρώμα
}
