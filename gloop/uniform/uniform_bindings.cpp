/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../uniforms.hpp"

namespace gloop {

    void uniform_float_binding::apply() const {
        glUseProgram(pId);
        glUniform1f(loc, value);
    }

    void uniform_float_array_binding::apply() const {
        glUseProgram(pId);
        glUniform1fv(loc, count, values);
    }

    void uniform_int_binding::apply() const {
        glUseProgram(pId);
        glUniform1i(loc, value);
    }

    void uniform_int_array_binding::apply() const {
        glUseProgram(pId);
        glUniform1iv(loc, count, values);
    }

    void uniform_ivec2_binding::apply() const {
        glUseProgram(pId);
        glUniform2i(loc, x, y);
    }

    void uniform_ivec2_array_binding::apply() const {
        glUseProgram(pId);
        glUniform2iv(loc, count, values);
    }

    void uniform_ivec3_binding::apply() const {
        glUseProgram(pId);
        glUniform3i(loc, x, y, z);
    }

    void uniform_ivec3_array_binding::apply() const {
        glUseProgram(pId);
        glUniform3iv(loc, count, values);
    }

    void uniform_ivec4_binding::apply() const {
        glUseProgram(pId);
        glUniform4i(loc, x, y, z, w);
    }

    void uniform_ivec4_array_binding::apply() const {
        glUseProgram(pId);
        glUniform4iv(loc, count, values);
    }

    void uniform_vec2_binding::apply() const {
        glUseProgram(pId);
        glUniform2f(loc, x, y);
    }

    void uniform_vec2_array_binding::apply() const {
        glUseProgram(pId);
        glUniform2fv(loc, count, values);
    }

    void gloop::uniform_vec3_binding::apply() const {
        glUseProgram(pId);
        glUniform3f(loc, x, y, z);
    }

    void uniform_vec3_array_binding::apply() const {
        glUseProgram(pId);
        glUniform3fv(loc, count, values);
    }

    void gloop::uniform_vec4_binding::apply() const {
        glUseProgram(pId);
        glUniform4f(loc, x, y, z, w);
    }

    void uniform_vec4_array_binding::apply() const {
        glUseProgram(pId);
        glUniform4fv(loc, count, values);
    }

    void uniform_mat2_binding::apply() const {
        glUseProgram(pId);
        glUniformMatrix2fv(loc, count, GL_FALSE, values);
    }

    void uniform_mat3_binding::apply() const {
        glUseProgram(pId);
        glUniformMatrix3fv(loc, count, GL_FALSE, values);
    }

    void uniform_mat4_binding::apply() const {
        glUseProgram(pId);
        glUniformMatrix4fv(loc, count, GL_FALSE, values);
    }
}