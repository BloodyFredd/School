/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .cpp file for the manager.

#include "Manager.h"

// This is the default ctor.
Manager::Manager() : Worker() {}

// This is another ctor.
Manager::Manager(string first, string last, int id, int num) : Worker(first, last, id, num) {}

// This is copy ctor.
Manager::Manager(const Manager& m) : Worker(m) {}

// This function returns the check of the manager.
float Manager::getCheck() {
	return (float)(Worker::Basis() * 2 + 500 * Worker::getYears());
}

// This function checks if the manager is excellent.
bool Manager::isExcellent() {
	return Worker::getYears() > 3;
}

// This function prints the manager.
void Manager::printPerson() {
	cout << "Manager: " << endl;
	Worker::printPerson();
}

// This is the dtor.
Manager::~Manager() {}
