#pragma once
#include "Vehicle.h"

class Motorcycle: public Vehicle
{
	public:
		std::string move() override;
};

