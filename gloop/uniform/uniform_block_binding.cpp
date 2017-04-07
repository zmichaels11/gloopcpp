/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../glint.hpp"
#include "../wrapper/shaders_and_programs.hpp"
#include "uniform_block_binding.hpp"

namespace gloop {
    namespace uniform {

        void uniform_block_binding::pushUniformBinding(const gloop::uint_t uniformBlockBinding) const {
            if (this->isValid()) {
                gloop::wrapper::uniformBlockBinding(_pId, _blockIndex, uniformBlockBinding);
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