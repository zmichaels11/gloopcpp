/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <GL/glew.h>

#include "uniform_block_binding.hpp"

namespace gloop {

    void uniform_block_binding::pushUniformBinding(const GLuint uniformBlockBinding) const {
        if (this->isValid()) {
            glUniformBlockBinding(_pId, this->_blockIndex, uniformBlockBinding);
        }
    }

    bool uniform_block_binding::isValid() const {
        return (_pId != 0);
    }

    uniform_block_binding::operator bool() const {
        return this->isValid();
    }
}