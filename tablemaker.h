/*
 * tablemaker.h
 *
 *  Created on: 11 mai 2022
 *      Author: jcomble
 */
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "node.h"
#include "traffic.h"
#include "Connection.h"

using namespace std;
#ifndef TABLEMAKER_H_
#define TABLEMAKER_H_

class TableMaker {
private:
	string content;
	vector<Node> vector_nodes;
	vector<Traffic> vector_traffics;
	vector<Connection> vector_connections;
public:
	void set_content(string content);
	TableMaker();
	~TableMaker();
	TableMaker(string content);
	void build_tables();
	vector<Node> get_nodes();
	vector<Traffic> get_traffics();
	vector<Connection> get_connections();
};




#endif /* TABLEMAKER_H_ */
