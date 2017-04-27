#version 130

//HEADER_TAG

in vec2 vPos;
in vec4 vColor;
in vec4 vMvp0;
in vec4 vMvp1;
in vec4 vMvp2;
in vec4 vMvp3;

out vec4 fColor;

void main() {
    mat4 mvp = mat4(vMvp0, vMvp1, vMvp2, vMvp3);
    fColor = vColor;

    gl_Position = mvp * vec4(vPos, 0.0, 1.0);
}
