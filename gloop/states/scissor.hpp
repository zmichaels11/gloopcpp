/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <iostream>
#include <stack>

#include "../glint.hpp"

namespace gloop {
    namespace states {

        class scissor {
        private:
            static std::stack<scissor> SCISSOR_STACK;
            static scissor CURRENT_SCISSOR;
            
        public:
            static void push();
            static scissor pop();
            static const scissor& getCurrentScissor();
            
        public:

            struct offset {
                gloop::int_t x;
                gloop::int_t y;
                
                friend std::ostream& operator<<(std::ostream& os, const offset& o);
            };

            struct size {
                gloop::sizei_t width;
                gloop::sizei_t height;
                
                friend std::ostream& operator<<(std::ostream& os, const size& s);
            };
        private:

            bool _enable;
            offset _offset;
            size _size;

        public:

            scissor(
                    const bool enable,
                    const offset offset,
                    const size size) :
            _enable(enable),
            _offset(offset),
            _size(size) {
            }

            scissor withEnable(const bool enable) const;

            scissor withOffset(const offset offset) const;

            scissor withSize(const size size) const;

            const offset& getOffset() const;

            const size& getSize() const;

            bool isEnabled() const;

            void apply() const;

            inline void operator()() const {
                this->apply();
            }
            
            friend std::ostream& operator<<(std::ostream& os, const scissor& s);
        };
    }
}