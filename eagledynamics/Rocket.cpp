#include "Rocket.h"
#include "Physic.h"

Rocket::Rocket(vec2 position, double mass, const AerodynamicProperties& properties, const Engine& engine) :
	Aircraft(position, mass, properties, engine),
	target(nullptr),
	deathRadius(5.0),
	N(3.0)
{

}

Rocket::Rocket(vec2 position, vec2 velocity, double mass, const AerodynamicProperties& properties, const Engine& engine) :
	Aircraft(position, velocity, mass, properties, engine),
	target(nullptr),
	deathRadius(5.0),
	N(3.0)
{

}

double Rocket::GetLiftForce()
{
	return PNGuidance(N).length() * mass;
}

double Rocket::GetDragForce()
{
	auto cxa = GetDragForceÑoefficient();
	if (cxa > 0.5)
	{
		cxa = 0.5;
	}
	return (velocity.length() * velocity.length()) / 2.0 * (cxa * rho * properties.GetS());
}

double Rocket::GetDragForceÑoefficient()
{
	double Cya = GetLiftForceÑoefficient();
	return properties.GetCx0Value(velocityToM(velocity)) + properties.GetKp() * Cya * Cya;
}

void Rocket::SetPNCoefficient(double N)
{
	this->N = N;
}


void Rocket::SetTarget(const Object* target)
{
	this->target = target;
}

void Rocket::SetDeathRadius(double radius)
{
	deathRadius = radius;
}

double Rocket::distanceToTraget() const
{
	return abs(target->GetPosition().distance(position));
}

const Engine& Rocket::GetEngine() const
{
	return engine;
}

vec2 Rocket::PNGuidance(double N)
{	
	vec2 vr = target->GetVelocity() - velocity;
	vec2 r = target->GetPosition() - position;
	vec3 omega = vec3::cross(r, vr) / r.dot(r);
	vec3 a = vec3::cross(vr, omega) * N;
	//vec3 a = vec3::cross(velocity, omega) * (-N * vr.length() / velocity.length());
	//vec3 a = vec3::cross(r, omega) * (-N * vr.length() / r.length());
	
	if (a.y > 30.0 * G)
	{
		a.y = 30.0 * G;
	}

	return vec2(a.x, a.y);
}

bool Rocket::IsHitTarget() const
{
	if (distanceToTraget() <= deathRadius)
	{
		return true;
	}

	return false;
}

bool Rocket::IsHitGround() const
{
	if (position.y < 0.0) 
	{
		return true;
	}

	return false;
}

void Rocket::Move(double dt)
{
	if (target == nullptr)
	{
		return;
	}

	double tetta = atan2(velocity.y, velocity.x);
	double thrust = engine.GetThrustForce();
	double drag = GetDragForce();
	vec2 liftAcceleration = PNGuidance(N);

	acceleration.x = liftAcceleration.x + (thrust - drag) / mass * cos(tetta);
	acceleration.y = liftAcceleration.y + (thrust - drag) / mass * sin(tetta) - G;
	velocity += acceleration * dt;
	position += velocity * dt;
	
	mass -= engine.ReduceFuelMass(dt);
}
