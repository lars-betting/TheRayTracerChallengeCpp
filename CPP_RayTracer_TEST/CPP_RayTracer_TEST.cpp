#include "pch.h"
#include "CppUnitTest.h"

#include "../CPP_RayTracer/Tuple.cpp"
#include "../CPP_RayTracer/Vector3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace CPPRayTracerTEST
{
	TEST_CLASS(CPPRayTracerTEST)
	{
	public:
		
		TEST_METHOD(PointAndVector)
		{
			
			Tuple testPoint = Tuple{ 4, -4, 3, 1 };
			Vector3 point = Vector3{ 4, -4, 3 };
			Tuple p = point.PointToTuple();
			
			return p.IsEqual(testPoint) ? 0 : Assert::Fail();

			Tuple testVector = Tuple{ 4, -4, 3, 0 };
			Vector3 vector = Vector3{ 4,-4, 3 };
			Tuple v = vector.VectorToTuple();

			return v.IsEqual(testVector) ? 0 : Assert::Fail();
			
		

		}

		TEST_METHOD(Addition)
		{
			Tuple a = Tuple{ 1.f, 1.f, 1.f, 1.f };
			Tuple b = Tuple{ 1.f, 1.f, 1.f, 0.f };
			Tuple c = b + a;
			return c.IsEqual(Tuple(2.f, 2.f, 2.f, 1.f)) ? 0 : Assert::Fail();
			
		}

		TEST_METHOD(Negate)
		{
			Tuple a = { 1.f , 1.f, 1.f, 1.f };
			Tuple b = -a;
			return b.IsEqual(Tuple(-1.f, -1.f, -1.f, -1.f)) ? 0 : Assert::Fail();
		}

		TEST_METHOD(Scalar)
		{
			Tuple a = { 1, -2, 3, -4 };
			Tuple b = a * 3.5;
			return b.IsEqual(Tuple(3.5, -7, 10.5, -14)) ? 0 : Assert::Fail();

			Tuple c = a / 2;
			return c.IsEqual(Tuple(0.5, -1, 1.5, -2)) ? 0 : Assert::Fail();

		}

		TEST_METHOD(Magnitude)
		{
			Tuple a = { 1, -2, 2, 0 }; // vector
		    float magnitude = a.GetMagnitude();
			Assert::AreEqual(magnitude, 3.f);
		}

		TEST_METHOD(Normalize)
		{
			Tuple a = { 1, -2, 2, 0 };
			a = a.NormalizeTuple();
			Assert::AreEqual(a.GetMagnitude(), 1.f);
		}

		TEST_METHOD(DotProduct)
		{
			Tuple a = { 2, 2, 2, 2 };
			float dotProduct = a.Dot(a);
			Assert::AreEqual(dotProduct, 16.f);
		}

		TEST_METHOD(Cross)
		{
			Vector3 a = { 1, 2, 3 };
			Vector3 b = { 2, 3, 4 };
			a = a.Cross(b);
			Tuple c = a.VectorToTuple();
			return c.IsEqual(Tuple(-1, 2, -1, 0)) ? 0 : Assert::Fail();
		}
	};
}
