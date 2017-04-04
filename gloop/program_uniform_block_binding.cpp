/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "program.hpp"

#include <memory>

#include <GL/glew.h>

#include "exception.hpp"

void gloop::uniform_block_binding::pushUniformBinding(const GLuint uniformBlockBinding) const {
    if (this->isValid()) {
        glUniformBlockBinding(*_pId, this->_blockIndex, uniformBlockBinding);        
    }
}

bool gloop::uniform_block_binding::isValid() const {
    return (this->_pId.get() != nullptr);
}

gloop::uniform_block_binding::operator bool() const {
    return this->isValid();
}