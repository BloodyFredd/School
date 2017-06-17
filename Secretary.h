/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .h file for the secretary. Here I declare all my functions.

#ifndef SECRETARY_H
#define SECRETARY_H
#include "Worker.h"
class Secretary:public Worker
{
	int NumOfKids;
public:
	Secretary();
	Secretary(string, string, int, int, int);
	Secretary(const Secretary&);
	float getCheck();
	bool isExcellent();
	void printPerson();
	virtual ~Secretary();
};

#endif
