/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#pragma once

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