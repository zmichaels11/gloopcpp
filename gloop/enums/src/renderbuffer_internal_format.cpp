#include "renderbuffer_internal_format.hpp"

#include <iostream>

namespace gloop {
	namespace enums {
		std::ostream& operator<<(std::ostream& os, renderbuffer_internal_format enumval) {
			switch (enumval) {
				case renderbuffer_internal_format::DEPTH16:
					return os << "DEPTH16";
				case renderbuffer_internal_format::R4_G4_B4_A4:
					return os << "R4_G4_B4_A4";
				case renderbuffer_internal_format::R5_G5_B5_A1:
					return os << "R5_G5_B5_A1";
				case renderbuffer_internal_format::R5_G6_B5:
					return os << "R5_G6_B5";
				case renderbuffer_internal_format::STENCIL_INDEX8:
					return os << "STENCIL_INDEX8";
				default:
					return os << "UNKNOWN";
			}
		}
	}
}
