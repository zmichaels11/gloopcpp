/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   matrices.hpp
 * Author: zmichaels
 *
 * Created on April 25, 2017, 9:47 AM
 */

#pragma once

#include <array>

namespace gloop {
    typedef std::array<float, 4> mat2;
    typedef std::array<float, 9> mat3;
    typedef std::array<float, 16> mat4;
    typedef std::array<float, 25> mat5;

    typedef std::array<float, 2> vec2;
    typedef std::array<float, 3> vec3;
    typedef std::array<float, 4> vec4;
    typedef std::array<float, 5> vec5;

    namespace states {
        class viewport;
    }

    namespace matrices {

        constexpr mat4 createMat4(const vec4& v0, const vec4& v1, const vec4& v2, const vec4& v3) {
            return {
                v0[0], v0[1], v0[2], v0[3],
                v1[0], v1[1], v1[2], v1[3],
                v2[0], v2[1], v2[2], v2[3],
                v3[0], v3[1], v3[2], v3[3]};
        }

        constexpr mat4 identity4F() {
            return mat4{
                1.0F, 0.0F, 0.0F, 0.0F,
                0.0F, 1.0F, 0.0F, 0.0F,
                0.0F, 0.0F, 1.0F, 0.0F,
                0.0F, 0.0F, 0.0F, 1.0F};
        }

        constexpr mat4 rotationX4F(float sa, float ca) {
            return mat4{
                1.0F, 0.0F, 0.0F, 0.0F,
                0.0F, ca, sa, 0.0F,
                0.0F, -sa, ca, 0.0F,
                0.0F, 0.0F, 0.0F, 1.0F};
        }

        mat4 rotationX4F(float angle);

        constexpr mat4 rotationY4F(float sa, float ca) {
            return mat4{
                ca, 0.0F, -sa, 0.0F,
                0.0F, 1.0F, 0.0F, 0.0F,
                sa, 0.0F, ca, 0.0F,
                0.0F, 0.0F, 0.0F, 1.0F};
        }

        mat4 rotationY4F(float angle);

        constexpr mat4 rotationZ4F(float sa, float ca) {
            return mat4{
                ca, sa, 0.0F, 0.0F,
                -sa, 1.0F, 0.0F, 0.0F,
                0.0F, 0.0F, 1.0F, 0.0F,
                0.0F, 0.0F, 0.0F, 1.0F};
        }

        mat4 rotationZ4F(float angle);

        constexpr mat4 translation4F(float x, float y, float z, float w) {
            return mat4{
                1.0F, 0.0F, 0.0F, 0.0F,
                0.0F, 1.0F, 0.0F, 0.0F,
                0.0F, 0.0F, 1.0F, 0.0F,
                x, y, z, w};
        }

        constexpr mat4 translation4F(const vec4& v) {
            return mat4{
                1.0F, 0.0F, 0.0F, 0.0F,
                0.0F, 1.0F, 0.0F, 0.0F,
                0.0F, 0.0F, 1.0F, 0.0F,
                v[0], v[1], v[2], v[3]};
        }

        constexpr mat4 scale4F(float x, float y, float z, float w) {
            return mat4{
                x, 0.0F, 0.0F, 0.0F,
                0.0F, y, 0.0F, 0.0F,
                0.0F, 0.0F, z, 0.0F,
                0.0F, 0.0F, 0.0F, w};
        }

        constexpr mat4 scale4F(const vec4& v) {
            return mat4{
                v[0], 0.0F, 0.0F, 0.0F,
                0.0F, v[1], 0.0F, 0.0F,
                0.0F, 0.0F, v[2], 0.0F,
                0.0F, 0.0F, 0.0F, v[3]};
        }

        constexpr mat4 ortho4F(float left, float right, float bottom, float top, float near, float far) {
            return mat4{
                2.0F / (right - left), 0.0F, 0.0F, 0.0F,
                0.0F, 2.0F / (top - bottom), 0.0F, 0.0F,
                0.0F, 0.0F, -2.0F / (far - near), 0.0F,
                -(right + left) / (right - left), -(top + bottom) / (top - bottom), -(far + near) / (far - near), 1.0F};
        }

        mat4 ortho4F(const gloop::states::viewport& view);

        constexpr mat4 perspective4F(float fov, float aspect, float near, float far) {
            return mat4{
                fov / aspect, 0.0F, 0.0F, 0.0F,
                0.0F, fov, 0.0F, 0.0F,
                0.0F, 0.0F, (far + near) / (far - near), -1.0F,
                0.0F, 0.0F, (2.0F * far * near) / (near - far), 0.0F};
        }

        mat4 makePerspective4F(float fov, float aspect, float near, float far);

