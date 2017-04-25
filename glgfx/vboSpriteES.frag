#version 100

precision mediump float;

varying mat4 fCt;
varying vec4 fCo;
varying float fIgnoreCT;
varying vec2 fUVs;

uniform sampler2D spritesheet;

void main() {
    vec4 baseColor = texture2D(spritesheet, fUVs);

    if (fIgnoreCT > 0.0) {
        gl_FragColor = baseColor;
    } else {
        gl_FragColor = fCt * baseColor + fCo;
    }
}