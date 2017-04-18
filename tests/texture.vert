#version 100

attribute vec2 vPos;
attribute vec2 vUVs;

varying vec2 fUVs;

void main() {
    gl_Position = vec4(vPos, 0.0, 1.0);

    fUVs = vUVs;
}

