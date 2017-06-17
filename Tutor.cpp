/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .cpp file for the tutor.

#include "Tutor.h"

// This is my default ctor.
Tutor::Tutor() : Teacher() {
	ClassOfTutor = NULL;
}

// This is another ctor.
Tutor::Tutor(string first, string last, int id, int nwork, int nclass, string* names, Class* classTutor) : 
	Teacher(first, last, id, nwork, nclass, names) {
	ClassOfTutor = classTutor;
}

// This is the copy ctor.
Tutor::Tutor(const Tutor& t) : Teacher(t) {
	ClassOfTutor = t.ClassOfTutor;
}

// This is a bool function to check if the tutor is excellent.
bool Tutor::isExcellent() {
	int count = 0;
	for (int i = 0; i < ClassOfTutor->getNumberOfPupils(); i++) {
		if (ClassOfTutor->returnPupil(i + 1)->isExcellent())
			count++;
	} // Check if more than half of class is excellent.
	if (count > (ClassOfTutor->getNumberOfPupils()) / 2)
		return true;
	return false;
}

// This function returns the tutor's check.
float Tutor::getCheck() {
	return (float)Teacher::getCheck() + 1000;
}

// This function prints the tutor's class.
void Tutor::PrintClass() const{
	ClassOfTutor->PrintClass();
}

// This function prints the tutor.
void Tutor::printPerson() {
	cout << "Tutor: " << endl;
	Teacher::printPerson();
	if (ClassOfTutor->getNumberOfPupils() != 0) { // Print the tutor's class, if he have one.
		cout << "And his class he tutors: " << endl;
		PrintClass();
	}
	else
		cout << "No students in his class yet." << endl;
}

// This is the dtor.
Tutor::~Tutor() {}
