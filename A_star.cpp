#include"Node.hpp"
#include"Math.hpp"

/*
template<typename T>
bool Cmp<T>::operator()(const T& x, const T& y) const {
	return static_cast<Node*>(x)->f > static_cast<Node*>(y)->f;
}


A_star::A_star() {
	_map = Map();
}

A_star::A_star(const Map& map, Cost* cost) {
	_map = map;
	_cost = cost;
}

A_star::A_star(const A_star& a_star) {
	this->_map = a_star._map;
	_openlist = a_star._openlist;
}

Map* A_star::getMap() {
	return &_map;
}

bool A_star::Moveable(const int x, const int y) {
	return true;
}

void A_star::Init(Node* sn, Node* gn) {
	_snode = sn;
	_gnode = gn;
}

Node* A_star::Run() {

	//‰¼‚Ìf’l
	float temp_f, temp_g;
	Node *tempnode = nullptr, *pastnode = nullptr;

	_snode->stat = STAT::OPEN;
	_snode->f = MyMath::MyDist(_gnode->x - _snode->x, _gnode->y - _snode->y);
	_snode->h = _snode->f;
	_snode->g = 0.0f;

	_openlist.push_back(_snode);

	while (true)
	{
		//openlist‚ª‹ó‚Ìê‡
		if (_openlist.empty()) {
			return nullptr;
		}
		//Å¬‚Ìf’l‚ðŽ‚Âƒm[ƒh‚ðŽæ“¾‚·‚é
		auto a = std::min_element(_openlist.cbegin(), _openlist.cend(), [](Node* n1, Node* n2) {return n1->f < n2->f; });
		tempnode = *a;
		_openlist.erase(a);
		//pop‚³‚ê‚½ƒm[ƒh‚ªƒS[ƒ‹ƒm[ƒh‚©‚Ç‚¤‚©
		if ((_gnode->x == tempnode->x) && (_gnode->y == tempnode->y)) {
			//‘®‚µ‚Ä‚¢‚éê‡A’TõI—¹
			break;
		}
		else {
			tempnode->stat = STAT::CLOSE;
			_closelist.push_back(tempnode);
		}

		//—×Úƒm[ƒh‚Ì“WŠJ
		for (int x = tempnode->x - 1; x <= tempnode->x + 1; x++) {
			for (int y = tempnode->y - 1; y <= tempnode->y + 1; y++) {
				//node‚ÌŽüˆÍ‚Ìƒm[ƒh‚Ìê‡
				if ((!((x == tempnode->x) && (y == tempnode->y)))
					&& ((x >= 0) && (x < _map.getWidth())) && ((y >= 0) && (y < _map.getHeight()))
					&& (_map.getNode(x, y)->f_movable)
					&& ((x == tempnode->x) || (y == tempnode->y))) {

					//‰¼‚Ìf’l‚ÌŒvŽZ
					temp_f = (tempnode->f - MyMath::MyDist(_gnode->x - tempnode->x, _gnode->y - tempnode->y)) + _cost->getCost(nullptr, nullptr) + MyMath::MyDist(_gnode->x - x, _gnode->y - y);
					//ƒm[ƒh‚Ìó‘Ô‚É‚æ‚Á‚Äˆ—‚ð•ªŠò

					switch (_map.getNode(x, y)->stat) {
					case STAT::NONE:
						_map.getNode(x, y)->parent_node = tempnode;
						_map.getNode(x, y)->f = temp_f;
						_map.getNode(x, y)->stat = STAT::OPEN;
						_openlist.push_back(_map.getNode(x, y));
						break;
					case STAT::OPEN:
						if (temp_f < _map.getNode(x, y)->f) {
							_map.getNode(x, y)->parent_node = tempnode;
							_map.getNode(x, y)->f = temp_f;
						}
					case STAT::CLOSE:
						if (temp_f < _map.getNode(x, y)->f) {
							_map.getNode(x, y)->parent_node = tempnode;
							_map.getNode(x, y)->f = temp_f;
							_map.getNode(x, y)->stat = STAT::OPEN;
							_closelist.erase(std::remove(_closelist.begin(), _closelist.end(),_map.getNode(x, y)));
							_openlist.push_back(_map.getNode(x, y));
						}
					}
				

				}
			}
		}

		
	}
	return _gnode;

}

*/