#version 450

out vec3 color;

uniform vec3 in_color;

void main() {
  color = in_color;
}