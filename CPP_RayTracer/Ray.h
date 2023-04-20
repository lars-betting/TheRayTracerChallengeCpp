#pragma once
#include "Tuple.h"
class Ray 
{
public:
	Ray(Tuple& origin, Tuple& direction);
	
	Tuple GetPosition(float t);


	Tuple GetOrigin() { return _origin; }
	Tuple GetDirection() { return _direction; }
private:
	Tuple _origin;
	Tuple _direction;
};
