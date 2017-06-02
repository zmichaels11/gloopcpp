/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   matrices.hpp
 * Author: zmichaels
 *
 * Created on April 25, 2017, 9:47 AM
 */

#pragma once

#include <array>

#include <iostream>

namespace gloop {
    typedef std::array<float, 4> mat2;
    typedef std::array<float, 9> mat3;
    typedef std::array<float, 16> mat4;
    typedef std::array<float, 25> mat5;

    typedef std::array<float, 2> vec2;
    typedef std::array<float, 3> vec3;
    typedef std::array<float, 4> vec4;
    typedef std::array<float, 5> vec5;	

    namespace states {
        class viewport;
    }

	template <class vec_t>
	constexpr float x(const vec_t& v) {
		return v[0];
	}

	template <class vec_t>
	constexpr float y(const vec_t& v) {
		return v[1];
	}

	template <class vec_t>
	constexpr float z(const vec_t& v) {
		return v[2];
	}

	template <class vec_t>
	constexpr float w(const vec_t& v) {
		return v[3];
	}

	template <class vec_t>
	constexpr float& x(vec_t& v) {
		return v[0];
	}

	template <class vec_t>
	constexpr float& y(vec_t& v) {
		return v[1];
	}

	template <class vec_t>
	constexpr float& z(vec_t& v) {
		return v[2];
	}

	template <class vec_t>
	constexpr float& w(vec_t& v) {
		return v[3];
	}

    namespace matrices {

        constexpr mat4 createMat4(const vec4& v0, const vec4& v1, const vec4& v2, const vec4& v3) {
            return {
                x(v0), y(v0), z(v0), w(v0),
                x(v1), y(v1), z(v1), w(v1),
                x(v2), y(v2), z(v2), w(v2),
                x(v3), y(v3), z(v3), w(v3)};
        }

		constexpr mat3 createMat3(const vec3& v0, const vec3& v1, const vec3& v2) {
			return {
				x(v0), y(v0), z(v0),
				x(v1), y(v1), z(v1),
				x(v2), y(v2), z(v2)};
		}

		constexpr mat2 createMat2(const vec2& v0, const vec2& v1) {
			return {
				x(v0), y(v0),
				x(v1), y(v1)};
		}

        constexpr mat4 identity4F() {
            return {
                1.0F, 0.0F, 0.0F, 0.0F,
                0.0F, 1.0F, 0.0F, 0.0F,
                0.0F, 0.0F, 1.0F, 0.0F,
                0.0F, 0.0F, 0.0F, 1.0F};
        }

		constexpr mat3 identity3F() {
			return {
				1.0F, 0.0F, 0.0F,
				0.0F, 1.0F, 0.0F,
				0.0F, 0.0F, 1.0F};
		}

		constexpr mat2 identity2F() {
			return {
				1.0F, 0.0F,
				0.0F, 1.0F};
		}

        constexpr mat4 rotationX4F(float sa, float ca) {
            return mat4{
                1.0F, 0.0F, 0.0F, 0.0F,
                0.0F, ca, sa, 0.0F,
                0.0F, -sa, ca, 0.0F,
                0.0F, 0.0F, 0.0F, 1.0F};
        }

        mat4 rotationX4F(float angle);

        constexpr mat4 rotationY4F(float sa, float ca) {
            return mat4{
                ca, 0.0F, -sa, 0.0F,
                0.0F, 1.0F, 0.0F, 0.0F,
                sa, 0.0F, ca, 0.0F,
                0.0F, 0.0F, 0.0F, 1.0F};
        }

        mat4 rotationY4F(float angle);

        constexpr mat4 rotationZ4F(float sa, float ca) {
            return mat4{
                ca, sa, 0.0F, 0.0F,
                -sa, ca, 0.0F, 0.0F,
                0.0F, 0.0F, 1.0F, 0.0F,
                0.0F, 0.0F, 0.0F, 1.0F};
        }

		constexpr mat3 rotation3F(float sa, float ca) {
			return mat3{
				ca, sa, 0.0F,
				-sa, ca, 0.0F,
				0.0F, 0.0F, 1.0F};
		}

        mat4 rotationZ4F(float angle);

		mat3 rotation3F(float angle);

