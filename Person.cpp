/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .cpp file of person.

#include "Person.h"

// This is the default ctor.
Person::Person() : FirstName("Tmp"), LastName("Tmp"), id(-1) {}

// This is anoter ctor.
Person::Person(string first, string last, int ID) : FirstName(first), LastName(last), id(ID) {}

// This is the copy ctor.
Person::Person(const Person& p) {
	FirstName = p.FirstName;
	LastName = p.LastName;
	id = p.id;
}

// This is the function that prints the person.
void Person::printPerson() {
	cout << "Id: " << id << ", name: " << FirstName << " " << LastName << endl;
}

// This is the dtor.
Person::~Person() {}
