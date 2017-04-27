#version 130

#extension GL_ARB_bindless_texture : enable

in vec2 fImageUVs;
in vec2 fMaskUVs;

#ifdef GL_ARB_bindless_texture
    flat in sampler2D image;
    flat in sampler2D mask;
#else
    uniform sampler2D image;
    uniform sampler2D mask;
#endif

out vec4 result;

void main() {
    vec4 imageColor = texture(image, fImageUVs);
    float mask = texture(mask, fMaskUVs).r; //NOTE: this should probably use all color channels for the mask...

    result = vec4(imageColor.rgb, imageColor.a * mask);
}
