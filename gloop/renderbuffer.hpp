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

#include <iostream>

#include "glint.hpp"

namespace gloop {

    namespace enums {
        enum class renderbuffer_internal_format : gloop::enum_t;
    }
    
    class renderbuffer {
    public:

        struct size {
            gloop::sizei_t width;
            gloop::sizei_t height;

            friend std::ostream& operator<<(std::ostream& os, const size& s) ;
        };
    private:
        gloop::uint_t _id;
        size _size;
        enums::renderbuffer_internal_format _format;

    public:

        renderbuffer(
                const enums::renderbuffer_internal_format fmt,
                const gloop::sizei_t width, const gloop::sizei_t height) :
        _id(0),
        _size({width, height}),
        _format(fmt) {
        }

        ~renderbuffer();

        renderbuffer(const renderbuffer&) = delete;

        renderbuffer(renderbuffer&&) = default;

        renderbuffer& operator=(const renderbuffer&) = delete;

        renderbuffer& operator=(renderbuffer&&) = default;

        friend std::ostream& operator<<(std::ostream& os, const renderbuffer& rb);

        bool isValid() const;

        gloop::uint_t getId();

        const size& getSize() const;

        enums::renderbuffer_internal_format getInternalFormat() const;

        void free();
    };
}