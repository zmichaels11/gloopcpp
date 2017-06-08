#version 300 es

precision mediump float;

flat in mat4 fCt;
flat in vec4 fCo;
flat in float fIgnoreCT;
in vec2 fUVs;

uniform sampler2D spritesheet;

out vec4 result;

void main() {
    vec4 baseColor = texture(spritesheet, fUVs);

    if (fIgnoreCT > 0.0) {
        result = baseColor;
    } else {
        result = fCt * baseColor + fCo;
    }    
}
