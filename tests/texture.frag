#version 100

precision mediump float;

varying vec2 fUVs;

uniform sampler2D fTexture;

void main() {
    gl_FragColor = texture2D(fTexture, fUVs);
}

