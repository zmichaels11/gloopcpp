/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "program.hpp"

#include <cstddef>
#include <string>

#include <GL/glew.h>

#include "exception/invalid_uniform_name_exception.hpp"
#include "exception/program_link_exception.hpp"

#include "shader.hpp"
#include "vertex_attributes.hpp"

namespace {

    static std::string getProgramLog(GLuint program) {
        GLint logLength = 0;
        GLint maxLength = 0;

        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

        GLchar * infoLog = new GLchar[maxLength];

        glGetProgramInfoLog(program, maxLength, &logLength, infoLog);

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
    
    program::~program() {
        free();
    }

    void program::use() const {
        if (this->isInitialized()) {
            glUseProgram(this->getId());
        } else {
            throw gloop::exception::program_link_exception("Program is not linked!");
        }
    }

    GLuint program::getId() const {
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
        auto glId = glCreateProgram();

        this->_attribs.bindAttributes(glId);

        for (std::size_t i = 0; i < count; i++) {
            glAttachShader(glId, shaders[i]);
        }

        glLinkProgram(glId);

        for (std::size_t i = 0; i < count; i++) {
            glDetachShader(glId, shaders[i]);
        }

        GLint isLinked = GL_FALSE;

        glGetProgramiv(glId, GL_LINK_STATUS, &isLinked);

        if (isLinked == GL_FALSE) {
            std::string infoLog = getProgramLog(glId);

            glDeleteProgram(glId);
            throw gloop::exception::program_link_exception(infoLog);
        } else {
            this->_id = glId;
        }
    }

    void program::free() {
        if (this->isInitialized()) {
            glDeleteProgram(this->_id);
            this->_id = 0;
        }
    }

    program::operator bool() const {
        return this->isInitialized();
    }

    program::operator GLuint() const {
        return this->getId();
    }

    void program::setVertexAttributes(const vertex_attributes attribs) {
        if (this->isInitialized()) {
            throw gloop::exception::program_link_exception("Cannot set vertex attributes if program is already linked!");
        }

        this->_attribs = attribs;
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
        GLuint glIndex = glGetUniformBlockIndex(glId, uniformName.c_str());

        if (glIndex == GL_INVALID_INDEX) {
            throw gloop::exception::invalid_uniform_name_exception("Could not find uniform block name: " + uniformName);
        }
        
        out = gloop::uniform::uniform_block_binding(glId, glIndex);

        this->_uniformBlocks[uniformName] = out;

        return out;
    }
}