/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "blend.hpp"

#include <iostream>
#include <stack>

#include "../enums/blend_eq.hpp"
#include "../enums/blend_func.hpp"
#include "../exception/invalid_operation_exception.hpp"
#include "../gloop_throw.hpp"
#include "../wrapper/states.hpp"

namespace gloop {
    namespace states {
        blend blend::CURRENT_BLEND;
        std::stack<blend> blend::BLEND_STACK;
        
        void blend::push() {
            BLEND_STACK.push(CURRENT_BLEND);
        }
        
        blend blend::pop() {
            if (BLEND_STACK.empty()) {
                gloop_throw(gloop::exception::invalid_operation_exception("Attempted to pop empty stack!"));
            } else {
                blend current = CURRENT_BLEND;
                blend restore = BLEND_STACK.top();
                
                BLEND_STACK.pop();
                
                restore();
                
                return current;
            }
        }
        
        const blend& blend::getCurrentBlend() {
            return CURRENT_BLEND;
        }
        
        std::ostream& operator<<(std::ostream& os, const blend& b) {
            return os << "blend: ["
                    << "rgb: [src: " << b._srcRGB
                    << ", dst: " << b._dstRGB
                    << ", eq: " << b._eqRGB
                    << "], alpha: [src: " << b._srcAlpha
                    << ", dst: " << b._dstAlpha
                    << ", eq: " << b._eqAlpha
                    << "]";
        }
        
        blend::blend() {
            _srcRGB = enums::blend_func::ONE;
            _srcAlpha = enums::blend_func::ONE;
            _dstRGB = enums::blend_func::ZERO;
            _dstAlpha = enums::blend_func::ZERO;
            _eqRGB = enums::blend_eq::ADD;
            _eqAlpha = enums::blend_eq::ADD;
        }

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
            CURRENT_BLEND = *this;
            
            if (_enabled) {
                gloop::wrapper::enable(gloop::wrapper::BLEND);

                gloop::wrapper::blendFuncSeparate(
                        static_cast<gloop::enum_t> (_srcRGB), static_cast<gloop::enum_t> (_dstRGB),
                        static_cast<gloop::enum_t> (_srcAlpha), static_cast<gloop::enum_t> (_dstAlpha));

                gloop::wrapper::blendEquationSeparate(
                        static_cast<gloop::enum_t> (_eqRGB),
                        static_cast<gloop::enum_t> (_eqAlpha));
            } else {
                gloop::wrapper::disable(gloop::wrapper::BLEND);
            }
        }
    }
}