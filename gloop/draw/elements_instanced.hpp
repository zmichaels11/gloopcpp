/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <GL/glew.h>

#include "call.hpp"
#include "index_type.hpp"
#include "mode.hpp"

namespace gloop {
    namespace draw {
        struct elements_instanced : draw_call {
            mode drawMode;
            GLsizei count;
            index_type indexType;
            const void * indices;
            GLsizei primitiveCount;            
            
            virtual void draw() const;
        };
    }
}
