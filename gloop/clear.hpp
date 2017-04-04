/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   clear.hpp
 * Author: zmichaels
 *
 * Created on April 4, 2017, 10:54 AM
 */

#ifndef CLEAR_HPP
#define CLEAR_HPP

#include <GL/glew.h>

namespace gloop {

    enum class clear_mask : GLbitfield {
        COLOR = GL_COLOR_BUFFER_BIT,
        DEPTH = GL_DEPTH_BUFFER_BIT,
        STENCIL = GL_STENCIL_BUFFER_BIT
    };

    inline clear_mask operator|(clear_mask lhs, clear_mask rhs) {
        return static_cast<clear_mask> (
                static_cast<GLbitfield> (lhs) | static_cast<GLbitfield> (rhs));
    }

    inline clear_mask operator&(clear_mask lhs, clear_mask rhs) {
        return static_cast<clear_mask> (
                static_cast<GLbitfield> (lhs) & static_cast<GLbitfield> (rhs));
    }

    inline clear_mask operator^ (clear_mask lhs, clear_mask rhs) {
        return static_cast<clear_mask> (
                static_cast<GLbitfield> (lhs) ^ static_cast<GLbitfield> (rhs));
    }

    inline clear_mask operator~(clear_mask lhs) {
        return static_cast<clear_mask> (~static_cast<GLbitfield> (lhs));
    }

    inline clear_mask& operator|=(clear_mask& lhs, clear_mask rhs) {
        lhs = static_cast<clear_mask> (
                static_cast<GLbitfield> (lhs) | static_cast<GLbitfield> (rhs));

        return lhs;
    }

    inline clear_mask& operator&=(clear_mask& lhs, clear_mask rhs) {
        lhs = static_cast<clear_mask> (
                static_cast<GLbitfield> (lhs) & static_cast<GLbitfield> (rhs));

        return lhs;
    }

    inline clear_mask& operator^=(clear_mask& lhs, clear_mask rhs) {
        lhs = static_cast<clear_mask> (
                static_cast<GLbitfield> (lhs) ^ static_cast<GLbitfield> (rhs));

        return lhs;
    }

    class clear {
    private:
        clear_mask _mask;
        GLfloat _red;
        GLfloat _green;
        GLfloat _blue;
        GLfloat _alpha;
        GLdouble _depth;
        GLint _stencil;

    public:

        clear(
                const clear_mask mask = clear_mask::COLOR,
                const GLfloat red = 0.0F, const GLfloat green = 0.0F, const GLfloat blue = 0.0F, const GLfloat alpha = 0.0F,
                const GLdouble depth = 1.0, const GLint stencil = 0) :
        _mask(mask),
        _red(red), _green(green), _blue(blue), _alpha(alpha),
        _depth(depth), _stencil(stencil) {
        }

        inline clear withMask(const clear_mask mask) const {
            return clear(mask, _red, _green, _blue, _alpha, _depth, _stencil);
        }

        inline clear withColor(const GLfloat red, const GLfloat green, const GLfloat blue, const GLfloat alpha) const {
            return clear(_mask, red, green, blue, alpha, _depth, _stencil);
        }

        inline clear withDepth(const GLdouble depth) const {
            return clear(_mask, _red, _green, _blue, _alpha, depth, _stencil);
        }

        inline clear withStencil(const GLint stencil) const {
            return clear(_mask, _red, _green, _blue, _alpha, _depth, stencil);
        }

        struct clear_color {
            GLfloat red;
            GLfloat green;
            GLfloat blue;
            GLfloat alpha;
        };

        inline clear_color getClearColor() const {
            return {_red, _green, _blue, _alpha};
        }

        inline GLdouble getClearDepth() const {
            return _depth;
        }

        inline GLint getClearStencil() const {
            return _stencil;
        }
        
        inline clear_mask getClearMask() const {
            return _mask;
        }

        inline void apply() const {
            if ((_mask & clear_mask::COLOR) == clear_mask::COLOR) {
                glClearColor(_red, _green, _blue, _alpha);
            }

            if ((_mask & clear_mask::DEPTH) == clear_mask::DEPTH) {
                glClearDepth(_depth);
            }

            if ((_mask & clear_mask::STENCIL) == clear_mask::STENCIL) {
                glClearStencil(_stencil);
            }
            
            glClear(static_cast<GLbitfield> (_mask));
        }
        
        inline void operator()() const {
            this->apply();
        }
    };
}

#endif /* CLEAR_HPP */

