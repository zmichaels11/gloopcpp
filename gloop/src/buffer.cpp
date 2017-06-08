/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "buffer.hpp"

#include <type_traits>

#include "enums/buffer_target.hpp"
#include "enums/buffer_storage_hint.hpp"
#include "exception/invalid_operation_exception.hpp"
#include "gl_traits.hpp"
#include "glint.hpp"
#include "gloop_throw.hpp"
#include "wrapper/buffer_objects.hpp"
#include "bitfields/buffer_immutable_storage_hint.hpp"

namespace gloop {

    std::ostream& operator<<(std::ostream& os, const buffer& b) {
        os << "buffer: [";

        if (b.isInitialized()) {
            os << "id: " << b._id;
            os << ", target: " << b._target;
            os << ", size: " << b._size;

            if (b.isImmutable()) {
                os << ", immutable storage hints: " << b._immutableStorageHints;
            } else {
                os << ", storage hints " << b._storageHint;
            }

            os << "]";
        } else {
            os << "UNINITIALIZED]";
        }

        return os;
    }

    buffer::buffer() {
        _target = enums::buffer_target::UNKNOWN;
        _id = 0;
        _size = 0;
        _storageHint = enums::buffer_storage_hint::UNKNOWN;
        _immutableStorageHints = bitfields::buffer_immutable_storage_hint::NONE;
        _isImmutable = false;
    }

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

    void buffer::getData(
            const gloop::intptr_t offset,
            const gloop::sizeiptr_t size,
            void * data) const {

		if (isGLES()) {
            gloop_throw(gloop::exception::invalid_operation_exception("GetBufferSubData is not supported!"));
		}

        if (this->isInitialized()) {
            wrapper::getNamedBufferSubData(
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

		if (isGLES2()) {
			gloop_throw(gloop::exception::invalid_operation_exception("BindBufferBase is not supported!"));
		}

        if (this->isInitialized()) {
            wrapper::bindBufferRange(
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

		if (isGLES2()) {
			gloop_throw(gloop::exception::invalid_operation_exception("BindBufferBase is not supported!"));
		}

        if (this->isInitialized()) {
            wrapper::bindBufferBase(
                    static_cast<gloop::enum_t> (target),
                    binding,
                    _id);
        }
    }
}
