#include "Sphere.h"

Sphere::Sphere(float radius, std::string id)
	:_id(id), _radius(radius)
{
}
std::vector<Intersection&> Sphere::Intersections(int nOfArguments, ...)
{

}
std::vector<float> Sphere::intersect(Ray& ray)
{
	float t1{}, t2{};
	for (int i = 0; _intersections.size(); i++)
	{
		_intersections.pop_back();
	}
	Tuple sphere_to_ray = ray.GetOrigin() - Tuple(0, 0, 0, 1);
	float a = Dot(ray.GetDirection(), ray.GetDirection());
	float b = 2 * Dot(ray.GetDirection(), sphere_to_ray);
	float c = Dot(sphere_to_ray, sphere_to_ray)  -1;

	float discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < 0)
	{
		return _intersections;
	}
	else
	{
		t1 = (-1 * b - sqrt(discriminant)) / (2 * a);
		t2 = (-1 * b + sqrt(discriminant)) / (2 * a);
	}
	_intersections.push_back(t1);
	_intersections.push_back(t2);

	return _intersections; 
}

float Sphere::Dot(const Tuple& tuple, const Tuple& other)
{
	return { tuple.x() * other.x() + tuple.y() * other.y() + tuple.z() * other.z() + tuple.w() * other.w()};
}
