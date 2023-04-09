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

	virtual Tuple operator+(const Tuple& otherTuple) const; // ADDITION
	virtual Tuple operator-(const Tuple& otherTuple) const; // SUBTRACTION
	virtual Tuple operator-() const;						  // Negation
	virtual Tuple operator*(float scalar) const ;		      // Scalar multiplication 
	virtual Tuple operator/(float scalar) const;			  // Scalar division

	virtual float x() const;
	virtual float y() const;
	virtual float z() const;
	virtual float w() const;

private:

	float _x{};
	float _y{};
	float _z{};
	float _w{};
	
protected:
	float EPSILON{ 0.00001f };

};

