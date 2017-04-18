/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   renderbuffer.hpp
 * Author: zmichaels
 *
 * Created on April 18, 2017, 3:02 PM
 */

#pragma once

#include "enums/renderbuffer_internal_format.hpp"
#include "glint.hpp"

namespace gloop {

    class renderbuffer {
    private:
        gloop::uint_t _id;
        gloop::sizei_t _width;
        gloop::sizei_t _height;
        enums::renderbuffer_internal_format _format;

    public:

        renderbuffer(
                const enums::renderbuffer_internal_format fmt,
                const gloop::sizei_t width, const gloop::sizei_t height) :
        _id(0),
        _width(width),
        _height(height),
        _format(fmt) {
        }
        
        renderbuffer(const renderbuffer&) = delete;
        
        ~renderbuffer();

        bool isValid() const;
        
        gloop::uint_t getId();

        gloop::sizei_t getWidth() const;

        gloop::sizei_t getHeight() const;
        
        enums::renderbuffer_internal_format getInternalFormat() const;        
        
        void free();
    };
}