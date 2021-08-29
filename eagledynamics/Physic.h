#pragma once
#include "PhysicConstants.h"
#include "vec2.h"

double velocityToM(double velocity)
{
	return velocity / SS;
}

double velocityToM(vec2 velocity)
{
	return velocity.length() / SS;
}
