/*
 * Node.h
 *
 *  Created on: 9 mai 2022
 *      Author: jcomble
 */

#ifndef NODE_H_
#define NODE_H_

class Node {
private:
	int node_num;
	int node_x;
	int node_y;
public:
	Node(int num, int x, int y);
	virtual ~Node();
};

#endif /* NODE_H_ */
