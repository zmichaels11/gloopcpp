/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../glint.hpp"
#include "../uniforms.hpp"
#include "../wrapper/gl.hpp"
#include "../wrapper/shaders_and_programs.hpp"

namespace gloop {
    namespace uniform {

        void uniform_float_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniform1f(loc, value);
        }

        void uniform_float_array_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniform1fv(loc, count, values);
        }

        void uniform_int_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniform1i(loc, value);
        }

        void uniform_int_array_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniform1iv(loc, count, values);
        }

        void uniform_ivec2_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniform2i(loc, value.x, value.y);
        }

        void uniform_ivec2_array_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniform2iv(loc, count, reinterpret_cast<const gloop::int_t *> (values));
        }

        void uniform_ivec3_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniform3i(loc, value.x, value.y, value.z);
        }

        void uniform_ivec3_array_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniform3iv(loc, count, reinterpret_cast<const gloop::int_t *> (values));
        }

        void uniform_ivec4_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniform4i(loc, value.x, value.y, value.z, value.w);
        }

        void uniform_ivec4_array_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniform4iv(loc, count, reinterpret_cast<const gloop::int_t *> (values));
        }

        void uniform_vec2_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniform2f(loc, value.x, value.y);
        }

        void uniform_vec2_array_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniform2fv(loc, count, reinterpret_cast<const gloop::float_t *> (values));
        }

        void uniform_vec3_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniform3f(loc, value.x, value.y, value.z);
        }

        void uniform_vec3_array_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniform3fv(loc, count, reinterpret_cast<const gloop::float_t *> (values));
        }

        void uniform_vec4_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniform4f(loc, value.x, value.y, value.z, value.w);
        }

        void uniform_vec4_array_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniform4fv(loc, count, reinterpret_cast<const gloop::float_t *> (values));
        }

        void uniform_mat2_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniformMatrix2fv(loc, count, gloop::wrapper::FALSE, reinterpret_cast<const gloop::float_t *> (values));
        }

        void uniform_mat3_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniformMatrix3fv(loc, count, gloop::wrapper::FALSE, reinterpret_cast<const gloop::float_t *> (values));
        }

        void uniform_mat4_binding::apply() const {
            gloop::wrapper::useProgram(pId);
            gloop::wrapper::uniformMatrix4fv(loc, count, gloop::wrapper::FALSE, reinterpret_cast<const gloop::float_t *> (values));
        }
    }
}