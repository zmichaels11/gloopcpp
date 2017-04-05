/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   uniform_block_binding.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 11:15 AM
 */

#ifndef UNIFORM_BLOCK_BINDING_HPP
#define UNIFORM_BLOCK_BINDING_HPP

#include <GL/glew.h>

namespace gloop {

    class uniform_block_binding {
    private:
        GLuint _pId;
        GLuint _blockIndex;

    public:

        uniform_block_binding(const GLuint pId = 0, const GLuint blockIndex = 0) :
        _pId(pId), _blockIndex(blockIndex) {
        }

        void pushUniformBinding(const GLuint uniformBlockBinding) const;

        bool isValid() const;

        operator bool() const;
    };
}

#endif /* UNIFORM_BLOCK_BINDING_HPP */

