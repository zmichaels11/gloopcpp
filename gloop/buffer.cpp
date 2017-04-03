/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "buffer.hpp"

#include <GL/glew.h>

#include "exception.hpp"
#include "tools.hpp"

namespace {        
    static GLenum storageHintToGLenum(const gloop::buffer_storage_hint hint) {
        switch (hint) {
            case gloop::buffer_storage_hint::DYNAMIC_COPY:
                return GL_DYNAMIC_COPY;
            case gloop::buffer_storage_hint::DYNAMIC_DRAW:
                return GL_DYNAMIC_DRAW;
            case gloop::buffer_storage_hint::DYNAMIC_READ:
                return GL_DYNAMIC_READ;
            case gloop::buffer_storage_hint::STATIC_COPY:
                return GL_STATIC_COPY;
            case gloop::buffer_storage_hint::STATIC_DRAW:
                return GL_STATIC_DRAW;
            case gloop::buffer_storage_hint::STATIC_READ:
                return GL_STATIC_READ;
            case gloop::buffer_storage_hint::STREAM_COPY:
                return GL_STREAM_COPY;
            case gloop::buffer_storage_hint::STREAM_DRAW:
                return GL_STREAM_DRAW;
            case gloop::buffer_storage_hint::STREAM_READ:
                return GL_STREAM_READ;
            default:
                throw gloop::invalid_enum_exception("Unsupported buffer storage hint!");
        }
    }
    
    static GLenum bufferTargetToGLenum(const gloop::buffer_target target) {
        switch (target) {
            case gloop::buffer_target::ARRAY:
                return GL_ARRAY_BUFFER;
            case gloop::buffer_target::ATOMIC_COUNTER:
                return GL_ATOMIC_COUNTER_BUFFER;
            case gloop::buffer_target::COPY_READ:
                return GL_COPY_READ_BUFFER;
            case gloop::buffer_target::COPY_WRITE:
                return GL_COPY_WRITE_BUFFER;
            case gloop::buffer_target::DISPATCH_INDIRECT:
                return GL_DISPATCH_INDIRECT_BUFFER;
            case gloop::buffer_target::DRAW_INDIRECT:
                return GL_DRAW_INDIRECT_BUFFER;
            case gloop::buffer_target::ELEMENT_ARRAY:
                return GL_ELEMENT_ARRAY_BUFFER;
            case gloop::buffer_target::PIXEL_PACK:
                return GL_PIXEL_PACK_BUFFER;
            case gloop::buffer_target::PIXEL_UNPACK:
                return GL_PIXEL_UNPACK_BUFFER;
            case gloop::buffer_target::QUERY:
                return GL_QUERY_BUFFER;
            case gloop::buffer_target::SHADER_STORAGE:
                return GL_SHADER_STORAGE_BUFFER;
            case gloop::buffer_target::TEXTURE:
                return GL_TEXTURE_BUFFER;
            case gloop::buffer_target::TRANSFORM_FEEDBACK:
                return GL_TRANSFORM_FEEDBACK_BUFFER;
            case gloop::buffer_target::UNIFORM:
                return GL_UNIFORM_BUFFER;
            default:
                throw gloop::invalid_enum_exception("Unsupported buffer target!");
        }
    }
}

void gloop::buffer::reallocate() const {
    if (this->isInitialized()) {
        glBindBuffer(GL_ARRAY_BUFFER, *(this->_id));
        glBufferData(GL_ARRAY_BUFFER, this->_size, nullptr, storageHintToGLenum(this->_storageHint));
    }
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
    glBufferData(GL_ARRAY_BUFFER, size, data, storageHintToGLenum(storageHint));    

    this->_id = std::shared_ptr<GLuint>(new GLuint, [ = ] (GLuint * id){
        if (id != nullptr) {
            glDeleteBuffers(1, id);
            delete id;
        }
    });

    *(this->_id) = glId;
    this->_size = size;
    this->_storageHint = storageHint;
}

bool gloop::buffer::isInitialized() const {
    return (this->_id.get() != nullptr);
}

GLuint gloop::buffer::getId() {
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
    return nullptr;
}

void gloop::buffer::unmap() const {
    if (this->isInitialized()) {
        glBindBuffer(GL_ARRAY_BUFFER, *(this->_id));
        glUnmapBuffer(GL_ARRAY_BUFFER);
    }
}

void gloop::buffer::bind(const gloop::buffer_target target) const {
    if (this->isInitialized()) {
        glBindBuffer(bufferTargetToGLenum(target), *(this->_id));
    }
}