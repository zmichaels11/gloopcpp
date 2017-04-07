/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "buffer.hpp"

#include <GL/glew.h>

#include "enums/buffer_target.hpp"
#include "enums/buffer_storage_hint.hpp"
#include "glint.hpp"
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

    bitfields::buffer_immutable_storage_hint buffer::getImmutableStorageHints() const {
        return this->_immutableStorageHints;
    }

    enums::buffer_storage_hint buffer::getStorageHint() const {
        return this->_storageHint;
    }

    void buffer::allocateImmutable(
            const gloop::sizeiptr_t size,
            const bitfields::buffer_immutable_storage_hint access) {

        allocateImmutable(size, nullptr, access);
    }

    void buffer::allocateImmutable(
            const gloop::sizeiptr_t size,
            const void* data,
            const bitfields::buffer_immutable_storage_hint access) {

        GLuint glId = 0;

        glGenBuffers(1, &glId);
        glBindBuffer(GL_ARRAY_BUFFER, glId);
        glBufferStorage(GL_ARRAY_BUFFER, size, data, static_cast<GLbitfield> (access));

        this->_id = glId;
        this->_size = size;
        this->_isImmutable = true;
        this->_immutableStorageHints = access;
        this->_storageHint = static_cast<enums::buffer_storage_hint> (0);
    }

    void buffer::allocate(
            const gloop::sizeiptr_t size,
            const enums::buffer_storage_hint storageHint) {

        allocate(size, nullptr, storageHint);
    }

    void buffer::allocate(
            const gloop::sizeiptr_t size,
            const void * data,
            const enums::buffer_storage_hint storageHint) {

        GLuint glId = 0;

        glGenBuffers(1, &glId);
        glBindBuffer(GL_ARRAY_BUFFER, glId);
        glBufferData(GL_ARRAY_BUFFER, size, data, static_cast<GLenum> (storageHint));

        this->_id = glId;
        this->_size = size;
        this->_storageHint = storageHint;
        this->_immutableStorageHints = static_cast<bitfields::buffer_immutable_storage_hint> (0);
        this->_isImmutable = false;
    }

    bool buffer::isInitialized() const {
        return _id != 0;
    }

    gloop::uint_t buffer::getId() const {
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

    void buffer::setData(
            const gloop::intptr_t offset,
            const gloop::sizeiptr_t size,
            const void * data) {

        glBindBuffer(GL_ARRAY_BUFFER, _id);
        glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
    }

    void buffer::getData(
            const gloop::intptr_t offset,
            const gloop::sizeiptr_t size,
            void * data) const {

        if (this->isInitialized()) {
            glBindBuffer(GL_ARRAY_BUFFER, _id);
            glGetBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
        }
    }

    void * buffer::map(
            const gloop::intptr_t offset,
            const gloop::sizeiptr_t length,
            const bitfields::buffer_access_hint accessHints) {

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

    void buffer::bind(const enums::buffer_target target) const {
        if (this->isInitialized()) {
            glBindBuffer(static_cast<GLenum> (target), _id);
        }
    }

    void buffer::blockBind(
            const enums::buffer_target target,
            const gloop::uint_t binding,
            const gloop::intptr_t offset,
            const gloop::intptr_t size) const {

        if (this->isInitialized()) {
            glBindBufferRange(static_cast<GLenum> (target), binding, _id, offset, size);
        }
    }

    void buffer::blockBind(
            const enums::buffer_target target,
            const gloop::uint_t binding) const {
        
        if (this->isInitialized()) {
            glBindBufferBase(static_cast<GLenum> (target), binding, _id);
        }
    }
}