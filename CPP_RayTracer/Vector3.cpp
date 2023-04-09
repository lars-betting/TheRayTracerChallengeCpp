#include "Vector3.h"

Tuple Vector3::PointToTuple()
{
    return {_x, _y, _z, 1.f};
}

Tuple Vector3::VectorToTuple()
{
    return { _x, _y, _z, 0 };
}

float Vector3::GetMagnitude()
{
    return sqrt(pow(_x, 2.f) + pow(_y, 2.f) + pow(_z, 2.f));
}

Vector3 Vector3::NormalizeVector()
{
    float magnitude = GetMagnitude();
    return { _x / magnitude, _y / magnitude, _z / magnitude };
}

bool Vector3::IsEqual(const Vector3& otherVector)
{
	if (abs(_x - otherVector._x) < EPSILON &&
		abs(_y - otherVector._y) < EPSILON &&
		abs(_z - otherVector._z) < EPSILON)
	{
		return true;
	}
	else
	{
		return false;
	}
}

float Vector3::Dot(const Vector3& otherVector)
{
    return 0.0f;
}

Vector3 Vector3::Cross(const Vector3& otherVector)
{
    return { _y * otherVector._z - _z * otherVector._y,
             _z * otherVector._x - _x * otherVector._z, 
             _x * otherVector._y - _y * otherVector._x };

}

float Vector3::x()
{
	return _x;
}

float Vector3::y()
{
	return _y;
}

float Vector3::z()
{
	return _z;
}
