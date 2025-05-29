#include "Helicopter.h"

// overriding a pure virtual (abstract) method looks 
// exactly the same as overriding a regular virtual method
std::string Helicopter::move() {
	return "moving my propellers!";
}