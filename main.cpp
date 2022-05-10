#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream> 
#include "node.h"

using namespace std;

/**
 * Split lines by "," and stock it in a vector.
 */
vector<string> get_vector(const string chaine) {
	vector<string> vect;
	string copy_chaine = chaine;
	while (copy_chaine.find(",") != string::npos) {
		string tmp_string = copy_chaine.substr(0, copy_chaine.find(","));
		vect.push_back(tmp_string);
		copy_chaine = copy_chaine.substr(copy_chaine.find(",") + 1, copy_chaine.length() - tmp_string.length() - 1);
	}
	vect.push_back(copy_chaine);
	return vect;
}

/**
 * Checks if a string can be converted into a number.
 */
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
/**
 * Checks if a string is in the following form:
 * "Node[0-9]*"
 */
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

/**
 * Checks which case of line it is:
 * 1) "Node",,
 * 2) "Node[0-9]*",[0-9]*,[0-9]*
 * 3) "traffic",,
 * 5) "connection",,
 * 4) ("Node[0-9]*",)*"Node[0-9]*"
 * 6) else
 */
short check_vect(vector<string> vect) {
	if (vect.size() == 1 && vect.at(0) == "") {
		return 7;
	}
	if (vect.size() == 3 && vect.at(0) == "\"Node\"" && vect.at(1) == "" && vect.at(2) == "") {
		return 1;
	} else if (vect.size() == 3 && is_named_node(vect.at(0)) && isNumber(vect.at(1)) && isNumber(vect.at(2))) {
		return 2;
	} else if (vect.size() == 3 && vect.at(0) == "\"traffic\"" && vect.at(1) == "" && vect.at(2) == "") {
		return 3;
	} else if (vect.size() == 3 && vect.at(0) == "\"connection\"" && vect.at(1) == "" && vect.at(2) == "") {
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
	cout << "Longueur :" << vect.size() << vect.at(0);
	cout << "longueur premier argument" << vect.at(0).length();
	return 6;
}

/**
 * Returns the node of the case 2).
 */
Node parse2(vector<string> vect) {
	int num_node = atoi(vect[0].substr(5, vect[0].length() - 6).c_str());
	int node_x = atoi(vect[1].c_str());
	int node_y = atoi(vect[2].c_str());
	Node node = Node(num_node, node_x, node_y);
	return node;
}
/**
 * Returns the vector of node ids.
 */
vector<int> parse4(vector<string> vect) {
	vector<int> vect_id;
	for (string element : vect) {
		int num_node = atoi(element.substr(5, element.length() - 6).c_str());
		vect_id.push_back(num_node);
	}
	return vect_id;
}

void write_type_2(Node * nodeArray [], vector<string> vect, ofstream *out_dat_file, ofstream *out_dem_file) {
	Node node = parse2(vect);
	nodeArray[node.get_id()] = &node;
	*out_dat_file << node.get_X() << "," << node.get_Y() << endl;
	*out_dem_file << "set label \"Node" << node.get_id() << "\"  at " << node.get_X() << "," << node.get_Y() << endl;
}

void write_type_4(Node * nodeArray [], vector<string> vect, ofstream *out_dat_file, ofstream *out_dem_file) {
	string f = vect.at(0).substr(5,1);// first
	string s = vect.at(1).substr(5,1);// seconde
	Node fnode = *nodeArray[stoi(f)];// first node
	Node snode = *nodeArray[stoi(s)];// seconde node
	// write the connection
	*out_dat_file << endl << fnode.get_X() << "," << fnode.get_Y() << endl << snode.get_X() << "," << snode.get_Y() << endl;
}

int main(int argc,char * argv[]){
	// opening input files
	if (argc > 1) {
		ifstream in_file;
		const char *filename = argv[1];
		in_file.open(filename);
		if(in_file.is_open()){
			ofstream out_dat_file;
			ofstream out_dem_file;
			string line;
			out_dat_file.open("output.dat");
			out_dem_file.open("output.dem");
			// line-by-line reading until end of file
			if (out_dat_file.is_open() && out_dem_file.is_open()) {
				cout << "output.dem or output.dat is opened" << endl;
				Node * nodeArray [100]; // we cant have more than an hundred nodes
				bool check = true;
				int count = 0;
				while (!in_file.eof()){
					getline(in_file, line);
					vector<string> vect = get_vector(line);
					short type = check_vect(vect);
					cout << line << endl;
					if (count == 0) {
						cout << "count = 0" << endl;
						cout << "Type = " << type << endl;
						if (type == 7) {
							;
						} else if (type == 1) {
							cout << "Node" << endl;
							count = 1;
						} else {
							check=false;
							break;
						}
					} else if (count == 1) {
						if (type == 7) {
							;
						} else if (type == 2){
							write_type_2(&*nodeArray, vect, &out_dat_file, &out_dem_file);
						} else if (type == 3) {
							count = 2;
							cout << "Traffic" << endl;
						} else {
							check = false;
							break;
						}

					} else if (count == 2) {
						if (type == 7) {
							;
						} else if(type == 4) {
							write_type_4(&*nodeArray, vect, &out_dat_file, &out_dem_file);
						} else if (type == 5) {
							count = 3;
							cout << "Connection" << endl;
						} else {
							check = false;
							break;
						}
					} else {
						if (type == 7) {
							;
						} else if (type == 4) {
							write_type_4(&*nodeArray, vect, &out_dat_file, &out_dem_file);
						} else {
							check = false;
							break;
						}
					}
				}
				if (check){
					out_dem_file << "plot 'output.dat' every :::1::20 with lp, "" every :::0::0 with points;" << endl;
					out_dem_file << "pause -1 \" (-> return)\"" << endl;
					cout << "Converted" << endl;
				} else {
					cout << "File not in the right format" << endl;
				}
				// closing files
				out_dat_file.close();
				in_file.close();
				// gnuplot output file
				out_dem_file.close();
			} else {
				cout << "output.dem or output.dat is not opened"<<endl;
			}
		} else {
			cout << filename <<" is not opened"<<endl;
		}
		return 0;
	} else {
		cout << "No file in args, (main arg1.csv)";
	}
	return 1;
}
