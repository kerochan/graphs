#pragma once
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include"Node.hpp"
#include "cost.hpp"
#include "mylib.hpp"

namespace mylib {

	/*
		undirected_graph�錾��
	*/
	template<typename T = type_id>
	class undirected_graph {

	protected:
		//�����O���t�̗אڃ��X�g�ɂ��\��
		std::map <type_id, std::vector<type_id>> _undirected_graph;
		//�m�[�h��id�̑Ή��֌W
		std::map<type_id, mylib::base_node<T>> _nodes;
	public:
		//�R���X�g���N�^
		undirected_graph();
		explicit undirected_graph(const undirected_graph<T>& graph);

		virtual ~undirected_graph();

		//�אڃ��X�g�𓾂�
		const std::map<type_id, std::vector<type_id>>& get_graph() const noexcept;
		const std::map<type_id, mylib::base_node<T>>& get_nodes() const noexcept;

		//�m�[�h�Ƃ���Ɛڑ����Ă���m�[�h�̃��X�g��ǉ�����
		int add_node(const mylib::base_node<T>& node);
		int add_node(const mylib::base_node<T>& node, const std::vector<type_id>& nodes);

		//��̃m�[�h��אڂ�����
		virtual void adjacent_nodes(const type_id id1, const type_id id2);
		
		//�[���D��T��
		bool search_dfs(const type_id val, const type_id start) const;
		//���D��T��
		bool search_bfs(const type_id val, const type_id start) const;
	
		//�ŒZ�o�H�T��
		//�_�C�N�X�g���@
		std::vector<type_id> dijkstra(const type_id start, const type_id end, const cost& cost) const;
		//A*�@
		void a_star(const type_id start, const type_id end, const cost& cost) const;

		//�Œ��o�H�T��
		
	};

	/*
		undirected_graph��`
	*/
	template<typename T>
	undirected_graph<T>::undirected_graph() {
		this->_undirected_graph = std::map<type_id, std::vector<type_id>>();
		this->_nodes = std::map<type_id, base_node<T>>();
	}

	template<typename T>
	undirected_graph<T>::undirected_graph(const undirected_graph<T>& graph) {
		this->_undirected_graph = graph.get_graph();
	}

	template<typename T>
	undirected_graph<T>::~undirected_graph() {

	}

	template<typename T>
	const std::map<type_id, std::vector<type_id>>& undirected_graph<T>::get_graph() const noexcept {
		return this->_undirected_graph;
	}

	template<typename T>
	const std::map<type_id, mylib::base_node<T>>& undirected_graph<T>::get_nodes() const noexcept {
		return this->_nodes;
	}

	
	template<typename T>
	int undirected_graph<T>::add_node(const mylib::base_node<T>& node) {
		if (!((this->_nodes).insert({ node.get_id(), node }).second)) return 1;
		if (!(this->_undirected_graph.insert({ node.get_id(), std::vector<type_id>() }).second)) return 1;
		return 0;
	}

	template<typename T>
	int undirected_graph<T>::add_node(const mylib::base_node<T>& node, const std::vector<type_id>& nodes) {
		if (!(this->_nodes.insert({ node.get_id(), node }).second)) return 1;
		if (!(this->_undirected_graph.insert({ node.get_id(), nodes }).second)) return 1;
		return 0;
	}

	template<typename T>
	void undirected_graph<T>::adjacent_nodes(const type_id id1, const type_id id2) {
		this->_undirected_graph.at(id1).push_back(id2);
		
	}



	template<typename T>
	bool undirected_graph<T>::search_dfs(const type_id val_id, const type_id start_id) const {
		

		//�ċA�֐��ŗp����X�^�b�N�Ɠ��������̃X�^�b�N
		std::stack<type_id> node_stack;
		//�O���t�̊e�m�[�h�ɖK�ꂽ���ǂ�����\���A�z�z��
		std::map<type_id, bool> visited;
		for (const auto& n : this->_undirected_graph)
			visited[n.first] = false;
		
		//�T���J�n�m�[�h��id���v�b�V��
		node_stack.push(start_id);

		while (!node_stack.empty()) {
	TO_NEXT_NODE:
			type_id current = node_stack.top();
			visited.at(current) = true;
			if (val_id == current) return true;
			for (type_id id : _undirected_graph.at(current)) {
				if (!visited.at(id)) {
					node_stack.push(id);
					goto TO_NEXT_NODE;
				}
			}
			node_stack.pop();
		}
		
		return false;
		
	}

	template<typename T>
	bool undirected_graph<T>::search_bfs(const type_id val, const type_id start) const {
		
		std::queue<type_id> node_queue;
		//node_queue.push(val);

		//�O���t�̊e�m�[�h�ɖK�ꂽ���ǂ�����\���A�z�z��
		std::map<type_id, bool> visited;
		for (const auto& n : this->_undirected_graph)
			visited[n.first] = false;

		//�T���J�n�m�[�h��id���G���L���[
		node_queue.push(val);

		while (!node_queue.empty()) {
			type_id current = node_queue.pop();
			visited.at(current) = true;
			if (val == current) return true;
			for (type_id id : _undirected_graph.at(current))
				if (!visited.at(id)) node_queue.push(id);
			
		}

		return false;

	}

	template<typename T>
	std::vector<type_id> undirected_graph<T>::dijkstra(const type_id start, const type_id end, const cost& cost) const {
		std::map<type_id, int> len;
		std::map<type_id, type_id> prev_node;
		std::vector<type_id> pass;

		for (auto e : this->_nodes) {
			if (e.first == start)
				len.insert({ e.first, 0 });
			else
				len.insert({ e.first, 9999 });
			prev_node.insert({ e.first, -1 });
		}

		while (!len.empty()) {
			auto minitr = std::min_element(len.begin(), len.end(), [](auto a, auto b) {return a.second < b.second; });
			
			for (auto e : this->_undirected_graph.at((*minitr).first)) {
				
				auto valitr = std::find_if(len.begin(), len.end(), [e](auto a) {return a.first == e; });
				
				if (valitr != len.end()) {
					
					auto tempcost = (*valitr).second;
					
					if (tempcost > (*minitr).second + cost(0, 0)) {
						(*valitr).second = (*minitr).second + cost(0 , 0);
						prev_node.at((*valitr).first) = (*minitr).first;
					}
					
				}
				
			}
			len.erase(minitr);
			
		}
		type_id prev = end;
		while (prev != -1) {
			pass.push_back(prev);
			prev = prev_node.at(prev);
			
		}

		return pass;

	}

	template<typename T>
	void undirected_graph<T>::a_star(const type_id start, const type_id end, const cost& cost) const {

	}

}