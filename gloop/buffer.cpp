/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "buffer.hpp"

#include <GL/glew.h>

#include "tools.hpp"

namespace gloop {

    buffer::~buffer() {
        free();
    }
    
    void buffer::reallocate() const {
        if (this->isInitialized()) {
            glBindBuffer(GL_ARRAY_BUFFER, _id);
            glBufferData(GL_ARRAY_BUFFER, this->_size, nullptr, static_cast<GLenum> (this->_storageHint));
        }
    }

    bool buffer::isImmutable() const {
        return this->_isImmutable;
    }

    buffer_access_hint buffer::getAccessHints() const {
        return this->_accessHints;
    }

    buffer_storage_hint buffer::getStorageHint() const {
        return this->_storageHint;
    }

    void buffer::allocateImmutable(
            const GLsizeiptr size,
            const buffer_access_hint access) {

        allocateImmutable(size, nullptr, access);
    }

    void buffer::allocateImmutable(
            const GLsizeiptr size,
            const GLvoid* data,
            const buffer_access_hint access) {

        GLuint glId = 0;

        glGenBuffers(1, &glId);
        glBindBuffer(GL_ARRAY_BUFFER, glId);
        glBufferStorage(GL_ARRAY_BUFFER, size, data, static_cast<GLbitfield> (access));

        this->_id = glId;
        this->_size = size;
        this->_isImmutable = true;
        this->_accessHints = access;
    }

    void buffer::allocate(
            const GLsizeiptr size,
            const buffer_storage_hint storageHint) {

        allocate(size, nullptr, storageHint);
    }

    void buffer::allocate(
            const GLsizeiptr size,
            const GLvoid * data,
            const buffer_storage_hint storageHint) {

        GLuint glId = 0;

        glGenBuffers(1, &glId);
        glBindBuffer(GL_ARRAY_BUFFER, glId);
        glBufferData(GL_ARRAY_BUFFER, size, data, static_cast<GLenum> (storageHint));

        this->_id = glId;
        this->_size = size;
        this->_storageHint = storageHint;
        this->_isImmutable = false;
    }

    bool buffer::isInitialized() const {
        return _id != 0;
    }

    GLuint buffer::getId() const {
        if (this->isInitialized()) {
            return _id;
        } else {
            return 0;
        }
    }

    buffer::operator GLuint() {
        return this->getId();
    }

    buffer::operator bool() const {
        return this->isInitialized();
    }

    void buffer::free() {
        if (this->isInitialized()) {
            glDeleteBuffers(1, &_id);
            this->_id = 0;
        }
    }

    void buffer::setData(const GLintptr offset, const GLsizeiptr size, const GLvoid* data) {
        glBindBuffer(GL_ARRAY_BUFFER, _id);
        glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
    }

    void buffer::getData(const GLintptr offset, const GLsizeiptr size, GLvoid* data) const {
        if (this->isInitialized()) {
            glBindBuffer(GL_ARRAY_BUFFER, _id);
            glGetBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
        }
    }

    void * buffer::map(GLintptr offset, GLsizeiptr length, buffer_access_hint accessHints) {
        if (this->isInitialized()) {
            glBindBuffer(GL_ARRAY_BUFFER, _id);

            return glMapBufferRange(GL_ARRAY_BUFFER, offset, length, static_cast<GLbitfield> (accessHints));
        } else {
            return nullptr;
        }
    }

    void buffer::unmap() const {
        if (this->isInitialized()) {
            glBindBuffer(GL_ARRAY_BUFFER, _id);
            glUnmapBuffer(GL_ARRAY_BUFFER);
        }
    }

    void buffer::bind(const gloop::buffer_target target) const {
        if (this->isInitialized()) {
            glBindBuffer(static_cast<GLenum> (target), _id);
        }
    }

    void buffer::blockBind(const buffer_target target, const GLuint binding, const GLintptr offset, GLintptr size) const {
        if (this->isInitialized()) {
            glBindBufferRange(static_cast<GLenum> (target), binding, _id, offset, size);
        }
    }

    void buffer::blockBind(const buffer_target target, const GLuint binding) const {
        if (this->isInitialized()) {
            glBindBufferBase(static_cast<GLenum> (target), binding, _id);
        }
    }
}