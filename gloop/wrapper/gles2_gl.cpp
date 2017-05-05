/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#define GLES2 2
#if GL == GLES2
#include "gl.hpp"
#include "gl_gles2.hpp"

#include <iostream>

#include "../buffer.hpp"
#include "../draw/call.hpp"
#include "../glint.hpp"
#include "../texture2D.hpp"

#include <SDL2/SDL_opengles2.h>

namespace gloop {
    namespace wrapper {
        oes_vertex_array_object_support_t OES_vertex_array_object;
        angle_instanced_arrays_support_t ANGLE_instanced_arrays;
        ext_map_buffer_range_support_t EXT_map_buffer_range;
        oes_mapbuffer_support_t OES_mapbuffer;
        ext_buffer_storage_support_t EXT_buffer_storage;
        ext_texture_storage_support_t EXT_texture_storage;
    }
}

namespace {
    static gloop::buffer::features _bufferFeatures;
    static gloop::texture2D::features _textureFeatures;
    static gloop::draw::draw_call::features _drawCallFeatures;

    static void initFeatures() {
        _bufferFeatures.map = gloop::wrapper::OES_mapbuffer;
        _bufferFeatures.mapRange = gloop::wrapper::EXT_map_buffer_range;
        _bufferFeatures.blockBind = false;
        _bufferFeatures.immutable = gloop::wrapper::EXT_buffer_storage;
        
        _textureFeatures.bindless = false;
        
        _drawCallFeatures.drawInstanced = gloop::wrapper::ANGLE_instanced_arrays;
    }
}

namespace gloop {
    const buffer::features& gloop::buffer::FEATURES = _bufferFeatures;
    const texture2D::features& gloop::texture2D::FEATURES = _textureFeatures;
    const draw::draw_call::features& gloop::draw::draw_call::FEATURES = _drawCallFeatures;
}

namespace gloop {
    namespace wrapper {        
        

        gloop::enum_t getError() {
            return glGetError();
        }

        const gloop::ubyte_t * getString(gloop::enum_t param) {
            return glGetString(param);
        }

        void init() {
            static bool isInit = false;
            
            if (!isInit) {
                initFeatures();
                isInit = true;
            }
        }
    }
}

#endif
#undef GLES2