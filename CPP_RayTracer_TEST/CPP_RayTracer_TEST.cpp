#include "pch.h"
#include "CppUnitTest.h"

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
			Tuple p = PointToTuple(point);

			return IsEqual(p, testPoint) ? 0 : Assert::Fail();

			Tuple testVector = Tuple{ 4, -4, 3, 0 };
			Vector3 vector = Vector3{ 4,-4, 3 };
			Tuple v = VectorToTuple(vector);

			return IsEqual(v, testVector) ? 0 : Assert::Fail();
			
		

		}

		TEST_METHOD(Addition)
		{
			Tuple a = Tuple{ 1.f, 1.f, 1.f, 1.f };
			Tuple b = Tuple{ 1.f, 1.f, 1.f, 0.f };
			Tuple c = b + a;
			return IsEqual(c, Tuple(2.f, 2.f, 2.f, 1.f)) ? 0 : Assert::Fail();
			
		}

		TEST_METHOD(Negate)
		{
			Tuple a = { 1.f , 1.f, 1.f, 1.f };
			Tuple b = -a;
			return IsEqual(b, Tuple(-1.f, -1.f, -1.f, -1.f)) ? 0 : Assert::Fail();
		}

		TEST_METHOD(Scalar)
		{
			Tuple a = { 1, -2, 3, -4 };
			Tuple b = a * 3.5;
			return IsEqual(b, Tuple(3.5, -7, 10.5, -14)) ? 0 : Assert::Fail();

			Tuple c = a / 2;
			return IsEqual(c, Tuple(0.5, -1, 1.5, -2)) ? 0 : Assert::Fail();

		}

		TEST_METHOD(Magnitude)
		{
			Tuple a = { 1, -2, 2, 0 }; // vector
		    float magnitude = GetMagnitude(a);
			Assert::AreEqual(magnitude, 3.f);
		}
	};
}
