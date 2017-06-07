/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "blend_mode.hpp"

#include "../gloop/enums/blend_eq.hpp"
#include "../gloop/enums/blend_func.hpp"
#include "../gloop/states/blend.hpp"

namespace {
    static const gloop::states::blend _min(
            true,
            gloop::enums::blend_func::ONE, gloop::enums::blend_func::ONE,
            gloop::enums::blend_func::SRC_ALPHA, gloop::enums::blend_func::ONE_MINUS_SRC_ALPHA,
            gloop::enums::blend_eq::MIN, gloop::enums::blend_eq::ADD);

    static const gloop::states::blend _max(
            true,
            gloop::enums::blend_func::ONE, gloop::enums::blend_func::ONE,
            gloop::enums::blend_func::SRC_ALPHA, gloop::enums::blend_func::ONE_MINUS_SRC_ALPHA,
            gloop::enums::blend_eq::MAX, gloop::enums::blend_eq::ADD);

    static const gloop::states::blend _normal(
            true,
            gloop::enums::blend_func::SRC_ALPHA, gloop::enums::blend_func::ONE_MINUS_SRC_ALPHA,
            gloop::enums::blend_func::ONE, gloop::enums::blend_func::ONE_MINUS_SRC_ALPHA,
            gloop::enums::blend_eq::ADD, gloop::enums::blend_eq::ADD);

    static const gloop::states::blend _add(
            true,
            gloop::enums::blend_func::SRC_ALPHA, gloop::enums::blend_func::ONE,
            gloop::enums::blend_func::ONE, gloop::enums::blend_func::ONE_MINUS_SRC_ALPHA,
            gloop::enums::blend_eq::ADD, gloop::enums::blend_eq::ADD);

    static const gloop::states::blend _subtract(
            true,
            gloop::enums::blend_func::SRC_ALPHA, gloop::enums::blend_func::ONE,
            gloop::enums::blend_func::ONE, gloop::enums::blend_func::ONE_MINUS_SRC_ALPHA,
            gloop::enums::blend_eq::REVERSE_SUBTRACT, gloop::enums::blend_eq::ADD);

    static const gloop::states::blend _multiply(
            true,
            gloop::enums::blend_func::DST_COLOR, gloop::enums::blend_func::ONE_MINUS_SRC_ALPHA,
            gloop::enums::blend_func::ONE, gloop::enums::blend_func::ONE_MINUS_SRC_ALPHA,
            gloop::enums::blend_eq::ADD, gloop::enums::blend_eq::ADD);

    static const gloop::states::blend _multiplyAdd(
            true,
            gloop::enums::blend_func::DST_COLOR, gloop::enums::blend_func::ONE_MINUS_SRC_ALPHA,
            gloop::enums::blend_func::ONE, gloop::enums::blend_func::ONE_MINUS_SRC_ALPHA,
            gloop::enums::blend_eq::ADD, gloop::enums::blend_eq::ADD);

    static const gloop::states::blend _linearDodge(
            true,
            gloop::enums::blend_func::ONE, gloop::enums::blend_func::ONE,
            gloop::enums::blend_func::ONE, gloop::enums::blend_func::ONE_MINUS_SRC_ALPHA,
            gloop::enums::blend_eq::ADD, gloop::enums::blend_eq::ADD);

    static const gloop::states::blend _none(
            true,
            gloop::enums::blend_func::ONE, gloop::enums::blend_func::ZERO,
            gloop::enums::blend_func::ONE, gloop::enums::blend_func::ZERO,
            gloop::enums::blend_eq::ADD, gloop::enums::blend_eq::ADD);

    static const gloop::states::blend _screen(
            true,
            gloop::enums::blend_func::ONE_MINUS_DST_COLOR, gloop::enums::blend_func::ONE,
            gloop::enums::blend_func::ONE, gloop::enums::blend_func::ONE_MINUS_SRC_ALPHA,
            gloop::enums::blend_eq::ADD, gloop::enums::blend_eq::ADD);

    static const gloop::states::blend _preMultiplied(
            true,
            gloop::enums::blend_func::ONE, gloop::enums::blend_func::ONE_MINUS_SRC_ALPHA,
            gloop::enums::blend_func::ONE, gloop::enums::blend_func::ZERO,
            gloop::enums::blend_eq::ADD, gloop::enums::blend_eq::ADD);
}
namespace glgfx {

    void apply(blend_mode blend) {
        switch (blend) {
            case blend_mode::NORMAL:
                _normal();
                break;
            case blend_mode::MIN:
                _min();
                break;
            case blend_mode::MAX:
                _max();
                break;
            case blend_mode::ADD:
                _add();
                break;
            case blend_mode::SUBTRACT:
                _subtract();
                break;
            case blend_mode::MULTIPLY:
                _multiply();
                break;
            case blend_mode::MULTIPLY_ADD:
                _multiplyAdd();
                break;
            case blend_mode::SCREEN:
                _screen();
                break;
            case blend_mode::LINEAR_DODGE:
                _linearDodge();
                break;
            case blend_mode::PRE_MULTIPLIED:
                _preMultiplied();
                break;
            case blend_mode::NONE:
                _none();
                break;
            default:
                _normal();
                break;
        }
    }
}