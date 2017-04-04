/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   viewport.hpp
 * Author: zmichaels
 *
 * Created on April 4, 2017, 9:42 AM
 */

#ifndef VIEWPORT_HPP
#define VIEWPORT_HPP

#include <GL/glew.h>

namespace gloop {

    class viewport {
    private:
        GLint _x;
        GLint _y;
        GLsizei _width;
        GLsizei _height;
        GLfloat _nearVal;
        GLfloat _farVal;
    public:

        struct point {
            GLint x;
            GLint y;
        };

        struct size {
            GLsizei width;
            GLsizei height;
        };

        struct range {
            GLfloat near;
            GLfloat far;
        };

        viewport(
                const GLint x, const GLint y,
                const GLsizei width, const GLsizei height,
                const GLfloat nearVal = 0.0F, const GLfloat farVal = 0.0F) :
        _x(x), _y(y),
        _width(width), _height(height),
        _nearVal(nearVal), _farVal(farVal) {
        }
        
        inline viewport withOffset(const GLint x, const GLint y) const {
            return viewport(x, y, _width, _height, _nearVal, _farVal);
        }
        
        inline viewport withSize(const GLsizei width, const GLsizei height) const {
            return viewport(_x, _y, width, height, _nearVal, _farVal);
        }
        
        inline viewport withDepthRange(const GLfloat nearVal, const GLfloat farVal) const {
            return viewport(_x, _y, _width, _height, nearVal, farVal);
        }

        inline point getOffset() const {
            return {_x, _y};
        }

        inline size getSize() const {
            return {_width, _height};
        }

        inline range getDepthRange() const {
            return {_nearVal, _farVal};
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

        inline GLfloat getNearClip() const {
            return _nearVal;
        }

        inline GLfloat getFarClip() const {
            return _farVal;
        }

        inline void apply() const {
            glViewport(_x, _y, _width, _height);
            
            if (_nearVal != 0.0F || _farVal != 0.0F) {
                glDepthRange(_nearVal, _farVal);
            }
        }

        inline void operator()() const {
            apply();
        }
    };
}

#endif /* VIEWPORT_HPP */

