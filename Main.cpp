#include<iostream>
#include<algorithm>
//conio.h : windows依存の関数
#include<conio.h>
#include"Node.hpp"
#include"undirected_graph.hpp"
#include"grid_graph.hpp"
#include"draw_grid_graph.hpp"
#include"cost.hpp"
#include"maze.hpp"
#include"grid.hpp"


int main()
{
	std::vector<mylib::base_node<int>> nodes;
	
	for (int i = 0; i < 8; i++) {
		nodes.push_back(mylib::base_node<int>(i, i));
	}

	std::vector<std::vector<int>> aj_matrix = {
		{0 ,1, 0, 0, 1, 1, 0},
		{1, 0, 1, 0, 0, 0, 0},
		{0, 1, 0, 1, 0, 1, 1},
		{0, 0, 1, 0, 0, 1, 0},
		{1, 0, 0, 0, 0, 0, 0},
		{1, 0, 1, 1, 0, 0, 1},
		{0, 0, 1, 0, 0, 1, 0}
	};

	mylib::undirected_graph<int> graph;

	std::vector<mylib::type_id> con_nodes;
	int nodecnt = 0;
	for (int l = 0; l < aj_matrix.size(); l++) {
		for (int c = 0; c < aj_matrix[l].size(); c++) {
			if(aj_matrix[l][c] != 0)
				con_nodes.push_back(nodes[c].get_id());
		}
		graph.add_node(nodes[nodecnt++], con_nodes);
		con_nodes.clear();
	}
	auto result_dfs = graph.search_dfs(1, 2);
	auto result_bfs = graph.search_dfs(1, 2);
	
	
	mylib::grid_graph<int> g(10, 5);
	g.adjacent_allnodes();
	mylib::draw_grid_graph_cui::draw_at(g, 2, 3);
	mylib::cost_mono c;
	auto res = g.dijkstra(0, 49,c);
	
	mylib::grid<int> grid = { 1,2,3 };

	mylib::type_id player = 0;
	int buf = 0;

	while (!_kbhit()) {
		buf = _getch();
		switch (buf) {
		case 'a':
			
			break;
		case 'w':
			
			break;
		case 's':
			
			break;
		case 'd':
			
			break;

		}

	};
	

	return 0;


}

