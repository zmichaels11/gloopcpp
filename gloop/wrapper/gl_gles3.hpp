/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gl_gles3.hpp
 * Author: zmichaels
 *
 * Created on April 19, 2017, 1:23 PM
 */

#pragma once

#define GLES3 3
#if GL == GLES3

#include <functional>

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {
        // EXT_texture_storage
        extern const std::function<void(gloop::enum_t, gloop::sizei_t, gloop::enum_t, gloop::sizei_t, gloop::sizei_t)>& glTexStorage2DEXT;
        extern const bool& EXT_texture_storage;
        
        // EXT_buffer_storage
        extern const std::function<void(gloop::enum_t, gloop::sizeiptr_t, const void *, gloop::bitfield_t)>& glBufferStorageEXT;
        extern const bool& EXT_buffer_storage;
    }
}

#endif
#undef GLES3