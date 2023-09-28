#version 330 core

layout(location = 0) in vec3 vertexPosition;

uniform mat4 renderMatrix;

void main(){
	gl_Position = renderMatrix * vec4(vertexPosition, 1);
}