        constexpr mat4 translation4F(float x, float y, float z, float w) {
            return mat4{
                1.0F, 0.0F, 0.0F, 0.0F,
                0.0F, 1.0F, 0.0F, 0.0F,
                0.0F, 0.0F, 1.0F, 0.0F,
                x, y, z, w};
        }

		constexpr mat3 translation3F(float x, float y, float z) {
			return {
				1.0F, 0.0F, 0.0F,
				0.0F, 1.0F, 0.0F,
				x, y, z};
		}

		constexpr mat2 translation2F(float x, float y) {
			return {
				1.0F, 0.0F,
				x, y};
		}

        constexpr mat4 translation4F(const vec4& v) {
            return translation4F(x(v), y(v), z(v), w(v));
        }

		constexpr mat3 translation3F(const vec3& v) {
			return translation3F(x(v), y(v), z(v));
		}

		constexpr mat2 translation2F(const vec2& v) {
			return translation2F(x(v), y(v));
		}

        constexpr mat4 scale4F(float x, float y, float z, float w) {
            return {
                x, 0.0F, 0.0F, 0.0F,
                0.0F, y, 0.0F, 0.0F,
                0.0F, 0.0F, z, 0.0F,
                0.0F, 0.0F, 0.0F, w};
        }

		constexpr mat3 scale3F(float x, float y, float z) {
			return {
				x, 0.0F, 0.0F,
				0.0F, y, 0.0F,
				0.0F, 0.0F, z};
		}

		constexpr mat2 scale2F(float x, float y) {
			return {
				x, 0.0F,
				0.0F, y};
		}

        constexpr mat4 scale4F(const vec4& v) {
            return scale4F(x(v), y(v), z(v), w(v));
        }

		constexpr mat3 scale3F(const vec3& v) {
			return scale3F(x(v), y(v), z(v));
		}

		constexpr mat2 scale2F(const vec2& v) {
			return scale2F(x(v), y(v));
		}

        constexpr mat4 ortho4F(float left, float right, float bottom, float top, float near, float far) {
            return {
                2.0F / (right - left), 0.0F, 0.0F, 0.0F,
                0.0F, 2.0F / (top - bottom), 0.0F, 0.0F,
                0.0F, 0.0F, -2.0F / (far - near), 0.0F,
                -(right + left) / (right - left), -(top + bottom) / (top - bottom), -(far + near) / (far - near), 1.0F};
        }

        mat4 ortho4F(const gloop::states::viewport& view);

        constexpr mat4 perspective4F(float fov, float aspect, float near, float far) {
            return {
                fov / aspect, 0.0F, 0.0F, 0.0F,
                0.0F, fov, 0.0F, 0.0F,
                0.0F, 0.0F, (far + near) / (far - near), -1.0F,
                0.0F, 0.0F, (2.0F * far * near) / (near - far), 0.0F};
        }

        mat4 makePerspective4F(float fov, float aspect, float near, float far);        
        
        constexpr mat4 multiply(const mat4& in0, const mat4& in1) {
            return {
                in0[0] * in1[0] + in0[1] * in1[4] + in0[2] * in1[8] + in0[3] * in1[12],
                in0[0] * in1[1] + in0[1] * in1[5] + in0[2] * in1[9] + in0[3] * in1[13],
                in0[0] * in1[2] + in0[1] * in1[6] + in0[2] * in1[10] + in0[3] * in1[14],
                in0[0] * in1[3] + in0[1] * in1[7] + in0[2] * in1[11] + in0[3] * in1[15],
                in0[4] * in1[0] + in0[5] * in1[4] + in0[6] * in1[8] + in0[7] * in1[12],
                in0[4] * in1[1] + in0[5] * in1[5] + in0[6] * in1[9] + in0[7] * in1[13],
                in0[4] * in1[2] + in0[5] * in1[6] + in0[6] * in1[10] + in0[7] * in1[14],
                in0[4] * in1[3] + in0[5] * in1[7] + in0[6] * in1[11] + in0[7] * in1[15],
                in0[8] * in1[0] + in0[9] * in1[4] + in0[10] * in1[8] + in0[11] * in1[12],
                in0[8] * in1[1] + in0[9] * in1[5] + in0[10] * in1[9] + in0[11] * in1[13],
                in0[8] * in1[2] + in0[9] * in1[6] + in0[10] * in1[10] + in0[11] * in1[14],
                in0[8] * in1[3] + in0[9] * in1[7] + in0[10] * in1[11] + in0[11] * in1[15],
                in0[12] * in1[0] + in0[13] * in1[4] + in0[14] * in1[8] + in0[15] * in1[12],
                in0[12] * in1[1] + in0[13] * in1[5] + in0[14] * in1[9] + in0[15] * in1[13],
                in0[12] * in1[2] + in0[13] * in1[6] + in0[14] * in1[10] + in0[15] * in1[14],
                in0[12] * in1[3] + in0[13] * in1[7] + in0[14] * in1[11] + in0[15] * in1[15]};
        }        

