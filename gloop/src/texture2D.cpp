/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "texture2D.hpp"

#include <iostream>
#include <type_traits>

#include "enums/buffer_target.hpp"
#include "enums/texture_internal_format.hpp"
#include "exception/invalid_operation_exception.hpp"
#include "gl_traits.hpp"
#include "glint.hpp"
#include "gloop_throw.hpp"
#include "states/texture2D_parameters.hpp"
#include "tools.hpp"
#include "wrapper/texture_objects.hpp"
#include "wrapper/gl.hpp"
#include "wrapper/buffer_objects.hpp"

namespace gloop {

    texture2D::texture2D() {
        _id = 0;
        _size.width = 0;
        _size.height = 0;
        _format = enums::texture_internal_format::UNKNOWN;
        _levels = 0;
        _params = std::make_unique<states::texture2D_parameters>();
        _handle = 0;
    }

    namespace {
        static constexpr bool supports_bindless = isGLEW || isGLES3;
        
        template <bool isSupported = supports_bindless, typename std::enable_if<isSupported, void * >::type = nullptr>
        static inline gloop::uint64_t __getTextureHandle(gloop::uint_t texture) {
            return wrapper::getTextureHandle(texture);            
        }
        
        template <bool isSupported = supports_bindless, typename std::enable_if<!isSupported, void * >::type = nullptr>
        static inline gloop::uint64_t __getTextureHandle(...) {
            gloop_throw(gloop::exception::invalid_operation_exception("Bindless textures are not supported!"));
        }
        
        template <bool isSupported = supports_bindless, typename std::enable_if<isSupported, void * >::type = nullptr>
        static inline void __makeTextureHandleResident(gloop::uint64_t handle) {
            wrapper::makeTextureHandleResident(handle);
        }
        
        template <bool isSupported = supports_bindless, typename std::enable_if<!isSupported, void * >::type = nullptr>
        static inline void __makeTextureHandleResident(...) {
            gloop_throw(gloop::exception::invalid_operation_exception("Bindless textures are not supported!"));
        }
        
        template <bool isSupported = supports_bindless, typename std::enable_if<isSupported, void * >::type = nullptr>
        static inline void __makeTextureHandleNonResident(gloop::uint64_t handle) {
            wrapper::makeTextureHandleNonResident(handle);
        }
        
        template <bool isSupported = supports_bindless, typename std::enable_if<!isSupported, void * >::type = nullptr>
        static inline void __makeTextureHandleNonResident(...) {
            gloop_throw(gloop::exception::invalid_operation_exception("Bindless textures are not supported!"));
        }
    }
    
    gloop::uint64_t texture2D::getHandle() {
        if (_handle == 0) {
            _handle = __getTextureHandle(_id);
            __makeTextureHandleResident(_handle);            
        }

        return _handle;
    }

    void texture2D::makeResident() const {
        if (_handle) {
            __makeTextureHandleResident(_handle);
        }
    }

    void texture2D::makeNonResident() const {
        if (_handle) {
            __makeTextureHandleNonResident(_handle);
        }
    }

    gloop::uint_t texture2D::getId() const {
        return _id;
    }

    bool texture2D::isValid() const {
        return (_id != 0);
    }

    const texture2D::size& texture2D::getSize() const {
        return _size;
    }

    enums::texture_internal_format texture2D::getInternalFormat() const {
        return _format;
    }

    gloop::uint_t texture2D::getMipmapLevelCount() const {
        return _levels;
    }

    texture2D::~texture2D() {
        this->free();
    }

    void texture2D::allocate(
            const enums::texture_internal_format internalFormat,
            const gloop::sizei_t levels, const gloop::sizei_t width, const gloop::sizei_t height) {

        if (this->isValid()) {
            this->free();
        }

        gloop::uint_t glId = 0;

        wrapper::createTextures(wrapper::TEXTURE_2D, 1, &glId);

        wrapper::textureParameteri(glId, wrapper::TEXTURE_MAG_FILTER, static_cast<gloop::int_t> (_params->getMagFilter()));
        wrapper::textureParameteri(glId, wrapper::TEXTURE_MIN_FILTER, static_cast<gloop::int_t> (_params->getMinFilter()));
        wrapper::textureParameteri(glId, wrapper::TEXTURE_WRAP_S, static_cast<gloop::int_t> (_params->getWrapS()));
        wrapper::textureParameteri(glId, wrapper::TEXTURE_WRAP_T, static_cast<gloop::int_t> (_params->getWrapT()));
        wrapper::textureParameterf(glId, wrapper::TEXTURE_MAX_ANISOTROPY, _params->getAnisotropic());

        wrapper::textureStorage2D(glId, levels, static_cast<gloop::enum_t> (internalFormat), width, height);

        tools::assertGLError("Error creating texture2D!");

        _id = glId;
        _format = internalFormat;
        _size.width = width;
        _size.height = height;
        _levels = levels;

    }

    void texture2D::update(
            const gloop::sizei_t level,
            const gloop::int_t xOffset, const gloop::int_t yOffset,
            const gloop::sizei_t width, const gloop::sizei_t height,
            const gloop::pixel_formats::B32F_G32F_R32F* data) const {

        wrapper::textureSubImage2D(_id, level, xOffset, yOffset, width, height, wrapper::BGR, wrapper::FLOAT, data);
    }

    void texture2D::update(
            const gloop::sizei_t level,
            const gloop::int_t xOffset, const gloop::int_t yOffset,
            const gloop::sizei_t width, const gloop::sizei_t height,
            const gloop::pixel_formats::B32F_G32F_R32F_A32F* data) const {

        wrapper::textureSubImage2D(_id, level, xOffset, yOffset, width, height, wrapper::BGRA, wrapper::FLOAT, data);
    }

