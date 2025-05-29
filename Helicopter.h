#pragma once
#include "Vehicle.h"

class Helicopter : public Vehicle
{
	public:
		std::string move() override;
};

