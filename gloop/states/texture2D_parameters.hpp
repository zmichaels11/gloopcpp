/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   texture_parameters.hpp
 * Author: zmichaels
 *
 * Created on April 10, 2017, 10:58 AM
 */

#pragma once

#include "../enums/texture_mag_filter.hpp"
#include "../enums/texture_min_filter.hpp"
#include "../enums/texture_wrap.hpp"
#include "../glint.hpp"
#include "../texture2D.hpp"

namespace gloop {
    namespace states {

        class texture2D_parameters {
        private:
            enums::texture_mag_filter _magFilter;
            enums::texture_min_filter _minFilter;
            enums::texture_wrap _wrapS;
            enums::texture_wrap _wrapT;
            gloop::float_t _aniso;

        public:

            texture2D_parameters() :
            _magFilter(enums::texture_mag_filter::LINEAR),
            _minFilter(enums::texture_min_filter::NEAREST_MIPMAP_LINEAR),
            _wrapS(enums::texture_wrap::REPEAT),
            _wrapT(enums::texture_wrap::REPEAT),
            _aniso(1.0F) {
            }

            texture2D_parameters(
                    const enums::texture_mag_filter magFilter,
                    const enums::texture_min_filter minFilter,
                    const enums::texture_wrap wrapS, const enums::texture_wrap wrapT,
                    const gloop::float_t aniso) :
            _magFilter(magFilter), _minFilter(minFilter),
            _wrapS(wrapS), _wrapT(wrapT),
            _aniso(aniso) {
            }

            texture2D_parameters withMagFilter(const enums::texture_mag_filter magFilter) const;

            texture2D_parameters withMinFilter(const enums::texture_min_filter minFilter) const;

            texture2D_parameters withWrapS(const enums::texture_wrap wrapS) const;

            texture2D_parameters withWrapT(const enums::texture_wrap wrapT) const;

            texture2D_parameters withAnisotropic(const gloop::float_t aniso) const;

            enums::texture_mag_filter getMagFilter() const;

            enums::texture_min_filter getMinFilter() const;

            enums::texture_wrap getWrapS() const;

            enums::texture_wrap getWrapT() const;

            gloop::float_t getAnisotropic() const;

            void apply(texture2D const * const texture) const;

            inline void operator()(texture2D * texture) const {
                apply(texture);
            }
        };
    }
}