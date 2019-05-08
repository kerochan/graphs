#pragma once
#include<vector>

namespace mylib {
	
	//�O���t�̃m�[�h�̃f�[�^��\�����邽�߂̃N���X
	template<typename T>
	class base_node {
		//�m�[�h�̎��ʔԍ�
		int _id;
		//�m�[�h�̎��f�[�^
		T _value;

	public:

		//�f�t�H���g�R���X�g���N�^
		base_node();
		//�Ϗ��R���X�g���N�^
		base_node(const int id) : _id(id) {};
		base_node(const int id, const T& value) : _id(id), _value(value) {};
		
		//id��Ԃ�getter
		int get_id() const noexcept;
		//value�̎Q�Ƃ�Ԃ�getter
		T& get_value() const noexcept;

		//�������Z�q�̃I�[�o�[���[�h
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


	