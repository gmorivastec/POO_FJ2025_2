#include "OOPUtils.h"

void OOPUtils::staticTest() {
	std::cout << "DOING STUFF IN A STATIC METHOD!" << std::endl;
}

void OOPUtils::cleanCin() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// receive a string, break it apart using the delimiter as a 
// breakpoint, return a vector with the parts
std::vector<std::string> OOPUtils::split(const std::string& source, const std::string& delimiter) {
	std::vector<std::string> result;

	int start = 0;
	int end;

	// go through the string search for location of delimiter and substring
	// (substring is creating a string that is a part of another string)

	// there is a find method within the string that returns the location
	// of a string

	/*
	// https://cplusplus.com/reference/string/string/find/
	int pos = source.find(delimiter);

	if (pos == std::string::npos)
	{
		std::cout << "STRING NOT FOUND" << std::endl;
	}
	else
	{
		std::cout << "string found at position: " << pos << std::endl;
	}
	*/

	// what we need to do is search for the indexes
	end = source.find(delimiter);

	// optimize this in a couple of years!
	while (end != std::string::npos) {
		
		// get slice
		std::string part = source.substr(start, end - start);

		// save slice 
		result.push_back(part);

		// we need a new start!
		start = end + delimiter.length();

		// search for new end position
		end = source.find(delimiter, start);
	}
	
	// add the last part
	result.push_back(source.substr(start));
	return result;
}