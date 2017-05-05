/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define GLES3 3
#if GL == GLES3

#include "gl.hpp"
#include "gl_gles3.hpp"

#include "../buffer.hpp"
#include "../draw/call.hpp"
#include "../texture2D.hpp"

#include <functional>
#include <type_traits>

#include <GLES3/gl3.h>

#include <SDL2/SDL_video.h>

namespace {
    static gloop::buffer::features _bufferFeatures;
    static gloop::texture2D::features _textureFeatures;
    static gloop::draw::draw_call::features _drawCallFeatures;

    static void initFeatures() {
        _bufferFeatures.map = true;
        _bufferFeatures.mapRange = true;
        _bufferFeatures.blockBind = true;
        _bufferFeatures.immutable = gloop::wrapper::EXT::buffer_storage;
        
        _textureFeatures.bindless = false;
        
        _drawCallFeatures.drawInstanced = true;
    }
}

namespace gloop {
    const buffer::features& buffer::FEATURES = _bufferFeatures;
    const texture2D::features& texture2D::FEATURES = _textureFeatures;
    const draw::draw_call::features& gloop::draw::draw_call::FEATURES = _drawCallFeatures;
}

namespace gloop {
    namespace wrapper {
        gles30_support_t GLES30;
        gles31_support_t GLES31;
        gles32_support_t GLES32;

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
#undef GLES3