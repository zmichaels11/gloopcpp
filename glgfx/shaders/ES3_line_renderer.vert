#version 300 es

precision mediump float;

//HEADER_TAG

in vec2 vSelect;
in vec4 vPos;
in vec4 vColor;
in vec4 vMvp0;
in vec4 vMvp1;
in vec4 vMvp2;
in vec4 vMvp3;

out vec4 fColor;

void main() {    
    mat4 mvp = mat4(vMvp0, vMvp1, vMvp2, vMvp3);

    vec2 pos = mix(vPos.xy, vPos.zw, vSelect);

    gl_Position = mvp * vec4(pos, 0.0, 1.0);

    fColor = vColor;
}