        constexpr mat4 multiply(const mat4& in0, const mat4& in1) {
            return mat4{
                in0[0] * in1[0] + in0[1] * in1[4] + in0[2] * in1[8] + in0[3] * in1[12],
                in0[0] * in1[1] + in0[1] * in1[5] + in0[2] * in1[9] + in0[3] * in1[13],
                in0[0] * in1[2] + in0[1] * in1[6] + in0[2] * in1[10] + in0[3] * in1[14],
                in0[0] * in1[3] + in0[1] * in1[7] + in0[2] * in1[11] + in0[3] * in1[15],
                in0[4] * in1[0] + in0[5] * in1[4] + in0[6] * in1[8] + in0[7] * in1[12],
                in0[4] * in1[1] + in0[5] * in1[5] + in0[6] * in1[9] + in0[7] * in1[13],
                in0[4] * in1[2] + in0[5] * in1[6] + in0[6] * in1[10] + in0[7] * in1[14],
                in0[4] * in1[3] + in0[5] * in1[7] + in0[6] * in1[11] + in0[7] * in1[15],
                in0[8] * in1[0] + in0[9] * in1[4] + in0[10] * in1[8] + in0[11] * in1[12],
                in0[8] * in1[1] + in0[9] * in1[5] + in0[10] * in1[9] + in0[11] * in1[13],
                in0[8] * in1[2] + in0[9] * in1[6] + in0[10] * in1[10] + in0[11] * in1[14],
                in0[8] * in1[3] + in0[9] * in1[7] + in0[10] * in1[11] + in0[11] * in1[15],
                in0[12] * in1[0] + in0[13] * in1[4] + in0[14] * in1[8] + in0[15] * in1[12],
                in0[12] * in1[1] + in0[13] * in1[5] + in0[14] * in1[9] + in0[15] * in1[13],
                in0[12] * in1[2] + in0[13] * in1[6] + in0[14] * in1[10] + in0[15] * in1[14],
                in0[12] * in1[3] + in0[13] * in1[7] + in0[14] * in1[11] + in0[15] * in1[15]};
        }

        constexpr vec4 multiply(const mat4& in0, const vec4& in1) {
            return vec4{
                in0[0] * in1[0] + in0[4] * in1[1] + in0[8] * in1[2] + in0[12] * in1[3],
                in0[1] * in1[0] + in0[5] * in1[1] + in0[9] * in1[2] + in0[13] * in1[3],
                in0[2] * in1[0] + in0[6] * in1[1] + in0[10] * in1[2] + in0[14] * in1[3],
                in0[3] * in1[0] + in0[7] * in1[1] + in0[11] * in1[2] + in0[15] * in1[3]};
        }

        constexpr vec4 getRow(vec4& out, const mat4& in, int rowId) {
            return vec4{in[4 * rowId], in[4 * rowId + 1], in[4 * rowId + 2], in[4 * rowId + 3]};
        }

        constexpr vec5 getRow(vec5& out, const mat5& in, int rowId) {
            return vec5{in[5 * rowId], in[5 * rowId + 1], in[5 * rowId + 3], in[5 * rowId + 4]};
        }

        void setRow(mat4& inout, int rowId, const vec4& in);

        void setRow(mat5& inout, int rowId, const vec5& in);
    }

    namespace vectors {

        constexpr vec4 add(const vec4& in0, const vec4& in1) {
            return vec4{
                in0[0] + in1[0],
                in0[1] + in1[1],
                in0[2] + in1[2],
                in0[3] + in1[3]};
        }

        constexpr vec4 subtract(const vec4& in0, const vec4& in1) {
            return vec4{
                in0[0] - in1[0],
                in0[1] - in1[1],
                in0[2] - in1[2],
                in0[3] - in1[3]};
        }

        constexpr vec4 scale(const vec4& in0, float scale) {
            return vec4{
                in0[0] * scale,
                in0[1] * scale,
                in0[2] * scale,
                in0[3] * scale};
        }

        constexpr vec4 scale(const vec4& in0, const vec4& in1) {
            return vec4{
                in0[0] * in1[0],
                in0[1] * in1[1],
                in0[2] * in1[2],
                in0[3] * in1[3]};
        }

        constexpr float dot(const vec4& in0, const vec4& in1) {
            return in0[0] * in1[0]
                    + in0[1] * in1[1]
                    + in0[2] * in1[2]
                    + in0[3] * in1[3];
        }

        constexpr float length2(const vec4& in) {
            return dot(in, in);
        }

        float length(const vec4& in);

        constexpr vec2 asVec2(const vec3& in) {
            return vec2{in[0], in[1]};
        }

        constexpr vec3 asVec3(const vec4& in) {
            return vec3{in[0], in[1], in[2]};
        }

        constexpr vec4 asVec4(const vec5& in) {
            return vec4{in[0], in[1], in[2], in[3]};
        }
    }
}