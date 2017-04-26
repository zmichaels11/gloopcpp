/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#pragma once

#include <array>
#include <cstddef>
#include <iostream>
#include <vector>

#include "glint.hpp"

namespace gloop {
    namespace bitfields {
        enum class buffer_access_hint : gloop::bitfield_t;
        enum class buffer_immutable_storage_hint : gloop::bitfield_t;
    }

    namespace enums {
        enum class buffer_target : gloop::enum_t;
        enum class buffer_storage_hint : gloop::enum_t;
    }

    class buffer {
    public:
        struct features {
            bool mapRange;
            bool map;
            bool immutable;
            bool blockBind;
        };
        
        const static features& FEATURES;
        
    private:
        enums::buffer_target _target;
        gloop::uint_t _id;
        gloop::sizeiptr_t _size;
        enums::buffer_storage_hint _storageHint;
        bitfields::buffer_immutable_storage_hint _immutableStorageHints;
        bool _isImmutable;

    public:

        buffer();

        ~buffer();

        buffer(const buffer&) = delete;

        buffer(buffer&&) = default;

        buffer& operator=(const buffer&) = delete;

        buffer& operator=(buffer&&) = default;

        inline friend std::ostream& operator<<(std::ostream& os, const buffer& b);

        enums::buffer_target getTargetHint() const;

        enums::buffer_storage_hint getStorageHint() const;

        bitfields::buffer_immutable_storage_hint getImmutableStorageHints() const;

        bool isImmutable() const;

        void allocate(
                const enums::buffer_target target,
                const gloop::sizeiptr_t size,
                const enums::buffer_storage_hint storageHint = static_cast<enums::buffer_storage_hint>(0x88E4));

        void allocateImmutable(
                const enums::buffer_target target,
                const gloop::sizeiptr_t size,
                const bitfields::buffer_immutable_storage_hint access = static_cast<bitfields::buffer_immutable_storage_hint> (0x0001 | 0x0002));

        void allocateImmutable(
                const enums::buffer_target target,
                const gloop::sizeiptr_t size,
                const void * data,
                const bitfields::buffer_immutable_storage_hint access = static_cast<bitfields::buffer_immutable_storage_hint> (0x0001));

        template<class T>
        inline void allocateImmutable(
                const enums::buffer_target target,
                const std::vector<T>& data,
                const bitfields::buffer_immutable_storage_hint accessHints = static_cast<bitfields::buffer_immutable_storage_hint>(0x0001)) {

            allocateImmutable(target, sizeof (T) * data.size(), data.data(), accessHints);
        }

        template<class T, std::size_t N>
        inline void allocateImmutable(
                const enums::buffer_target target,
                const std::array<T, N>& data,
                const bitfields::buffer_immutable_storage_hint accessHints = static_cast<bitfields::buffer_immutable_storage_hint>(0x0001)) {

            allocateImmutable(target, sizeof (data), data.data(), accessHints);
        }

        void allocate(
                const enums::buffer_target target,
                const gloop::sizeiptr_t size,
                const void * data,
                const enums::buffer_storage_hint storageHint = static_cast<enums::buffer_storage_hint>(0x88E4));

        template<class T>
        inline void allocate(
                const enums::buffer_target target,
                const std::vector<T>& data,
                const enums::buffer_storage_hint storageHint = static_cast<enums::buffer_storage_hint>(0x88E4)) {

            allocate(sizeof (T) * data.size(), data.data(), storageHint);
        }

        template<class T, std::size_t N>
        inline void allocate(
                const enums::buffer_target target,
                const std::array<T, N>& data,
                const enums::buffer_storage_hint storageHint = static_cast<enums::buffer_storage_hint>(0x88E4)) {

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