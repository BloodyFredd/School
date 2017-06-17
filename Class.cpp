/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .cpp file for class.

#include "Class.h"

// This is the default ctor.
Class::Class() : NameOfClass('n'), NumberOfClass(-1), NumberOfPupils(0){
	Pupils = new Pupil*;
	Tutorr = NULL;
}

// This is another ctor.
Class::Class(char name, int num) : NameOfClass(name), NumberOfClass(num), NumberOfPupils(0) {
	Pupils = new Pupil*;
	Tutorr = NULL;
}

// This is the copy ctor.
Class::Class(const Class& c) {
	NameOfClass = c.NameOfClass;
	NumberOfClass = c.NumberOfClass;
	NumberOfPupils = c.NumberOfPupils;
	Pupils = new Pupil*[NumberOfPupils];
	Tutorr = new Tutor;
	for (int i = 0; i < NumberOfPupils; i++) {
		Pupils[i] = new Pupil;
		Pupils[i] = c.Pupils[i];
	}
	Tutorr = c.Tutorr;
}

// This function adds a pupil to the class.
void Class::addPupil(Pupil* p) {
	Pupil** tmpPupil = new Pupil*[NumberOfPupils + 1];
	for (int i = 0; i < NumberOfPupils + 1; i++) // Make a tmp array and move the pupils.
		tmpPupil[i] = new Pupil;
	for (int i = 0; i < NumberOfPupils; i++)
		tmpPupil[i] = Pupils[i];
	NumberOfPupils++;
	Pupils = new Pupil*[NumberOfPupils]; // Build a new and bigger one and move them all back.
	for (int i = 0; i < NumberOfPupils; i++)
		Pupils[i] = new Pupil;
	for (int i = 0; i < NumberOfPupils; i++)
		Pupils[i] = tmpPupil[i];
	*Pupils[NumberOfPupils - 1] = *p; // Move the pupil to the last place.
}

// This function returns the pupil at the given index at the class.
Pupil* Class::returnPupil(const int index) {
	if (index <= NumberOfPupils && index > 0)
		for (int i = 0; i < NumberOfPupils; i++) {
			if (i + 1 == index)
				return Pupils[i];
		}
	return NULL;
}

// This function prints the class.
void Class::PrintClass() const {
	for (int i = 0; i < NumberOfPupils; i++) {
		Pupils[i]->printPerson();
		if (Pupils[i]->isExcellent()) // Check if the pupil is excellent.
			cout << "He is excellent." << endl;
	}
}

// This function add a tutor to the class.
void Class::addTutor(Tutor* t) {
	Tutorr = t;
}

// This function checks if the class have a tutor.
bool Class::checkTutor() const {
	return Tutorr == NULL;
}

// This is the dtor.
Class::~Class(){
	for (int i = 0; i < NumberOfPupils; i++)
		delete Pupils[i];
	delete[] Pupils;
}
