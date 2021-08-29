#pragma once
#include "Object.h"
#include "vec3.h"
#include <vector>
#include <array>
#include "AirCraft.h"


class Rocket : public Aircraft
{
public:
	Rocket(vec2 position, double mass, const AerodynamicProperties& properties, const Engine& engine);
	Rocket(vec2 position, vec2 velocity, double mass, const AerodynamicProperties& properties, const Engine& engine);

	void SetTarget(const Object* target);
	void SetDeathRadius(double radius);
	void SetPNCoefficient(double N);
	bool IsHitTarget() const;
	bool IsHitGround() const;
	double distanceToTraget() const;

	vec2 PNGuidance(double N);
	const Engine& GetEngine() const;

	virtual double GetLiftForce() override;
	virtual double GetDragForce() override;
	virtual double GetDragForce—oefficient() override;
	virtual void Move(double dt) override;

private:
	double time = 0.0;
	const Object* target;
	double deathRadius;
	double N;
};

