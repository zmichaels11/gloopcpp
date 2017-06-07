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

#include "../glint.hpp"

#include "pfnglproc.hpp"
#include "glext.hpp"
#include "glversion.hpp"

namespace gloop {
    namespace wrapper {

        struct oes_vertex_array_object_support_t {
            glext support;
            pfnglproc<void(gloop::sizei_t, gloop::uint_t *) > genVertexArraysOES;
            pfnglproc<void(gloop::uint_t) > bindVertexArrayOES;
            pfnglproc<void(gloop::sizei_t, gloop::uint_t *) > deleteVertexArraysOES;

            oes_vertex_array_object_support_t() :
            support("OES_vertex_array_object"),
            genVertexArraysOES("glGenVertexArraysOES"),
            bindVertexArrayOES("glBindVertexArrayOES"),
            deleteVertexArraysOES("glDeleteVertexArraysOES") {
            }

            inline operator bool() {
                return support;
            }
        };

        extern oes_vertex_array_object_support_t OES_vertex_array_object;

        struct angle_instanced_arrays_support_t {
            glext support;
            pfnglproc<void(gloop::enum_t, gloop::int_t, gloop::sizei_t, gloop::sizei_t) > drawArraysInstancedANGLE;
            pfnglproc<void(gloop::enum_t, gloop::sizei_t, gloop::enum_t, const void *, gloop::sizei_t) > drawElementsInstancedANGLE;
            pfnglproc<void(gloop::uint_t, gloop::uint_t) > vertexAttribDivisorANGLE;

            angle_instanced_arrays_support_t() :
            support("ANGLE_instanced_arrays"),
            drawArraysInstancedANGLE("glDrawArraysInstancedANGLE"),
            drawElementsInstancedANGLE("glDrawElementsInstancedANGLE"),
            vertexAttribDivisorANGLE("glVertexAttribDivisorANGLE") {
            }

            inline operator bool() {
                return support;
            }
        };

        extern angle_instanced_arrays_support_t ANGLE_instanced_arrays;

        struct ext_map_buffer_range_support_t {
            glext support;
            pfnglproc<void*(gloop::enum_t, gloop::intptr_t, gloop::sizeiptr_t, gloop::bitfield_t) > mapBufferRangeEXT;

            ext_map_buffer_range_support_t() :
            support("EXT_map_buffer_range"),
            mapBufferRangeEXT("glMapBufferRangeEXT") {
            }

            inline operator bool() {
                return support;
            }
        };
        
        extern ext_map_buffer_range_support_t EXT_map_buffer_range;
        
        struct oes_mapbuffer_support_t {
            glext support;
            pfnglproc<void*(gloop::enum_t, gloop::enum_t)> mapBufferOES;
            pfnglproc<gloop::boolean_t(gloop::enum_t)> unmapBufferOES;
            
            oes_mapbuffer_support_t() :
            support("OES_mapbuffer"),
            mapBufferOES("glMapBufferOES"),
            unmapBufferOES("glUnmapBufferOES") {}
            
            inline operator bool() {
                return support;
            }
        };
        
        extern oes_mapbuffer_support_t OES_mapbuffer;
        
        struct ext_buffer_storage_support_t {
            glext support;
            pfnglproc<void(gloop::enum_t, gloop::sizeiptr_t, const void *, gloop::bitfield_t)> bufferStorageEXT;
            
            ext_buffer_storage_support_t() :
            support("EXT_buffer_storage"),
            bufferStorageEXT("glBufferStorageEXT") {}
            
            inline operator bool() {
                return support;
            }
        };
        
        extern ext_buffer_storage_support_t EXT_buffer_storage;
        
        struct ext_texture_storage_support_t {
            glext support;
            pfnglproc<void(gloop::enum_t, gloop::int_t, gloop::enum_t, gloop::sizei_t, gloop::sizei_t)> texStorage2DEXT;
            
            ext_texture_storage_support_t() :
            support("EXT_texture_storage"),
            texStorage2DEXT("glTexStorage2DEXT") {}
            
            inline operator bool() {
                return support;
            }            
        };
        
        extern ext_texture_storage_support_t EXT_texture_storage;
    }
}
#endif
#undef GLES2