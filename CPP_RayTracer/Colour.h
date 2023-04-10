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

	//Getters and Setters
	float r() const { return _r; }
	void set_r(float r) { _r = r; }

	float g() const { return _g; }
	void set_g(float g) { _g = g; }

	float b() const { return _b; }
	void set_b(float b) { _b = b; }

	float alpha();

	Colour Hadamard( const Colour& other) const;

private:
	float _r{};
	float _g{};
	float _b{};
	float _alpha{};
};

