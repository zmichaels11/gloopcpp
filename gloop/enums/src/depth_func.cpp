#include "depth_func.hpp"

#include <iostream>

namespace gloop {
	namespace enums {
		std::ostream& operator<<(std::ostream& os, depth_func enumval) {
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
