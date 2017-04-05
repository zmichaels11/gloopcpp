/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <GL/glew.h>

namespace gloop {
    enum class shader_type : GLenum {
        UNKNOWN = 0,
        VERTEX = GL_VERTEX_SHADER,
        FRAGMENT = GL_FRAGMENT_SHADER,
        GEOMETRY = GL_GEOMETRY_SHADER,
        TESSELLATION_EVALUATION = GL_TESS_EVALUATION_SHADER,
        TESSELLATION_CONTROL = GL_TESS_CONTROL_SHADER,
        COMPUTE = GL_COMPUTE_SHADER
    };
}