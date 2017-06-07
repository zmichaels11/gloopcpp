#include "depth_test.hpp"

#include <iostream>
#include <stack>

#include "../enums/depth_func.hpp"
#include "../exception/invalid_operation_exception.hpp"
#include "../gloop_throw.hpp"
#include "../wrapper/states.hpp"

namespace gloop {
	namespace states {
		depth_test depth_test::CURRENT_DEPTH_TEST;
		std::stack<depth_test> depth_test::DEPTH_TEST_STACK;

		void depth_test::push() {
			DEPTH_TEST_STACK.push(CURRENT_DEPTH_TEST);
		}

		depth_test depth_test::pop() {
			if (DEPTH_TEST_STACK.empty()) {
				gloop_throw(gloop::exception::invalid_operation_exception("Attempted to pop empty stack!"));
			} else {
				depth_test current = CURRENT_DEPTH_TEST;
				depth_test restore = DEPTH_TEST_STACK.top();

				DEPTH_TEST_STACK.pop();

				restore();

				return current;
			}
		}

		const depth_test& depth_test::getCurrentDepthTest() {
			return CURRENT_DEPTH_TEST;
		}

		std::ostream& operator<<(std::ostream& os, const depth_test& dt) {
			return os << "depth_test: ["
					<< "func: " << dt._depthFunc
					<< "]";
		}

		depth_test::depth_test() {
			_enabled = false;
			_depthFunc = enums::depth_func::LESS;
		}

		depth_test depth_test::withEnabled(const bool enabled) const {
			return depth_test(enabled, _depthFunc);
		}

		depth_test depth_test::withDepthFunc(const enums::depth_func depthFunc) const {
			return depth_test(_enabled, depthFunc);
		}

		enums::depth_func depth_test::getDepthFunc() const {
			return _depthFunc;
		}

		bool depth_test::isEnabled() const {
			return _enabled;
		}

		void depth_test::apply() const {
			CURRENT_DEPTH_TEST = *this;

			if (_enabled) {
				gloop::wrapper::enable(gloop::wrapper::DEPTH_TEST);

				gloop::wrapper::depthFunc(static_cast<gloop::enum_t> (_depthFunc));					
			} else {
				gloop::wrapper::disable(gloop::wrapper::DEPTH_TEST);
			}
		}
	}
}
