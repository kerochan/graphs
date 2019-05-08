#pragma once
#include "mylib.hpp"
namespace mylib {
	class cost {
	public:
		virtual const int operator()(const type_id id1, const type_id id2) const noexcept = 0;
	};



	class cost_mono : public cost {
	public:
		const int operator()(const type_id id1, const type_id id2) const noexcept;
	};

	

	

}
