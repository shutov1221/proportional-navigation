#pragma once
#include "Object.h"
#include "Engine.h"
#include <vector>
#include <array>

using MvsCx0 = std::vector<std::array<double, 2>>;

class AerodynamicProperties
{
public:
	AerodynamicProperties(double s, double kp, const MvsCx0& m_vs_cx0);

	double GetCx0Value(double M) const;
	double GetS() const;
	double GetKp() const;

private:
	double s;
	double kp;
	const MvsCx0 m_vs_cx0;
};

class Aircraft : public Object
{
public:
	Aircraft(vec2 position, double mass, const AerodynamicProperties& properties, const Engine& engine);
	Aircraft(vec2 position, vec2 velocity, double mass, const AerodynamicProperties& properties, const Engine& engine);

	double GetMass();

	virtual double GetLiftForce() = 0;
	virtual double GetDragForce() = 0;

	virtual double GetDragForce—oefficient();
	virtual double GetLiftForce—oefficient();

protected:
	double mass;
	AerodynamicProperties properties;
	Engine engine;
};

