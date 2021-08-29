#include "AirCraft.h"

AerodynamicProperties::AerodynamicProperties(double s, double kp, const MvsCx0& m_vs_cx0) :
	s(s),
	kp(kp),
	m_vs_cx0(m_vs_cx0)
{
}

double AerodynamicProperties::GetCx0Value(double M) const
{
	double temp = M;
	double x = 0.0;
	for (auto& i : m_vs_cx0)
	{
		auto a = abs(M - i[0]);
		if (a < temp)
		{
			temp = abs(M - i[0]);
			x = i[1];
		}
	}

	return x;
}

double AerodynamicProperties::GetS() const
{
	return s;
}

double AerodynamicProperties::GetKp() const
{
	return kp;
}

Aircraft::Aircraft(vec2 position, double mass, const AerodynamicProperties& properties, const Engine& engine) :
	Object(position),
	mass(mass + engine.GetFuelMass()),
	properties(properties),
	engine(engine)
{

}

Aircraft::Aircraft(vec2 position, vec2 velocity, double mass, const AerodynamicProperties& properties, const Engine& engine) :
	Object(position, velocity),
	mass(mass + engine.GetFuelMass()),
	properties(properties),
	engine(engine)
{

}

double Aircraft::GetMass()
{
	return mass;
}

double Aircraft::GetDragForceÑoefficient()
{
	double vl = velocity.length() * velocity.length();
	return GetDragForce() * 2.0 / (vl * rho * properties.GetS());
}

double Aircraft::GetLiftForceÑoefficient()
{
	double vl = velocity.length() * velocity.length();
	return GetLiftForce() * 2.0 / (vl * rho * properties.GetS());
}
