/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <memory>
#include <utility>
#include <string>
#include <sstream>

#include "gloop.hpp"
#include "glgfx.hpp"

namespace {

    static struct sprite_test_context : gloop::context {        
        std::unique_ptr<glgfx::sprite_sheet> sprites;
    } glContext;

    static void initSprites(sprite_test_context * ctx) {
        ctx->sprites.reset(new glgfx::sprite_sheet("duke_wave"));
        
        const std::string baseName = "duke";
        const std::string basePath = "tests/data/duke";
        
        for (int i = 0; i < 10; i++) {
            std::ostringstream name;
            std::ostringstream path;
            
            name << baseName << i;
            path << basePath << i << ".png";
            
            ctx->sprites->addInput(name.str(), path.str());
        }
    }

    static void render(const gloop::application * app, gloop::context * ctx) {
        if (ctx == nullptr) {
            throw "Context is null!";
        }

        auto glCtx = reinterpret_cast<sprite_test_context *> (ctx);

        static bool texturesInit = false;
        
        if (!texturesInit) {
            initSprites(glCtx);
            texturesInit = true;
            //initFrames(glCtx);
        }

        static float frame = 0.0F;

        int frameSelect = (int(frame)) % 10;        

        auto size = glCtx->currentViewport.getSize();
        float xSpacing = float(size.width) / 8.0F;
        float ySpacing = float(size.height) / 8.0F;
        static const auto projection = gloop::matrices::ortho4F(glCtx->currentViewport);

        glgfx::graphics gfx(gloop::framebuffer::getDefaultFramebuffer(), glCtx->currentViewport);
        
        gfx.clear();

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                glgfx::sprite sprite;

                int frameSelect = (int(frame) + i * 8 + j) % 10;

                const static std::string ids[] = {"duke0", "duke1", "duke2", "duke3", "duke4", "duke5", "duke6", "duke7", "duke8", "duke9"};
                
                sprite.textureData = glCtx->sprites->get(ids[frameSelect]);
                sprite.hasColorTransform = false;
                sprite.blendMode = glgfx::blend_mode::NORMAL;

                {
                    static constexpr float width = 32;
                    static constexpr float height = 64;

                    auto mSize = gloop::matrices::scale4F(width, height, 1.0F, 1.0F);
                    auto mTr = gloop::matrices::translation4F(width / 2, 0.0F, 0.0F, 1.0F);
                    auto modelView = gloop::matrices::translation4F(i * xSpacing, j * ySpacing, 0.0F, 1.0F);
                    auto mvp = gloop::matrices::multiply(modelView, projection);
                    auto mCat = gloop::matrices::multiply(mSize, gloop::matrices::multiply(mTr, mvp));

                    sprite.transformation = mCat;
                }

                gfx.drawSprite(sprite);
            }
        }

        gfx.drawLine(
                projection,
                gloop::vec4{1.0F, 0.0F, 0.0F, 1.0F},
                gloop::vec2{0.0F, 0.0F},
                gloop::vec2{128.0F, 128.0F});
        
        gfx.drawRect(projection, gloop::vec4{1.0F, 1.0F, 0.0F, 1.0F}, gloop::vec2{256.0F, 256.0F}, gloop::vec2{32.0F, 32.0F});
        
        gfx.fillRect(projection, gloop::vec4{0.0F, 1.0F, 0.0F, 1.0F}, gloop::vec2{0.0F, 0.0F}, gloop::vec2{32.0F, 32.0F});

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
        frameCount++;
    }
}

int main(int argc, char** argv) {
    gloop::application app(640, 480, "Sprite Test");

    app.setGLHints(gloop::wrapper::getDefaultContextHints());

    app.setGLContext(&glContext);

    app.setMainLoop(render);

	gloop::vec2 x = {1.0F, 2.0F};
	gloop::vec2 y = {2.0F, 3.0F};
	
	std::cout << "z: " << (x + y) << std::endl;

    try {
        app.start();
    } catch (const char * err) {
        std::cerr << err << std::endl;
    }

    return 0;
}
