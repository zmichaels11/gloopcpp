/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "program.hpp"

#include <iostream>

#include <GL/glew.h>

#include "exception/invalid_uniform_name_exception.hpp"

namespace gloop {

    GLuint program::getUniform(const std::string& uniformName) {
        auto it = this->_uniforms.find(uniformName);

        if (it != this->_uniforms.end()) {
            return it->second;
        } else {
            GLint loc = glGetUniformLocation(*_id, uniformName.c_str());

            if (loc == -1) {
                throw gloop::exception::invalid_uniform_name_exception("Could not find uniform with name: " + uniformName);
            } else {
                this->_uniforms[uniformName] = loc;

                return loc;
            }
        }
    }

    const uniform_float_binding program::getUniformFloatBinding(
            const std::string& uniformName,
            const GLfloat x) {

        return {*_id, getUniform(uniformName), x};
    }

    const uniform_int_binding program::getUniformIntBinding(
            const std::string& uniformName,
            const GLint x) {

        return {*_id, getUniform(uniformName), x};
    }

    const uniform_vec2_binding program::getUniformVec2Binding(
            const std::string& uniformName,
            const GLfloat x, const GLfloat y) {

        return {*_id, getUniform(uniformName), x, y};
    }

    const uniform_vec3_binding gloop::program::getUniformVec3Binding(
            const std::string& uniformName,
            const GLfloat x, const GLfloat y, const GLfloat z) {

        return {*_id, getUniform(uniformName), x, y, z};
    }

    const uniform_vec4_binding gloop::program::getUniformVec4Binding(
            const std::string& uniformName,
            const GLfloat x, const GLfloat y, const GLfloat z, const GLfloat w) {

        return {*_id, getUniform(uniformName), x, y, z, w};
    }

    const uniform_ivec2_binding program::getUniformIVec2Binding(
            const std::string& uniformName,
            const GLint x, const GLint y) {

        return {*_id, getUniform(uniformName), x, y};
    }

    const uniform_ivec3_binding program::getUniformIVec3Binding(
            const std::string& uniformName,
            const GLint x, const GLint y, const GLint z) {

        return {*_id, getUniform(uniformName), x, y, z};
    }

    const uniform_ivec4_binding program::getUniformIVec4Binding(
            const std::string& uniformName,
            const GLint x, const GLint y, const GLint z, const GLint w) {

        return {*_id, getUniform(uniformName), x, y, z, w};
    }

    const uniform_mat2_binding program::getUniformMat2Binding(
            const std::string& uniformName,
            const GLfloat* values,
            const GLsizei count) {

        return {*_id, getUniform(uniformName), values, count};
    }

    const uniform_mat3_binding program::getUniformMat3Binding(
            const std::string& uniformName,
            const GLfloat* values,
            const GLsizei count) {

        return {*_id, getUniform(uniformName), values, count};
    }

    const uniform_mat4_binding program::getUniformMat4Binding(
            const std::string& uniformName,
            const GLfloat* values,
            const GLsizei count) {

        return {*_id, getUniform(uniformName), values, count};
    }

    const uniform_float_array_binding program::getUniformFloatArrayBinding(
            const std::string& uniformName,
            const GLfloat* values,
            const GLsizei count) {

        return {*_id, getUniform(uniformName), values, count};
    }

    const uniform_int_array_binding program::getUniformIntArrayBinding(
            const std::string& uniformName,
            const GLint* values,
            const GLsizei count) {

        return {*_id, getUniform(uniformName), values, count};
    }

    const uniform_vec2_array_binding program::getUniformVec2ArrayBinding(
            const std::string& uniformName,
            const GLfloat* values,
            const GLsizei count) {

        return {*_id, getUniform(uniformName), values, count};
    }

    const uniform_vec3_array_binding program::getUniformVec3ArrayBinding(
            const std::string& uniformName,
            const GLfloat* values,
            const GLsizei count) {

        return {*_id, getUniform(uniformName), values, count};
    }

    const uniform_vec4_array_binding program::getUniformVec4ArrayBinding(
            const std::string& uniformName,
            const GLfloat* values,
            const GLsizei count) {

        return {*_id, getUniform(uniformName), values, count};
    }

    const uniform_ivec2_array_binding program::getUniformIVec2ArrayBinding(
            const std::string& uniformName,
            const GLint* values,
            const GLsizei count) {

        return {*_id, getUniform(uniformName), values, count};
    }

    const uniform_ivec3_array_binding program::getUniformIVec3ArrayBinding(
            const std::string& uniformName,
            const GLint* values,
            const GLsizei count) {

        return {*_id, getUniform(uniformName), values, count};
    }

    const uniform_ivec4_array_binding program::getUniformIVec4ArrayBinding(
            const std::string& uniformName,
            const GLint* values,
            const GLsizei count) {

        return {*_id, getUniform(uniformName), values, count};
    }
}