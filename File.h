/*
 * File.h
 *
 *  Created on: 9 mai 2022
 *      Author: jcomble
 */

#ifndef FILE_H_
#define FILE_H_
#include <fstream>
class File {
private:
	std::string content;
public:
	File(std::string path);
	virtual ~File();
	bool check_valid();
};

#endif /* FILE_H_ */
