/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .h file for the manager. Here I declare all my functions.

#ifndef MANAGER_H
#define MANAGER_H
#include "Worker.h"
class Manager:public Worker
{
public:
	Manager();
	Manager(string, string, int, int);
	Manager(const Manager&);
	float getCheck();
	bool isExcellent();
	void printPerson();
	virtual ~Manager();
};

#endif
