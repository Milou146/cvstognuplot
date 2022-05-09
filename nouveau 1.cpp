#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "Node.h"

using namespace std;

vector<string> get_vector(const string chaine) {
	vector<string> vect;
	string copy_chaine = chaine;
	while (copy_chaine.find(",") != string::npos) {
		string tmp_string = copy_chaine.substr(0, copy_chaine.find(","));
		vect.push_back(tmp_string);
		copy_chaine = copy_chaine.substr(copy_chaine.find(",") + 1, copy_chaine.length() - tmp_string.length() - 1);
	}
	if (copy_chaine != "") {
		vect.push_back(copy_chaine);
	}
	for (int i = 0; i < vect.size(); i++){
		cout << vect.at(i) << endl;
	}
	return vect;
}

bool isNumber(string chaine) {
	int length = chaine.length();
	bool check = true;
	if (length == 0) {
		check = false;
	}
	for (int i = 0; i < length; i++) {
		if ('0' > chaine[i] || chaine[i] > '9') {
			check = false;
		 	break;
		}
	}
	return check;
}

bool is_named_node(string chaine) {
	int length = chaine.length();
	if (length < 6) {
		return false;
	}
	if (chaine.substr(0, 5) != "\"Node" || chaine.substr(length - 1, 1) != "\"" || !isNumber(chaine.substr(5, length - 6))) {
		return false;
	}
	return true;
}

int check_vect(vector<string> vect) {
	if (vect.at(0) == "\"Node\"" && vect.at(1) == "" && vect.at(2) == "") {
		return 1;
	} else if (is_named_node(vect.at(0)) && isNumber(vect.at(1)) && isNumber(vect.at(2))) {
		return 2;
	} else if (vect.at(0) == "\"traffic\"" && vect.at(1) == "" && vect.at(2) == "") {
		return 3;
	} else if (vect.at(0) == "\"connection\"" && vect.at(1) == "" && vect.at(2) == "") {
		return 5;
	} else {
		bool check = true;
		for (const string elem : vect) {
			if (!is_named_node(elem)) {
				check = false;
				break;
			}
		}
		if (check) {
			return 4;
		}
	}
	return 6;
}
Node parse2(vector<string> vect) {
	int num_node = atoi(vect[0].substr(5, vect[0].length() - 6).c_str());
	int node_x = atoi(vect[1].c_str());
	int node_y = atoi(vect[2].c_str());
	Node node = Node(num_node, node_x, node_y);
	return node;
}

vector<int> parse4(vector<string> vect) {
	vector<int> vect_id;
	for (string element : vect) {
		int num_node = atoi(element.substr(5, element.length() - 6).c_str());
		vect_id.push_back(num_node);
	}
	return vect_id;
}

int main(){
	vector<string> vect = get_vector("coucou, les amis, et ici, et là");
	cout << check_vect(vect);
}
