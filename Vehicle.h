#pragma once
#include <iostream>

class Vehicle
{
	public:
		// constructor
		Vehicle();

		// destructor / deconstructor
		~Vehicle();

		// pure virtual methods (abstract in other languages)
		// abstract classes

		// having at least 1 pure virtual (abstract) methods in a class
		// makes the class an abstract class

		// abstract classes have 1 big restriction:
		// you cannot initialize objects of this type
		virtual std::string move() = 0;

		// MORE ABOUT ABSTRACT METHODS:
		// in other languages interfaces exists
		// interfaces are classes with ONLY abstract methods
};

