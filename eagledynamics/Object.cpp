#include "Object.h"

Object::Object(vec2 position) :
	position(position),
	velocity(vec2(0.0, 0.0)),
	acceleration(vec2(0.0, 0.0))
{

}

Object::Object(vec2 position, vec2 velocity) :
	position(position), 
	velocity(velocity),
	acceleration(vec2(0.0, 0.0))
{

}

void Object::SetPosition(vec2 position)
{
	this->position = position;
}

void Object::SetVelocity(vec2 velocity)
{
	this->velocity = velocity;
}

void Object::SetAcceleration(vec2 acceleration)
{
	this->acceleration = acceleration;
}


const vec2& Object::GetPosition() const
{
	return position;
}

const vec2& Object::GetVelocity() const
{
	return velocity;
}

const vec2& Object::GetAcceleration() const
{ 
	return acceleration;
}

void Object::writeLog(std::ofstream& file) const
{	
	//file << std::setprecision(2) << "pos: " << position << "\t" << " vel: " << velocity.length() << "\t" << " acc: " << acceleration.length();
	file << "pos: " << position << "\t";
	file << "vel: " << velocity.length() << "\t";
	file << "acc: " << acceleration.length() << "\t";
}

