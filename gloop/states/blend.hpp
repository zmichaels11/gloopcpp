/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#pragma once

#include <iostream>

#include "../enums/blend_eq.hpp"
#include "../enums/blend_func.hpp"

namespace gloop {
    namespace states {

        class blend {
        private:
            bool _enabled;
            enums::blend_func _srcRGB;
            enums::blend_func _dstRGB;
            enums::blend_func _srcAlpha;
            enums::blend_func _dstAlpha;
            enums::blend_eq _eqRGB;
            enums::blend_eq _eqAlpha;

        public:

            blend() :
            blend(false,
            enums::blend_func::ONE, enums::blend_func::ZERO,
            enums::blend_func::ONE, enums::blend_func::ZERO,
            enums::blend_eq::ADD, enums::blend_eq::ADD) {
            }

            blend(
                    const bool enabled,
                    const enums::blend_func srcRGB, const enums::blend_func dstRGB,
                    const enums::blend_func srcAlpha, const enums::blend_func dstAlpha,
                    const enums::blend_eq eqRGB, const enums::blend_eq eqAlpha) :

            _enabled(enabled),
            _srcRGB(srcRGB), _dstRGB(dstRGB),
            _srcAlpha(srcAlpha), _dstAlpha(dstAlpha),
            _eqRGB(eqRGB), _eqAlpha(eqAlpha) {
            }

            blend withEnabled(const bool enabled) const;

            blend withBlendFuncRGB(const enums::blend_func srcRGB, const enums::blend_func dstRGB) const;

            blend withBlendFuncAlpha(const enums::blend_func srcAlpha, const enums::blend_func dstAlpha) const;

            blend withBlendFunc(const enums::blend_func src, const enums::blend_func dst) const;

            blend withBlendEq(const enums::blend_eq rgb, const enums::blend_eq alpha) const;

            blend withBlendEq(const enums::blend_eq eq) const;

            enums::blend_func getRGBSrcFunc() const;

            enums::blend_func getRGBDstFunc() const;

            enums::blend_func getAlphaSrcFunc() const;

            enums::blend_func getAlphaDstFunc() const;

            enums::blend_eq getRGBEq() const;

            enums::blend_eq getAlphaEq() const;

            bool isEnabled() const;

            void apply() const;

            inline void operator()() const {
                this->apply();
            }
            
            inline friend std::ostream& operator<<(std::ostream& os, const blend& b) {
                return os << "blend: ["
                        << "rgb: [src: " << b._srcRGB
                        << ", dst: " << b._dstRGB
                        << ", eq: " << b._eqRGB
                        << "], alpha: [src: " << b._srcAlpha
                        << ", dst: " << b._dstAlpha
                        << ", eq: " << b._eqAlpha
                        << "]";
            }
        };
    }
}