    void texture2D::update(
            const gloop::sizei_t level,
            const gloop::int_t xOffset, const gloop::int_t yOffset,
            const gloop::sizei_t width, const gloop::sizei_t height,
            const gloop::pixel_formats::B8_G8_R8* data) const {

        wrapper::textureSubImage2D(_id, level, xOffset, yOffset, width, height, wrapper::BGR, wrapper::UNSIGNED_BYTE, data);
    }

    void texture2D::update(
            const gloop::sizei_t level,
            const gloop::int_t xOffset, const gloop::int_t yOffset,
            const gloop::sizei_t width, const gloop::sizei_t height,
            const gloop::pixel_formats::B8_G8_R8_A8* data) const {

        wrapper::textureSubImage2D(_id, level, xOffset, yOffset, width, height, wrapper::BGRA, wrapper::UNSIGNED_BYTE, data);
    }

    void texture2D::update(
            const gloop::sizei_t level,
            const gloop::int_t xOffset, const gloop::int_t yOffset,
            const gloop::sizei_t width, const gloop::sizei_t height,
            const gloop::pixel_formats::R32F_G32F_B32F* data) const {

        wrapper::textureSubImage2D(_id, level, xOffset, yOffset, width, height, wrapper::RGB, wrapper::FLOAT, data);
    }

    void texture2D::update(
            const gloop::sizei_t level,
            const gloop::int_t xOffset, const gloop::int_t yOffset,
            const gloop::sizei_t width, const gloop::sizei_t height,
            const gloop::pixel_formats::R32F_G32F_B32F_A32F* data) const {

        wrapper::textureSubImage2D(_id, level, xOffset, yOffset, width, height, wrapper::RGBA, wrapper::FLOAT, data);
    }

    void texture2D::update(
            const gloop::sizei_t level,
            const gloop::int_t xOffset, const gloop::int_t yOffset,
            const gloop::sizei_t width, const gloop::sizei_t height,
            const gloop::pixel_formats::R8_G8_B8* data) const {

        wrapper::textureSubImage2D(_id, level, xOffset, yOffset, width, height, wrapper::RGB, wrapper::UNSIGNED_BYTE, data);
    }

    void texture2D::update(
            const gloop::sizei_t level,
            const gloop::int_t xOffset, const gloop::int_t yOffset,
            const gloop::sizei_t width, const gloop::sizei_t height,
            const gloop::pixel_formats::R8_G8_B8_A8* data) const {

        wrapper::textureSubImage2D(_id, level, xOffset, yOffset, width, height, wrapper::RGBA, wrapper::UNSIGNED_BYTE, data);
    }
    
    void texture2D::update(
    const gloop::sizei_t level, 
            const gloop::int_t xOffset, const gloop::int_t yOffset, 
            const gloop::sizei_t width, const gloop::sizei_t height,
            const gloop::enums::texture_format format, 
            const gloop::enums::texture_pixel_pack pixelPack, 
            const gloop::buffer& buffer, const gloop::intptr_t offset) const {
        
        constexpr auto TARGET = static_cast<gloop::enum_t> (gloop::enums::buffer_target::PIXEL_UNPACK);        
        const void * pOffset = (const void *) offset;
        auto eFormat = static_cast<gloop::enum_t> (format);
        auto eType = static_cast<gloop::enum_t> (pixelPack);
        
        
        wrapper::bindBuffer(TARGET, buffer.getId());
        wrapper::textureSubImage2D(_id, level, xOffset, yOffset, width, height, eFormat, eType, pOffset);
        wrapper::bindBuffer(TARGET, 0);
    }

    void texture2D::free() {
        if (isValid()) {
            throw "Deleting";
            wrapper::deleteTextures(1, &_id);
            _id = 0;
            _format = static_cast<enums::texture_internal_format> (0);
            _size.width = 0;
            _size.height = 0;
            _levels = 0;
        }
    }

    void texture2D::bind(const gloop::uint_t unit) const {
        if (isValid()) {
            wrapper::bindTextureUnit(unit, _id);
        }
    }

    void texture2D::setParameters(const gloop::states::texture2D_parameters& params) {
        _params = std::make_unique<states::texture2D_parameters> (params);

        if (isValid()) {
            wrapper::textureParameteri(_id, wrapper::TEXTURE_MAG_FILTER, static_cast<gloop::int_t> (_params->getMagFilter()));
            wrapper::textureParameteri(_id, wrapper::TEXTURE_MIN_FILTER, static_cast<gloop::int_t> (_params->getMinFilter()));
            wrapper::textureParameteri(_id, wrapper::TEXTURE_WRAP_S, static_cast<gloop::int_t> (_params->getWrapS()));
            wrapper::textureParameteri(_id, wrapper::TEXTURE_WRAP_T, static_cast<gloop::int_t> (_params->getWrapT()));
            wrapper::textureParameterf(_id, wrapper::TEXTURE_MAX_ANISOTROPY, _params->getAnisotropic());
        }
    }

    const states::texture2D_parameters& texture2D::getParameters() const {
        return *_params;
    }

    std::ostream& operator<<(std::ostream& os, const texture2D::size& s) {
        return os << "size: <"
                << s.width
                << ", "
                << s.height
                << ">";
    }

    std::ostream& operator<<(std::ostream& os, const texture2D& t) {
        os << "texture2D: [";

        if (t.isValid()) {
            os << "id: " << t._id;
            os << ", format: " << t._format;
            os << ", levels: " << t._levels;
            os << ", " << t._size;
            os << ", " << *t._params;
            os << "]";
        } else {
            os << "UNINITIALIZED]";
        }

        return os;
    }
}
