#pragma once

#include <string>
#include <vector>
#include <iostream>

class OOPUtils
{
	// static members
	// each object has a copy of their "regular" members 

	// static member means we have a single copy of the
	// member belonging to the class itself
	public:
		static void staticTest();
		static void cleanCin();
		static std::vector<std::string> split(std::string delimiter);

};

