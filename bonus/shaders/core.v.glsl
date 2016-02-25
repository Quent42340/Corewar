#version 330

in vec3 vertex;
in vec3 color;

out vec3 v_color;

uniform mat4 u_projectionMatrix;

void main() {
	gl_Position = u_projectionMatrix * vec4(vertex, 1.0);
	
	v_color = color;
}
