#pragma once
#include"undirected_graph.hpp"

namespace mylib {
	template <typename T>
	class grid_graph : public undirected_graph<T>{
		
		//二次元グラフの幅と高さ
		int _width = 0, _height = 0;

	public:
		
		grid_graph(const int width, const int height);

		void adjacent_nodes(const type_id id1, const type_id id2) override;
		//接続可能なすべてのノードを接続
		void adjacent_allnodes();

		//２次元グラフの幅と高さを得る
		const int get_width() const noexcept;
		const int get_height() const noexcept;

		const base_node<T>& operator()(const int w, const int h) const;
		base_node<T>& operator()(const int w, const int h);

	};


	template<typename T>
	grid_graph<T>::grid_graph(const int width, const int height) {
		this->_width = width; this->_height = height;

		this->_undirected_graph = std::map<type_id, std::vector<type_id>>();
		this->_nodes = std::map<type_id, base_node<T>>();


		for (int n = 0; n < width * height; n++) {
			this->add_node(base_node<T>(n));
		}


	}
	
	template<typename T>
	void grid_graph<T>::adjacent_nodes(const type_id id1, const type_id id2) {
		if((std::abs(id1 - id2)) == 1
			|| ((std::abs(id1 - id2)) == this->_width)) {
			undirected_graph<T>::adjacent_nodes(id1, id2);
		}
	}

	template<typename T>
	void grid_graph<T>::adjacent_allnodes() {
	
		type_id key;
		for (int w = 0; w < this->_width; w++) {
			for (int h = 0; h < this->_height; h++) {
				key = h * this->_width + w;
				if (w - 1 >= 0) this->adjacent_nodes(key, key - 1);
				if (w + 1 < this->_width) this->adjacent_nodes(key, key + 1);
				if (h - 1 >= 0) this->adjacent_nodes(key, key - this->_width);
				if (h + 1 < this->_height) this->adjacent_nodes(key, key + this->_width);
			}
		}
	}

	template<typename T>
	const int grid_graph<T>::get_width() const noexcept {
		return this->_width;
	}

	template<typename T>
	const int grid_graph<T>::get_height() const noexcept{
		return this->_height;
	}

	template<typename T>
	const base_node<T>& grid_graph<T>::operator()(const int w, const int h) const {
		return this->get_nodes().at(this->_width * h + w);
	};

	template<typename T>
	base_node<T>& grid_graph<T>::operator()(const int w, const int h) {
		return this->get_nodes().at(this->_width * h + w);
	};
}