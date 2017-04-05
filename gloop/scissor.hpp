/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <GL/glew.h>

namespace gloop {

    class scissor {
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
    };
}