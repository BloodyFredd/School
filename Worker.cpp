/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .cpp file of worker.

#include "Worker.h"

// This is my default ctor.
Worker::Worker() : Person(), numOfWorkYears(0) {}

// This is another ctor.
Worker::Worker(string first, string last, int id, int num) : Person(first, last, id), numOfWorkYears(num) {}

// This is copy ctor.
Worker::Worker(const Worker& w) : Person(w) {
	numOfWorkYears = w.numOfWorkYears;
}

// This is the print for the worker.
void Worker::printPerson() {
	Person::printPerson();
	cout << "The check is: " << getCheck() << ", number of work years: " << numOfWorkYears;
}

// This is the dtor.
Worker::~Worker() { }

