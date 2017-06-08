#ifndef __EMSCRIPTEN__
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
		gloop::context_hints getDefaultContextHints() {
			return {{3, 3}, gloop::context_profile::CORE, 1, true};
		}

        void init() {
            static bool isInit = false;
            
            if (isInit) {
                return;
            } else {
                isInit = true;
            }
            
            if (glewInit() != GLEW_OK) {                
                throw "GLEW could not be initialized!";
            }            
            
            initFeatures();
        }
    }
}
#endif
