#version 100

precision mediump float;

//HEADER_TAG

attribute vec2 vSelect;
attribute vec4 vPos;
attribute vec4 vColor;
attribute vec4 vMvp0;
attribute vec4 vMvp1;
attribute vec4 vMvp2;
attribute vec4 vMvp3;

varying vec4 fColor;

void main() {    
    mat4 mvp = mat4(vMvp0, vMvp1, vMvp2, vMvp3);

    vec2 pos = mix(vPos.xy, vPos.zw, vSelect);

    gl_Position = mvp * vec4(pos, 0.0, 1.0);

    fColor = vColor;
}