        constexpr vec4 multiply(const mat4& in0, const vec4& in1) {
            return {
                in0[0] * in1[0] + in0[4] * in1[1] + in0[8] * in1[2] + in0[12] * in1[3],
                in0[1] * in1[0] + in0[5] * in1[1] + in0[9] * in1[2] + in0[13] * in1[3],
                in0[2] * in1[0] + in0[6] * in1[1] + in0[10] * in1[2] + in0[14] * in1[3],
                in0[3] * in1[0] + in0[7] * in1[1] + in0[11] * in1[2] + in0[15] * in1[3]};
        }

        constexpr vec4 getRow(vec4& out, const mat4& in, int rowId) {
            return {in[4 * rowId], in[4 * rowId + 1], in[4 * rowId + 2], in[4 * rowId + 3]};
        }

        constexpr vec5 getRow(vec5& out, const mat5& in, int rowId) {
            return {in[5 * rowId], in[5 * rowId + 1], in[5 * rowId + 3], in[5 * rowId + 4]};
        }

        void setRow(mat4& inout, int rowId, const vec4& in);

        void setRow(mat5& inout, int rowId, const vec5& in);
    }

    namespace vectors {

        constexpr vec4 add(const vec4& in0, const vec4& in1) {
            return {
                x(in0) + x(in1),
                y(in0) + y(in1),
                z(in0) + z(in1),
                w(in0) + w(in1)};
        }

		constexpr vec3 add(const vec3& in0, const vec3& in1) {
			return vec3{
				x(in0) + x(in1),
				y(in0) + y(in1),
				z(in0) + z(in1)};
		}

		constexpr vec2 add(const vec2& in0, const vec2& in1) {
			return vec2{
				x(in0) + x(in1),
				y(in0) + y(in1)};
		}		

        constexpr vec4 subtract(const vec4& in0, const vec4& in1) {
            return vec4{
                x(in0) - x(in1),
                y(in0) - y(in1),
                z(in0) - z(in1),
                w(in0) - w(in1)};
        }

		constexpr vec3 subtract(const vec3& in0, const vec3& in1) {
			return vec3{
				x(in0) - x(in1),
				y(in0) - y(in1),
				z(in0) - z(in1)};
		}

		constexpr vec2 subtract(const vec2& in0, const vec2& in1) {
			return vec2{
				x(in0) - x(in1),
				y(in0) - y(in1)};
		}

        constexpr vec4 scale(const vec4& in0, float scale) {
            return vec4{
                x(in0) * scale,
                y(in0) * scale,
                z(in0) * scale,
                w(in0) * scale};
        }

		constexpr vec3 scale(const vec3& in0, float scale) {
			return vec3{
				x(in0) * scale,
				y(in0) * scale,
				z(in0) * scale};
		}

		constexpr vec2 scale(const vec2& in0, float scale) {
			return {
				x(in0) * scale,
				y(in0) * scale};
		}

        constexpr vec4 scale(const vec4& in0, const vec4& in1) {
            return {
                x(in0) * x(in1),
                y(in0) * y(in1),
                z(in0) * z(in1),
                w(in0) * w(in1)};
        }

		constexpr vec3 scale(const vec3& in0, const vec3& in1) {
			return {
				x(in0) * x(in1),
				y(in0) * y(in1),
				z(in0) * z(in1)};
		}

		constexpr vec2 scale(const vec2& in0, const vec2& in1) {
			return {
				x(in0) * x(in1),
				y(in0) * y(in1)};
		}

        constexpr float dot(const vec4& in0, const vec4& in1) {
            return x(in0) * x(in1)
                    + y(in0) * y(in1)
                    + z(in0) * z(in1)
                    + w(in0) * w(in1);
        }

