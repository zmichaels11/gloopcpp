/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

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
         
    };
}

