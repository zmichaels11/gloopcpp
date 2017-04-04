/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   program.hpp
 * Author: zmichaels
 *
 * Created on April 3, 2017, 10:53 AM
 */

#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <cstddef>
#include <map>
#include <memory>
#include <string>

#include <GL/glew.h>

#include "exception.hpp"
#include "shader.hpp"
#include "vertex_attributes.hpp"

namespace gloop {

    class program_link_exception : public exception {
    public:

        program_link_exception(std::string msg) : exception(msg) {
        }
    };

    class invalid_uniform_name_exception : public exception {
    public:

        invalid_uniform_name_exception(std::string msg) : exception(msg) {
        }
    };

    class uniform_binding {
    private:
        std::shared_ptr<GLuint> _pId;
        GLuint _loc;

    public:

        uniform_binding(const std::shared_ptr<GLuint> pId = std::shared_ptr<GLuint>(nullptr), const GLuint loc = 0)
        : _pId(pId), _loc(loc) {
        }

        operator bool() const;

        bool isValid() const;

        void pushFloat(const GLfloat * v, const GLsizei count) const;

        inline void pushFloat(GLfloat x) const {
            const GLfloat v[] = {x};

            pushFloat(v, 1);
        }

        void pushVec2(const GLfloat * v, const GLsizei count) const;

        inline void pushVec2(GLfloat x, GLfloat y) const {
            const GLfloat v[] = {x, y};

            pushVec2(v, 1);
        }

        void pushVec3(const GLfloat * v, const GLsizei count) const;

        inline void pushVec3(GLfloat x, GLfloat y, GLfloat z) const {
            const GLfloat v[] = {x, y, z};

            pushVec3(v, 1);
        }

        void pushVec4(const GLfloat * v, const GLsizei count) const;

        inline void pushVec4(GLfloat x, GLfloat y, GLfloat z, GLfloat w) const {
            const GLfloat v[] = {x, y, z, w};

            pushVec4(v, 1);
        }

        void pushInt(const GLint * v, const GLsizei count) const;

        inline void pushInt(GLint x) const {
            const GLint v[] = {x};

            pushInt(v, 1);
        }

        void pushIVec2(const GLint * v, const GLsizei count) const;

        inline void pushIVec2(GLint x, GLint y) const {
            const GLint v[] = {x, y};

            pushIVec2(v, 1);
        }

        void pushIVec3(const GLint * v, const GLsizei count) const;

        inline void pushIVec3(GLint x, GLint y, GLint z) const {
            const GLint v[] = {x, y, z};

            pushIVec3(v, 1);
        }

        void pushIVec4(const GLint * v, const GLsizei count) const;

        inline void pushIVec4(GLint x, GLint y, GLint z, GLint w) const {
            const GLint v[] = {x, y, z, w};

            pushIVec4(v, 1);
        }

        void pushMat2(const GLfloat * m, const GLsizei count) const;

        void pushMat3(const GLfloat * m, const GLsizei count) const;

        void pushMat4(const GLfloat * m, const GLsizei count) const;
    };

    class uniform_block_binding {
    private:
        std::shared_ptr<GLuint> _pId;
        GLuint _blockIndex;        

    public:

        uniform_block_binding(const std::shared_ptr<GLuint> pId = std::shared_ptr<GLuint>(nullptr), const GLuint blockIndex = 0) :
        _pId(pId), _blockIndex(blockIndex) {
        }

        void pushUniformBinding(const GLuint uniformBlockBinding) const;

        bool isValid() const;

        operator bool() const;
    };

    class program {
    private:
        std::shared_ptr<GLuint> _id;
        vertex_attributes _attribs;
        std::map<std::string, uniform_binding> _uniforms;
        std::map<std::string, uniform_block_binding> _uniformBlocks;

    public:

        program() : _id(nullptr) {
        }

        void setVertexAttributes(const vertex_attributes attribs);

        void linkShaders(shader * shaders, const std::size_t count);

        GLuint getId() const;

        bool isInitialized() const;

        void use() const;

        void free();

        operator bool() const;

        operator GLuint() const;

        const uniform_binding bindUniform(const std::string& uniformName);

        const uniform_block_binding bindUniformBlock(const std::string& uniformName);

        const uniform_binding getUniform(const std::string& uniformName) const;

        const uniform_block_binding getUniformBlock(const std::string& uniformName) const;
    };
}

#endif /* PROGRAM_HPP */

