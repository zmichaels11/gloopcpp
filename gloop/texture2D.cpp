/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "texture2D.hpp"

#include "enums/texture_internal_format.hpp"
#include "glint.hpp"

namespace gloop {
    gloop::uint_t texture2D::getId() const {
        return _id;
    }
    
    bool texture2D::isValid() const {
        return (_id != 0);
    }
    
    const texture2D::size& texture2D::getSize() const {
        return _size;
    }
    
    enums::texture_internal_format texture2D::getInternalFormat() const {
        return _format;
    }
    
    gloop::uint_t texture2D::getMipmapLevelCount() const {
        return _levels;
    }
}