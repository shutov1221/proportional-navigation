#pragma once
#include <utility>
#include <iostream>
#include <sciplot/Constants.hpp>

class vec2
{
public:
	vec2() :
		x(0.0), y(0.0)
	{
	}

	vec2(double x, double y) :
		x(std::move(x)), y(std::move(y))
	{
	}

	vec2(double n) :
		x(n), y(n)
	{
	}

	double x;
	double y;

public:
	friend std::ostream& operator<< (std::ostream& out, const vec2& vec);

	const vec2& operator+=(const vec2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	const vec2& operator-=(const vec2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}
	const vec2& operator*=(const vec2& other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}

	const vec2& operator/=(const vec2& other)
	{
		x /= other.x;
		y /= other.y;
		return *this;
	}
	
	vec2 operator- () const
	{
		return vec2(-x, -y);
	}

	vec2 operator+ (const vec2& other) const
	{
		return vec2(x + other.x, y + other.y);
	}

	vec2 operator- (const vec2& other) const
	{
		return vec2(x - other.x, y - other.y);
	}

	vec2 operator* (const vec2& other) const
	{
		return vec2(x * other.x, y * other.y);
	}

	vec2 operator/ (const vec2& other) const
	{
		return vec2(x / other.x, y / other.y);
	}

	bool operator< (const vec2& other) const
	{
		if (x < other.x)
			return true;
		if (other.x < x)
			return false;
		return y < other.y;
	}

	bool operator> (const vec2& other) const
	{
		return other < *this;
	}

	bool operator<= (const vec2& other) const
	{
		return !(other < *this);
	}

	bool operator>= (const vec2& other) const
	{
		return !(*this < other);
	}

	bool operator== (const vec2& other) const
	{
		if (x != other.x)
		{
			return false;
		}
		if (y != other.y)
		{
			return false;
		}
		
		return true;
	}

	double dot(const vec2& other) const
	{
		return x * other.x + y * other.y;
	}

	double length() const
	{
		return sqrt(x * x + y * y);
	}

	double distance(const vec2& other) const
	{
		return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
	}

	double angleTo(const vec2 other) const
	{
		return acos(this->dot(other) / (length() * other.length()));
	}

	double degrees(double radians) const
	{
		return radians * 180.0 / sciplot::PI;
	}

	vec2 normalized() const
	{
		return *this / length();
	}

	vec2 abs() const
	{
		return vec2(std::abs(x), std::abs(y));
	}
};

