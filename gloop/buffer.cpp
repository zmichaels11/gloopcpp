/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "buffer.hpp"

#include <GL/glew.h>

#include "exception.hpp"
#include "tools.hpp"

void gloop::buffer::reallocate() const {
    if (this->isInitialized()) {
        glBindBuffer(GL_ARRAY_BUFFER, *(this->_id));
        glBufferData(GL_ARRAY_BUFFER, this->_size, nullptr, static_cast<GLenum> (this->_storageHint));
    }
}

bool gloop::buffer::isImmutable() const {
    return this->_isImmutable;
}

gloop::buffer_access_hint gloop::buffer::getAccessHints() const {
    return this->_accessHints;
}

gloop::buffer_storage_hint gloop::buffer::getStorageHint() const {
    return this->_storageHint;
}

void gloop::buffer::allocateImmutable(
        const GLsizeiptr size,
        const buffer_access_hint access) {

    allocateImmutable(size, nullptr, access);
}

void gloop::buffer::allocateImmutable(
        const GLsizeiptr size,
        const GLvoid* data,
        const buffer_access_hint access) {

    GLuint glId = 0;

    glGenBuffers(1, &glId);
    glBindBuffer(GL_ARRAY_BUFFER, glId);
    glBufferStorage(GL_ARRAY_BUFFER, size, data, static_cast<GLbitfield> (access));

    this->_id = std::shared_ptr<GLuint>(new GLuint, [ = ] (GLuint * id){
        if (id != nullptr) {
            glDeleteBuffers(1, id);
            delete id;
        }
    });
    
    *(this->_id) = glId;
    this->_size = size;
    this->_isImmutable = true;
    this->_accessHints = access;
}

void gloop::buffer::allocate(
        const GLsizeiptr size,
        const buffer_storage_hint storageHint) {

    allocate(size, nullptr, storageHint);
}

void gloop::buffer::allocate(
        const GLsizeiptr size,
        const GLvoid * data,
        const buffer_storage_hint storageHint) {

    GLuint glId = 0;

    glGenBuffers(1, &glId);
    glBindBuffer(GL_ARRAY_BUFFER, glId);
    glBufferData(GL_ARRAY_BUFFER, size, data, static_cast<GLenum> (storageHint));        

    this->_id = std::shared_ptr<GLuint>(new GLuint, [ = ] (GLuint * id){
        if (id != nullptr) {
            glDeleteBuffers(1, id);
                    delete id;
        }
    });

    *(this->_id) = glId;
    this->_size = size;
    this->_storageHint = storageHint;
    this->_isImmutable = false;
}

bool gloop::buffer::isInitialized() const {
    return (this->_id.get() != nullptr);
}

GLuint gloop::buffer::getId() const {
    if (this->isInitialized()) {
        return *(this->_id);
    } else {
        return 0;
    }
}

gloop::buffer::operator GLuint() {
    return this->getId();
}

gloop::buffer::operator bool() const {
    return this->isInitialized();
}

void gloop::buffer::free() {
    if (this->isInitialized()) {
        glDeleteBuffers(1, this->_id.get());
        this->_id.reset();
    }
}

void gloop::buffer::setData(const GLintptr offset, const GLsizeiptr size, const GLvoid* data) {
    glBindBuffer(GL_ARRAY_BUFFER, *(this->_id));
    glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
}

void gloop::buffer::getData(const GLintptr offset, const GLsizeiptr size, GLvoid* data) const {
    if (this->isInitialized()) {
        glBindBuffer(GL_ARRAY_BUFFER, *(this->_id));
        glGetBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
    }
}

void * gloop::buffer::map(GLintptr offset, GLsizeiptr length, buffer_access_hint accessHints) {
    if (this->isInitialized()) {
        glBindBuffer(GL_ARRAY_BUFFER, *_id);

        return glMapBufferRange(GL_ARRAY_BUFFER, offset, length, static_cast<GLbitfield> (accessHints));
    } else {
        return nullptr;
    }
}

void gloop::buffer::unmap() const {
    if (this->isInitialized()) {
        glBindBuffer(GL_ARRAY_BUFFER, *(this->_id));
        glUnmapBuffer(GL_ARRAY_BUFFER);
    }
}

void gloop::buffer::bind(const gloop::buffer_target target) const {
    if (this->isInitialized()) {
        glBindBuffer(static_cast<GLenum> (target), *(this->_id));
    }
}

void gloop::buffer::blockBind(const buffer_target target, const GLuint binding, const GLintptr offset, GLintptr size) const {
    if (this->isInitialized()) {
        glBindBufferRange(static_cast<GLenum> (target), binding, *_id, offset, size);
    }
}

void gloop::buffer::blockBind(const buffer_target target, const GLuint binding) const {
    if (this->isInitialized()) {
        glBindBufferBase(static_cast<GLenum> (target), binding, *_id);
    }
}