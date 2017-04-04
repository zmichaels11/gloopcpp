/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   texture2D.hpp
 * Author: zmichaels
 *
 * Created on April 4, 2017, 11:31 AM
 */

#ifndef TEXTURE2D_HPP
#define TEXTURE2D_HPP

#include <memory>

#include <GL/glew.h>

namespace gloop {
    class texture2D {
    private:
        std::shared_ptr<GLuint> _id;
        GLuint _width;
        GLuint _height;
        GLuint _mipmaps;
        
    public:
        void 
    };
}

#endif /* TEXTURE2D_HPP */

