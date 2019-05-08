#include"cost.hpp"

namespace mylib {
	const int cost_mono::operator()(const type_id id1, const type_id id2) const noexcept {
		return 1;
	}
}