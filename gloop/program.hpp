/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <cstddef>
#include <map>
#include <memory>
#include <string>

#include <GL/glew.h>

#include "shader.hpp"
#include "uniforms.hpp"
#include "vertex_attributes.hpp"

namespace gloop {    

    class program {
    private:
        std::shared_ptr<GLuint> _id;
        vertex_attributes _attribs;
        std::map<std::string, GLuint> _uniforms;
        std::map<std::string, uniform::uniform_block_binding> _uniformBlocks;
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

        const uniform::uniform_block_binding bindUniformBlock(const std::string& uniformName);

        const uniform::uniform_block_binding getUniformBlock(const std::string& uniformName) const;

        const uniform::uniform_float_binding getUniformFloatBinding(const std::string& uniformName, const GLfloat x);

        const uniform::uniform_float_array_binding getUniformFloatArrayBinding(const std::string& uniformName, const GLfloat * values, const GLsizei count);

        const uniform::uniform_int_binding getUniformIntBinding(const std::string& uniformName, const GLint x);

        const uniform::uniform_int_array_binding getUniformIntArrayBinding(const std::string& uniformName, const GLint * values, const GLsizei count);

        const uniform::uniform_vec2_binding getUniformVec2Binding(const std::string& uniformName, const GLfloat x, const GLfloat y);

        const uniform::uniform_vec2_array_binding getUniformVec2ArrayBinding(const std::string& uniformName, const GLfloat * values, const GLsizei count);

        const uniform::uniform_vec3_binding getUniformVec3Binding(const std::string& uniformName, const GLfloat x, const GLfloat y, const GLfloat z);

        const uniform::uniform_vec3_array_binding getUniformVec3ArrayBinding(const std::string& uniformName, const GLfloat * values, const GLsizei count);

        const uniform::uniform_vec4_binding getUniformVec4Binding(const std::string& uniformName, const GLfloat x, const GLfloat y, const GLfloat z, const GLfloat w);

        const uniform::uniform_vec4_array_binding getUniformVec4ArrayBinding(const std::string& uniformName, const GLfloat * values, const GLsizei count);

        const uniform::uniform_ivec2_binding getUniformIVec2Binding(const std::string& uniformName, const GLint x, const GLint y);

        const uniform::uniform_ivec3_binding getUniformIVec3Binding(const std::string& uniformName, const GLint x, const GLint y, const GLint z);

        const uniform::uniform_ivec4_binding getUniformIVec4Binding(const std::string& uniformName, const GLint x, const GLint y, const GLint z, const GLint w);

        const uniform::uniform_ivec2_array_binding getUniformIVec2ArrayBinding(const std::string& uniformName, const GLint * values, const GLsizei count);

        const uniform::uniform_ivec3_array_binding getUniformIVec3ArrayBinding(const std::string& uniformName, const GLint * values, const GLsizei count);

        const uniform::uniform_ivec4_array_binding getUniformIVec4ArrayBinding(const std::string& uniformName, const GLint * values, const GLsizei count);

        const uniform::uniform_mat2_binding getUniformMat2Binding(const std::string& uniformName, const GLfloat * values, const GLsizei count = 1);

        const uniform::uniform_mat3_binding getUniformMat3Binding(const std::string& uniformName, const GLfloat * values, const GLsizei count = 1);

        const uniform::uniform_mat4_binding getUniformMat4Binding(const std::string& uniformName, const GLfloat * values, const GLsizei count = 1);
    };
}