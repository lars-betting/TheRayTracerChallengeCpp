#include "Ray.h"

Ray::Ray(Tuple& origin, Tuple& direction)
	:_origin(origin), _direction(direction)
{
}

Tuple Ray::GetPosition(float t)
{
	return _origin + (_direction * t);
}


