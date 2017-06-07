/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sprite_sheet.hpp"

#include <memory>

#include <SDL2/SDL_surface.h>

#ifdef USE_SDL_IMAGE
#include <SDL2/SDL_image.h>
#endif

#include "../gloop/enums/texture_internal_format.hpp"
#include "../gloop/gloop_throw.hpp"
#include "../gloop/pixel_formats.hpp"
#include "../gloop/texture2D.hpp"

#include "skyline_packer.hpp"

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
        if (_image) {
            SDL_FreeSurface(_image);
        }
        
        _isValid = false;
        _image = nullptr;
        _texture.reset(nullptr);
    }
    
    void sprite_sheet::clear() {
        invalidate();
        _inputs.clear();
        _imageData.clear();
    }

    void sprite_sheet::removeInput(const std::string& name) {
        invalidate();

        std::vector<input>::iterator toRemove;
        bool found = false;

        for (auto it = _inputs.begin(); it != _inputs.end(); it++) {
            if (it->name == name) {
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

    namespace {

        static SDL_Surface * __load(const std::string& img) {
#ifdef USE_SDL_IMAGE
            static bool isInit = false;

            if (!isInit) {
                auto result = IMG_Init(IMG_INIT_PNG);

                if ((result & IMG_INIT_PNG) != IMG_INIT_PNG) {
                    gloop_throw("Unable to initialize PNG library!");
                }

                isInit = true;
            }

            const auto unprocessed = IMG_Load(img.c_str());
#else
            const auto unprocessed = SDL_LoadBMP(img.c_str());
#endif

            if (unprocessed == nullptr) {
                gloop_throw("Unable to load image!");
            }

            constexpr Uint32 rmask = 0x000000FF;
            constexpr Uint32 gmask = 0x0000FF00;
            constexpr Uint32 bmask = 0x00FF0000;
            constexpr Uint32 amask = 0xFF000000;

            const auto optimized = SDL_CreateRGBSurface(0, unprocessed->w, unprocessed->h, 32, rmask, gmask, bmask, amask);

            if (optimized == nullptr) {
                gloop_throw("Unable to create RGB surface!");
            }

            SDL_BlitSurface(unprocessed, nullptr, optimized, nullptr);
            SDL_FreeSurface(unprocessed);

            return optimized;
        }
    }

    void sprite_sheet::loadFromInputs() {

        struct processed {
            std::string name;
            SDL_Surface * img;
            skyline_packer::rect * rect;
        };

        const auto spriteCount = _inputs.size();
        auto sprites = std::make_unique < processed[]>(spriteCount);
        auto rects = std::make_unique < skyline_packer::rect[]>(spriteCount);

        for (int i = 0; i < spriteCount; i++) {
            const auto& input = _inputs[i];
            auto img = __load(input.image);
            auto sprite = sprites.get() + i;
            auto rect = rects.get() + i;

            sprite->img = img;
            sprite->name = input.name;
            sprite->rect = rect;

            rect->x = 0;
            rect->y = 0;
            rect->width = img->w;
            rect->height = img->h;
        }

        skyline_packer packer;

        packer.pack(rects.get(), spriteCount);

        const auto width = packer.getWidth();
        const auto height = packer.getHeight();
        
        _size.width = width;
        _size.height = height;

        _texture.reset(new gloop::texture2D);
        _texture->allocate(gloop::enums::texture_internal_format::R8_G8_B8_A8_UNORM, 1, width, height);

        constexpr Uint32 rmask = 0x000000FF;
        constexpr Uint32 gmask = 0x0000FF00;
        constexpr Uint32 bmask = 0x00FF0000;
        constexpr Uint32 amask = 0xFF000000;

        _image = SDL_CreateRGBSurface(0, width, height, 32, rmask, gmask, bmask, amask);

        for (int i = 0; i < spriteCount; i++) {
            auto sprite = sprites.get() + i;
            const auto x = sprite->rect->x;
            const auto y = sprite->rect->y;
            const auto w = sprite->img->w;
            const auto h = sprite->img->h;

            sprite::texture_data textureData;

            textureData.texture = _texture.get();
            textureData.u0 = float(x) / float(width);
            textureData.u1 = float(x + w) / float(width);
            textureData.v0 = float(y) / float(height);
            textureData.v1 = float(y + h) / float(height);

            _texture->update(0, x, y, w, h, reinterpret_cast<const gloop::pixel_formats::R8_G8_B8_A8 *> (sprite->img->pixels));

            SDL_Rect src;
            src.x = 0;
            src.y = 0;
            src.w = sprite->img->w;
            src.h = sprite->img->h;

            SDL_Rect dst;
            dst.x = x;
            dst.y = y;
            dst.w = w;
            dst.h = h;

            SDL_BlitSurface(sprite->img, &src, _image, &dst);

            SDL_FreeSurface(sprite->img);
            sprite->img = nullptr;

            _imageData[sprite->name] = textureData;
        }
        
#ifdef _DEBUG
        std::cout << "DEBUG: Generated spritesheet: ["                
                << " name: " << _name
                << " w: " << _size.width
                << " h: " << _size.height
                << " usage: " << packer.getUsageRatio()
                << "]" << std::endl;
#endif        
    }
}