Node::Node(int id, int x, int y) {
	node_id = id;
	node_x = x;
	node_y = y;
}

int Node::get_X() {
	return node_x;
}

int Node::get_y() {
	return node_y;
}

int Node::get_id() {
	return node_id;
}