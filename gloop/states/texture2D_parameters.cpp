/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "texture2D_parameters.hpp"

#include "../enums/texture_mag_filter.hpp"
#include "../enums/texture_min_filter.hpp"
#include "../enums/texture_wrap.hpp"
#include "../glint.hpp"

namespace gloop {
    namespace states {

        texture2D_parameters texture2D_parameters::withAnisotropic(const gloop::float_t aniso) const {
            return texture2D_parameters(_magFilter, _minFilter, _wrapS, _wrapT, aniso);
        }

        texture2D_parameters texture2D_parameters::withMagFilter(const enums::texture_mag_filter magFilter) const {
            return texture2D_parameters(magFilter, _minFilter, _wrapS, _wrapT, _aniso);
        }

        texture2D_parameters texture2D_parameters::withMinFilter(const enums::texture_min_filter minFilter) const {
            return texture2D_parameters(_magFilter, minFilter, _wrapS, _wrapT, _aniso);
        }

        texture2D_parameters texture2D_parameters::withWrapS(const enums::texture_wrap wrapS) const {
            return texture2D_parameters(_magFilter, _minFilter, wrapS, _wrapT, _aniso);
        }

        texture2D_parameters texture2D_parameters::withWrapT(const enums::texture_wrap wrapT) const {
            return texture2D_parameters(_magFilter, _minFilter, _wrapS, wrapT, _aniso);
        }

        enums::texture_mag_filter texture2D_parameters::getMagFilter() const {
            return _magFilter;
        }

        enums::texture_min_filter texture2D_parameters::getMinFilter() const {
            return _minFilter;
        }

        enums::texture_wrap texture2D_parameters::getWrapS() const {
            return _wrapS;
        }

        enums::texture_wrap texture2D_parameters::getWrapT() const {
            return _wrapT;
        }

        gloop::float_t texture2D_parameters::getAnisotropic() const {
            return _aniso;
        }
    }
}