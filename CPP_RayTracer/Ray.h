#pragma once
#include "Tuple.h"
#include <string>
class Ray 
{
public:
	Ray(Tuple& origin, Tuple& direction);
	
	Tuple GetPosition(float t);

private:
	Tuple _origin;
	Tuple _direction;
};

class Sphere
{
public:
	Sphere(float radius, std::string id);

private:
	float _radius;
	std::string _id;
};