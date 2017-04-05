/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   depth_range.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 9:56 AM
 */

#ifndef DEPTH_RANGE_HPP
#define DEPTH_RANGE_HPP

#include <GL/glew.h>

namespace gloop {
    struct depth_range {
        GLdouble near;
        GLdouble far;
        
        void apply() const;
        
        inline void operator()() const {
            apply();
        }
    };
}

#endif /* DEPTH_RANGE_HPP */

