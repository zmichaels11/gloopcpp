#pragma once

#include <iostream>

#include "../glint.hpp"

namespace gloop {
	namespace enums {
		enum class depth_func : gloop::enum_t {
			UNKNOWN = 0xFFFF,
			NEVER = 512,
			ALWAYS = 519,
			LESS = 513,
			GREATER = 516,
			EQUAL = 514,
			LEQUAL = 515,
			GEQUAL = 518,
			NOTEQUAL = 517
		};

		inline std::ostream& operator<<(std::ostream& os, depth_func enumval) {
			switch (enumval) {
				case depth_func::NEVER:
					return os << "NEVER";
				case depth_func::ALWAYS:
					return os << "ALWAYS";
				case depth_func::LESS:
					return os << "LESS";
				case depth_func::GREATER:
					return os << "GREATER";
				case depth_func::EQUAL:
					return os << "EQUAL";
				case depth_func::LEQUAL:
					return os << "LEQUAL";
				case depth_func::GEQUAL:
					return os << "GEQUAL";
				case depth_func::NOTEQUAL:
					return os << "NOTEQUAL";
				default:
					return os << "UNKNOWN";
			}
		}
	}
}
