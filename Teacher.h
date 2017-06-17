/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .h file for the teacher. Here I declare all my functions.

#ifndef TEACHER_H
#define TEACHER_H
#include "Worker.h"
class Teacher:public Worker
{
	int numOfClasses;
	string* NamesOfClasses;
public:
	Teacher();
	Teacher(string, string, int, int, int, string*);
	Teacher(const Teacher&);
	float getCheck();
	virtual bool isExcellent();
	void PrintClasses() const;
	void printPerson();
	virtual ~Teacher();
};

#endif

