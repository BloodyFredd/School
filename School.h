/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .h file for the school. Here I declare all my functions.

#ifndef SCHOOL_H
#define SCHOOL_H
#include "Layer.h"
#include "Person.h"
#include "Manager.h"
#include "Secretary.h"
class Layer;
class Person;
class School
{
	Layer** Layers;
	Person** Persons;
	bool OneManager;
	int NumOfLayers = 6, NumOfPersons;
	void addPerson();
public:
	School();
	virtual ~School();
	void Menu();
};

#endif

