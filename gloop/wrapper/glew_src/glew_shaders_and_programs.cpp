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

        void programUniform1fv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::float_t * values) {

            if (GLEW_ARB_separate_shader_objects) {
                glProgramUniform1fv(pid, loc, count, values);
            } else {
                glUseProgram(pid);
                glUniform1fv(loc, count, values);
            }
        }

        void programUniform2fv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::float_t * values) {

            if (GLEW_ARB_separate_shader_objects) {
                glProgramUniform2fv(pid, loc, count, values);
            } else {
                glUseProgram(pid);
                glUniform2fv(loc, count, values);
            }
        }

        void programUniform3fv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::float_t * values) {

            if (GLEW_ARB_separate_shader_objects) {
                glProgramUniform3fv(pid, loc, count, values);
            } else {
                glUseProgram(pid);
                glUniform3fv(loc, count, values);
            }
        }

        void programUniform4fv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::float_t * values) {

            if (GLEW_ARB_separate_shader_objects) {
                glProgramUniform4fv(pid, loc, count, values);
            } else {
                glUseProgram(pid);
                glUniform4fv(loc, count, values);
            }
        }

        void programUniform1iv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::int_t * values) {

            if (GLEW_ARB_separate_shader_objects) {
                glProgramUniform1iv(pid, loc, count, values);
            } else {
                glUseProgram(pid);
                glUniform1iv(loc, count, values);
            }
        }

        void programUniform2iv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::int_t * values) {

            if (GLEW_ARB_separate_shader_objects) {
                glProgramUniform2iv(pid, loc, count, values);
            } else {
                glUseProgram(pid);
                glUniform2iv(loc, count, values);
            }
        }

        void programUniform3iv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::int_t * values) {

            if (GLEW_ARB_separate_shader_objects) {
                glProgramUniform3iv(pid, loc, count, values);
            } else {
                glUseProgram(pid);
                glUniform3iv(loc, count, values);
            }
        }

        void programUniform4iv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                const gloop::int_t * values) {

            if (GLEW_ARB_separate_shader_objects) {
                glProgramUniform4iv(pid, loc, count, values);
            } else {
                glUseProgram(pid);
                glUniform4iv(loc, count, values);
            }
        }

        void programUniformMatrix2fv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                gloop::boolean_t transpose,
                const gloop::float_t * values) {

            if (GLEW_ARB_separate_shader_objects) {
                glProgramUniformMatrix2fv(pid, loc, count, transpose, values);
            } else {
                glUseProgram(pid);
                glUniformMatrix2fv(loc, count, transpose, values);
            }
        }

        void programUniformMatrix3fv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                gloop::boolean_t transpose,
                const gloop::float_t * values) {

            if (GLEW_ARB_separate_shader_objects) {
                glProgramUniformMatrix3fv(pid, loc, count, transpose, values);
            } else {
                glUseProgram(pid);
                glUniformMatrix3fv(loc, count, transpose, values);
            }
        }

        void programUniformMatrix4fv(
                gloop::uint_t pid,
                gloop::uint_t loc,
                gloop::sizei_t count,
                gloop::boolean_t transpose,
                const gloop::float_t * values) {

            if (GLEW_ARB_separate_shader_objects) {
                glProgramUniformMatrix4fv(pid, loc, count, transpose, values);
            } else {
                glUseProgram(pid);
                glUniformMatrix4fv(loc, count, transpose, values);
            }
        }
    }
}
#endif
#undef GLEW