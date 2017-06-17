/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .h file for the person. Here I declare all my functions.

#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
using namespace std;
class Person
{
	string FirstName, LastName;
	int id;
public:
	Person();
	Person(string, string, int);
	Person(const Person&);
	virtual ~Person();
	virtual void printPerson() = 0;
	virtual bool isExcellent() = 0;
	int getPersonId() const { return id; }
};

#endif
