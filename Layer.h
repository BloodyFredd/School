/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .h file for the layer. Here I declare all my functions.

#ifndef LAYER_H
#define LAYER_H
#include "Class.h"
class Class;
class Layer
{
	char NameOfLayer;
	int NumOfClasses = 3;
	Class** Classes;
public:
	Layer(char);
	Layer(const Layer&);
	char getNameLayer() { return NameOfLayer; }
	Class* returnClass(const int) const;
	virtual ~Layer();
};

#endif

