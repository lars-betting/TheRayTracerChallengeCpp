#include "Tuple.h"

inline Tuple::Tuple(float X, float Y, float Z, float W)
	: _x(X), _y(Y), _z(Z), _w(W)
{
}

Tuple Tuple::operator+(const Tuple& otherTuple) const
{
	return { _x + otherTuple._x, _y + otherTuple._y, _z + otherTuple._z, _w + otherTuple._w };
}

Tuple Tuple::operator-(const Tuple& otherTuple) const
{
	return { _x - otherTuple._x, _y - otherTuple._y, _z - otherTuple._z, _w - otherTuple._w };
}



Tuple Tuple::operator-() const
{
	return { -(_x), -(_y), -(_z), -(_w) };
}

Tuple Tuple::operator*(float scalar) const
{
	return { _x * scalar, _y * scalar, _z * scalar, _w * scalar };
}

Tuple Tuple::operator/(float scalar) const
{
	return { _x / scalar, _y / scalar, _z / scalar, _w / scalar };
}

float Tuple::x() const
{
	return _x;
}

float Tuple::y() const
{
	return _y;
}

float Tuple::z() const
{
	return _z;
}

float Tuple::w() const
{
	return _w;
}


float Tuple::GetMagnitude()
{
	return sqrt(pow(_x, 2.f) + pow(_y, 2.f) + pow(_z, 2.f) + pow(_w, 2.f));
}

Tuple Tuple::NormalizeTuple()
{
	float magnitude = GetMagnitude();
	return {_x / magnitude, _y / magnitude, _z / magnitude, _w / magnitude};
}

bool Tuple::IsEqual(const Tuple& otherTuple)
{
	
		if (abs(_x - otherTuple._x) < EPSILON &&
			abs(_y - otherTuple._y) < EPSILON &&
			abs(_z - otherTuple._z) < EPSILON &&
			abs(_w - otherTuple._w) < EPSILON)
		{
			return true;
		}
		else 
		{
			return false; 
		}
}

float Tuple::Dot(const Tuple& otherTuple)
{
	return {_x * otherTuple._x + _y * otherTuple._y + _z * otherTuple._z +_w * otherTuple._w };
}


