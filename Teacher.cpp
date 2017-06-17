/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .cpp file for the teacher.

#include "Teacher.h"

// This is the default ctor.
Teacher::Teacher() : Worker(), numOfClasses(0) {
	NamesOfClasses = new string;
}

// This is another ctor.
Teacher::Teacher(string first, string last, int id, int nwork, int nclass, string* names) : 
	Worker(first, last, id, nwork), numOfClasses(nclass) {
	NamesOfClasses = new string[nclass];
	for (int i = 0; i < nclass; i++)
		NamesOfClasses[i] = names[i];
}

// This is copy ctor.
Teacher::Teacher(const Teacher& t) :Worker(t) {
	numOfClasses = t.numOfClasses;
	NamesOfClasses = new string[numOfClasses];
	for (int i = 0; i < numOfClasses; i++)
		NamesOfClasses[i] = t.NamesOfClasses[i];
}

// This function returns the check of the teacher.
float Teacher::getCheck() {
	return (Worker::Basis() * (1 + ((float)numOfClasses / 10)) + 300 * Worker::getYears());
}

// This function checks if the teacher is excellent.
bool Teacher::isExcellent() {
	return numOfClasses > 5;
}

// This function print the classes of the teacher.
void Teacher::PrintClasses() const {
	for (int i = 0; i < numOfClasses; i++)
		cout << i + 1 << ". " << NamesOfClasses[i] << "." << endl;
	if (numOfClasses == 0) // check if he have none.
		cout << "No classes yet." << endl;
}

// This function prints the teacher.
void Teacher::printPerson() {
	cout << "Teacher: " << endl;
	Worker::printPerson();
	cout << ", and his classes: " << endl;
	PrintClasses();
	cout << endl;
}

// This is the dtor.
Teacher::~Teacher() {
	delete[] NamesOfClasses;
}

