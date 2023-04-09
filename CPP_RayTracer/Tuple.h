#pragma once
#include <cmath>


class Tuple
{
public:
	Tuple() {};
	Tuple(float X, float Y, float Z, float W);
	~Tuple() {};
	
	virtual float GetMagnitude();
	virtual Tuple NormalizeTuple();
	virtual bool IsEqual(const Tuple& otherTuple);
	virtual float Dot(const Tuple& otherTuple);

	Tuple operator+(const Tuple& otherTuple); // ADDITION
	Tuple operator-(const Tuple& otherTuple); // SUBTRACTION
	Tuple operator-();						  // Negation
	Tuple operator*(float scalar);		      // Scalar multiplication 
	Tuple operator/(float scalar);			  // Scalar division

	virtual float x();
	virtual float y();
	virtual float z();
	virtual float w();

private:

	float _x{};
	float _y{};
	float _z{};
	float _w{};

protected:
	float EPSILON{ 0.00001f };

};

