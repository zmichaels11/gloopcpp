#version 100

attribute vec2 LVertexPos2D;

void main() {
    gl_Position = vec4(LVertexPos2D, 0.0, 1.0);
}
