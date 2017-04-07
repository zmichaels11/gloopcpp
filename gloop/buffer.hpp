/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#pragma once

#include <vector>
#include <array>
#include <cstddef>

#include <GL/glew.h>

namespace gloop {

    enum class buffer_target : GLenum {
        ARRAY = GL_ARRAY_BUFFER,
        ELEMENT_ARRAY = GL_ELEMENT_ARRAY_BUFFER,
        ATOMIC_COUNTER = GL_ATOMIC_COUNTER_BUFFER,
        COPY_READ = GL_COPY_READ_BUFFER,
        COPY_WRITE = GL_COPY_WRITE_BUFFER,
        DISPATCH_INDIRECT = GL_DISPATCH_INDIRECT_BUFFER,
        DRAW_INDIRECT = GL_DRAW_INDIRECT_BUFFER,
        PIXEL_PACK = GL_PIXEL_PACK_BUFFER,
        PIXEL_UNPACK = GL_PIXEL_UNPACK_BUFFER,
        QUERY = GL_QUERY_BUFFER,
        SHADER_STORAGE = GL_SHADER_STORAGE_BUFFER,
        TEXTURE = GL_TEXTURE_BUFFER,
        TRANSFORM_FEEDBACK = GL_TRANSFORM_FEEDBACK_BUFFER,
        UNIFORM = GL_UNIFORM_BUFFER
    };

    enum class buffer_storage_hint : GLenum {
        STATIC_DRAW = GL_STATIC_DRAW,
        STATIC_READ = GL_STATIC_READ,
        STATIC_COPY = GL_STATIC_COPY,
        DYNAMIC_DRAW = GL_DYNAMIC_DRAW,
        DYNAMIC_READ = GL_DYNAMIC_READ,
        DYNAMIC_COPY = GL_DYNAMIC_COPY,
        STREAM_DRAW = GL_STREAM_DRAW,
        STREAM_READ = GL_STREAM_READ,
        STREAM_COPY = GL_STREAM_COPY
    };

    enum class buffer_access_hint : GLbitfield {
        READ,
        WRITE,
        PERSISTENT,
        COHERENT,
        INVALIDATE_BUFFER,
        INVALIDATE_RANGE,
        FLUSH_EXPLICIT,
        MAP_UNSYNCHRONIZED
    };

    inline buffer_access_hint operator|(buffer_access_hint lhs, buffer_access_hint rhs) {
        return static_cast<buffer_access_hint> (
                static_cast<GLbitfield> (lhs) | static_cast<GLbitfield> (rhs));
    }

    inline buffer_access_hint operator&(buffer_access_hint lhs, buffer_access_hint rhs) {
        return static_cast<buffer_access_hint> (
                static_cast<GLbitfield> (lhs) & static_cast<GLbitfield> (rhs));
    }

    inline buffer_access_hint operator^ (buffer_access_hint lhs, buffer_access_hint rhs) {
        return static_cast<buffer_access_hint> (
                static_cast<GLbitfield> (lhs) ^ static_cast<GLbitfield> (rhs));
    }

    inline buffer_access_hint operator~(buffer_access_hint lhs) {
        return static_cast<buffer_access_hint> (~static_cast<GLbitfield> (lhs));
    }

    inline buffer_access_hint& operator|=(buffer_access_hint& lhs, buffer_access_hint rhs) {
        lhs = static_cast<buffer_access_hint> (
                static_cast<GLbitfield> (lhs) | static_cast<GLbitfield> (rhs));

        return lhs;
    }

    inline buffer_access_hint& operator&=(buffer_access_hint& lhs, buffer_access_hint rhs) {
        lhs = static_cast<buffer_access_hint> (
                static_cast<GLbitfield> (lhs) & static_cast<GLbitfield> (rhs));

        return lhs;
    }

    inline buffer_access_hint& operator^=(buffer_access_hint& lhs, buffer_access_hint rhs) {
        lhs = static_cast<buffer_access_hint> (
                static_cast<GLbitfield> (lhs) ^ static_cast<GLbitfield> (rhs));

        return lhs;
    }

    class buffer {
    private:
        GLuint _id;
        GLsizeiptr _size;
        buffer_storage_hint _storageHint;
        buffer_access_hint _accessHints;
        bool _isImmutable;

    public:

        buffer() :
        _id(0),
        _size(0),
        _storageHint(static_cast<buffer_storage_hint> (0)),
        _accessHints(static_cast<buffer_access_hint> (0)), _isImmutable(false) {
        }
        
        buffer(buffer&) = delete;
        
        buffer(buffer&&) = default;
        
        ~buffer();

        buffer_storage_hint getStorageHint() const;

        buffer_access_hint getAccessHints() const;

        bool isImmutable() const;

        void allocate(
                const GLsizeiptr size,
                const buffer_storage_hint storageHint = buffer_storage_hint::STATIC_DRAW);

        void allocateImmutable(
                const GLsizeiptr size,
                const buffer_access_hint access = buffer_access_hint::READ | buffer_access_hint::WRITE);

        void allocateImmutable(
                const GLsizeiptr size,
                const GLvoid * data,
                const buffer_access_hint access = buffer_access_hint::READ);

        template<class T>
        inline void allocateImmutable(
                const std::vector<T>& data,
                const buffer_access_hint accessHints = buffer_access_hint::READ) {

            allocateImmutable(sizeof (T) * data.size(), data.data(), accessHints);
        }

        template<class T, std::size_t N>
        inline void allocateImmutable(
                const std::array<T, N>& data,
                const buffer_access_hint accessHints = buffer_access_hint::READ) {

            allocateImmutable(sizeof (data), data.data(), accessHints);
        }

        void allocate(
                const GLsizeiptr size,
                const GLvoid * data,
                const buffer_storage_hint storageHint = buffer_storage_hint::STATIC_DRAW);

        template<class T>
        inline void allocate(
                const std::vector<T>& data,
                const buffer_storage_hint storageHint = buffer_storage_hint::STATIC_DRAW) {

            allocate(sizeof (T) * data.size(), data.data(), storageHint);
        }

        template<class T, std::size_t N>
        inline void allocate(
                const std::array<T, N>& data,
                const buffer_storage_hint storageHint = buffer_storage_hint::STATIC_DRAW) {

            allocate(sizeof (data), data.data(), storageHint);
        }

        void reallocate() const;

        bool isInitialized() const;

        GLuint getId() const;

        operator GLuint();

        operator bool() const;

        void free();

        void setData(const GLintptr offset, const GLsizeiptr size, const GLvoid * data);

        template<class T>
        void setData(const GLintptr offset, const std::vector<T>& data) {
            setData(offset, sizeof (T) * data.size(), &data[0]);
        }

        template<class T, std::size_t N>
        void setData(const GLintptr offset, const std::array<T, N>& data) {
            setData(offset, sizeof (data), data.data());
        }

        void getData(const GLintptr offset, const GLsizeiptr size, GLvoid * data) const;

        void * map(GLintptr offset, GLsizeiptr length, buffer_access_hint accessHints);

        void unmap() const;

        void bind(const buffer_target target) const;

        void blockBind(const buffer_target target, const GLuint binding, const GLintptr offset, GLintptr size) const;

        void blockBind(const buffer_target target, const GLuint binding) const;
    };
}