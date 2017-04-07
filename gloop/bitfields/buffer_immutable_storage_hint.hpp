/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buffer_immutable_storage_hint.hpp
 * Author: zmichaels
 *
 * Created on April 7, 2017, 10:11 AM
 */

#pragma once

#include <GL/glew.h>

#include "../glint.hpp"

namespace gloop {
    namespace bitfields {

        enum class buffer_immutable_storage_hint : gloop::bitfield_t {
            READ = GL_MAP_READ_BIT,
            WRITE = GL_MAP_WRITE_BIT,
            DYNAMIC_STORAGE = GL_DYNAMIC_STORAGE_BIT,
            CLIENT_STORAGE = GL_CLIENT_STORAGE_BIT,
            MAP_COHERENT = GL_MAP_COHERENT_BIT,
            MAP_PERSISTENT = GL_MAP_PERSISTENT_BIT
        };

        buffer_immutable_storage_hint operator~(buffer_immutable_storage_hint lhs);
        buffer_immutable_storage_hint operator&(buffer_immutable_storage_hint lhs, buffer_immutable_storage_hint rhs);
        buffer_immutable_storage_hint operator|(buffer_immutable_storage_hint lhs, buffer_immutable_storage_hint rhs);
        buffer_immutable_storage_hint operator^(buffer_immutable_storage_hint lhs, buffer_immutable_storage_hint rhs);
        buffer_immutable_storage_hint& operator&=(buffer_immutable_storage_hint& lhs, buffer_immutable_storage_hint rhs);
        buffer_immutable_storage_hint& operator^=(buffer_immutable_storage_hint& lhs, buffer_immutable_storage_hint rhs);
        buffer_immutable_storage_hint& operator|=(buffer_immutable_storage_hint& lhs, buffer_immutable_storage_hint rhs);
    }
}