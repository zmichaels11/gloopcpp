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

#include "../enums/texture_mag_filter.hpp"
#include "../enums/texture_min_filter.hpp"
#include "../enums/texture_wrap.hpp"
#include "../glint.hpp"

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
            texture2D_parameters(
            enums::texture_mag_filter::NEAREST, enums::texture_min_filter::NEAREST,
            enums::texture_wrap::REPEAT, enums::texture_wrap::REPEAT,
            1.0F) {
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
            
            friend inline std::ostream& operator<<(std::ostream& os, const texture2D_parameters& params) {
                os << "Texture Parameters: [";
                                
                switch (params._magFilter) {
                    case enums::texture_mag_filter::NEAREST:
                        os << "mag filter: nearest, ";
                        break;
                    case enums::texture_mag_filter::LINEAR:
                        os << "mag filter: linear, ";
                        break;
                    default:
                        os << "mag filter: unknown, ";
                        break;
                }
                
                switch (params._minFilter) {
                    case enums::texture_min_filter::NEAREST:
                        os << "min filter: nearest, ";
                        break;
                    case enums::texture_min_filter::LINEAR:
                        os << "min filter: linear, ";
                        break;
                    case enums::texture_min_filter::NEAREST_MIPMAP_NEAREST:
                        os << "min filter: nearest mipmap nearest, ";
                        break;
                    case enums::texture_min_filter::NEAREST_MIPMAP_LINEAR:
                        os << "min filter: nearest mipmap linear, ";
                        break;
                    case enums::texture_min_filter::LINEAR_MIPMAP_NEAREST:
                        os << "min filter: linear mipmap nearest, ";
                        break;
                    case enums::texture_min_filter::LINEAR_MIPMAP_LINEAR:
                        os << "min filter: linear mipmap linear, ";
                        break;
                    default:
                        os << "min filter:: unknown, ";
                        break;
                }
                
                switch (params._wrapS) {
                    case enums::texture_wrap::REPEAT:
                        os << "wrap s: repeat, ";
                        break;
                    case enums::texture_wrap::CLAMP_TO_EDGE:
                        os << "wrap s: clamp to edge, ";
                        break;
                    case enums::texture_wrap::MIRRORED_REPEAT:
                        os << "wrap s: mirrored repeat, ";
                        break;
                    default:
                        os << "wrap s: unknown, ";
                }
                
                switch (params._wrapS) {
                    case enums::texture_wrap::REPEAT:
                        os << "wrap t: repeat, ";
                        break;
                    case enums::texture_wrap::CLAMP_TO_EDGE:
                        os << "wrap t: clamp to edge, ";
                        break;
                    case enums::texture_wrap::MIRRORED_REPEAT:
                        os << "wrap t: mirrored repeat, ";
                        break;
                    default:
                        os << "wrap t: unknown, ";
                }
                
                os << "aniso: " << params._aniso;
                
                return os;
            }
        };
    }
}