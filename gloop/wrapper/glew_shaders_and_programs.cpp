/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#define GLEW 1
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

        void uniformBlockBinding(
                gloop::uint_t program,
                gloop::uint_t uniformBlockIndex,
                gloop::uint_t uniformBlockBinding) {

            glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
        }

        void bindAttribLocation(
                gloop::uint_t program,
                gloop::uint_t index,
                const gloop::char_t * name) {

            glBindAttribLocation(program, index, name);
        }
        
        void uniform1f(
                gloop::uint_t loc,
                gloop::float_t value) {
            
            glUniform1f(loc, value);
        }

        void uniform2f(
                gloop::uint_t loc,
                gloop::float_t x,
                gloop::float_t y) {
            
            glUniform2f(loc, x, y);
        }

        void uniform3f(
                gloop::uint_t loc,
                gloop::float_t x,
                gloop::float_t y,
                gloop::float_t z) {
            
            glUniform3f(loc, x, y, z);
        }

        void uniform4f(
                gloop::uint_t loc,
                gloop::float_t x,
                gloop::float_t y,
                gloop::float_t z,
                gloop::float_t w) {
            
            glUniform4f(loc, x, y, z, w);
        }

        void uniform1i(
                gloop::uint_t loc,
                gloop::int_t value) {
            
            glUniform1i(loc, value);
        }

        void uniform2i(
                gloop::uint_t loc,
                gloop::int_t x,
                gloop::int_t y) {
            
            glUniform2i(loc, x, y);
        }

        void uniform3i(
                gloop::uint_t loc,
                gloop::int_t x,
                gloop::int_t y,
                gloop::int_t z) {
            
            glUniform3i(loc, x, y, z);
        }

        void uniform4i(
                gloop::uint_t loc,
                gloop::int_t x,
                gloop::int_t y,
                gloop::int_t z,
                gloop::int_t w) {
            
            glUniform4i(loc, x, y, z, w);
        }

        void uniform1fv(
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::float_t * values) {
            
            glUniform1fv(loc, count, values);
        }

        void uniform2fv(
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::float_t * values) {
            
            glUniform2fv(loc, count, values);
        }

        void uniform3fv(
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::float_t * values) {
            
            glUniform3fv(loc, count, values);
        }

        void uniform4fv(
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::float_t * values) {
            
            glUniform4fv(loc, count, values);
        }

        void uniform1iv(
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::int_t * values) {
            
            glUniform1iv(loc, count, values);
        }

        void uniform2iv(
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::int_t * values) {
            
            glUniform2iv(loc, count, values);
        }

        void uniform3iv(
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::int_t * values) {
            
            glUniform3iv(loc, count, values);
        }

        void uniform4iv(
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::int_t * values) {
            
            glUniform4iv(loc, count, values);
        }

        void uniformMatrix2fv(
                gloop::uint_t loc,
                gloop::sizei_t count,
                gloop::boolean_t transpose,
                const gloop::float_t * values) {
            
            glUniformMatrix2fv(loc, count, transpose, values);
        }
        
        void uniformMatrix3fv(
                gloop::uint_t loc,
                gloop::sizei_t count,
                gloop::boolean_t transpose,
                const gloop::float_t * values) {
            
            glUniformMatrix3fv(loc, count, transpose, values);
        }
        
        void uniformMatrix4fv(
                gloop::uint_t loc,
                gloop::sizei_t count,
                gloop::boolean_t transpose,
                const gloop::float_t * values) {
            
            glUniformMatrix4fv(loc, count, transpose, values);
        }
    }
}
#endif
#undef GLEW