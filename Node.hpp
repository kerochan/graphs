#pragma once
#include<vector>

namespace mylib {
	
	//グラフのノードのデータを表現するためのクラス
	template<typename T>
	class base_node {
		//ノードの識別番号
		int _id;
		//ノードの持つデータ
		T _value;

	public:

		//デフォルトコンストラクタ
		base_node();
		//委譲コンストラクタ
		base_node(const int id) : _id(id) {};
		base_node(const int id, const T& value) : _id(id), _value(value) {};
		
		//idを返すgetter
		int get_id() const noexcept;
		//valueの参照を返すgetter
		T& get_value() const noexcept;

		//等価演算子のオーバーロード
		bool operator==(const base_node<T>& node) const;
		bool operator!=(const base_node<T>& node) const;
		bool operator<(const base_node<T>& node) const;
		bool operator>(const base_node<T>& node) const;
		bool operator<=(const base_node<T>& node) const;
		bool operator>=(const base_node<T>& node) const;
	};

	template<typename T>
	base_node<T>::base_node() {

	}

	template<typename T>
	int base_node<T>::get_id() const noexcept {
		return this->_id;
	};
	template<typename T>
	T& base_node<T>::get_value() const noexcept {
		return this->_value;
	};

	template<typename T>
	bool base_node<T>::operator==(const base_node<T>& node) const {
		return this->get_id() == node.get_id();
	}
	
	template<typename T>
	bool base_node<T>::operator!=(const base_node<T>& node) const {
		return this->get_id() != node.get_id();
	}

	template<typename T>
	bool base_node<T>::operator<(const base_node<T>& node) const {
		return this->get_id() < node.get_id();
	}

	template<typename T>
	bool base_node<T>::operator>(const base_node<T>& node) const {
		return this->get_id() > node.get_id();
	}

	template<typename T>
	bool base_node<T>::operator<=(const base_node<T>& node) const {
		return this->get_id() <= node.get_id();
	}

	template<typename T>
	bool base_node<T>::operator>=(const base_node<T>& node) const {
		return this->get_id() >= node.get_id();
	}

}


	