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
            gloop::wrapper::programUniform1f(pId, loc, value);
        }

        void uniform_float_array_binding::apply() const {            
            gloop::wrapper::programUniform1fv(pId, loc, count, values);
        }

        void uniform_int_binding::apply() const {            
            gloop::wrapper::programUniform1i(pId, loc, value);
        }

        void uniform_int_array_binding::apply() const {            
            gloop::wrapper::programUniform1iv(pId, loc, count, values);
        }

        void uniform_ivec2_binding::apply() const {            
            gloop::wrapper::programUniform2i(pId, loc, value.x, value.y);
        }

        void uniform_ivec2_array_binding::apply() const {            
            gloop::wrapper::programUniform2iv(pId, loc, count, reinterpret_cast<const gloop::int_t *> (values));
        }

        void uniform_ivec3_binding::apply() const {            
            gloop::wrapper::programUniform3i(pId, loc, value.x, value.y, value.z);
        }

        void uniform_ivec3_array_binding::apply() const {            
            gloop::wrapper::programUniform3iv(pId, loc, count, reinterpret_cast<const gloop::int_t *> (values));
        }

        void uniform_ivec4_binding::apply() const {            
            gloop::wrapper::programUniform4i(pId, loc, value.x, value.y, value.z, value.w);
        }

        void uniform_ivec4_array_binding::apply() const {            
            gloop::wrapper::programUniform4iv(pId, loc, count, reinterpret_cast<const gloop::int_t *> (values));
        }

        void uniform_vec2_binding::apply() const {            
            gloop::wrapper::programUniform2f(pId, loc, value.x, value.y);
        }

        void uniform_vec2_array_binding::apply() const {            
            gloop::wrapper::programUniform2fv(pId, loc, count, reinterpret_cast<const gloop::float_t *> (values));
        }

        void uniform_vec3_binding::apply() const {            
            gloop::wrapper::programUniform3f(pId, loc, value.x, value.y, value.z);
        }

        void uniform_vec3_array_binding::apply() const {            
            gloop::wrapper::programUniform3fv(pId, loc, count, reinterpret_cast<const gloop::float_t *> (values));
        }

        void uniform_vec4_binding::apply() const {            
            gloop::wrapper::programUniform4f(pId, loc, value.x, value.y, value.z, value.w);
        }

        void uniform_vec4_array_binding::apply() const {            
            gloop::wrapper::programUniform4fv(pId, loc, count, reinterpret_cast<const gloop::float_t *> (values));
        }

        void uniform_mat2_binding::apply() const {            
            gloop::wrapper::programUniformMatrix2fv(pId, loc, count, gloop::wrapper::FALSE, reinterpret_cast<const gloop::float_t *> (values));
        }

        void uniform_mat3_binding::apply() const {            
            gloop::wrapper::programUniformMatrix3fv(pId, loc, count, gloop::wrapper::FALSE, reinterpret_cast<const gloop::float_t *> (values));
        }

        void uniform_mat4_binding::apply() const {            
            gloop::wrapper::programUniformMatrix4fv(pId, loc, count, gloop::wrapper::FALSE, reinterpret_cast<const gloop::float_t *> (values));
        }
    }
}