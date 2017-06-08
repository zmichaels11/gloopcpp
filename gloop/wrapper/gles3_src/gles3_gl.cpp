#include "gl.hpp"
#include "gl_gles3.hpp"

#include "../buffer.hpp"
#include "../context_hints.hpp"
#include "../draw/call.hpp"
#include "../glint.hpp"
#include "../texture2D.hpp"

#include <GLES3/gl3.h>

namespace gloop {
    namespace wrapper {
        gles30_support_t GLES30;
        gles31_support_t GLES31;
        gles32_support_t GLES32;
        ext_buffer_storage_support_t EXT_buffer_storage;
    }
}

namespace {
    static gloop::buffer::features _bufferFeatures;
    static gloop::texture2D::features _textureFeatures;
    static gloop::draw::draw_call::features _drawCallFeatures;

    static void initFeatures() {
        _bufferFeatures.map = true;
        _bufferFeatures.mapRange = true;
        _bufferFeatures.blockBind = true;
        _bufferFeatures.immutable = gloop::wrapper::EXT_buffer_storage;
        
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
		gloop::context_hints getDefaultContextHints() {
#ifdef __EMSCRIPTEN__
			return {{2, 0}, gloop::context_profile::ES, 1, true};
#else
			return {{3, 0}, gloop::context_profile::ES, 1, true};
#endif
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
