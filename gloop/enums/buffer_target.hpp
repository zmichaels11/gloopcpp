/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buffer_target.hpp
 * Author: zmichaels
 *
 * Created on April 7, 2017, 10:00 AM
 */

#pragma once

#include <GL/glew.h>

#include "../glint.hpp"

namespace gloop {
    namespace enums {

        enum class buffer_target : gloop::enum_t {
            ARRAY = GL_ARRAY_BUFFER,
            ELEMENT_ARRAY = GL_ELEMENT_ARRAY_BUFFER,
            ATOMIC_COUNTER = GL_ATOMIC_COUNTER_BUFFER,
            COPY_READ = GL_COPY_READ_BUFFER,
            COPY_WRITE = GL_COPY_WRITE_BUFFER,
            DISPATCH_INDIRECT = GL_DISPATCH_INDIRECT_BUFFER,
            DRAW_INDIRECT = GL_DRAW_INDIRECT_BUFFER,
            PIXEL_PACK = GL_PIXEL_PACK_BUFFER,
            PIXEL_UNPACK = GL_PIXEL_UNPACK_BUFFER,
            QUERY = GL_QUERY_BUFFER,
            SHADER_STORAGE = GL_SHADER_STORAGE_BUFFER,
            TEXTURE = GL_TEXTURE_BUFFER,
            TRANSFORM_FEEDBACK = GL_TRANSFORM_FEEDBACK_BUFFER,
            UNIFORM = GL_UNIFORM_BUFFER
        };
    }
}