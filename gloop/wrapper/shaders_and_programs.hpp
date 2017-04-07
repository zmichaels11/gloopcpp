/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   shaders_and_programs.hpp
 * Author: zmichaels
 *
 * Created on April 7, 2017, 3:36 PM
 */

#pragma once

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {
        constexpr gloop::enum_t INFO_LOG_LENGTH = 0x8B84;
        constexpr gloop::enum_t COMPILE_STATUS = 0x8B81;
        constexpr gloop::enum_t LINK_STATUS = 0x8B82;
        constexpr gloop::enum_t INVALID_INDEX = 0xFFFFFFFF;

        void getShaderiv(
                gloop::uint_t shader,
                gloop::enum_t pname,
                gloop::int_t * param);

        void getShaderInfoLog(
                gloop::uint_t shader,
                gloop::sizei_t bufSize,
                gloop::sizei_t * length,
                gloop::char_t * infoLog);

        gloop::uint_t createShader(gloop::enum_t type);

        void shaderSource(
                gloop::uint_t shader,
                gloop::sizei_t count,
                const gloop::char_t * const * src,
                const gloop::int_t * length);

        void compileShader(gloop::uint_t shader);

        void deleteShader(gloop::uint_t shader);

        void getProgramiv(
                gloop::uint_t program,
                gloop::enum_t pname,
                gloop::int_t * param);

        void getProgramInfoLog(
                gloop::uint_t program,
                gloop::sizei_t bufSize,
                gloop::sizei_t * length,
                gloop::char_t * infoLog);

        void useProgram(gloop::uint_t program);

        gloop::uint_t createProgram();

        void attachShader(gloop::uint_t program, gloop::uint_t shader);

        void linkProgram(gloop::uint_t program);

        void detachShader(gloop::uint_t program, gloop::uint_t shader);

        void deleteProgram(gloop::uint_t program);

        gloop::uint_t getUniformBlockIndex(
                gloop::uint_t program,
                const gloop::char_t * uniformName);

        gloop::int_t getUniformLocation(
                gloop::uint_t program,
                const gloop::char_t * uniformName);

        void uniformBlockBinding(
                gloop::uint_t program,
                gloop::uint_t uniformBlockIndex,
                gloop::uint_t uniformBlockBinding);

        void bindAttribLocation(
                gloop::uint_t program,
                gloop::uint_t index,
                const gloop::char_t * name);
    }
}