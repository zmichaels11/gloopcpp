/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buffer_access_hint.hpp
 * Author: zmichaels
 *
 * Created on April 7, 2017, 10:01 AM
 */

#pragma once

#include <GL/glew.h>

#include "../glint.hpp"

namespace gloop {
    namespace bitfields {

        enum class buffer_access_hint : gloop::bitfield_t {
            READ = GL_MAP_READ_BIT,
            WRITE = GL_MAP_WRITE_BIT,
            PERSISTENT = GL_MAP_PERSISTENT_BIT,
            COHERENT = GL_MAP_COHERENT_BIT,
            INVALIDATE_BUFFER = GL_MAP_INVALIDATE_BUFFER_BIT,
            INVALIDATE_RANGE = GL_MAP_INVALIDATE_RANGE_BIT,
            FLUSH_EXPLICIT = GL_MAP_FLUSH_EXPLICIT_BIT,
            UNSYNCHRONIZED = GL_MAP_UNSYNCHRONIZED_BIT
        };

        buffer_access_hint operator|(buffer_access_hint, buffer_access_hint);
        buffer_access_hint operator&(buffer_access_hint lhs, buffer_access_hint rhs);
        buffer_access_hint operator^ (buffer_access_hint lhs, buffer_access_hint rhs);
        buffer_access_hint operator~(buffer_access_hint lhs);
        buffer_access_hint& operator|=(buffer_access_hint& lhs, buffer_access_hint rhs);
        buffer_access_hint& operator&=(buffer_access_hint& lhs, buffer_access_hint rhs);
        buffer_access_hint& operator^=(buffer_access_hint& lhs, buffer_access_hint rhs);
    }
}
