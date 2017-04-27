/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sprite_sheet.hpp"

#include <SDL2/SDL_surface.h>

#include "../gloop/gloop_throw.hpp"
#include "../gloop/texture2D.hpp"

namespace glgfx {
    sprite_sheet::sprite_sheet(const std::string& name) {
        _name = name;
        _isCached = false;
        _isValid = false;
        _size = {0, 0};
        _image = nullptr;
    }
    
    sprite_sheet::sprite_sheet(const std::string& name, const std::string& cachedImg, const std::string& cachedMeta) {
        _name = name;
        _isCached = true;
        _path = cachedImg;
        _meta = cachedMeta;
        _size = {0, 0};
        _image = nullptr;
    }
    
    sprite_sheet::~sprite_sheet() {
        if (_image) {
            SDL_FreeSurface(_image);
        }
    }
    
    bool sprite_sheet::isCached() const {
        return _isCached;
    }
    
    SDL_Surface * sprite_sheet::getImage() {
        if (!_isValid) {
            rebuild();
        }
        
        return _image;
    }
    
    const std::string& sprite_sheet::getName() const {
        return _name;
    }
    
    void sprite_sheet::invalidate() {
        SDL_FreeSurface(_image);
        _isValid = false;       
        _image = nullptr;
        _texture.reset(nullptr);
    }
    
    void sprite_sheet::remove(const std::string& name) {
        invalidate();
        
        std::vector<input>::iterator toRemove;
        bool found = false;
        
        for (auto it = _inputs.begin(); it != _inputs.end(); it++) {
            if(it->name == name) {
                toRemove = it;
                found = true;
                break;
            }
        }
        
        if (found) {
            _inputs.erase(toRemove);
        }
    }
    
    void sprite_sheet::addInput(const std::string& name, const std::string& path) {
        _inputs.push_back({name, path});
    }
    
    sprite::texture_data * sprite_sheet::get(const std::string& name) {
        if (!_isValid) {
            rebuild();
        }
        
        for (auto it = _imageData.begin(); it != _imageData.end(); it++) {
            if (it->first == name) {
                return &(it->second);
            }
        }
        
        return nullptr;
    }
    
    std::vector<std::string> sprite_sheet::getNames() const {
        std::vector<std::string> nameList;
        
        for (const auto& kv : _imageData) {
            nameList.push_back(kv.first);
        }
        
        return nameList;
    }
    
    const sprite_sheet::size& sprite_sheet::getSize() const {
        return _size;
    }
    
    void sprite_sheet::rebuild() {
        if (_isCached) {
            loadFromCache();
        } else {
            loadFromInputs();
        }
        
        _isValid = true;
    }
    
    void sprite_sheet::loadFromCache() {
        
    }
    
    void sprite_sheet::loadFromInputs() {
        
    }
}