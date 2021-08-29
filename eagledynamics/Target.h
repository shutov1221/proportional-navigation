#pragma once
#include "Object.h"
#include <functional>
#include <ctime>

using move_func = std::function<double(vec2)>;

class Target : public Object
{
public:
	Target(vec2 position);
	Target(vec2 position, vec2 velocity);

	virtual void Move(double dt) override;

	void SetMoveFunction(const move_func& function);
	void SetRandromAcceleration();
	void SetMaxOverload(double value);
	void SetMinOverload(double value);

private:
	double maxOverload;
	double minOverload;
	move_func m_f;

	vec2 getRandomAcceleration();
};

