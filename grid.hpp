#pragma once
#include<vector>
#include<initializer_list>

namespace mylib {

	//２次元配列を表現するグラフ
	template<typename T = int>
	class grid {
		//２次元配列の幅と高さ
		int _width, _height;

		//２次元配列本体
		std::vector<std::vector<T>> _grid;
	
	public:
		grid();
		grid(std::initializer_list<T> init);
		explicit grid(const grid<T>& obj);

		//変更不能なメンバ変数を得る
		const std::vector<std::vector<T>>& get_grid() const noexcept;
		const int get_width() const noexcept;
		const int get_height() const noexcept;

		//y行x列の要素を取り出す
		T& operator()(const int y, const int x);
		const T& operator()(const int y, const int x) const;
	};

	template<typename T>
	grid<T>::grid() {

	}

	template<typename T>
	grid<T>::grid(std::initializer_list<T> init) : _grid(init.begin(), init.end()) {

	}


	template<typename T>
	grid<T>::grid(const grid<T>& obj) {
		this->_grid = obj.get_grid();
		this->_height = obj.get_height();
		this->_width = obj.get_width();
	}

	template<typename T>
	const std::vector<std::vector<T>>& grid<T>::get_grid() const noexcept {
		return this->_grid;
	}
	
	template<typename T>
	const int grid<T>::get_width() const noexcept {
		return this->_width;
	}
	
	template<typename T>
	const int grid<T>::get_height() const noexcept {
		return this->_height;
	}

	template<typename T>
	T& grid<T>::operator()(const int y, const int x) {
		return this->_grid[y][x];
	}

	template<typename T>
	const T& grid<T>::operator()(const int y, const int x) const {
		return this->_grid[y][x];
	}
}

