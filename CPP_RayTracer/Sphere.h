#pragma once
#include <string>
#include <vector>
#include "Shape.h"
#include "Ray.h"
class Sphere : public Shape
{
public:
	Sphere(float radius, std::string id);

	std::vector<float> intersect(Ray& ray);

protected:
	std::vector<Intersection&> Intersections(int nOfArguments, ...) override;
private:

	float Dot(const Tuple& tuple, const Tuple& other);
	std::vector<float> _intersections{};
	float _radius{};
	std::string _id{};
};
