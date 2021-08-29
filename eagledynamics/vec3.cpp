#include "vec3.h"
#include "vec2.h"

vec3 vec3::cross(const vec3& v1, const vec3& v2)
{
	return vec3(v1.y * v2.z - v1.z * v2.y,
				v1.z * v2.x - v1.x * v2.z,
				v1.x * v2.y - v1.y * v2.x);
}

vec3 vec3::cross(const vec2& v1, const vec2& v2)
{
	return vec3::cross(vec3(v1, 0.0), vec3(v2, 0.0));
}

vec3 vec3::cross(const vec3& v1, const vec2& v2)
{
	return vec3::cross(v1, vec3(v2, 0.0));
}

vec3 vec3::cross(const vec2& v1, const vec3& v2)
{
	return vec3::cross(vec3(v1, 0.0), v2);
}

vec2 to_vec2(const vec3& v)
{
	return vec2(v.x, v.y);
}

