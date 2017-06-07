/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#define GLES2 2
#if GL == GLES2
#include "shaders_and_programs.hpp"

#include <SDL2/SDL_opengles2.h>

#include "../glint.hpp"
#include "../tools.hpp"

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
            gloop::tools::__debugAssertGLError("Unable to specify shader code!");
        }

        void compileShader(gloop::uint_t shader) {
            glCompileShader(shader);
            gloop::tools::__debugAssertGLError("Unable to compile shader!");
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
            gloop::tools::__debugAssertGLError("Unable to attach shader!");
        }

        void linkProgram(gloop::uint_t program) {
            glLinkProgram(program);
            gloop::tools::__debugAssertGLError("Unable to link program!");
        }

        void detachShader(gloop::uint_t program, gloop::uint_t shader) {
            glDetachShader(program, shader);
            gloop::tools::__debugAssertGLError("Unable to detach shader!");
        }

        void deleteProgram(gloop::uint_t program) {
            glDeleteProgram(program);
        }

        gloop::int_t getUniformLocation(gloop::uint_t program, const gloop::char_t * uniformName) {
            return glGetUniformLocation(program, uniformName);
        }        

        void bindAttribLocation(
                gloop::uint_t program,
                gloop::uint_t index,
                const gloop::char_t * name) {

            glBindAttribLocation(program, index, name);
        }        

        void programUniform1fv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::float_t * values) {

            glUseProgram(pid);
            glUniform1fv(loc, count, values);

        }

        void programUniform2fv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::float_t * values) {

            glUseProgram(pid);
            glUniform2fv(loc, count, values);

        }

        void programUniform3fv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::float_t * values) {

            glUseProgram(pid);
            glUniform3fv(loc, count, values);

        }

        void programUniform4fv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::float_t * values) {

            glUseProgram(pid);
            glUniform4fv(loc, count, values);

        }

        void programUniform1iv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::int_t * values) {

            glUseProgram(pid);
            glUniform1iv(loc, count, values);

        }

        void programUniform2iv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::int_t * values) {

            glUseProgram(pid);
            glUniform2iv(loc, count, values);

        }

        void programUniform3iv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::int_t * values) {

            glUseProgram(pid);
            glUniform3iv(loc, count, values);

        }

        void programUniform4iv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::int_t * values) {

            glUseProgram(pid);
            glUniform4iv(loc, count, values);

        }

        void programUniformMatrix2fv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                gloop::boolean_t transpose,
                const gloop::float_t * values) {

            glUseProgram(pid);
            glUniformMatrix2fv(loc, count, transpose, values);

        }

        void programUniformMatrix3fv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                gloop::boolean_t transpose,
                const gloop::float_t * values) {

            glUseProgram(pid);
            glUniformMatrix3fv(loc, count, transpose, values);

        }

        void programUniformMatrix4fv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                gloop::boolean_t transpose,
                const gloop::float_t * values) {

            glUseProgram(pid);
            glUniformMatrix4fv(loc, count, transpose, values);

        }
    }
}
#endif
#undef GLES2