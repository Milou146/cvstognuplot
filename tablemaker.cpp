/*
 * tablemaker.cpp
 *
 *  Created on: 11 mai 2022
 *      Author: jcomble
 */
#include "tablemaker.h"
#include "node.h"
#include "Connection.h"
#include "traffic.h"
#include <vector>

TableMaker::TableMaker(string content) {
	set_content(content);
}

TableMaker::~TableMaker() {
	this->content = "";
}

void TableMaker::set_content(string content) {
	this->content = content;
}

void TableMaker::build_tables() {

}

vector<Node> TableMaker::get_nodes() {
	return NULL;
}

vector<Traffic> TableMaker::get_traffics() {
	return NULL;
}

vector<Connection> TableMaker::get_connections() {
	return NULL;
}
