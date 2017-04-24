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

#include <iostream>

#include "../glint.hpp"

namespace gloop {
    namespace enums {
        enum class texture_mag_filter : gloop::enum_t;
        enum class texture_min_filter : gloop::enum_t;
        enum class texture_wrap : gloop::enum_t;
    }
    
    namespace states {

        class texture2D_parameters {
        private:
            enums::texture_mag_filter _magFilter;
            enums::texture_min_filter _minFilter;
            enums::texture_wrap _wrapS;
            enums::texture_wrap _wrapT;
            gloop::float_t _aniso;

        public:

            texture2D_parameters();

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
            
            friend std::ostream& operator<<(std::ostream& os, const texture2D_parameters& params);
        };
    }
}