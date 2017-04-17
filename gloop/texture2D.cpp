/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "texture2D.hpp"

#include "enums/texture_internal_format.hpp"
#include "glint.hpp"
#include "wrapper/texture_objects.hpp"
#include "wrapper/gl.hpp"
#include "tools.hpp"

namespace gloop {

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
            const gloop::pixel_formats::B8_R8_G8_A8* data) const {

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
    
    void texture2D::free() {
        if (isValid()) {
            wrapper::deleteTextures(1, &_id);
            _id = 0;
            _format = static_cast<enums::texture_internal_format> (0);
            _size.width = 0;
            _size.height = 0;
            _levels = 0;
        }
    }
    
    void texture2D::bind(const gloop::uint_t unit) const {
        wrapper::bindTextureUnit(unit, _id);
    }
}