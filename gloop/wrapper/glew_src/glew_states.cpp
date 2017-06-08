#ifndef __EMSCRIPTEN__
#include "states.hpp"

#include <GL/glew.h>

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {
        void enable(gloop::enum_t state) {
            glEnable(state);
        }
        
        void disable(gloop::enum_t state) {
            glDisable(state);
        }
        
        void blendFuncSeparate(
                gloop::enum_t srcRGB, gloop::enum_t dstRGB,
                gloop::enum_t srcAlpha, gloop::enum_t dstAlpha) {
            
            glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
        }

        void blendEquationSeparate(
                gloop::enum_t eqRGB,
                gloop::enum_t eqAlpha) {
            
            glBlendEquationSeparate(eqRGB, eqAlpha);
        }

        void clear(gloop::bitfield_t clearMask) {
            glClear(clearMask);
        }

        void depthRange(
                gloop::double_t near,
                gloop::double_t far) {
            
            glDepthRange(near, far);
        }

		void depthFunc(gloop::enum_t depthFunc) {
			glDepthFunc(depthFunc);
		}			

        void scissor(
                gloop::int_t x, gloop::int_t y,
                gloop::sizei_t width, gloop::sizei_t height) {
            
            glScissor(x, y, width, height);
        }

        void viewport(
                gloop::int_t x, gloop::int_t y,
                gloop::sizei_t width, gloop::sizei_t height) {
            
            glViewport(x, y, width, height);
        }
        
        void clearColor(
                gloop::float_t red,
                gloop::float_t green,
                gloop::float_t blue,
                gloop::float_t alpha) {
            
            glClearColor(red, green, blue, alpha);
        }
        
        void clearDepth(gloop::double_t depth) {
            glClearDepth(depth);
        }
        
        void clearStencil(gloop::int_t stencil) {
            glClearStencil(stencil);
        }
    }
}
#endif
