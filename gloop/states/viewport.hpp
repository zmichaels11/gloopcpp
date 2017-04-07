/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <GL/glew.h>

#include "depth_range.hpp"

namespace gloop {
    namespace states {

        class viewport {
        public:

            struct offset {
                GLint x;
                GLint y;
            };

            struct size {
                GLsizei width;
                GLsizei height;
            };

        private:
            offset _offset;
            size _size;
            depth_range _depthRange;

        public:

            viewport(
                    const offset offset = {0, 0},
            const size sz = {0, 0},
            const depth_range depthRange = {0.0, 1.0}) :

            _offset(offset), _size(sz), _depthRange(depthRange) {
            }

            viewport withOffset(const offset offset) const;

            viewport withSize(const size sz) const;

            viewport withDepthRange(const depth_range depthRange) const;

            const offset& getOffset() const;

            const size& getSize() const;

            const depth_range& getDepthRange() const;

            void apply() const;

            inline void operator()() const {
                apply();
            }
        };
    }
}