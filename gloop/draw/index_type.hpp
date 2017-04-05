/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <GL/glew.h>

namespace gloop {
    namespace draw {
        enum class index_type : GLenum {
            UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
            UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
            UNSIGNED_INT = GL_UNSIGNED_INT
        };
    }
}