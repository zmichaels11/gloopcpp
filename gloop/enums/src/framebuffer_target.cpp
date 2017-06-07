#include "framebuffer_target.hpp"

#include <iostream>

namespace gloop {
	namespace enums {
		std::ostream& operator<<(std::ostream& os, framebuffer_target tgt) {
			switch (tgt) {
				case framebuffer_target::FRAMEBUFFER:
					return os << "FRAMEBUFFER";
				default:
					return os << "UNKNOWN";
			}
		}
	}
}
