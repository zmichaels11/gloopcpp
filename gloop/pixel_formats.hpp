/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pixel_format.hpp
 * Author: zmichaels
 *
 * Created on April 10, 2017, 10:51 AM
 */

#pragma once

namespace gloop {
    namespace pixel_formats {

        struct R8_G8_B8 {
            gloop::uint8_t red;
            gloop::uint8_t green;
            gloop::uint8_t blue;
        };

        struct R8_G8_B8_A8 {
            gloop::uint8_t red;
            gloop::uint8_t green;
            gloop::uint8_t blue;
            gloop::uint8_t alpha;
        };

        struct B8_G8_R8 {
            gloop::uint8_t blue;
            gloop::uint8_t green;
            gloop::uint8_t red;
        };

        struct B8_R8_G8_A8 {
            gloop::uint8_t blue;
            gloop::uint8_t green;
            gloop::uint8_t red;
            gloop::uint8_t alpha;
        };

        struct R32F_G32F_B32F {
            gloop::float_t red;
            gloop::float_t green;
            gloop::float_t blue;
        };

        struct B32F_G32F_R32F {
            gloop::float_t blue;
            gloop::float_t green;
            gloop::float_t alpha;
        };

        struct R32F_G32F_B32F_A32F {
            gloop::float_t red;
            gloop::float_t green;
            gloop::float_t blue;
            gloop::float_t alpha;
        };

        struct B32F_G32F_R32F_A32F {
            gloop::float_t blue;
            gloop::float_t green;
            gloop::float_t red;
            gloop::float_t alpha;
        };
    }
}