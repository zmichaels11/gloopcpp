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

    struct uniform_binding {
        virtual void apply() const = 0;

        inline virtual void operator()() {
            apply();
        }
    };

    struct uniform_float_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLfloat value;

        uniform_float_binding(
                const GLuint pId = 0,
                const GLuint loc = 0,
                const GLfloat value = 0.0F) :
        pId(pId), loc(loc), value(value) {
        }

        virtual void apply() const;
    };

    struct uniform_float_array_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLsizei count;
        const GLfloat * values;

        uniform_float_array_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLfloat * values = nullptr,
                const GLsizei count = 1) :
        pId(pId), loc(loc), count(count), values(values) {
        }

        virtual void apply() const;
    };

    struct uniform_int_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLint value;

        uniform_int_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLint value = 0) :
        pId(pId), loc(loc), value(value) {
        }

        virtual void apply() const;
    };

    struct uniform_int_array_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLsizei count;
        const GLint * values;

        uniform_int_array_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLint * values = nullptr, const GLsizei count = 1) :
        pId(pId), loc(loc), values(values), count(count) {
        }

        virtual void apply() const;
    };

    struct uniform_vec2_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLfloat x;
        GLfloat y;

        uniform_vec2_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLfloat x = 0.0F, const GLfloat y = 0.0F) :
        pId(pId), loc(loc), x(x), y(y) {
        }

        virtual void apply() const;
    };

    struct uniform_vec2_array_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLsizei count;
        const GLfloat * values;

        uniform_vec2_array_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLfloat * values = nullptr, const GLsizei count = 1) :
        pId(pId), loc(loc), values(values), count(count) {
        }

        virtual void apply() const;
    };

    struct uniform_vec3_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLfloat x;
        GLfloat y;
        GLfloat z;

        uniform_vec3_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLfloat x = 0.0F, const GLfloat y = 0.0F, const GLfloat z = 0.0F) :
        pId(pId), loc(loc), x(x), y(y), z(z) {
        }

        virtual void apply() const;
    };

    struct uniform_vec3_array_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLsizei count;
        const GLfloat * values;

        uniform_vec3_array_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLfloat * values = nullptr, const GLsizei count = 1) :
        pId(pId), loc(loc), values(values), count(count) {
        }

        virtual void apply() const;
    };

    struct uniform_vec4_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLfloat x;
        GLfloat y;
        GLfloat z;
        GLfloat w;

        uniform_vec4_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLfloat x = 0.0F, const GLfloat y = 0.0F, const GLfloat z = 0.0F, const GLfloat w = 0.0F) :
        pId(pId), loc(loc), x(x), y(y), z(z), w(w) {            
        }

        virtual void apply() const;
    };

    struct uniform_vec4_array_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLsizei count;
        const GLfloat * values;

        uniform_vec4_array_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLfloat * values = nullptr, const GLsizei count = 1) :
        pId(pId), loc(loc), values(values), count(count) {
        }

        virtual void apply() const;
    };

    struct uniform_ivec2_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLint x;
        GLint y;

        uniform_ivec2_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLint x = 0, const GLint y = 0) :
        pId(pId), loc(loc), x(x), y(y) {
        }

        virtual void apply() const;
    };

    struct uniform_ivec3_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLint x;
        GLint y;
        GLint z;

        uniform_ivec3_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLint x = 0, const GLint y = 0, const GLint z = 0) :
        pId(pId), loc(loc), x(x), y(y), z(z) {
        }

        virtual void apply() const;
    };

    struct uniform_ivec4_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLint x;
        GLint y;
        GLint z;
        GLint w;

        uniform_ivec4_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLint x = 0, const GLint y = 0, const GLint z = 0, const GLint w = 0) :
        pId(pId), loc(loc), x(x), y(y), z(z), w(w) {
        }

        virtual void apply() const;
    };

    struct uniform_ivec2_array_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLsizei count;
        const GLint * values;

        uniform_ivec2_array_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLint * values = nullptr, const GLsizei count = 1) :
        pId(pId), loc(loc), count(count), values(values) {
        }

        virtual void apply() const;
    };

    struct uniform_ivec3_array_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLsizei count;
        const GLint * values;

        uniform_ivec3_array_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLint * values = nullptr, const GLsizei count = 1) :
        pId(pId), loc(loc), values(values), count(count) {
        }

        virtual void apply() const;
    };

    struct uniform_ivec4_array_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLsizei count;
        const GLint * values;

        uniform_ivec4_array_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLint * values = nullptr, const GLsizei count = 1) :
        pId(pId), loc(loc), count(count), values(values) {
        }

        virtual void apply() const;
    };

    struct uniform_mat2_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLsizei count;
        const GLfloat * values;

        uniform_mat2_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLfloat * values = nullptr, const GLsizei count = 1) :
        pId(pId), loc(loc), values(values), count(count) {
        }

        virtual void apply() const;
    };

    struct uniform_mat3_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLsizei count;
        const GLfloat * values;

        uniform_mat3_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLfloat * values = nullptr, const GLsizei count = 1) :
        pId(pId), loc(loc), count(count), values(values) {
        }

        virtual void apply() const;
    };

    struct uniform_mat4_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLsizei count;
        const GLfloat * values;

        uniform_mat4_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLfloat * values = nullptr, const GLsizei count = 1) :
        pId(pId), loc(loc), values(values), count(count) {
        }

        virtual void apply() const;
    };

    class uniform_block_binding {
    private:
        GLuint _pId;
        GLuint _blockIndex;

    public:

        uniform_block_binding(const GLuint pId = 0, const GLuint blockIndex = 0) :
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
        std::map<std::string, GLuint> _uniforms;
        std::map<std::string, uniform_block_binding> _uniformBlocks;
        GLuint getUniform(const std::string& uniformName);

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

        const uniform_block_binding bindUniformBlock(const std::string& uniformName);

        const uniform_block_binding getUniformBlock(const std::string& uniformName) const;

        const uniform_float_binding getUniformFloatBinding(const std::string& uniformName, const GLfloat x);

        const uniform_float_array_binding getUniformFloatArrayBinding(const std::string& uniformName, const GLfloat * values, const GLsizei count);

        const uniform_int_binding getUniformIntBinding(const std::string& uniformName, const GLint x);

        const uniform_int_array_binding getUniformIntArrayBinding(const std::string& uniformName, const GLint * values, const GLsizei count);

        const uniform_vec2_binding getUniformVec2Binding(const std::string& uniformName, const GLfloat x, const GLfloat y);

        const uniform_vec2_array_binding getUniformVec2ArrayBinding(const std::string& uniformName, const GLfloat * values, const GLsizei count);

        const uniform_vec3_binding getUniformVec3Binding(const std::string& uniformName, const GLfloat x, const GLfloat y, const GLfloat z);

        const uniform_vec3_array_binding getUniformVec3ArrayBinding(const std::string& uniformName, const GLfloat * values, const GLsizei count);

        const uniform_vec4_binding getUniformVec4Binding(const std::string& uniformName, const GLfloat x, const GLfloat y, const GLfloat z, const GLfloat w);

        const uniform_vec4_array_binding getUniformVec4ArrayBinding(const std::string& uniformName, const GLfloat * values, const GLsizei count);

        const uniform_ivec2_binding getUniformIVec2Binding(const std::string& uniformName, const GLint x, const GLint y);

        const uniform_ivec3_binding getUniformIVec3Binding(const std::string& uniformName, const GLint x, const GLint y, const GLint z);

        const uniform_ivec4_binding getUniformIVec4Binding(const std::string& uniformName, const GLint x, const GLint y, const GLint z, const GLint w);

        const uniform_ivec2_array_binding getUniformIVec2ArrayBinding(const std::string& uniformName, const GLint * values, const GLsizei count);

        const uniform_ivec3_array_binding getUniformIVec3ArrayBinding(const std::string& uniformName, const GLint * values, const GLsizei count);

        const uniform_ivec4_array_binding getUniformIVec4ArrayBinding(const std::string& uniformName, const GLint * values, const GLsizei count);

        const uniform_mat2_binding getUniformMat2Binding(const std::string& uniformName, const GLfloat * values, const GLsizei count = 1);

        const uniform_mat3_binding getUniformMat3Binding(const std::string& uniformName, const GLfloat * values, const GLsizei count = 1);

        const uniform_mat4_binding getUniformMat4Binding(const std::string& uniformName, const GLfloat * values, const GLsizei count = 1);
    };
}

#endif /* PROGRAM_HPP */

