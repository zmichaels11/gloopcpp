/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <GL/glew.h>

namespace gloop {
    namespace draw {

        enum class mode : GLenum {
            POINTS = GL_POINTS,
            LINE_STRIP = GL_LINE_STRIP,
            LINE_LOOP = GL_LINE_LOOP,
            LINES = GL_LINES,
            LINE_STRIP_ADJACENCY = GL_LINE_STRIP_ADJACENCY,
            LINES_ADJACENCY = GL_LINES_ADJACENCY,
            TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
            TRIANGLE_FAN = GL_TRIANGLE_FAN,
            TRIANGLES = GL_TRIANGLES,
            TRIANGLE_STRIP_ADJACENCY = GL_TRIANGLE_STRIP_ADJACENCY,
            TRIANGLES_ADJACENCY = GL_TRIANGLES_ADJACENCY,
            PATCHES = GL_PATCHES
        };
    }
}