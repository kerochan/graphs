#pragma once
#include<random>
#include "grid_graph.hpp"
namespace mylib {
	class maze {
	public:
		template<typename T>
		//–À˜H‚ğì¬‚·‚é
		static void create(grid_graph<T>& graph);
	
	private:

	};

	template<typename T>
	void maze::create(grid_graph<T>& graph) {
		std::mt19937 engine;
		std::uniform_int_distribution<> dist(0, graph.get_width() * graph.get_height() - 1);
		
		



	}
}


