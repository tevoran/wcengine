#version 450

in vec4 vertex_position;

void main() {
  gl_Position = vertex_position;
}