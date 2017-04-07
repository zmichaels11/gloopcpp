/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include "../glint.hpp"

namespace gloop {
    namespace uniform {

        class uniform_block_binding {
        private:
            gloop::uint_t _pId;
            gloop::uint_t _blockIndex;

        public:
            uniform_block_binding(
                    const gloop::uint_t pId = 0,
                    const gloop::uint_t blockId = 0) :
            _pId(pId), _blockIndex(blockId) {}
            
            void pushUniformBinding(const gloop::uint_t uniformBlockBinding) const;

            bool isValid() const;

            operator bool() const;
        };
    }
}