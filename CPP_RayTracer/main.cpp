#include <iostream>
#include "Vector3.h"
#include "Canvas.h"
#include "Tuple.h"
#include "Matrix.h"
struct Projectile
{
	Tuple Position{};
	Tuple Velocity{};
};

struct Environment
{
	Tuple Gravity{};
	Tuple Wind{};
};
void Tick(Environment& environment, Projectile& projectile)
{
	projectile.Position = projectile.Position + projectile.Velocity;
	projectile.Velocity = projectile.Velocity + environment.Gravity + environment.Wind;
}

int main()
{
	//Projectile p{};
	//Environment e{};

	//p.Position = { 0.0f, 1.0f, 0.0f, 1.0f};
	//p.Velocity = { 1.0f, 1.8f, 0.0f, 0.0f };
	//p.Velocity = p.Velocity.NormalizeTuple() * 11.25f;
	//e.Gravity = { 0.0f, -0.1f, 0.0f, 0.0f };
	//e.Wind = { -0.01f, 0.0f, 0.0f, 0.0f };

	//Canvas c{ 900, 500, {0, 0, 0} }; //init canvas to black
	//Colour red{ 255, 0, 0 };
	//while (p.Position.y() > 0)
	//{
	//	Tick(e, p);
	//	std::cout << "Position : " << p.Position.x() << ", " << p.Position.y() << ", " << p.Position.z() << ", " << p.Position.w() << std::endl;
	//	c.WritePixel(500 - (int)p.Position.y(), (int)p.Position.x(), red);
	//}
	//
	////c.WritePixel(1, 1,red);
	//c.WriteToPPM();


	//std::cout << newString;
	Matrix A(4, 4);
	A(0, 0) = 3;
	A(0, 1) = -9;
	A(0, 2) = 7;
	A(0, 3) = 3;
	A(1, 0) = 3;
	A(1, 1) = -8;
	A(1, 2) = 2;
	A(1, 3) = -9;
	A(2, 0) = -4;
	A(2, 1) = 4;
	A(2, 2) = 4;
	A(2, 3) = 1;
	A(3, 0) = -6;
	A(3, 1) = 5;
	A(3, 2) = -1;
	A(3, 3) = 1;

	Matrix B(4, 4);
	B(0, 0) = 8;
	B(0, 1) = 2;
	B(0, 2) = 2;
	B(0, 3) = 2;
	B(1, 0) = 3;
	B(1, 1) = -1;
	B(1, 2) = 7;
	B(1, 3) = 0;
	B(2, 0) = 7;
	B(2, 1) = 0;
	B(2, 2) = 5;
	B(2, 3) = 4;
	B(3, 0) = 6;
	B(3, 1) = -2;
	B(3, 2) = 0;
	B(3, 3) = 5;
	Matrix C(4, 4);
	C = Matrix::MatrixMultiply(A, B);

	Matrix D(4, 4);
	Matrix E(4, 4);
	E = B.Inverse();
	D = Matrix::MatrixMultiply(C, E);
	
	if (D == A)
	{
		std::cout << "that actually worked" << std::endl;
	}
	else
	{
		std::cout << "nope" << std::endl;
	}
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << D.at(i, j) << std::endl;
		}
	}
	//std::cout << x << std::endl;
	



	
	return 0;
}
