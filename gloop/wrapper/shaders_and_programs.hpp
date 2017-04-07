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
        constexpr gloop::enum_t SHADER_INFO_LOG = 0x8B84;
        constexpr gloop::enum_t COMPILE_STATUS = 0x8B81;
        
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
    }
}