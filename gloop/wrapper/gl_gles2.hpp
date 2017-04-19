/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gl_gles2.hpp
 * Author: zmichaels
 *
 * Created on April 19, 2017, 8:41 AM
 */

#pragma once

#define GLES2 2
#if GL == GLES2
#include <functional>

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {
        // OES_vertex_array_object        
        extern const std::function<void(gloop::sizei_t, gloop::uint_t *)>& glGenVertexArraysOES;
        extern const std::function<void(gloop::uint_t)>& glBindVertexArrayOES;
        extern const std::function<void(gloop::sizei_t, gloop::uint_t *)>& glDeleteVertexArraysOES;
        extern const bool& OES_vertex_array_object;

        // ANGLE_instanced_arrays
        extern const std::function<void(gloop::enum_t, gloop::int_t, gloop::sizei_t, gloop::sizei_t)>& glDrawArraysInstancedANGLE;
        extern const std::function<void(gloop::enum_t, gloop::sizei_t, gloop::enum_t, const void *, gloop::sizei_t)>& glDrawElementsInstancedANGLE;
        extern const std::function<void(gloop::uint_t, gloop::uint_t)>& glVertexAttribDivisorANGLE;
        extern const bool& ANGLE_instanced_arrays;

        // EXT_map_buffer_range
        extern const std::function<void*(gloop::enum_t, gloop::intptr_t, gloop::sizeiptr_t, gloop::bitfield_t)>& glMapBufferRangeEXT;
        extern const bool& EXT_map_buffer_range;

        // OES_mapbuffer
        extern const std::function<void*(gloop::enum_t, gloop::enum_t)>& glMapBufferOES;
        extern const std::function<gloop::boolean_t(gloop::enum_t)>& glUnmapBufferOES;
        extern const bool& OES_mapbuffer;

        // EXT_texture_storage
        extern const std::function<void(gloop::enum_t, gloop::sizei_t, gloop::enum_t, gloop::sizei_t, gloop::sizei_t)>& glTexStorage2DEXT;
        extern const bool& EXT_texture_storage;
        
        // EXT_buffer_storage
        extern const std::function<void(gloop::enum_t, gloop::sizeiptr_t, const void *, gloop::bitfield_t)>& glBufferStorageEXT;
        extern const bool& EXT_buffer_storage;
    }
}
#endif
#undef GLES2