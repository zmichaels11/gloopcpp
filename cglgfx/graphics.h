/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   graphics.h
 * Author: zmichaels
 *
 * Created on April 27, 2017, 5:10 PM
 */

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>

#include <SDL2/SDL_surface.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

void * glgfxGetCurrentContext() ;

void glgfxDestroyContext(void * ctx);

uint32_t glgfxGetBlendMode(void * ctx) ;

void glgfxSetBlendMode(void * ctx, uint32_t blend);

void glgfxClear(void * ctx, float * color);

void glgfxClearRect(void * ctx, float * color, int32_t x, int32_t y, uint32_t width, uint32_t height);

void glgfxDrawLine(void * ctx, float * mvp, float * color, float * p0, float * p1) ;

void glgfxDrawRect(void * ctx, float * mvp, float * color, float * pos, float * size);

void glgfxDrawTriangle(void * ctx, float * mvp, float * color, float * p0, float * p1, float * p2);

void glgfxFillRect(void * ctx, float * mvp, float * color, float * pos, float * size);

void glgfxFillTriangle(void * ctx, float * mvp, float * color, float * p0, float * p1, float * p2);

void glgfxFlush(void * ctx);

void * glgfxCreateSpritesheet(const char * name);

void glgfxDestroySpritesheet(void * sprite_sheet);

void glgfxSpritesheetAddInput(void * sprite_sheet, const char * name, const char * path);

void glgfxSpriteSheetRemoveInput(void * sprite_sheet, const char * name);

void glgfxInvalidateSpritesheet(void * sprite_sheet);

SDL_Surface * glgfxGetSpritesheetImage(void * sprite_sheet, unsigned int * width, unsigned int * height, void * pixels);

void * glgfxGetSpritesheetSprite(void * sprite_sheet, const char * name);

void glgfxDrawSprite(void * ctx, void * sprite, float * mvp, float * colorTransform);

#ifdef __cplusplus
}
#endif

#endif /* GRAPHICS_H */

