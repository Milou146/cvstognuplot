#include"traffic.h"
#include <istream>

using namespace std;


Traffic::Traffic(int id) {
    this->id_traffic = id;
}

int Traffic::get_id_traffic() {
    return this->id_traffic;
}

void Traffic::put_id_node(int id_node) {
	this->list_traffic.push_back(id_node);
}

vector<int> Traffic::get_traffic() {
	return this->list_traffic;
}
