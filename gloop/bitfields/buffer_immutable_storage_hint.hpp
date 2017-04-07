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

#include "../glint.hpp"

namespace gloop {
    namespace bitfields {

        enum class buffer_immutable_storage_hint : gloop::bitfield_t {
            READ = 0x0001,
            WRITE = 0x0002,
            DYNAMIC_STORAGE = 0x0100,
            CLIENT_STORAGE = 0x0200,
            MAP_COHERENT = 0x00000080,
            MAP_PERSISTENT = 0x00000040
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