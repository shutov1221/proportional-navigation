#pragma once
#include "vec2.h"
#include <iostream>
#include <fstream>
#include <iomanip>

#define G 9.81

class Object
{
public:
	Object(vec2 position);
	Object(vec2 position, vec2 velocity);

	void SetPosition(vec2 position);
	void SetVelocity(vec2 velocity);
	void SetAcceleration(vec2 acceleration);

	virtual void Move(double dt) = 0;

	const vec2& GetPosition() const;
	const vec2& GetVelocity() const;
	const vec2& GetAcceleration() const;

	void writeLog(std::ofstream& file) const;

protected:
	vec2 position;
	vec2 velocity;
	vec2 acceleration;
};

