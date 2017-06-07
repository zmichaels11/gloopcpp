#include "blend_eq.hpp"

#include <iostream>

namespace gloop {
	namespace enums {
		std::ostream& operator<<(std::ostream& os, const blend_eq enumval) {
			switch (enumval) {
				case blend_eq::ADD:
					return os << "ADD";
				case blend_eq::SUBTRACT:
					return os << "SUBTRACT";
				case blend_eq::REVERSE_SUBTRACT:
					return os << "REVERSE_SUBTRACT";
				case blend_eq::MIN:
					return os << "MIN";
				case blend_eq::MAX:
					return os << "MAX";
				default:
					return os << "UNKNOWN";
			}
		}
	}
}