		constexpr float dot(const vec3& in0, const vec3& in1) {
			return x(in0) * x(in1)
				+ y(in0) * y(in1)
				+ z(in0) * z(in1);
		}

		constexpr float dot(const vec2& in0, const vec2& in1) {
			return x(in0) * x(in1) + y(in0) * y(in1);
		}

        constexpr float length2(const vec4& in) {
            return dot(in, in);
        }

		constexpr float length2(const vec3& in) {
			return dot(in, in);
		}

		constexpr float length2(const vec2& in) {
			return dot(in, in);
		}

        float length(const vec4& in);

		float length(const vec3& in);

		float length(const vec2& in);

		constexpr vec4 asVec4(const vec3& in, float w = 0.0F) {
			return vec4{in[0], in[1], in[2], w};
		}

		constexpr vec4 asVec4(const vec2& in, float y = 0.0F, float z = 0.0F) {
			return vec4{in[0], in[1], y, z};
		}

		constexpr vec3 asVec3(const vec4& in) {
			return vec3{in[0], in[1], in[2]};
		}

		constexpr vec3 asVec3(const vec2& in, float z = 0.0F) {
			return vec3{in[0], in[1], z};
		}

		constexpr vec2 asVec2(const vec4& in) {
			return vec2{in[0], in[1]};
		}

        constexpr vec2 asVec2(const vec3& in) {
            return vec2{in[0], in[1]};
        }
    }	
}

inline std::ostream& operator<<(std::ostream& os, const gloop::vec2& v) {
	return os << "<"
		<< gloop::x(v) << ", "
		<< gloop::y(v) << ">";
}

inline std::ostream& operator<<(std::ostream& os, const gloop::vec3& v) {
	return os << "<"
		<< gloop::x(v) << ", "
		<< gloop::y(v) << ", "
		<< gloop::z(v) << ">";
}

inline std::ostream& operator<<(std::ostream& os, const gloop::vec4& v) {
	return os << "<"
		<< gloop::x(v) << ", "
		<< gloop::y(v) << ", "
		<< gloop::z(v) << ", "
		<< gloop::w(v) << ">";
}

constexpr gloop::vec2 operator+(const gloop::vec2& in0, const gloop::vec2& in1) {
	return gloop::vectors::add(in0, in1);
}

constexpr gloop::vec3 operator+(const gloop::vec3& in0, const gloop::vec3& in1) {
	return gloop::vectors::add(in0, in1);
}

constexpr gloop::vec4 operator+(const gloop::vec4& in0, const gloop::vec4& in1) {
	return gloop::vectors::add(in0, in1);
}

constexpr gloop::vec2 operator-(const gloop::vec2& in0, const gloop::vec2& in1) {
	return gloop::vectors::subtract(in0, in1);
}

constexpr gloop::vec3 operator-(const gloop::vec3& in0, const gloop::vec3& in1) {
	return gloop::vectors::subtract(in0, in1);
}

constexpr gloop::vec4 operator-(const gloop::vec4& in0, const gloop::vec4& in1) {
	return gloop::vectors::subtract(in0, in1);
}

constexpr gloop::vec2 operator*(const gloop::vec2& in0, float scalar) {
	return gloop::vectors::scale(in0, scalar);
}

constexpr gloop::vec3 operator*(const gloop::vec3& in0, float scalar) {
	return gloop::vectors::scale(in0, scalar);
}

constexpr gloop::vec4 operator*(const gloop::vec4& in0, float scalar) {
	return gloop::vectors::scale(in0, scalar);
}

constexpr gloop::vec2 operator/(const gloop::vec2& in0, float scalar) {
	return gloop::vectors::scale(in0, 1.0F / scalar);
}

constexpr gloop::vec3 operator/(const gloop::vec3& in0, float scalar) {
	return gloop::vectors::scale(in0, 1.0F / scalar);
}

constexpr gloop::vec4 operator/(const gloop::vec4& in0, float scalar) {
	return gloop::vectors::scale(in0, 1.0F / scalar);
}

constexpr gloop::mat4 operator*(const gloop::mat4& in0, const gloop::mat4& in1) {
	return gloop::matrices::multiply(in0, in1);
}

constexpr gloop::vec4 operator*(const gloop::mat4& in0, const gloop::vec4& in1) {
	return gloop::matrices::multiply(in0, in1);
}
