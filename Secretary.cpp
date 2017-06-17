/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .cpp file of the secretary.

#include "Secretary.h"

// This is the default ctor.
Secretary::Secretary() : Worker(), NumOfKids(0) {}

// This is another ctor.
Secretary::Secretary(string first, string last, int id, int num, int kids) : Worker(first, last, id, num), NumOfKids(kids) {}

// This is the copy ctor.
Secretary::Secretary(const Secretary& s) : Worker(s) {
	NumOfKids = s.NumOfKids;
}

// This function returns the check of the secretary.
float Secretary::getCheck() {
	return (float)Worker::Basis() + NumOfKids * 200;
}

// This function checks if the secretary is excellent.
bool Secretary::isExcellent() {
	return Worker::getYears() > 10;
}

// This function prints the secretary.
void Secretary::printPerson() {
	cout << "Secretary: " << endl;
	Worker::printPerson();
	cout << endl << "And number of kids: " << NumOfKids << endl;
}

// This is the dtor.
Secretary::~Secretary() {}
