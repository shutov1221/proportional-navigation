#pragma once
#include "PhysicConstants.h"
#include "vec2.h"

class Engine
{
public:
	Engine(double fuelMass, double impulse, double engineRunTime);

	double GetThrustForce() const;
	double GetFuelMass() const;
	double GetEngineRunTime() const;
	double ReduceFuelMass(double dt);
	
private:
	double dm;
	double fuelMass;
	double impulse;
	double engineRunTime;
};

