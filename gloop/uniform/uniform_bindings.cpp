/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../uniforms.hpp"
#include <GL/glew.h>

namespace gloop {
    namespace uniform {

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
            glUniform2i(loc, value.x, value.y);
        }

        void uniform_ivec2_array_binding::apply() const {
            glUseProgram(pId);
            glUniform2iv(loc, count, reinterpret_cast<const GLint *> (values));
        }

        void uniform_ivec3_binding::apply() const {
            glUseProgram(pId);
            glUniform3i(loc, value.x, value.y, value.z);
        }

        void uniform_ivec3_array_binding::apply() const {
            glUseProgram(pId);
            glUniform3iv(loc, count, reinterpret_cast<const GLint *> (values));
        }

        void uniform_ivec4_binding::apply() const {
            glUseProgram(pId);
            glUniform4i(loc, value.x, value.y, value.z, value.w);
        }

        void uniform_ivec4_array_binding::apply() const {
            glUseProgram(pId);
            glUniform4iv(loc, count, reinterpret_cast<const GLint *> (values));
        }

        void uniform_vec2_binding::apply() const {
            glUseProgram(pId);
            glUniform2f(loc, value.x, value.y);
        }

        void uniform_vec2_array_binding::apply() const {
            glUseProgram(pId);
            glUniform2fv(loc, count, reinterpret_cast<const GLfloat *> (values));
        }

        void uniform_vec3_binding::apply() const {
            glUseProgram(pId);
            glUniform3f(loc, value.x, value.y, value.z);
        }

        void uniform_vec3_array_binding::apply() const {
            glUseProgram(pId);
            glUniform3fv(loc, count, reinterpret_cast<const GLfloat *> (values));
        }

        void uniform_vec4_binding::apply() const {
            glUseProgram(pId);
            glUniform4f(loc, value.x, value.y, value.z, value.w);
        }

        void uniform_vec4_array_binding::apply() const {
            glUseProgram(pId);
            glUniform4fv(loc, count, reinterpret_cast<const GLfloat *> (values));
        }

        void uniform_mat2_binding::apply() const {
            glUseProgram(pId);
            glUniformMatrix2fv(loc, count, 0, reinterpret_cast<const GLfloat *> (values));
        }

        void uniform_mat3_binding::apply() const {
            glUseProgram(pId);
            glUniformMatrix3fv(loc, count, 0, reinterpret_cast<const GLfloat *> (values));
        }

        void uniform_mat4_binding::apply() const {
            glUseProgram(pId);
            glUniformMatrix4fv(loc, count, 0, reinterpret_cast<const GLfloat *> (values));
        }
    }
}