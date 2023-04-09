#pragma once
#include "Tuple.h"
class Colour : public Tuple
{
public:
	Colour() {}
	Colour(float r, float  g, float b, float alpha)
		:_r(r), _g(g), _b(b), _alpha(alpha) {}
	Colour(float r, float  g, float b)
		:_r(r), _g(g), _b(b) {}
	Colour(const Tuple& tuple);
	~Colour() {}

public:

	//Getters
	float r();
	float g();
	float b();
	float alpha();

	Colour Hadamard( const Colour& other) const;

private:
	float _r{};
	float _g{};
	float _b{};
	float _alpha{};
};

