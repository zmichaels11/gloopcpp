/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "graphics.h"

#include <stdint.h>

#include <cstring>

#include "../glgfx/blend_mode.hpp"
#include "../glgfx/graphics.hpp"
#include "../glgfx/sprite.hpp"
#include "../glgfx/sprite_sheet.hpp"

#include "../gloop/matrices.hpp"

void * glgfxGetCurrentContext() {
    return new glgfx::graphics;
}

void glgfxDestroyContext(void * ctx) {
    auto gfx = reinterpret_cast<glgfx::graphics *> (ctx);

    delete gfx;
}

uint32_t glgfxGetBlendMode(void * ctx) {
    auto gfx = reinterpret_cast<glgfx::graphics *> (ctx);
    auto out = gfx->getBlendMode();

    return static_cast<uint32_t> (out);
}

void glgfxSetBlendMode(void * ctx, uint32_t blend) {
    auto gfx = reinterpret_cast<glgfx::graphics *> (ctx);

    gfx->setBlendMode(static_cast<glgfx::blend_mode> (blend));
}

namespace {

    static gloop::vec4 __vec4(float * v) {
        return gloop::vec4{v[0], v[1], v[2], v[3]};
    }

    static gloop::mat4 __mat4(float * m) {
        return gloop::mat4{
            m[0], m[1], m[2], m[3],
            m[4], m[5], m[6], m[7],
            m[8], m[9], m[10], m[11],
            m[12], m[13], m[14], m[15]};
    }

    static gloop::vec2 __vec2(float * v) {
        return gloop::vec2{v[0], v[1]};
    }

    static gloop::mat5 __mat5(float * m) {
        return gloop::mat5{
            m[0], m[1], m[2], m[3], m[4],
            m[5], m[6], m[7], m[8], m[9],
            m[10], m[11], m[12], m[13], m[14],
            m[15], m[16], m[17], m[18], m[19],
            m[20], m[21], m[22], m[23], m[24]};
    }
}

void glgfxClear(void * ctx, float * color) {
    auto gfx = reinterpret_cast<glgfx::graphics *> (ctx);

    gfx->clear(__vec4(color));
}

void glgfxClearRect(void * ctx, float * color, int32_t x, int32_t y, uint32_t width, uint32_t height) {
    auto gfx = reinterpret_cast<glgfx::graphics *> (ctx);

    gfx->clearRect(__vec4(color), x, y, width, height);
}

void glgfxDrawLine(void * ctx, float * mvp, float * color, float * p0, float * p1) {
    auto gfx = reinterpret_cast<glgfx::graphics *> (ctx);

    gfx->drawLine(__mat4(mvp), __vec4(color), __vec2(p0), __vec2(p1));
}

void glgfxDrawRect(void * ctx, float * mvp, float * color, float * pos, float * size) {
    auto gfx = reinterpret_cast<glgfx::graphics *> (ctx);

    gfx->drawRect(__mat4(mvp), __vec4(color), __vec2(pos), __vec2(size));
}

void glgfxDrawTriangle(void * ctx, float * mvp, float * color, float * p0, float * p1, float * p2) {
    auto gfx = reinterpret_cast<glgfx::graphics *> (ctx);

    gfx->drawTriangle(__mat4(mvp), __vec4(color), __vec2(p0), __vec2(p1), __vec2(p2));
}

void glgfxFillRect(void * ctx, float * mvp, float * color, float * pos, float * size) {
    auto gfx = reinterpret_cast<glgfx::graphics *> (ctx);

    gfx->fillRect(__mat4(mvp), __vec4(color), __vec2(pos), __vec2(size));
}

void glgfxFillTriangle(void * ctx, float * mvp, float * color, float * p0, float * p1, float * p2) {
    auto gfx = reinterpret_cast<glgfx::graphics *> (ctx);

    gfx->fillTriangle(__mat4(mvp), __vec4(color), __vec2(p0), __vec2(p1), __vec2(p2));
}

void glgfxFlush(void * ctx) {
    auto gfx = reinterpret_cast<glgfx::graphics *> (ctx);

    gfx->flush();
}

void * glgfxCreateSpritesheet(const char * name) {
    return new glgfx::sprite_sheet(name);
}

void glgfxDestroySpritesheet(void * sprite_sheet) {
    auto spriteSheet = reinterpret_cast<glgfx::sprite_sheet *> (sprite_sheet);

    delete spriteSheet;
}

void glgfxSpritesheetAddInput(void * sprite_sheet, const char * name, const char * path) {
    auto spriteSheet = reinterpret_cast<glgfx::sprite_sheet *> (sprite_sheet);

    spriteSheet->addInput(name, path);
}

void glgfxSpritesheetRemoveInput(void * sprite_sheet, const char * name) {
    auto spriteSheet = reinterpret_cast<glgfx::sprite_sheet *> (sprite_sheet);

    spriteSheet->removeInput(name);
}

void glgfxInvalidateSpritesheet(void * sprite_sheet) {
    auto spriteSheet = reinterpret_cast<glgfx::sprite_sheet *> (sprite_sheet);

    spriteSheet->invalidate();
}

SDL_Surface * glgfxGetSpritesheetImage(void * sprite_sheet, unsigned int * width, unsigned int * height, void * pixels) {
    auto spriteSheet = reinterpret_cast<glgfx::sprite_sheet *> (sprite_sheet);
    auto out = spriteSheet->getImage();

    if (width != nullptr) {
        *width = out->w;
    }

    if (height != nullptr) {
        *height = out->h;
    }

    if (pixels != nullptr) {
        const auto count = out->w * out->h * sizeof (unsigned int);

        std::memcpy(pixels, out->pixels, count);
    }

    return out;
}

void * glgfxGetSpritesheetSprite(void * sprite_sheet, const char * name) {
    auto spriteSheet = reinterpret_cast<glgfx::sprite_sheet *> (sprite_sheet);

    return spriteSheet->get(name);
}

void glgfxDrawSprite(void * ctx, void * sprite, float * mvp, float * colorTransform) {
    auto gfx = reinterpret_cast<glgfx::graphics *> (ctx);

    glgfx::sprite gfxSprite;

    gfxSprite.blendMode = gfx->getBlendMode();

    if (mvp) {
        gfxSprite.transformation = __mat4(mvp);
    } else {
        gfxSprite.transformation = gloop::matrices::identity4F();
    }

    if (colorTransform) {
        gfxSprite.colorTransform = __mat5(mvp);
        gfxSprite.hasColorTransform = true;
    } else {
        gfxSprite.hasColorTransform = false;
    }
    
    if (sprite) {
        gfxSprite.textureData = reinterpret_cast<glgfx::sprite::texture_data *> (sprite);
    } else {
        gfxSprite.textureData = nullptr;
    }
    
    gfx->drawSprite(gfxSprite);
}