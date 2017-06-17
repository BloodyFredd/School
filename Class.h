/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .h file for the class. Here I declare all my functions.

#ifndef CLASS_H
#define CLASS_H
#include "Pupil.h"
#include "Tutor.h"
class Tutor;
class Class
{
	char NameOfClass;
	int NumberOfClass, NumberOfPupils;
	Pupil** Pupils;
	Tutor* Tutorr;
public:
	Class();
	Class(char, int);
	Class(const Class&);
	int getNumberOfPupils() { return NumberOfPupils; }
	void addPupil(Pupil*);
	int getNumOfClass() { return NumberOfClass; }
	Pupil* returnPupil(const int);
	void PrintClass() const;
	void addTutor(Tutor*);
	bool checkTutor() const;
	virtual ~Class();
};

#endif

