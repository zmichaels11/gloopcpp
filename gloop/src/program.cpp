/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "program.hpp"

#include <cstddef>
#include <string>

#include "exception/invalid_operation_exception.hpp"
#include "exception/invalid_uniform_name_exception.hpp"
#include "exception/program_link_exception.hpp"
#include "gl_traits.hpp"
#include "gloop_throw.hpp"
#include "shader.hpp"
#include "uniform/uniform_block_binding.hpp"
#include "vertex_attributes.hpp"
#include "wrapper/gl.hpp"
#include "wrapper/shaders_and_programs.hpp"

namespace {

    static std::string getProgramLog(gloop::uint_t program) {
        gloop::int_t logLength = 0;
        gloop::int_t maxLength = 0;

        gloop::wrapper::getProgramiv(program, gloop::wrapper::INFO_LOG_LENGTH, &maxLength);        

        auto infoLog = new gloop::char_t[maxLength];

        gloop::wrapper::getProgramInfoLog(program, maxLength, &logLength, infoLog);

        std::string out;

        if (logLength > 0) {
            out = std::string(reinterpret_cast<char *> (infoLog));
        } else {
            out = "No shader log!";
        }

        delete[] infoLog;

        return out;
    }
}

namespace gloop {
    
    program::program() {
        _id = 0;
        _attribs = std::make_unique<vertex_attributes>();        
    }
    
    program::~program() {
        free();
    }
    
    const vertex_attributes& program::getVertexAttributes() const {
        return *_attribs;
    }

    void program::use() const {
        if (this->isInitialized()) {
            gloop::wrapper::useProgram(getId());
        } else {
            gloop_throw(gloop::exception::program_link_exception("Program is not linked!"));
        }
    }

    gloop::uint_t program::getId() const {
        if (this->isInitialized()) {
            return this->_id;
        } else {
            return 0;
        }
    }

    bool program::isInitialized() const {
        return _id != 0;
    }

    void program::linkShaders(shader * shaders, const std::size_t count) {        
        auto glId = gloop::wrapper::createProgram();

        this->_attribs->bindAttributes(glId);        
        
        for (auto it = shaders; it != shaders + count; it++) {
            gloop::wrapper::attachShader(glId, it->getId());
        }                

        gloop::wrapper::linkProgram(glId);               

        for (auto it = shaders; it != shaders + count; it++) {
            gloop::wrapper::detachShader(glId, it->getId());
        }

        gloop::int_t isLinked = gloop::wrapper::FALSE;

        gloop::wrapper::getProgramiv(glId, gloop::wrapper::LINK_STATUS, &isLinked);

        if (isLinked) {
            this->_id = glId;            
        } else {
            auto infoLog = getProgramLog(glId);
            
            gloop::wrapper::deleteProgram(glId);
            gloop_throw(gloop::exception::program_link_exception(infoLog));
        }
    }

    void program::free() {
        if (this->isInitialized()) {
            gloop::wrapper::deleteProgram(this->_id);
            this->_id = 0;
        }
    }

    program::operator bool() const {
        return this->isInitialized();
    }

    void program::setVertexAttributes(const vertex_attributes& attribs) {
        if (this->isInitialized()) {            
            gloop_throw(gloop::exception::program_link_exception("Cannot set vertex attributes if program is already linked!"));
        }

        this->_attribs = std::make_unique<vertex_attributes> (attribs);
    }

    namespace {
#define GLEW 1
#define GLES2 2
#define GLES3 3
#ifndef GL
#define __GL_NOT_DEFINED
#define GL 0
#endif
      
        static constexpr bool supports_uniform_block_binding = (GL == GLEW || GL == GLES3);
        
        template <bool isSupported = supports_uniform_block_binding, typename std::enable_if<isSupported, void * >::type = nullptr>
        static inline gloop::uint_t __getUniformBlockIndex(gloop::uint_t pid, const gloop::char_t * uName) {
            return wrapper::getUniformBlockIndex(pid, uName);
        }
        
        template <bool isSupported = supports_uniform_block_binding, typename std::enable_if<!isSupported, void * >::type = nullptr>
        static inline gloop::uint_t __getUniformBlockIndex(gloop::uint_t pid, const gloop::char_t * uName) {
            gloop_throw(gloop::exception::invalid_operation_exception("GetUniformBlockIndex is not supported!"));
        }
      
#ifdef __GL_NOT_DEFINED
#undef GL
#undef __GL_NOT_DEFINED
#endif
#undef GLES3
#undef GLES2
#undef GLEW
    }
    
    const uniform::uniform_block_binding gloop::program::getUniformBlock(const std::string& uniformName) const {
        auto it = this->_uniformBlocks.find(uniformName);

        if (it != this->_uniformBlocks.end()) {
            return it->second;
        } else {
            return gloop::uniform::uniform_block_binding();
        }
    }

    const uniform::uniform_block_binding gloop::program::bindUniformBlock(const std::string& uniformName) {
        auto out = this->getUniformBlock(uniformName);

        if (out) {
            return out;
        }

        auto glId = this->getId();
        gloop::uint_t glIndex = __getUniformBlockIndex(glId, uniformName.c_str());

        if (glIndex == gloop::wrapper::INVALID_INDEX) {
            gloop_throw(gloop::exception::invalid_uniform_name_exception("Could not find uniform block name: " + uniformName));
        }
        
        out = gloop::uniform::uniform_block_binding(glId, glIndex);

        this->_uniformBlocks[uniformName] = out;

        return out;
    }
}
