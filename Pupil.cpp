/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .cpp file of the pupil.

#include "Pupil.h"

// This is the default ctor.
Pupil::Pupil() : Person(), numOfGrades(0), classNumber(0), nameOfClass('0') {
	Grades = NULL;
}

// This is another ctor.
Pupil::Pupil(string first, string last, int id, char cname, int cnum, int ngrades, int* grades) :
	Person(first, last, id), numOfGrades(ngrades), classNumber(cnum), nameOfClass(cname) {
	Grades = new int[numOfGrades];
	for (int i = 0; i < numOfGrades; i++)
		Grades[i] = grades[i];
}

// This is the copy ctor.
Pupil::Pupil(const Pupil& p) : Person(p) {
	numOfGrades = p.numOfGrades;
	nameOfClass = p.nameOfClass;
	classNumber = p.classNumber;
	Grades = new int[numOfGrades];
	for (int i = 0; i < numOfGrades; i++)
		Grades[i] = p.Grades[i];
}

// This is the dtor.
Pupil::~Pupil()
{
	delete[] Grades;
}

// This function checks the avg of the pupil.
float Pupil::avg() {
	float avg = 0;
	for (int i = 0; i < numOfGrades; i++)
		avg += Grades[i];
	return (avg / numOfGrades);
}

// This function checks if the pupil is excellent.
bool Pupil::isExcellent() {
	for (int i = 0; i < numOfGrades; i++) {
		if (Grades[i] < 65) // If one of his grades is below 65, he is not excellent.
			return false;
	}
	if (this->avg() > 85) // If his avg is above 85.
		return true;
	return false;
}

// This function prints the pupil.
void Pupil::printPerson() {
	cout << "Pupil: " << endl;
	Person::printPerson();
	cout << "class: " << nameOfClass << classNumber << endl;
	if (numOfGrades != 0) {
		cout << "His grades: " << endl;
		for (int i = 0; i < numOfGrades; i++)
			cout << Grades[i] << " ";
		cout << endl << "And his avg: " << avg() << endl;
	}
}
