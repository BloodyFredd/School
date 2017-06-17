/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .h file for the worker. Here I declare all my functions.

#ifndef WORKER_H
#define WORKER_H
#include "Person.h"
class Worker:public Person
{
	static const int basis = 5000;
	int numOfWorkYears;
public:
	Worker();
	Worker(string, string, int, int);
	Worker(const Worker&);
	int Basis() const { return basis; }
	int getYears() const { return numOfWorkYears; }
	virtual float getCheck() = 0;
	virtual void printPerson();
	virtual ~Worker();
};

#endif
