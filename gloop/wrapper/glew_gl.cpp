/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#define GLEW 1
#if GL == GLEW
#include "gl.hpp"

#include <GL/glew.h>

#include "../glint.hpp"
#include "../buffer.hpp"
#include "../draw/call.hpp"
#include "../texture2D.hpp"

namespace {
    static gloop::buffer::features _bufferFeatures;
    static gloop::texture2D::features _textureFeatures;
    static gloop::draw::draw_call::features _drawCallFeatures;

    static void initFeatures() {
        _bufferFeatures.map = GLEW_VERSION_1_5;
        _bufferFeatures.mapRange = GLEW_VERSION_3_0;
        _bufferFeatures.blockBind = GLEW_VERSION_3_0;
        _bufferFeatures.immutable = GLEW_VERSION_4_4 || GLEW_ARB_buffer_storage;
        
        _textureFeatures.bindless = GLEW_ARB_bindless_texture;
        
        _drawCallFeatures.drawInstanced = GLEW_VERSION_3_2 || GLEW_ANGLE_instanced_arrays;
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
        
        void init() {
            if (glewInit() != GLEW_OK) {                
                throw "GLEW could not be initialized!";
            }            
            
            initFeatures();
        }
        
        const gloop::ubyte_t * getString(gloop::enum_t param) {
            return glGetString(param);
        }
    }
}
#endif
#undef GLEW