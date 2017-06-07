/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <type_traits>

#include "../exception/invalid_operation_exception.hpp"
#include "../glint.hpp"
#include "../gloop_throw.hpp"
#include "../wrapper/shaders_and_programs.hpp"
#include "uniform_block_binding.hpp"

namespace gloop {
    namespace uniform {
        namespace {
#define GLEW 1
#define GLES2 2
#define GLES3 3
#ifndef GL
#define __GL_NOT_DEFINED
#define GL 0
#endif        
            
            static constexpr bool supports_uniform_block_bind = (GL == GLEW || GL == GLES3);
            
            template <bool isSupported = supports_uniform_block_bind, typename std::enable_if<isSupported, void * >::type = nullptr>
            void __uniformBlockBinding(gloop::uint_t pid, gloop::uint_t index, gloop::uint_t binding) {
                wrapper::uniformBlockBinding(pid, index, binding);
            }
            
            template <bool isSupported = supports_uniform_block_bind, typename std::enable_if<!isSupported, void * >::type = nullptr>
            void __uniformBlockBinding(gloop::uint_t, gloop::uint_t, gloop::uint_t) {
                gloop_throw(gloop::exception::invalid_operation_exception("UniformBlockBinding is not supported!"));
            }

#ifdef __GL_NOT_DEFINED
#undef GL
#undef __GL_NOT_DEFINED
#endif

#undef GLES3
#undef GLES2
#undef GLEW
        }

        void uniform_block_binding::pushUniformBinding(const gloop::uint_t uniformBlockBinding) const {
            if (this->isValid()) {
                __uniformBlockBinding(_pId, _blockIndex, uniformBlockBinding);
            }
        }

        bool uniform_block_binding::isValid() const {
            return (_pId != 0);
        }

        uniform_block_binding::operator bool() const {
            return this->isValid();
        }
    }
}