#pragma once
#include "Tuple.h"
class Vector3 : public Tuple
{
public:
	
		Vector3(float x, float y, float z)
			: _x(x), _y(y), _z(z) {}
		Vector3(Tuple& tuple);

		Tuple PointToTuple();
		Tuple VectorToTuple();
		Vector3 NormalizeVector();


		float GetMagnitude() override;

		bool IsEqual(const Vector3& otherVector);
		float Dot(const Vector3& otherVector);

		Vector3 Cross(const Vector3& otherVector);

		virtual float x();
		virtual float y();
		virtual float z();
		
private:

		float _x{ };
		float _y{ };
		float _z{ };
};

