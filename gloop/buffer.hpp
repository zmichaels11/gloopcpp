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

#include "bitfields/buffer_access_hint.hpp"
#include "bitfields/buffer_immutable_storage_hint.hpp"
#include "enums/buffer_target.hpp"
#include "enums/buffer_storage_hint.hpp"

namespace gloop {

    class buffer {
    private:
        GLuint _id;
        GLsizeiptr _size;
        enums::buffer_storage_hint _storageHint;
        bitfields::buffer_immutable_storage_hint _immutableStorageHints;
        bool _isImmutable;

    public:

        buffer() :
        _id(0),
        _size(0),
        _storageHint(static_cast<enums::buffer_storage_hint> (0)),
        _immutableStorageHints(static_cast<bitfields::buffer_immutable_storage_hint> (0)),
        _isImmutable(false) {
        }

        buffer(buffer&) = delete;

        buffer(buffer&&) = default;

        ~buffer();

        enums::buffer_storage_hint getStorageHint() const;

        bitfields::buffer_immutable_storage_hint getImmutableStorageHints() const;

        bool isImmutable() const;

        void allocate(
                const GLsizeiptr size,
                const enums::buffer_storage_hint storageHint = enums::buffer_storage_hint::STATIC_DRAW);

        void allocateImmutable(
                const GLsizeiptr size,
                const bitfields::buffer_immutable_storage_hint access = bitfields::buffer_immutable_storage_hint::READ | bitfields::buffer_immutable_storage_hint::WRITE);

        void allocateImmutable(
                const GLsizeiptr size,
                const GLvoid * data,
                const bitfields::buffer_immutable_storage_hint access = bitfields::buffer_immutable_storage_hint::READ);

        template<class T>
        inline void allocateImmutable(
                const std::vector<T>& data,
                const bitfields::buffer_immutable_storage_hint accessHints = bitfields::buffer_immutable_storage_hint::READ) {

            allocateImmutable(sizeof (T) * data.size(), data.data(), accessHints);
        }

        template<class T, std::size_t N>
        inline void allocateImmutable(
                const std::array<T, N>& data,
                const bitfields::buffer_immutable_storage_hint accessHints = bitfields::buffer_immutable_storage_hint::READ) {

            allocateImmutable(sizeof (data), data.data(), accessHints);
        }

        void allocate(
                const GLsizeiptr size,
                const GLvoid * data,
                const enums::buffer_storage_hint storageHint = enums::buffer_storage_hint::STATIC_DRAW);

        template<class T>
        inline void allocate(
                const std::vector<T>& data,
                const enums::buffer_storage_hint storageHint = enums::buffer_storage_hint::STATIC_DRAW) {

            allocate(sizeof (T) * data.size(), data.data(), storageHint);
        }

        template<class T, std::size_t N>
        inline void allocate(
                const std::array<T, N>& data,
                const enums::buffer_storage_hint storageHint = enums::buffer_storage_hint::STATIC_DRAW) {

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

        void * map(GLintptr offset, GLsizeiptr length, bitfields::buffer_access_hint accessHints);

        void unmap() const;

        void bind(const enums::buffer_target target) const;

        void blockBind(const enums::buffer_target target, const GLuint binding, const GLintptr offset, GLintptr size) const;

        void blockBind(const enums::buffer_target target, const GLuint binding) const;
    };
}