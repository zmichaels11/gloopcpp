/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <memory>
#include <utility>

#include "glgfx/sprite.hpp"
#include "glgfx/vbo_sprite_buffer.hpp"

#include "gloop/application.hpp"
#include "gloop/context.hpp"
#include "gloop/objects.hpp"
#include "gloop/tools.hpp"
#include "glgfx/blend_mode.hpp"
#include "gloop/matrices.hpp"

namespace {

    static struct sprite_test_context : gloop::context {
        glgfx::sprite::texture_data frames[10];
        std::unique_ptr<glgfx::vbo_sprite_buffer> renderer;
        gloop::texture2D texture;                
    } glContext;

    static void initFrames(sprite_test_context * ctx) {
        auto tex = gloop::tools::loadTexture("tests/data/duke.png");

        float scaleWidth = tex.view.u1;
        float scaleHeight = tex.view.v1;
        
        std::swap(ctx->texture, tex.texture);

        for (int i = 0; i < 10; i++) {
            ctx->frames[i].texture = &(ctx->texture);
            ctx->frames[i].u0 = float(i) / 10.0F * scaleWidth;
            ctx->frames[i].v0 = 0.0F;
            ctx->frames[i].u1 = float(i + 1) / 10.0F * scaleWidth;
            ctx->frames[i].v1 = scaleHeight;
        }
    }

    static void render(const gloop::application * app, gloop::context * ctx) {
        if (ctx == nullptr) {
            throw "Context is null!";
        }

        auto glCtx = reinterpret_cast<sprite_test_context *> (ctx);

        if (!glCtx->renderer) {
            glCtx->renderer = std::make_unique<glgfx::vbo_sprite_buffer>();
        }

        if (!glCtx->texture) {
            initFrames(glCtx);
        }

        static float frame = 0.0F;

        int frameSelect = (int(frame)) % 10;

        glCtx->currentClear();
        
        auto size = glCtx->currentViewport.getSize();
        float xSpacing = float(size.width) / 64.0F;
        float ySpacing = float(size.height) / 64.0F;
        
        for (int i = 0; i < 64; i++) {
            for (int j = 0; j < 64; j++) {
                glgfx::sprite sprite;

                int frameSelect = (int(frame) + i * 64 + j) % 10;
                
                sprite.textureData = glCtx->frames + frameSelect;
                sprite.hasColorTransform = false;
                sprite.blendMode = glgfx::blend_mode::NORMAL;

                {
                    static constexpr float width = 4;
                    static constexpr float height = 8;
                    static const auto projection = gloop::matrices::ortho4F(glCtx->currentViewport);                                                                                                    
                    
                    auto mSize = gloop::matrices::scale4F(width, height, 1.0F, 1.0F);
                    auto mTr = gloop::matrices::translation4F(width / 2, 0.0F, 0.0F, 1.0F);
                    auto modelView = gloop::matrices::translation4F(i * xSpacing, j * ySpacing, 0.0F, 1.0F);                    
                    auto mvp = gloop::matrices::multiply(modelView, projection);
                    auto mCat = gloop::matrices::multiply(mSize, gloop::matrices::multiply(mTr, mvp));

                    sprite.transformation = mCat;
                }
                
                glCtx->renderer->draw(sprite);        
            }
        }
        
        static auto fpsStart = SDL_GetTicks();
        static unsigned int frameCount = 0;
        
        auto now = SDL_GetTicks();                
        auto elapsedTime = now - fpsStart;
        
        if (elapsedTime > 5000) {                        
            std::cout << "FPS: " << (frameCount / 5) << std::endl;
            frameCount = 0;
            fpsStart = now;
        }
        
        frame = int(elapsedTime / 60);
        
        glCtx->renderer->flush();
        frameCount++;
    }
}

int sprite_test(int argc, char** argv) {
    gloop::application app(640, 480, "Sprite Test");

    app.setGLHints(gloop::getDefaultContextHints());

    app.setGLContext(&glContext);

    app.setMainLoop(render);

    try {
        app.start();
    } catch (const char * err) {
        std::cerr << err << std::endl;
    }

    return 0;
}