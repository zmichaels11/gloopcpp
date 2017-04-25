#version 100

//HEADER_TAG

precision mediump float;

attribute vec2 vPos;

attribute vec4 vMvp0;
attribute vec4 vMvp1;
attribute vec4 vMvp2;
attribute vec4 vMvp3;

attribute vec4 vUVs;

attribute vec4 vCTr0;
attribute vec4 vCTr1;
attribute vec4 vCTr2;
attribute vec4 vCTr3;
attribute vec4 vCo;

attribute float vIgnoreCT;

varying mat4 fCt;
varying vec4 fCo;
varying float fIgnoreCT;

varying vec2 fUVs;

const mat4 IDENTITY = mat4(
    vec4(1.0, 0.0, 0.0, 0.0),
    vec4(0.0, 1.0, 0.0, 0.0),
    vec4(0.0, 0.0, 1.0, 0.0),
    vec4(0.0, 0.0, 0.0, 1.0));

void main() {
    if (vIgnoreCT > 0.0) {
        fCt = IDENTITY;
        fCo = vec4(0.0, 0.0, 0.0, 0.0);        
    } else {
        fCt = mat4(vCTr0, vCTr1, vCTr2, vCTr3);
        fCo = vCo;        
    }

    fIgnoreCT = vIgnoreCT;

    mat4 mvp = mat4(vMvp0, vMvp1, vMvp2, vMvp3);

    fUVs = mix(vUVs.xy, vUVs.zw, vPos);

    gl_Position = mvp * vec4(vPos, 0.0, 1.0);
}
