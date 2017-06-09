/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../glint.hpp"
#include "../uniforms.hpp"
#include "../texture2D.hpp"
#include "../wrapper/gl.hpp"
#include "../wrapper/shaders_and_programs.hpp"

namespace gloop {
    namespace uniform {
		void uniform_binding::operator()() const {
			apply();
		}

		void uniform_int_binding::operator()(const gloop::texture2D& img) const {
			gloop::wrapper::programUniform1iv(pId, loc, 1, &value);
			img.bind(value);
		}

        void uniform_float_binding::apply() const {            
            gloop::wrapper::programUniform1fv(pId, loc, 1, &value);
        }

        void uniform_float_array_binding::apply() const {            
            gloop::wrapper::programUniform1fv(pId, loc, count, values);
        }

        void uniform_int_binding::apply() const {            
            gloop::wrapper::programUniform1iv(pId, loc, 1, &value);
        }

        void uniform_int_array_binding::apply() const {            
            gloop::wrapper::programUniform1iv(pId, loc, count, values);
        }

        void uniform_ivec2_binding::apply() const {            
            gloop::wrapper::programUniform2iv(pId, loc, 1, reinterpret_cast<const gloop::int_t *> (&value));
        }

        void uniform_ivec2_array_binding::apply() const {            
            gloop::wrapper::programUniform2iv(pId, loc, count, reinterpret_cast<const gloop::int_t *> (values));
        }

        void uniform_ivec3_binding::apply() const {            
            gloop::wrapper::programUniform3iv(pId, loc, 1, reinterpret_cast<const gloop::int_t *> (&value));
        }

        void uniform_ivec3_array_binding::apply() const {            
            gloop::wrapper::programUniform3iv(pId, loc, count, reinterpret_cast<const gloop::int_t *> (values));
        }

        void uniform_ivec4_binding::apply() const {            
            gloop::wrapper::programUniform4iv(pId, loc, 1, reinterpret_cast<const gloop::int_t *> (&value));
        }

        void uniform_ivec4_array_binding::apply() const {            
            gloop::wrapper::programUniform4iv(pId, loc, count, reinterpret_cast<const gloop::int_t *> (values));
        }

        void uniform_vec2_binding::apply() const {            
            gloop::wrapper::programUniform2fv(pId, loc, 1, reinterpret_cast<const gloop::float_t *> (&value));
        }

        void uniform_vec2_array_binding::apply() const {            
            gloop::wrapper::programUniform2fv(pId, loc, count, reinterpret_cast<const gloop::float_t *> (values));
        }

        void uniform_vec3_binding::apply() const {            
            gloop::wrapper::programUniform3fv(pId, loc, 1, reinterpret_cast<const gloop::float_t *> (&value));
        }

        void uniform_vec3_array_binding::apply() const {            
            gloop::wrapper::programUniform3fv(pId, loc, count, reinterpret_cast<const gloop::float_t *> (values));
        }

        void uniform_vec4_binding::apply() const {            
            gloop::wrapper::programUniform4fv(pId, loc, 1, reinterpret_cast<const gloop::float_t *> (&value));
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
