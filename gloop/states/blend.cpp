/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "blend.hpp"

#include <GL/glew.h>

#include "../enums/blend_eq.hpp"
#include "../enums/blend_func.hpp"

namespace gloop {
    namespace states {

        blend blend::withEnabled(const bool enabled) const {
            return blend(enabled, _srcRGB, _dstRGB, _srcAlpha, _dstAlpha, _eqRGB, _eqAlpha);
        }

        blend blend::withBlendFuncRGB(const enums::blend_func srcRGB, const enums::blend_func dstRGB) const {
            return blend(_enabled, srcRGB, dstRGB, _srcAlpha, _dstAlpha, _eqRGB, _eqAlpha);
        }

        blend blend::withBlendFuncAlpha(const enums::blend_func srcAlpha, const enums::blend_func dstAlpha) const {
            return blend(_enabled, _srcRGB, _dstRGB, srcAlpha, dstAlpha, _eqRGB, _eqAlpha);
        }

        blend blend::withBlendFunc(const enums::blend_func src, const enums::blend_func dst) const {
            return blend(_enabled, src, dst, src, dst, _eqRGB, _eqAlpha);
        }

        blend blend::withBlendEq(const enums::blend_eq rgb, const enums::blend_eq alpha) const {
            return blend(_enabled, _srcRGB, _dstRGB, _srcAlpha, _dstAlpha, rgb, alpha);
        }

        blend blend::withBlendEq(const enums::blend_eq eq) const {
            return blend(_enabled, _srcRGB, _dstRGB, _srcAlpha, _dstAlpha, eq, eq);
        }

        enums::blend_func blend::getRGBSrcFunc() const {
            return _srcRGB;
        }

        enums::blend_func blend::getRGBDstFunc() const {
            return _dstRGB;
        }

        enums::blend_func blend::getAlphaSrcFunc() const {
            return _srcAlpha;
        }

        enums::blend_func blend::getAlphaDstFunc() const {
            return _dstAlpha;
        }

        enums::blend_eq blend::getRGBEq() const {
            return _eqRGB;
        }

        enums::blend_eq blend::getAlphaEq() const {
            return _eqAlpha;
        }
        
        bool blend::isEnabled() const {
            return _enabled;
        }
        
        void blend::apply() const {
            if (_enabled) {
                    glEnable(GL_BLEND);
                    glBlendFuncSeparate(
                            static_cast<GLenum> (_srcRGB), static_cast<GLenum> (_dstRGB),
                            static_cast<GLenum> (_srcAlpha), static_cast<GLenum> (_dstAlpha));

                    glBlendEquationSeparate(static_cast<GLenum> (_eqRGB), static_cast<GLenum> (_eqAlpha));
                } else {
                    glDisable(GL_BLEND);
                }
        }
    }
}