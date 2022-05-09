/*
 * File.h
 *
 *  Created on: 9 mai 2022
 *      Author: jcomble
 */

#ifndef FILE_H_
#define FILE_H_

class File {
private:
	string content;
public:
	File();
	virtual ~File();
	bool check_valid();
};

#endif /* FILE_H_ */
