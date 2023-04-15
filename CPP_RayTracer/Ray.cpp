#include "Ray.h"

Ray::Ray(Tuple& origin, Tuple& direction)
	:_origin(origin), _direction(direction)
{
}

Tuple Ray::GetPosition(float t)
{
	return _origin + (_direction * t);
}

Sphere::Sphere(float radius, std::string id)
	:_radius(radius), _id(id)
{

}
