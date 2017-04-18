#include <iostream>
#include <memory>
#include <utility>

#include <SDL2/SDL_surface.h>

#include "gloop/application.hpp"
#include "gloop/buffer.hpp"
#include "gloop/draw/arrays.hpp"
#include "gloop/draw/call.hpp"
#include "gloop/exception/invalid_value_exception.hpp"
#include "gloop/program.hpp"
#include "gloop/shader.hpp"
#include "gloop/texture2D.hpp"
#include "gloop/tools.hpp"
#include "gloop/vertex_attributes.hpp"
#include "gloop/vertex_array.hpp"

namespace {

    static struct lesson06_context : gloop::context {
        gloop::program program;

        gloop::vertex_array vao;
        gloop::vertex_attributes attribs;

        gloop::buffer vPos;
        gloop::buffer vUVs;

        gloop::texture2D texture;

        struct model {
            gloop::program * program;
            gloop::texture2D * texture;
            gloop::vertex_array * vertexArray;

            std::unique_ptr<gloop::draw::draw_call> drawCall;
            std::unique_ptr<gloop::uniform::uniform_binding> uniforms;

            inline void render() const {
                program->use();
                vertexArray->bind();
                texture->bind(0);
                (*uniforms)();
                (*drawCall)();
            }
        } model;
    } glContext;
}

namespace {

    static void initProgram(lesson06_context * glCtx) {
        gloop::shader shaders[]{
            gloop::shader::makeVertexShader("tests/texture.vert"),
            gloop::shader::makeFragmentShader("tests/texture.frag")
        };

        glCtx->attribs.setLocation("vPos", 0);
        glCtx->attribs.setLocation("vUVs", 1);
        glCtx->program.setVertexAttributes(glCtx->attribs);
        glCtx->program.linkShaders(shaders, 2);
    }

    static void initVertexArray(lesson06_context * glCtx) {
        glCtx->vPos.allocate(
                gloop::enums::buffer_target::ARRAY,
                std::array<gloop::float_t, 8>{
            -0.5f, -0.5f,
            0.5f, -0.5f,
            -0.5f, 0.5f,
            0.5f, 0.5f
        });

        glCtx->vUVs.allocate(
                gloop::enums::buffer_target::ARRAY,
                std::array<gloop::float_t, 8>{
            0.0F, 1.0F,
            1.0F, 1.0F,
            0.0F, 0.0F,
            1.0F, 0.0F
        });

        glCtx->vao.addBinding(
                glCtx->attribs["vPos"]
                .bindBuffer(&(glCtx->vPos), gloop::enums::vertex_attribute_type::VEC2));

        glCtx->vao.addBinding(
                glCtx->attribs["vUVs"]
                .bindBuffer(&(glCtx->vUVs), gloop::enums::vertex_attribute_type::VEC2));        
    }
    
    static void initTexture(lesson06_context * glCtx) {
        auto img = gloop::tools::loadImage("tests/data/nehe.bmp");
        
        gloop::texture2D::load(glCtx->texture, img);
    }
    
    static void initModel(lesson06_context * glCtx) {
        glCtx->model.program = &(glCtx->program);
        glCtx->model.vertexArray = &(glCtx->vao);
        
        gloop::draw::arrays drawCall;
        
        drawCall.drawMode = gloop::draw::mode::TRIANGLE_STRIP;
        drawCall.count = 4;
        drawCall.first = 0;
        
        glCtx->model.drawCall = std::make_unique<gloop::draw::arrays>(drawCall);        
        glCtx->currentClear = glCtx->currentClear.withColor(0.5F, 0.5F, 0.6F, 1.0F);
        
        gloop::uniform::uniform_int_binding setTexture;
        
        setTexture = glCtx->program.getUniformIntBinding("fTexture", 0);
        
        glCtx->model.uniforms = std::make_unique<gloop::uniform::uniform_int_binding> (setTexture);
        
        glCtx->model.texture = &(glCtx->texture);        
    }

    static void render(const gloop::application * app, gloop::context * ctx) {
        if (ctx == nullptr) {
            throw gloop::exception::invalid_value_exception("Context is null!");
        }

        auto glCtx = reinterpret_cast<lesson06_context *> (ctx);

        if (!glCtx->program) {
            initProgram(glCtx);
        }
        
        if (!glCtx->vao) {
            initVertexArray(glCtx);
        }

        if (!glCtx->texture) {
            initTexture(glCtx);
        }

        if (!glCtx->model.program) {
            initModel(glCtx);
        }
                
        gloop::tools::assertGLError();
        
        glCtx->currentClear();
        glCtx->model.render();
    }
}

int lesson06(int argc, char** argv) {
    gloop::application app(640, 480, "NEHE: Lesson06");

    {
        gloop::context_hints hints;

        hints.profile = gloop::context_profile::ES;
        hints.version.major = 2;
        hints.version.minor = 0;
        hints.swapInterval = 1;
        hints.doubleBuffer = true;

        app.setGLHints(hints);
    }

    app.setGLContext(&glContext);

    app.setMainLoop(render);
    
    try {
        app.start();
    } catch (const char * err) {
        std::cerr << err << std::endl;
    }
    
    return 0;
}