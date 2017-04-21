/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "pixel_formats.hpp"

#include <cstddef>
#include <utility>

namespace gloop {
    namespace pixel_formats {

        B32F_G32F_R32F * reorder(R32F_G32F_B32F * pixels, const std::size_t count) {
            for (int i = 0; i < count; i++) {
                std::swap(pixels[i].red, pixels[i].blue);
            }

            return reinterpret_cast<B32F_G32F_R32F*> (pixels);
        }

        R32F_G32F_B32F * reorder(B32F_G32F_R32F * pixels, const std::size_t count) {
            for (int i = 0; i < count; i++) {
                std::swap(pixels[i].red, pixels[i].blue);
            }

            return reinterpret_cast<R32F_G32F_B32F*> (pixels);
        }

        B32F_G32F_R32F_A32F * reorder(R32F_G32F_B32F_A32F * pixels, const std::size_t count) {
            for (int i = 0; i < count; i++) {
                std::swap(pixels[i].red, pixels[i].blue);
            }

            return reinterpret_cast<B32F_G32F_R32F_A32F *> (pixels);
        }

        R32F_G32F_B32F_A32F * reorder(B32F_G32F_R32F_A32F * pixels, const std::size_t count) {
            for (int i = 0; i < count; i++) {
                std::swap(pixels[i].red, pixels[i].blue);
            }

            return reinterpret_cast<R32F_G32F_B32F_A32F*> (pixels);
        }

        B8_G8_R8 * reorder(R8_G8_B8 * pixels, const std::size_t count) {
            for (int i = 0; i < count; i++) {
                std::swap(pixels[i].red, pixels[i].blue);
            }

            return reinterpret_cast<B8_G8_R8*> (pixels);
        }

        R8_G8_B8 * reorder(B8_G8_R8 * pixels, const std::size_t count) {
            for (int i = 0; i < count; i++) {
                std::swap(pixels[i].red, pixels[i].blue);
            }

            return reinterpret_cast<R8_G8_B8*> (pixels);
        }

        B8_G8_R8_A8 * reorder(R8_G8_B8_A8 * pixels, const std::size_t count) {
            for (int i = 0; i < count; i++) {
                std::swap(pixels[i].red, pixels[i].blue);
            }

            return reinterpret_cast<B8_G8_R8_A8*> (pixels);
        }

        R8_G8_B8_A8 * reorder(B8_G8_R8_A8 * pixels, const std::size_t count) {
            for (int i = 0; i < count; i++) {
                std::swap(pixels[i].red, pixels[i].blue);
            }

            return reinterpret_cast<R8_G8_B8_A8*> (pixels);
        }

        void reorder(R32F_G32F_B32F * dst, const B32F_G32F_R32F * src, const std::size_t count) {
            for (int i = 0; i < count; i++) {
                dst[i].red = src[i].red;
                dst[i].green = src[i].green;
                dst[i].blue = src[i].blue;
            }
        }

        void reorder(B32F_G32F_R32F * dst, const R32F_G32F_B32F * src, const std::size_t count) {
            for (int i = 0; i < count; i++) {
                dst[i].red = src[i].red;
                dst[i].green = src[i].green;
                dst[i].blue = src[i].blue;
            }
        }

        void reorder(R32F_G32F_B32F_A32F * dst, const B32F_G32F_R32F_A32F * src, const std::size_t count) {
            for (int i = 0; i < count; i++) {
                dst[i].red = src[i].red;
                dst[i].green = src[i].green;
                dst[i].blue = src[i].blue;
            }
        }

        void reorder(B32F_G32F_R32F_A32F * dst, const R32F_G32F_B32F_A32F * src, const std::size_t count) {
            for (int i = 0; i < count; i++) {
                dst[i].red = src[i].red;
                dst[i].green = src[i].green;
                dst[i].blue = src[i].blue;
            }
        }

        void reorder(R8_G8_B8 * dst, const B8_G8_R8 * src, const std::size_t count) {
            for (int i = 0; i < count; i++) {
                dst[i].red = src[i].red;
                dst[i].green = src[i].green;
                dst[i].blue = src[i].blue;
            }
        }

        void reorder(B8_G8_R8 * dst, const R8_G8_B8 * src, const std::size_t count) {
            for (int i = 0; i < count; i++) {
                dst[i].red = src[i].red;
                dst[i].green = src[i].green;
                dst[i].blue = src[i].blue;
            }
        }

        void reorder(R8_G8_B8_A8 * dst, const B8_G8_R8_A8 * src, const std::size_t count) {
            for (int i = 0; i < count; i++) {
                dst[i].red = src[i].red;
                dst[i].green = src[i].green;
                dst[i].blue = src[i].blue;
            }
        }

        void reorder(B8_G8_R8_A8 * dst, const R8_G8_B8_A8 * src, const std::size_t count) {
            for (int i = 0; i < count; i++) {
                dst[i].red = src[i].red;
                dst[i].green = src[i].green;
                dst[i].blue = src[i].blue;
            }
        }
    }
}