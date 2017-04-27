#version 100
//HEADER_TAG

precision mediump float;

attribute vec2 vPos;
attribute vec4 vColor;
attribute vec4 vMvp0;
attribute vec4 vMvp1;
attribute vec4 vMvp2;
attribute vec4 vMvp3;

varying vec4 fColor;

void main() {
    mat4 mvp = mat4(vMvp0, vMvp1, vMvp2, vMvp3);
    fColor = vColor;

    gl_Position = mvp * vec4(vPos, 0.0, 1.0);
}
