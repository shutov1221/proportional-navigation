#pragma once
#include <utility>
#include "vec2.h"

class vec3
{
public:
	vec3() :
		x(0.0), y(0.0), z(0.0)
	{
	}

	vec3(vec2 v, double z) :
		x(v.x), y(v.y), z(z)
	{
	}

	vec3(double x, double y, double z) :
		x(std::move(x)), y(std::move(y)), z(std::move(z))
	{
	}

	vec3(double n) :
		x(n), y(n), z(n)
	{
	}

	double x;
	double y;
	double z;

public:
	const vec3& operator+=(const vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	const vec3& operator-=(const vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}
	const vec3& operator*=(const vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	const vec3& operator/=(const vec3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	vec3 operator- () const
	{
		return vec3(-x, -y, -z);
	}

	vec3 operator+ (const vec3& other) const
	{
		return vec3(x + other.x, y + other.y, z + other.z);
	}

	vec3 operator- (const vec3& other) const
	{
		return vec3(x - other.x, y - other.y, z - other.z);
	}

	vec3 operator* (const vec3& other) const
	{
		return vec3(x * other.x, y * other.y, z * other.z);
	}

	vec3 operator/ (const vec3& other) const
	{
		return vec3(x / other.x, y / other.y, z / other.z);
	}

	bool operator< (const vec3& other) const
	{
		if (x < other.x)
			return true;
		if (other.x < x)
			return false;
		if (y < other.y)
			return true;
		if (other.y < y)
			return false;
		return z < other.z;
	}

	bool operator> (const vec3& other) const
	{
		return other < *this;
	}

	bool operator<= (const vec3& other) const
	{
		return !(other < *this);
	}

	bool operator>= (const vec3& other) const
	{
		return !(*this < other);
	}

	bool operator== (const vec3& other) const
	{
		if (x != other.x)
		{
			return false;
		}
		if (y != other.y)
		{
			return false;
		}

		if (z != other.z)
		{
			return false;
		}

		return true;
	}

	double dot(const vec3& other) const
	{
		return x * other.x + y * other.y + z * other.z;
	}

	double length() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	double distance(const vec3& other) const
	{
		return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z));
	}

	vec3 normalized() const
	{
		return *this / length();
	}

	static vec3 cross(const vec3& v1, const vec3& v2);
	static vec3 cross(const vec2& v1, const vec2& v2);
	static vec3 cross(const vec3& v1, const vec2& v2);
	static vec3 cross(const vec2& v1, const vec3& v2);
};

