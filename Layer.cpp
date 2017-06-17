/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .cpp file for layer.

#include "Layer.h"

// This is the default ctor.
Layer::Layer(char name){
	NameOfLayer = name;
	Classes = new Class*[NumOfClasses];
	for (int i = 0; i < NumOfClasses; i++)
		Classes[i] = new Class(name, i + 1);
}

// This is the copy ctor.
Layer::Layer(const Layer& l) {
	NameOfLayer = l.NameOfLayer;
	Classes = new Class*[NumOfClasses];
	for (int i = 0; i < NumOfClasses; i++) {
		Classes[i] = new Class(NameOfLayer, NumOfClasses + 1);
		Classes[i] = l.Classes[i];
	}
}

// This function returns the class at the place of the index sent.
Class* Layer::returnClass(const int index) const{
	if (index <= NumOfClasses && index > 0)
		for (int i = 0; i < NumOfClasses; i++) {
			if (i + 1 == index) // If found the class.
				return Classes[i];
	}
	return NULL;
}

// This is the dtor.
Layer::~Layer(){
	for (int i = 0; i < NumOfClasses; i++)
		delete Classes[i];
	delete[] Classes;
}
