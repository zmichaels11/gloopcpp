/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buffer.hpp
 * Author: zmichaels
 *
 * Created on April 3, 2017, 12:50 PM
 */

#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <memory>
#include <vector>
#include <array>
#include <cstddef>

#include <GL/glew.h>

namespace gloop {

    enum class buffer_target {
        ARRAY,
        ELEMENT_ARRAY,
        ATOMIC_COUNTER,
        COPY_READ,
        COPY_WRITE,
        DISPATCH_INDIRECT,
        DRAW_INDIRECT,
        PIXEL_PACK,
        PIXEL_UNPACK,
        QUERY,
        SHADER_STORAGE,
        TEXTURE,
        TRANSFORM_FEEDBACK,
        UNIFORM
    };

    enum class buffer_storage_hint {
        STATIC_DRAW,
        STATIC_READ,
        STATIC_COPY,
        DYNAMIC_DRAW,
        DYNAMIC_READ,
        DYNAMIC_COPY,
        STREAM_DRAW,
        STREAM_READ,
        STREAM_COPY
    };

    enum class buffer_access_hint {
        READ,
        WRITE,
        PERSISTENT,
        COHERENT,
        INVALIDATE_BUFFER,
        INVALIDATE_RANGE,
        FLUSH_EXPLICIT,
        MAP_UNSYNCHRONIZED
    };

    class buffer {
    private:
        std::shared_ptr<GLuint> _id;
        GLsizeiptr _size;
        buffer_storage_hint _storageHint;

    public:
        void allocate(
                const GLsizeiptr size,
                const buffer_storage_hint storageHint = buffer_storage_hint::STATIC_DRAW);

        void allocate(
                const GLsizeiptr size,
                const GLvoid * data,
                const buffer_storage_hint storageHint = buffer_storage_hint::STATIC_DRAW);

        template<class T>
        void allocate(
                const std::vector<T> data,
                const buffer_storage_hint storageHint = buffer_storage_hint::STATIC_DRAW) {

            allocate(sizeof (T) * data.size(), data.data(), storageHint);
        }

        template<class T, std::size_t N>
        void allocate(                
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
    };        
}

#endif /* BUFFER_HPP */

