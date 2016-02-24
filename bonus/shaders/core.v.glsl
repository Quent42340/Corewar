#version 330

in vec3 vertex;

uniform mat4 u_projectionMatrix;

void main() {
	gl_Position = u_projectionMatrix * vec4(vertex, 1.0);
}
