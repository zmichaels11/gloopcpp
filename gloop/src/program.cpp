/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "program.hpp"

#include <cstddef>

#include <memory>
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

		auto infoLog = std::make_unique<gloop::char_t[]> (maxLength);

        gloop::wrapper::getProgramInfoLog(program, maxLength, &logLength, infoLog.get());

        std::string out;

        if (logLength > 0) {
            out = std::string(reinterpret_cast<char *> (infoLog.get()));
        } else {
            out = "No shader log!";
        }

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
    
    const uniform::uniform_block_binding gloop::program::getUniformBlock(const std::string& uniformName) const {
        auto it = this->_uniformBlocks.find(uniformName);

        if (it != this->_uniformBlocks.end()) {
            return it->second;
        } else {
            return gloop::uniform::uniform_block_binding();
        }
    }

    const uniform::uniform_block_binding gloop::program::bindUniformBlock(const std::string& uniformName) {
		if (isGLES2()) {
			gloop_throw(gloop::exception::invalid_operation_exception("GetUniformBlockIndex is not supported!"));
		}

        auto out = this->getUniformBlock(uniformName);

        if (out) {
            return out;
        }

        auto glId = this->getId();
        gloop::uint_t glIndex = wrapper::getUniformBlockIndex(glId, uniformName.c_str());

        if (glIndex == gloop::wrapper::INVALID_INDEX) {
            gloop_throw(gloop::exception::invalid_uniform_name_exception("Could not find uniform block name: " + uniformName));
        }
        
        out = gloop::uniform::uniform_block_binding(glId, glIndex);

        this->_uniformBlocks[uniformName] = out;

        return out;
    }
}
