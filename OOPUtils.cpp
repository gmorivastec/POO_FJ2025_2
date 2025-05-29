#include "OOPUtils.h"

void OOPUtils::staticTest() {
	std::cout << "DOING STUFF IN A STATIC METHOD!" << std::endl;
}

void OOPUtils::cleanCin() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::vector<std::string> OOPUtils::split(std::string delimiter) {
	std::vector<std::string> result;
	return result;
}