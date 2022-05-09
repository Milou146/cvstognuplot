/*
 * main1.cpp
 *
 *  Created on: 9 mai 2022
 *      Author: jcomble
 */
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "node.h"
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

int main(){

}


