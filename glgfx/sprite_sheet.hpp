/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   spritesheet.hpp
 * Author: zmichaels
 *
 * Created on April 27, 2017, 11:13 AM
 */

#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

#include <SDL2/SDL_image.h>

#include "sprite.hpp"

namespace gloop {
    class texture2D;
}

namespace glgfx {    
    class sprite_sheet {
    public:
        struct size {
            unsigned int width;
            unsigned int height;
        };
        
    private:
        struct input {
            std::string name;
            std::string image;           
        };
        
        std::vector<input> _inputs;
        
        bool _isValid;
        std::string _name;
        size _size;
        std::string _path;
        std::string _meta;
        bool _isCached;
        SDL_Surface * _image;
        std::map<std::string, sprite::texture_data> _imageData;        
        std::unique_ptr<gloop::texture2D> _texture;
        
        void loadFromCache();
        void loadFromInputs();
        void rebuild();
        
    public:
        sprite_sheet(const std::string& name);
        
        sprite_sheet(const std::string& name, const std::string& cachedImg, const std::string& cachedMeta);
        
        sprite_sheet(const sprite_sheet&) = delete;
        
        sprite_sheet(sprite_sheet&&) = default;
        
        ~sprite_sheet();
        
        sprite_sheet& operator=(const sprite_sheet&) = delete;
        
        sprite_sheet& operator=(sprite_sheet&&) = default;
        
        SDL_Surface * getImage();
        
        const std::string& getName() const;
        
        bool isCached() const;
        
        void clear();
        
        void invalidate();
        
        void removeInput(const std::string& name);
        
        void addInput(const std::string& name, const std::string& path);
        
        sprite::texture_data * get(const std::string& name);
        
        inline sprite::texture_data * operator[](const std::string& name) {
            return get(name);
        }
        
        std::vector<std::string> getNames() const;
        
        const size& getSize() const;
    };
}