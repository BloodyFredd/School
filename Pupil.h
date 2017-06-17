/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .h file for the pupil. Here I declare all my functions.

#ifndef PUPIL_H
#define PUPIL_H
#include "Person.h"
class Pupil:public Person
{
	int* Grades;
	int numOfGrades, classNumber;
	char nameOfClass;
public:
	Pupil();
	Pupil(string, string, int, char, int, int, int*);
	Pupil(const Pupil&);
	virtual ~Pupil();
	float avg();
	virtual bool isExcellent();
	void printPerson();
};

#endif

