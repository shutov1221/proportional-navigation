#include "Target.h"
#include "utils.h"

Target::Target(vec2 position) :
	Object(position),
	maxOverload(5.0 * G), 
	minOverload(-5.0 * G)
{
}

Target::Target(vec2 position, vec2 velocity) :
	Object(position, velocity), 
	maxOverload(5.0 * G), 
	minOverload(-5.0 * G)
{
}

void Target::SetMoveFunction(const move_func& function)
{
	m_f = function;
}

void Target::SetMaxOverload(double value)
{
	if (value <= minOverload || value == 0.0)
	{
		return;
	}

	maxOverload = value;
}

void Target::SetMinOverload(double value)
{
	if (value >= maxOverload || value == 0.0)
	{
		return;
	}

	minOverload = value;
}

void Target::Move(double dt)
{
	velocity += acceleration * dt;
	position += velocity * dt;
}

void Target::SetRandromAcceleration()
{
	acceleration = getRandomAcceleration();
}

vec2 Target::getRandomAcceleration()
{
	return vec2(acceleration.x, random<double>(minOverload, maxOverload));
}
