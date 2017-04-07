/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include "../glint.hpp"
#include "depth_range.hpp"

namespace gloop {
    namespace states {

        class viewport {
        public:

            struct offset {
                gloop::int_t x;
                gloop::int_t y;
            };

            struct size {
                gloop::sizei_t width;
                gloop::sizei_t height;
            };

        private:
            offset _offset;
            size _size;
            depth_range _depthRange;

        public:

            viewport() :
            _offset({0, 0}),
            _size({0, 0}),
            _depthRange({0.0, 1.0}) {
            }

            viewport(
                    const offset offset,
                    const size sz,
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