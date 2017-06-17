/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .h file for the tutor. Here I declare all my functions.

#ifndef TUTOR_H
#define TUTOR_H
#include "Teacher.h"
#include "Class.h"
class Class;
class Tutor:public Teacher
{
	Class* ClassOfTutor;
public:
	Tutor();
	Tutor(string, string, int, int, int, string*, Class*);
	Tutor(const Tutor&);
	bool isExcellent();
	float getCheck();
	void PrintClass() const;
	void printPerson();
	virtual ~Tutor();
};

#endif
