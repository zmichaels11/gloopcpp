/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#pragma once

#include <GL/glew.h>

namespace gloop {

    enum class blend_func : GLenum {
        ZERO = GL_ZERO,
        ONE = GL_ONE,
        SRC_COLOR = GL_SRC_COLOR,
        ONE_MINUS_SRC_COLOR = GL_ONE_MINUS_SRC_COLOR,
        DST_COLOR = GL_DST_COLOR,
        ONE_MINUS_DST_COLOR = GL_ONE_MINUS_DST_COLOR,
        SRC_ALPHA = GL_SRC_ALPHA,
        ONE_MINUS_SRC_ALPHA = GL_ONE_MINUS_SRC_ALPHA,
        DST_ALPHA = GL_DST_ALPHA,
        ONE_MINUS_DST_ALPHA = GL_ONE_MINUS_DST_ALPHA,
        CONSTANT_COLOR = GL_CONSTANT_COLOR,
        ONE_MINUS_CONSTANT_COLOR = GL_ONE_MINUS_CONSTANT_COLOR,
        CONSTANT_ALPHA = GL_CONSTANT_ALPHA,
        ONE_MINUS_CONSTANT_ALPHA = GL_ONE_MINUS_CONSTANT_ALPHA
    };

    enum class blend_eq : GLenum {
        ADD = GL_FUNC_ADD,
        SUBTRACT = GL_FUNC_SUBTRACT,
        REVERSE_SUBTRACT = GL_FUNC_REVERSE_SUBTRACT,
        MIN = GL_MIN,
        MAX = GL_MAX
    };

    class blend {
    private:
        bool _enabled;
        blend_func _srcRGB;
        blend_func _dstRGB;
        blend_func _srcAlpha;
        blend_func _dstAlpha;
        blend_eq _eqRGB;
        blend_eq _eqAlpha;

    public:

        blend(
                const bool enabled = false,
                const blend_func srcRGB = blend_func::ONE, const blend_func dstRGB = blend_func::ZERO,
                const blend_func srcAlpha = blend_func::ONE, const blend_func dstAlpha = blend_func::ZERO,
                const blend_eq eqRGB = blend_eq::ADD, const blend_eq eqAlpha = blend_eq::ADD) :

        _enabled(enabled),
        _srcRGB(srcRGB), _dstRGB(dstRGB),
        _srcAlpha(srcAlpha), _dstAlpha(dstAlpha),
        _eqRGB(eqRGB), _eqAlpha(eqAlpha) {
        }

        inline blend withEnabled(const bool enabled) const {
            return blend(enabled, _srcRGB, _dstRGB, _srcAlpha, _dstAlpha, _eqRGB, _eqAlpha);
        }

        inline blend withBlendFuncRGB(const blend_func srcRGB, const blend_func dstRGB) const {
            return blend(_enabled, srcRGB, dstRGB, _srcAlpha, _dstAlpha, _eqRGB, _eqAlpha);
        }

        inline blend withBlendFuncAlpha(const blend_func srcAlpha, const blend_func dstAlpha) const {
            return blend(_enabled, _srcRGB, _dstRGB, srcAlpha, dstAlpha, _eqRGB, _eqAlpha);
        }

        inline blend withBlendFunc(const blend_func src, const blend_func dst) const {
            return blend(_enabled, src, dst, src, dst, _eqRGB, _eqAlpha);
        }

        inline blend withBlendEq(const blend_eq rgb, const blend_eq alpha) const {
            return blend(_enabled, _srcRGB, _dstRGB, _srcAlpha, _dstAlpha, rgb, alpha);
        }

        inline blend withBlendEq(const blend_eq eq) const {
            return blend(_enabled, _srcRGB, _dstRGB, _srcAlpha, _dstAlpha, eq, eq);
        }

        struct blend_func_pair {
            blend_func src;
            blend_func dst;
        };

        inline blend_func_pair getBlendFuncRGB() const {
            return { _srcRGB, _dstRGB};
        }

        inline blend_func_pair getBlendFuncAlpha() const {
            return { _srcAlpha, _dstAlpha};
        }

        struct blend_eq_pair {
            blend_eq rgb;
            blend_eq alpha;
        };

        inline blend_eq_pair getBlendEq() const {
            return { _eqRGB, _eqAlpha};
        }

        inline bool isEnabled() const {
            return _enabled;
        }

        inline void apply() const {
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

        inline void operator()() const {
            this->apply();
        }
    };
}