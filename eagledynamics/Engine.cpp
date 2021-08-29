#include "Engine.h"

Engine::Engine(double fuelMass, double impulse, double engineRunTime) :
	fuelMass(fuelMass),
	impulse(impulse),
	engineRunTime(engineRunTime),
	dm(fuelMass / engineRunTime)
{

}

double Engine::GetThrustForce() const
{
	if (fuelMass <= 0.0)
	{
		return 0.0;
	}

	return dm * impulse * G;
}

double Engine::GetFuelMass() const
{
	return fuelMass;
}

double Engine::GetEngineRunTime() const
{
	return engineRunTime;
}

double Engine::ReduceFuelMass(double dt)
{
	fuelMass -= dm * dt;

	if (fuelMass < 0.0)
	{
		fuelMass = 0.0;
	}

	return dm * dt;
}
