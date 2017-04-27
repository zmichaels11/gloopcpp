#version 130

#extension GL_ARB_bindless_texture : enable

in vec2 vPos;
in vec4 vImageUVs;
in vec4 vMaskUVs;
in vec4 vMvp0;
in vec4 vMvp1;
in vec4 vMvp2;
in vec4 vMvp3;

#ifdef GL_ARB_bindless_texture
    in uvec2 vImage;
    in uvec2 vMask;
    flat out sampler2D image;
    flat out sampler2D mask;
#endif

out vec2 fImageUVs;
out vec2 fMaskUVs;

void main() {
    mat4 mvp = mat4(vMvp0, vMvp1, vMvp2, vMvp3);

    gl_Position = mvp * vec4(vPos, 0.0, 1.0);

    fImageUVs = mix(vImageUVs.xy, vImageUVs.zw, vPos);
    fMaskUVs = mix(vMaskUVs.xy, vMaskUVs.zw, vPos);

#ifdef GL_ARB_bindless_texture
    image = sampler2D(vImage);
    mask = sampler2D(vMask);
#endif
}
