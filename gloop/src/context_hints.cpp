#include "context_hints.hpp"

#include <iostream>

namespace gloop {
	std::ostream& operator<< (std::ostream& os, context_profile cp) {
		switch (cp) {
			case context_profile::CORE:
				return os << "CORE";
			case context_profile::ES:
				return os << "ES";
			case context_profile::COMPATIBILITY:
				return os << "COMPATIBILITY";
			default:
				return os << "UNKNOWN";
		}
	}	

	std::ostream& operator<< (std::ostream& os, const context_hints& ch) {
		return os << "Context Hints: ["
			<< "version: " << ch.version.major << "." << ch.version.minor
			<< " profile: " << ch.profile
			<< " swapInterval: " << ch.swapInterval
			<< " doubleBuffer: " << (ch.doubleBuffer ? "true" : "false")
			<< "]";
	}
}
