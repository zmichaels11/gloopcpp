/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   texture2D.hpp
 * Author: zmichaels
 *
 * Created on April 10, 2017, 9:59 AM
 */

#pragma once

#include <iostream>
#include <memory>

#include "glint.hpp"

namespace gloop {

    namespace enums {
        enum class texture_internal_format : gloop::enum_t;
    }        
    
    namespace pixel_formats {
        struct R8_G8_B8;
        struct R8_G8_B8_A8;
        struct B8_G8_R8;
        struct B8_G8_R8_A8;
        struct R32F_G32F_B32F;
        struct R32F_G32F_B32F_A32F;       
        struct B32F_G32F_R32F;
        struct B32F_G32F_R32F_A32F;
    }
    
    namespace states {
        class texture2D_parameters;
    }
    
    class texture2D {
    public:

        struct size {
            gloop::sizei_t width;
            gloop::sizei_t height;
            
            friend std::ostream& operator<<(std::ostream& os, const size& s);
        };
    private:
        gloop::uint_t _id;
        size _size;
        enums::texture_internal_format _format;
        gloop::sizei_t _levels;
        std::unique_ptr<states::texture2D_parameters> _params;

    public:

        texture2D();

        ~texture2D();
        
        texture2D(const texture2D&) = delete;
        
        texture2D(texture2D&&) = default;
        
        texture2D& operator=(const texture2D&) = delete;
        
        texture2D& operator=(texture2D&&) = default;    
        
        friend std::ostream& operator<<(std::ostream& os, const texture2D& t);

        gloop::uint_t getId() const;

        bool isValid() const;

        inline operator bool() const {
            return isValid();
        }

        const size& getSize() const;

        gloop::uint_t getMipmapLevelCount() const;

        enums::texture_internal_format getInternalFormat() const;

        void allocate(
                const enums::texture_internal_format internalFormat,
                const gloop::sizei_t levels,
                const gloop::sizei_t width, const gloop::sizei_t height);                                       
        
        void setParameters(const gloop::states::texture2D_parameters& params);
        
        const gloop::states::texture2D_parameters& getParameters() const;
       
        void update(
                const gloop::sizei_t level,
                const gloop::int_t xOffset, const gloop::int_t yOffset,
                const gloop::sizei_t width, const gloop::sizei_t height,
                const gloop::pixel_formats::B32F_G32F_R32F * data) const;

        void update(
                const gloop::sizei_t level,
                const gloop::int_t xOffset, const gloop::int_t yOffset,
                const gloop::sizei_t width, const gloop::sizei_t height,
                const gloop::pixel_formats::B32F_G32F_R32F_A32F * data) const;

        void update(
                const gloop::sizei_t level,
                const gloop::int_t xOffset, const gloop::int_t yOffset,
                const gloop::sizei_t width, const gloop::sizei_t height,
                const gloop::pixel_formats::B8_G8_R8 * data) const;

        void update(
                const gloop::sizei_t level,
                const gloop::int_t xOffset, const gloop::int_t yOffset,
                const gloop::sizei_t width, const gloop::sizei_t height,
                const gloop::pixel_formats::B8_G8_R8_A8 * data) const;

        void update(
                const gloop::sizei_t level,
                const gloop::int_t xOffset, const gloop::int_t yOffset,
                const gloop::sizei_t width, const gloop::sizei_t height,
                const gloop::pixel_formats::R32F_G32F_B32F * data) const;

        void update(
                const gloop::sizei_t level,
                const gloop::int_t xOffset, const gloop::int_t yOffset,
                const gloop::sizei_t width, const gloop::sizei_t height,
                const gloop::pixel_formats::R32F_G32F_B32F_A32F * data) const;

        void update(
                const gloop::sizei_t level,
                const gloop::int_t xOffset, const gloop::int_t yOffset,
                const gloop::sizei_t width, const gloop::sizei_t height,
                const gloop::pixel_formats::R8_G8_B8 * data) const;

        void update(
                const gloop::sizei_t level,
                const gloop::int_t xOffset, const gloop::int_t yOffset,
                const gloop::sizei_t width, const gloop::sizei_t height,
                const gloop::pixel_formats::R8_G8_B8_A8 * ddata) const;        

        void free();

        void bind(const gloop::uint_t unit) const;                
    };
}