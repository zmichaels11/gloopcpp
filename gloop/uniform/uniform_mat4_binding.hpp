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

        struct uniform_mat4_binding : uniform_binding {
            GLuint pId;
            GLuint loc;
            GLsizei count;
            const GLfloat * values;

            virtual void apply() const;
        };
    }
}