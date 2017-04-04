/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "program.hpp"

#include <iostream>

#include <GL/glew.h>

void gloop::uniform_float_binding::apply() const {
    glUseProgram(pId);
    glUniform1f(loc, value);
}

void gloop::uniform_float_array_binding::apply() const {
    glUseProgram(pId);
    glUniform1fv(loc, count, values);
}

void gloop::uniform_int_binding::apply() const {
    glUseProgram(pId);
    glUniform1i(loc, value);
}

void gloop::uniform_int_array_binding::apply() const {
    glUseProgram(pId);
    glUniform1iv(loc, count, values);
}

void gloop::uniform_ivec2_binding::apply() const {
    glUseProgram(pId);
    glUniform2i(loc, x, y);
}

void gloop::uniform_ivec2_array_binding::apply() const {
    glUseProgram(pId);
    glUniform2iv(loc, count, values);
}

void gloop::uniform_ivec3_binding::apply() const {
    glUseProgram(pId);
    glUniform3i(loc, x, y, z);
}

void gloop::uniform_ivec3_array_binding::apply() const {
    glUseProgram(pId);
    glUniform3iv(loc, count, values);
}

void gloop::uniform_ivec4_binding::apply() const {
    glUseProgram(pId);
    glUniform4i(loc, x, y, z, w);
}

void gloop::uniform_ivec4_array_binding::apply() const {
    glUseProgram(pId);
    glUniform4iv(loc, count, values);
}

void gloop::uniform_vec2_binding::apply() const {
    glUseProgram(pId);
    glUniform2f(loc, x, y);
}

void gloop::uniform_vec2_array_binding::apply() const {
    glUseProgram(pId);
    glUniform2fv(loc, count, values);
}

void gloop::uniform_vec3_binding::apply() const {
    glUseProgram(pId);
    glUniform3f(loc, x, y, z);
}

void gloop::uniform_vec3_array_binding::apply() const {
    glUseProgram(pId);
    glUniform3fv(loc, count, values);
}

void gloop::uniform_vec4_binding::apply() const {        
    glUseProgram(pId);
    glUniform4f(loc, x, y, z, w);
}

void gloop::uniform_vec4_array_binding::apply() const {
    glUseProgram(pId);
    glUniform4fv(loc, count, values);
}

void gloop::uniform_mat2_binding::apply() const {
    glUseProgram(pId);
    glUniformMatrix2fv(loc, count, GL_FALSE, values);
}

void gloop::uniform_mat3_binding::apply() const {
    glUseProgram(pId);
    glUniformMatrix3fv(loc, count, GL_FALSE, values);
}

void gloop::uniform_mat4_binding::apply() const {
    glUseProgram(pId);
    glUniformMatrix4fv(loc, count, GL_FALSE, values);
}

GLuint gloop::program::getUniform(const std::string& uniformName) {
    auto it = this->_uniforms.find(uniformName);

    if (it != this->_uniforms.end()) {
        return it->second;
    } else {
        GLint loc = glGetUniformLocation(*_id, uniformName.c_str());

        if (loc == -1) {
            throw gloop::invalid_uniform_name_exception("Could not find uniform with name: " + uniformName);
        } else {
            this->_uniforms[uniformName] = loc;

            return loc;
        }
    }
}

const gloop::uniform_float_binding gloop::program::getUniformFloatBinding(const std::string& uniformName, const GLfloat x) {        
    return {*_id, getUniform(uniformName), x};
}

const gloop::uniform_int_binding gloop::program::getUniformIntBinding(const std::string& uniformName, const GLint x) {
    return {*_id, getUniform(uniformName), x};
}

const gloop::uniform_vec2_binding gloop::program::getUniformVec2Binding(const std::string& uniformName, const GLfloat x, const GLfloat y) {
    return {*_id, getUniform(uniformName), x, y};
}

const gloop::uniform_vec3_binding gloop::program::getUniformVec3Binding(const std::string& uniformName, const GLfloat x, const GLfloat y, const GLfloat z) {
    return {*_id, getUniform(uniformName), x, y, z};
}

const gloop::uniform_vec4_binding gloop::program::getUniformVec4Binding(const std::string& uniformName, const GLfloat x, const GLfloat y, const GLfloat z, const GLfloat w) {
    return {*_id, getUniform(uniformName), x, y, z, w};
}

const gloop::uniform_ivec2_binding gloop::program::getUniformIVec2Binding(const std::string& uniformName, const GLint x, const GLint y) {
    return {*_id, getUniform(uniformName), x, y};
}

const gloop::uniform_ivec3_binding gloop::program::getUniformIVec3Binding(const std::string& uniformName, const GLint x, const GLint y, const GLint z) {
    return {*_id, getUniform(uniformName), x, y, z};
}

const gloop::uniform_ivec4_binding gloop::program::getUniformIVec4Binding(const std::string& uniformName, const GLint x, const GLint y, const GLint z, const GLint w) {
    return {*_id, getUniform(uniformName), x, y, z, w};
}

const gloop::uniform_mat2_binding gloop::program::getUniformMat2Binding(const std::string& uniformName, const GLfloat* values, const GLsizei count) {
    return {*_id, getUniform(uniformName), values, count};
}

const gloop::uniform_mat3_binding gloop::program::getUniformMat3Binding(const std::string& uniformName, const GLfloat* values, const GLsizei count) {
    return {*_id, getUniform(uniformName), values, count};
}

const gloop::uniform_mat4_binding gloop::program::getUniformMat4Binding(const std::string& uniformName, const GLfloat* values, const GLsizei count ) {
    return {*_id, getUniform(uniformName), values, count};
}

const gloop::uniform_float_array_binding gloop::program::getUniformFloatArrayBinding(const std::string& uniformName, const GLfloat* values, const GLsizei count) {
    return {*_id, getUniform(uniformName), values, count};
}

const gloop::uniform_int_array_binding gloop::program::getUniformIntArrayBinding(const std::string& uniformName, const GLint* values, const GLsizei count) {
    return {*_id, getUniform(uniformName), values, count};
}

const gloop::uniform_vec2_array_binding gloop::program::getUniformVec2ArrayBinding(const std::string& uniformName, const GLfloat* values, const GLsizei count) {
    return {*_id, getUniform(uniformName), values, count};
}

const gloop::uniform_vec3_array_binding gloop::program::getUniformVec3ArrayBinding(const std::string& uniformName, const GLfloat* values, const GLsizei count) {
    return {*_id, getUniform(uniformName), values, count};
}

const gloop::uniform_vec4_array_binding gloop::program::getUniformVec4ArrayBinding(const std::string& uniformName, const GLfloat* values, const GLsizei count) {
    return {*_id, getUniform(uniformName), values, count};
}

const gloop::uniform_ivec2_array_binding gloop::program::getUniformIVec2ArrayBinding(const std::string& uniformName, const GLint* values, const GLsizei count) {
    return {*_id, getUniform(uniformName), values, count};
}

const gloop::uniform_ivec3_array_binding gloop::program::getUniformIVec3ArrayBinding(const std::string& uniformName, const GLint* values, const GLsizei count) {
    return {*_id, getUniform(uniformName), values, count};
}

const gloop::uniform_ivec4_array_binding gloop::program::getUniformIVec4ArrayBinding(const std::string& uniformName, const GLint* values, const GLsizei count) {
    return {*_id, getUniform(uniformName), values, count};
}