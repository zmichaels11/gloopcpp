/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#pragma once

#include <GL/glew.h>

#include "uniform_binding.hpp"

namespace gloop {
    namespace uniform {

        struct uniform_ivec2_binding : uniform_binding {
            GLuint pId;
            GLuint loc;
            
            struct ivec2 {
                GLint x;
                GLint y;
            } value;        

            virtual void apply() const;
        };
    }
}