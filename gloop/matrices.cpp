/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cmath>

#include "matrices.hpp"
#include "states/depth_range.hpp"
#include "states/viewport.hpp"

namespace gloop {

    mat4 matrices::rotationX4F(float angle) {
        auto sa = std::sin(angle);
        auto ca = std::cos(angle);

        return rotationX4F(sa, ca);
    }

    mat4 matrices::rotationY4F(float angle) {
        auto sa = std::sin(angle);
        auto ca = std::cos(angle);

        return rotationY4F(sa, ca);
    }

    mat4 matrices::rotationZ4F(float angle) {
        auto sa = std::sin(angle);
        auto ca = std::cos(angle);

        return rotationZ4F(sa, ca);
    }

    mat4 matrices::ortho4F(const gloop::states::viewport& view) {
        auto offset = view.getOffset();
        auto size = view.getSize();
        auto depth = view.getDepthRange();

        float left = offset.x;
        float right = left + size.width;
        float top = offset.y;
        float bottom = top + size.height;
        float near = (float) depth.near;
        float far = (float) depth.far;

        return ortho4F(left, right, bottom, top, near, far);
    }

    mat4 matrices::makePerspective4F(float fov, float aspect, float near, float far) {
        constexpr float PI = 3.14159265358F;

        fov = 1.0F / std::tan(fov * PI / 180.0F * 0.5F);
        return perspective4F(fov, aspect, near, far);
    }

    void matrices::setRow(mat4& inout, int rowId, const vec4& in) {
        inout[rowId * 4] = in[0];
        inout[rowId * 4 + 1] = in[1];
        inout[rowId * 4 + 2] = in[2];
        inout[rowId * 4 + 3] = in[3];
    }

    void matrices::setRow(mat5& inout, int rowId, const vec5& in) {
        inout[rowId * 5] = in[0];
        inout[rowId * 5 + 1] = in[1];
        inout[rowId * 5 + 2] = in[2];
        inout[rowId * 5 + 3] = in[3];
        inout[rowId * 5 + 4] = in[4];
    }

    float vectors::length(const vec4& in) {
        return std::sqrt(length2(in));
    }

	float vectors::length(const vec3& in) {
		return std::sqrt(length2(in));
	}

	float vectors::length(const vec2& in) {
		return std::sqrt(length2(in));
	}
}
