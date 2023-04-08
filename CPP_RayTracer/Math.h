#pragma once
#include <string>
#include <cmath>
#include <iostream>
// HEADER FILE FOR ALL MATH LIBRARIES

//TEMPLATES
template <typename T>
constexpr T Abs(T value)
{
	if (value < 0)
	{
		return -value;
	}
	else
	{
		return value;
	}

}


//STRUCTS
struct Tuple 
{
	float x{}, y{}, z{}, w{};

	Tuple(float x, float y, float z, float w)
		: x(x), y(y), z(z), w(w) {}

	Tuple operator+(const Tuple& otherTuple); // ADDITION
	Tuple operator-(const Tuple& otherTuple); // SUBTRACTION
	Tuple operator-();						  // Negation
	Tuple operator*(float scalar);		      // Scalar multiplication 
	Tuple operator/(float scalar);			  // Scalar division
};



// Overloaded Operators for tuple
inline Tuple Tuple::operator+(const Tuple &otherTuple) // ADDITION
{
	
	return { x + otherTuple.x, y + otherTuple.y, z + otherTuple.z, w + otherTuple.w };
	
}

inline Tuple Tuple::operator-(const Tuple &otherTuple) // SUBTRACTION
{
	return { x - otherTuple.x, y - otherTuple.y, z - otherTuple.z, w - otherTuple.w };
}

inline Tuple Tuple::operator-()
{
	return { -(x), -(y), -(z), -(w) };
}

inline Tuple Tuple::operator*(float scalar)
{
	return { x * scalar, y * scalar, z * scalar, w * scalar };
}
inline Tuple Tuple::operator/(float scalar)
{
	return { x / scalar, y / scalar, z / scalar, w / scalar };
}

struct Vector3
{
	float x{ };
	float y{ };
	float z{ };
};

//FUNCTIONS

inline bool IsEqual(const Tuple& tuple, const Tuple& otherTuple) // EQUALS (IF ==)
{
	static float EPSILON = 0.00001f ;
	if (Abs(tuple.x - otherTuple.x) < EPSILON &&
		Abs(tuple.y - otherTuple.y) < EPSILON &&
		Abs(tuple.z - otherTuple.z) < EPSILON &&
		Abs(tuple.w - otherTuple.w) < EPSILON)
	{
		return true;
	}
	else 
	{
		return false; 
	}
}

inline Tuple PointToTuple(Vector3 point)
{
	return Tuple(point.x, point.y, point.z, 1);
}

inline Tuple VectorToTuple(Vector3 vector)
{
	return Tuple(vector.x, vector.y, vector.z, 0);
}

inline float GetMagnitude(const Tuple& tuple)
{
	return sqrt(pow(tuple.x, 2.f) + pow(tuple.y, 2.f) + pow(tuple.z, 2.f) + pow(tuple.w, 2.f));
}
