#pragma once

#include <iostream>
#include <stack>

#include "../glint.hpp"

namespace gloop {
	namespace enums {
		enum class depth_func : gloop::enum_t;
	}

	namespace states {

		class depth_test {
		private:
			static std::stack<depth_test> DEPTH_TEST_STACK;
			static depth_test CURRENT_DEPTH_TEST;

		public:
			static void push();
			static depth_test pop();
			static const depth_test& getCurrentDepthTest();

		private:
			bool _enabled;
			enums::depth_func _depthFunc;

		public:
			depth_test();

			depth_test(
				const bool enabled,
				const enums::depth_func depthFunc) :

				_enabled(enabled),
				_depthFunc(depthFunc) {}

			depth_test withEnabled(const bool enabled) const;

			depth_test withDepthFunc(const enums::depth_func depthFunc) const;

			bool isEnabled() const;

			enums::depth_func getDepthFunc() const;

			void apply() const;

			inline void operator()() const {
				this->apply();
			}

			friend std::ostream& operator<<(std::ostream& os, const depth_test& dt);
		};
	}
}
