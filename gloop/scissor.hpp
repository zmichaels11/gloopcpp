/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   scissor.hpp
 * Author: zmichaels
 *
 * Created on April 4, 2017, 10:16 AM
 */

#ifndef SCISSOR_HPP
#define SCISSOR_HPP

#include <GL/glew.h>

namespace gloop {

    class scissor {
    private:
        GLint _x;
        GLint _y;
        GLsizei _width;
        GLsizei _height;
        bool _enable;

    public:

        scissor(const bool enable, const GLint x, const GLint y, const GLsizei width, const GLsizei height) :
        _enable(enable), _x(x), _y(y), _width(width), _height(height) {
        }
        
        inline scissor withEnable(const bool enable) const {
            return scissor(enable, _x, _y, _width, _height);
        }
        
        inline scissor withOffset(const GLint x, const GLint y) const {
            return scissor(_enable, x, y, _width, _height);
        }
        
        inline scissor withSize(const GLsizei width, GLsizei height) const {
            return scissor(_enable, _x, _y, width, height);
        }

        struct point {
            GLint x;
            GLint y;
        };

        struct size {
            GLsizei width;
            GLsizei height;
        };

        inline point getOffset() const {
            return {_x, _y};
        }
        
        inline size getSize() const {
            return {_width, _height};
        }
        
        inline GLint getX() const {
            return _x;
        }
        
        inline GLint getY() const {
            return _y;
        }
        
        inline GLsizei getWidth() const {
            return _width;
        }
        
        inline GLsizei getHeight() const {
            return _height;
        }
        
        inline void apply() const {
            if (this->_enable) {
                glEnable(GL_SCISSOR_TEST);
                glScissor(_x, _y, _width, _height);
            } else {
                glDisable(GL_SCISSOR_TEST);
            }
        }
        
        inline void operator()() const {
            this->apply();
        }
    };
}

#endif /* SCISSOR_HPP */

