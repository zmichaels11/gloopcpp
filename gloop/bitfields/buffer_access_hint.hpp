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

#include "../glint.hpp"

namespace gloop {
    namespace bitfields {

        enum class buffer_access_hint : gloop::bitfield_t {
            READ = 0x0001,
            WRITE = 0x0002,
            PERSISTENT = 0x00000040,
            COHERENT = 0x00000080,
            INVALIDATE_BUFFER = 0x0008,
            INVALIDATE_RANGE = 0x0004,
            FLUSH_EXPLICIT = 0x0010,
            UNSYNCHRONIZED = 0x0020
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
