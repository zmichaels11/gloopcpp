#version 130

flat in mat4 fCt;
flat in vec4 fCo;
flat in float fIgnoreCT;
in vec2 fUVs;

uniform sampler2D spritesheet;

void main() {
    vec4 baseColor = texture2D(spritesheet, fUVs);

    if (fIgnoreCT > 0.0) {
        gl_FragColor = baseColor;
    } else {
        gl_FragColor = fCt * baseColor + fCo;
    }    
}