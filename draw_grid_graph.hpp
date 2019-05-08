#pragma once
#include<iostream>
#include<string>
#include"grid_graph.hpp"
namespace mylib {

	class draw_grid_graph_cui {
	public:
		template<typename T>
		static void draw(const grid_graph<T>& graph);
		
		template<typename T>
		static void draw_at(const grid_graph<T>& graph, const int w, const int h);
		
		static void clear();
	};


	template<typename T>
	static void draw_grid_graph_cui::draw(const grid_graph<T>& graph) {
		
		for (int h = 0; h < graph.get_height(); h++) {
			for (int w = 0; w < graph.get_width(); w++) {

				if (graph.get_graph().at(h * graph.get_width() + w).empty())
					std::cout << "#";
				else
					std::cout << " ";
				
			}
			std::cout << std::endl;
		}
		
	}

	template<typename T>
	static void draw_grid_graph_cui::draw_at(const grid_graph<T>& graph, const int width, const int height) {
		std::cout << "\033[" << std::to_string(height) << "B" << std::flush;

		for (int h = 0; h < graph.get_height(); h++) {
			std::cout << "\033[" << std::to_string(width) << "C" << std::flush;
			for (int w = 0; w < graph.get_width(); w++) {
				if (graph.get_graph().at(h * graph.get_width() + w).empty())
					std::cout << "#";
				else
					std::cout << " ";
			}
			std::cout << std::endl;
		}

	}

	void draw_grid_graph_cui::clear() {
		std::cout << "\033[2J" << std::flush;
	}

}
