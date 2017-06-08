#version 300 es

//HEADER_TAG

precision mediump float;

in vec2 vPos;

in vec4 vMvp0;
in vec4 vMvp1;
in vec4 vMvp2;
in vec4 vMvp3;

in vec4 vUVs;

in vec4 vCTr0;
in vec4 vCTr1;
in vec4 vCTr2;
in vec4 vCTr3;
in vec4 vCo;

in vec2 vIgnoreCT;

flat out mat4 fCt;
flat out vec4 fCo;
flat out float fIgnoreCT;

out vec2 fUVs;

const mat4 IDENTITY = mat4(
    vec4(1.0, 0.0, 0.0, 0.0),
    vec4(0.0, 1.0, 0.0, 0.0),
    vec4(0.0, 0.0, 1.0, 0.0),
    vec4(0.0, 0.0, 0.0, 1.0));

void main() {
    if (vIgnoreCT.x > 0.0) {
        fCt = IDENTITY;
        fCo = vec4(0.0, 0.0, 0.0, 0.0);        
    } else {
        fCt = mat4(vCTr0, vCTr1, vCTr2, vCTr3);
        fCo = vCo;        
    }

    fIgnoreCT = vIgnoreCT.x;

    mat4 mvp = mat4(vMvp0, vMvp1, vMvp2, vMvp3);

    fUVs = mix(vUVs.xy, vUVs.zw, vPos);

    gl_Position = mvp * vec4(vPos, 0.0, 1.0);
}
