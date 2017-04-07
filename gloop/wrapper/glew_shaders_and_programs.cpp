/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#if GL == GLEW
#include "shaders_and_programs.hpp"

#include <GL/glew.h>

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {
        void getShaderiv(
                gloop::uint_t shader,
                gloop::enum_t pname,
                gloop::int_t * param) {
            
            glGetShaderiv(shader, pname, param);
        }

        void getShaderInfoLog(
                gloop::uint_t shader,
                gloop::sizei_t bufSize,
                gloop::sizei_t * length,
                gloop::char_t * infoLog) {
            
            glGetShaderInfoLog(shader, bufSize, length, infoLog);
        }

        gloop::uint_t createShader(gloop::enum_t type) {
            return glCreateShader(type);
        }

        void shaderSource(
                gloop::uint_t shader,
                gloop::sizei_t count,
                const gloop::char_t * const * src,
                const gloop::int_t * length) {
            
            glShaderSource(shader, count, src, length);
        }
        
        void compileShader(gloop::uint_t shader) {
            glCompileShader(shader);
        }
        
        void deleteShader(gloop::uint_t shader) {
            glDeleteShader(shader);
        }
        
        void getProgramiv(
                gloop::uint_t program,
                gloop::enum_t pname,
                gloop::int_t * param) {
            
            glGetProgramiv(program, pname, param);
        }

        void getProgramInfoLog(
                gloop::uint_t program,
                gloop::sizei_t bufSize,
                gloop::sizei_t * length,
                gloop::char_t * infoLog) {
            
            glGetProgramInfoLog(program, bufSize, length, infoLog);
        }
     
        void useProgram(gloop::uint_t program) {
            glUseProgram(program);
        }
        
        gloop::uint_t createProgram() {
            return glCreateProgram();
        }
        
        void attachShader(gloop::uint_t program, gloop::uint_t shader) {
            glAttachShader(program, shader);
        }
        
        void linkProgram(gloop::uint_t program) {
            glLinkProgram(program);
        }
        
        void detachShader(gloop::uint_t program, gloop::uint_t shader) {
            glDetachShader(program, shader);
        }
        
        void deleteProgram(gloop::uint_t program) {
            glDeleteProgram(program);
        }
        
        gloop::uint_t getUniformBlockIndex(gloop::uint_t program, const gloop::char_t * uniformName) {
            return glGetUniformBlockIndex(program, uniformName);
        }
        
        gloop::int_t getUniformLocation(gloop::uint_t program, const gloop::char_t * uniformName) {
            return glGetUniformLocation(program, uniformName);
        }
    }
}

#endif