/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <GL/glew.h>

#include "call.hpp"
#include "mode.hpp"

namespace gloop {
    namespace draw {

        struct arrays_instanced : draw_call {
            mode drawMode;
            GLint first;
            GLsizei count;
            GLsizei primitiveCount;

            virtual void draw() const;
        };
    }
}