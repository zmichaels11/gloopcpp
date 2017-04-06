/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <GL/glew.h>

namespace gloop {
    namespace uniform {

        class uniform_block_binding {
        private:
            GLuint _pId;
            GLuint _blockIndex;

        public:
            uniform_block_binding(
                    const GLuint pId = 0,
                    const GLuint blockId = 0) :
            _pId(pId), _blockIndex(blockId) {}
            
            void pushUniformBinding(const GLuint uniformBlockBinding) const;

            bool isValid() const;

            operator bool() const;
        };
    }
}