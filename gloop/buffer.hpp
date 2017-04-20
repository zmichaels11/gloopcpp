/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#pragma once

#include <array>
#include <cstddef>
#include <vector>

#include "bitfields/buffer_access_hint.hpp"
#include "bitfields/buffer_immutable_storage_hint.hpp"
#include "enums/buffer_target.hpp"
#include "enums/buffer_storage_hint.hpp"
#include "glint.hpp"

namespace gloop {

    class buffer {
    private:
        enums::buffer_target _target;
        gloop::uint_t _id;
        gloop::sizeiptr_t _size;
        enums::buffer_storage_hint _storageHint;
        bitfields::buffer_immutable_storage_hint _immutableStorageHints;
        bool _isImmutable;

    public:

        buffer() :
        _target(enums::buffer_target::ARRAY),
        _id(0),
        _size(0),
        _storageHint(static_cast<enums::buffer_storage_hint> (0)),
        _immutableStorageHints(static_cast<bitfields::buffer_immutable_storage_hint> (0)),
        _isImmutable(false) {
        }        

        enums::buffer_target getTargetHint() const;

        buffer(const buffer&) = delete;

        buffer(buffer&&) = default;

        ~buffer();

        enums::buffer_storage_hint getStorageHint() const;

        bitfields::buffer_immutable_storage_hint getImmutableStorageHints() const;

        bool isImmutable() const;

        void allocate(
                const enums::buffer_target target,
                const gloop::sizeiptr_t size,
                const enums::buffer_storage_hint storageHint = enums::buffer_storage_hint::STATIC_DRAW);

        void allocateImmutable(
                const enums::buffer_target target,
                const gloop::sizeiptr_t size,
                const bitfields::buffer_immutable_storage_hint access = bitfields::buffer_immutable_storage_hint::READ | bitfields::buffer_immutable_storage_hint::WRITE);

        void allocateImmutable(
                const enums::buffer_target target,
                const gloop::sizeiptr_t size,
                const void * data,
                const bitfields::buffer_immutable_storage_hint access = bitfields::buffer_immutable_storage_hint::READ);

        template<class T>
        inline void allocateImmutable(
                const enums::buffer_target target,
                const std::vector<T>& data,
                const bitfields::buffer_immutable_storage_hint accessHints = bitfields::buffer_immutable_storage_hint::READ) {

            allocateImmutable(target, sizeof (T) * data.size(), data.data(), accessHints);
        }

        template<class T, std::size_t N>
        inline void allocateImmutable(
                const enums::buffer_target target,
                const std::array<T, N>& data,
                const bitfields::buffer_immutable_storage_hint accessHints = bitfields::buffer_immutable_storage_hint::READ) {

            allocateImmutable(target, sizeof (data), data.data(), accessHints);
        }

        void allocate(
                const enums::buffer_target target,
                const gloop::sizeiptr_t size,
                const void * data,
                const enums::buffer_storage_hint storageHint = enums::buffer_storage_hint::STATIC_DRAW);

        template<class T>
        inline void allocate(
                const enums::buffer_target target,
                const std::vector<T>& data,
                const enums::buffer_storage_hint storageHint = enums::buffer_storage_hint::STATIC_DRAW) {

            allocate(sizeof (T) * data.size(), data.data(), storageHint);
        }

        template<class T, std::size_t N>
        inline void allocate(
                const enums::buffer_target target,
                const std::array<T, N>& data,
                const enums::buffer_storage_hint storageHint = enums::buffer_storage_hint::STATIC_DRAW) {

            allocate(target, sizeof (data), data.data(), storageHint);
        }

        void reallocate() const;

        bool isInitialized() const;

        gloop::uint_t getId() const;

        operator bool() const;

        void free();

        void setData(
                const gloop::intptr_t offset,
                const gloop::sizeiptr_t size,
                const void * data);

        template<class T>
        inline void setData(
                const gloop::intptr_t offset,
                const std::vector<T>& data) {

            setData(offset, sizeof (T) * data.size(), &data[0]);
        }

        template<class T, std::size_t N>
        inline void setData(
                const gloop::intptr_t offset,
                const std::array<T, N>& data) {

            setData(offset, sizeof (data), data.data());
        }

        void getData(
                const gloop::intptr_t offset,
                const gloop::sizeiptr_t size,
                void * data) const;

        void * map(
                const gloop::intptr_t offset,
                const gloop::sizeiptr_t length,
                const bitfields::buffer_access_hint accessHints);

        void unmap() const;

        void bind(const enums::buffer_target target) const;

        void blockBind(
                const enums::buffer_target target,
                const gloop::uint_t binding,
                const gloop::intptr_t offset,
                const gloop::intptr_t size) const;

        void blockBind(
                const enums::buffer_target target,
                const gloop::uint_t binding) const;
    };
}