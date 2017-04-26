#version 130
#extension GL_ARB_bindless_texture : enable

flat in mat4 fCt;
flat in vec4 fCo;
flat in float fIgnoreCT;
in vec2 fUVs;

#if GL_ARB_bindless_texture
    flat in sampler2D spritesheet;
#else    
    uniform sampler2D spritesheet;
#endif

void main() {
    vec4 baseColor = texture2D(spritesheet, fUVs);

    if (fIgnoreCT > 0.0) {
        gl_FragColor = baseColor;
    } else {
        gl_FragColor = fCt * baseColor + fCo;
    }    
}