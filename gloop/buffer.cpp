/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "buffer.hpp"

#include "enums/buffer_target.hpp"
#include "enums/buffer_storage_hint.hpp"
#include "exception/invalid_operation_exception.hpp"
#include "glint.hpp"
#include "gloop_throw.hpp"
#include "tools.hpp"
#include "wrapper/buffer_objects.hpp"

namespace gloop {

    buffer::~buffer() {
        free();
    }

    void buffer::reallocate() const {
        if (this->isInitialized()) {
            gloop::wrapper::namedBufferData(
                    static_cast<gloop::enum_t> (_target),
                    _id,
                    _size,
                    nullptr,
                    static_cast<gloop::enum_t> (_storageHint));
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
            const enums::buffer_target target,
            const gloop::sizeiptr_t size,
            const bitfields::buffer_immutable_storage_hint access) {

        allocateImmutable(target, size, nullptr, access);
    }

    void buffer::allocateImmutable(
            const enums::buffer_target target,
            const gloop::sizeiptr_t size,
            const void* data,
            const bitfields::buffer_immutable_storage_hint access) {

        gloop::uint_t glId = 0;

        gloop::wrapper::createBuffers(1, &glId);
        gloop::wrapper::namedBufferStorage(
                static_cast<gloop::enum_t> (target),
                glId,
                size,
                data,
                static_cast<gloop::bitfield_t> (access));

        this->_target = target;
        this->_id = glId;
        this->_size = size;
        this->_isImmutable = true;
        this->_immutableStorageHints = access;
        this->_storageHint = static_cast<enums::buffer_storage_hint> (0);
    }

    void buffer::allocate(
            const gloop::enums::buffer_target target,
            const gloop::sizeiptr_t size,
            const enums::buffer_storage_hint storageHint) {

        allocate(target, size, nullptr, storageHint);
    }

    void buffer::allocate(
            const enums::buffer_target target,
            const gloop::sizeiptr_t size,
            const void * data,
            const enums::buffer_storage_hint storageHint) {

        gloop::uint_t glId = 0;

        gloop::wrapper::createBuffers(1, &glId);
        gloop::wrapper::namedBufferData(
                static_cast<gloop::enum_t> (target),
                glId,
                size,
                data,
                static_cast<gloop::enum_t> (storageHint));

        this->_target = target;
        this->_id = glId;
        this->_size = size;
        this->_storageHint = storageHint;
        this->_immutableStorageHints = static_cast<bitfields::buffer_immutable_storage_hint> (0);
        this->_isImmutable = false;
    }

    enums::buffer_target buffer::getTargetHint() const {
        return _target;
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

    buffer::operator bool() const {
        return this->isInitialized();
    }

    void buffer::free() {
        if (this->isInitialized()) {
            gloop::wrapper::deleteBuffers(1, &_id);
            this->_id = 0;
        }
    }

    void buffer::setData(
            const gloop::intptr_t offset,
            const gloop::sizeiptr_t size,
            const void * data) {

        gloop::wrapper::namedBufferSubData(
                static_cast<gloop::enum_t> (_target),
                _id,
                offset,
                size,
                data);
    }

    namespace {
#define GLEW 1
#define GLES2 2
#define GLES3 3
#ifndef GL
#define __GL_NOT_DEFINED
#define GL 0
#endif        

        static constexpr bool supports_getdata = (GL == GLEW);
        static constexpr bool supports_blockbind = (GL == GLEW || GL == GLES3);

        template<bool isSupported = supports_getdata, typename std::enable_if<isSupported, void * >::type = nullptr>
        static inline void __getNamedBufferSubData(
                gloop::enum_t targetHint,
                gloop::uint_t buffer,
                gloop::intptr_t offset,
                gloop::sizeiptr_t size,
                void * data) {

            wrapper::getNamedBufferSubData(targetHint, buffer, offset, size, data);
        }

        template<bool isSupported = supports_getdata, typename std::enable_if<!isSupported, void * >::type = nullptr>
        static inline void __getNamedBufferSubData(...) {
            gloop_throw(gloop::exception::invalid_operation_exception("GetBufferSubData is not supported!"));
        }

        template<bool isSupported = supports_blockbind, typename std::enable_if<isSupported, void * >::type = nullptr>
        static inline void __bindBufferBase(
                gloop::enum_t target,
                gloop::uint_t index,
                gloop::uint_t buffer) {

            wrapper::bindBufferBase(target, index, buffer);
        }

        template<bool isSupported = supports_blockbind, typename std::enable_if<!isSupported, void * >::type = nullptr>
        static inline void __bindBufferBase(...) {
            gloop_throw(gloop::exception::invalid_operation_exception("BindBufferBase is not supported!"));
        }

        template<bool isSupported = supports_blockbind, typename std::enable_if<isSupported, void * >::type = nullptr>
        static inline void __bindBufferRange(
                gloop::enum_t target,
                gloop::uint_t index,
                gloop::uint_t buffer,
                gloop::intptr_t offset, gloop::sizeiptr_t size) {

            wrapper::bindBufferRange(target, index, buffer, offset, size);
        }

        template<bool isSupported = supports_blockbind, typename std::enable_if<!isSupported, void * >::type = nullptr>
        static inline void __bindBufferRange(...) {
            gloop_throw(gloop::exception::invalid_operation_exception("BindBufferRange is not supported!"));
        }

#ifdef __GL_NOT_DEFINED
#undef GL
#undef __GL_NOT_DEFINED
#endif

#undef GLES3
#undef GLES2
#undef GLES1
    }

    void buffer::getData(
            const gloop::intptr_t offset,
            const gloop::sizeiptr_t size,
            void * data) const {

        if (this->isInitialized()) {
            __getNamedBufferSubData(
                    static_cast<gloop::enum_t> (_target),
                    _id,
                    offset,
                    size,
                    data);
        }
    }

    void * buffer::map(
            const gloop::intptr_t offset,
            const gloop::sizeiptr_t length,
            const bitfields::buffer_access_hint accessHints) {

        if (this->isInitialized()) {
            return gloop::wrapper::mapNamedBufferRange(
                    static_cast<gloop::enum_t> (_target),
                    _id,
                    offset,
                    length,
                    static_cast<gloop::bitfield_t> (accessHints));
        } else {
            return nullptr;
        }
    }

    void buffer::unmap() const {
        if (this->isInitialized()) {
            gloop::wrapper::unmapNamedBuffer(static_cast<gloop::enum_t> (_target), _id);
        }
    }

    void buffer::bind(const enums::buffer_target target) const {
        if (this->isInitialized()) {
            gloop::wrapper::bindBuffer(static_cast<gloop::enum_t> (target), _id);
        }
    }

    void buffer::blockBind(
            const enums::buffer_target target,
            const gloop::uint_t binding,
            const gloop::intptr_t offset,
            const gloop::intptr_t size) const {

        if (this->isInitialized()) {
            __bindBufferRange(
                    static_cast<gloop::enum_t> (target),
                    binding,
                    _id,
                    offset,
                    size);
        }
    }

    void buffer::blockBind(
            const enums::buffer_target target,
            const gloop::uint_t binding) const {

        if (this->isInitialized()) {
            __bindBufferBase(
                    static_cast<gloop::enum_t> (target),
                    binding,
                    _id);
        }
    }
}