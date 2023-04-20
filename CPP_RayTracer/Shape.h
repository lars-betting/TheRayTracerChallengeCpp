#pragma once
#include <vector>
#include <string>


struct Intersection
{
public:
	Intersection(float t, std::string ID)
	:_t(t), _ID(ID) { }

private:
	float _t{};
	std::string _ID{};
};

class Shape
{
public:
	Shape();
	virtual std::vector<Intersection&> Intersections(int noOfArgs, ...);
protected:

	static std::vector<Intersection&> _Intersections;
};

