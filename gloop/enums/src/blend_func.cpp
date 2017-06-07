#include "blend_func.hpp"

#include <iostream>

namespace gloop {
	namespace enums {
		std::ostream& operator<<(std::ostream& os, blend_func enumval) {
			switch (enumval) {
				case blend_func::ZERO:
					return os << "ZERO";
				case blend_func::ONE:
					return os << "ONE";
				case blend_func::SRC_COLOR:
					return os << "SRC_COLOR";
				case blend_func::ONE_MINUS_SRC_COLOR:
					return os << "ONE_MINUS_SRC_COLOR";
				case blend_func::DST_COLOR:
					return os << "DST_COLOR";
				case blend_func::ONE_MINUS_DST_COLOR:
					return os << "ONE_MINUS_DST_COLOR";
				case blend_func::SRC_ALPHA:
					return os << "SRC_ALPHA";
				case blend_func::ONE_MINUS_SRC_ALPHA:
					return os << "ONE_MINUS_SRC_ALPHA";
				case blend_func::DST_ALPHA:
					return os << "DST_ALPHA";
				case blend_func::ONE_MINUS_DST_ALPHA:
					return os << "ONE_MINUS_DST_ALPHA";
				case blend_func::CONSTANT_COLOR:
					return os << "CONSTANT_COLOR";
				case blend_func::ONE_MINUS_CONSTANT_COLOR:
					return os << "ONE_MINUS_CONSTANT_COLOR";
				case blend_func::CONSTANT_ALPHA:
					return os << "CONSTANT_ALPHA";
				case blend_func::ONE_MINUS_CONSTANT_ALPHA:
					return os << "ONE_MINUS_CONSTANT_ALPHA";
				default:
					return os << "UNKNOWN";
			}
		}
	}
}
					
