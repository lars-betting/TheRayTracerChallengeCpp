#include <iostream>
#include "Vector3.h"
#include "Canvas.h"
#include "Tuple.h"

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
	Projectile p{};
	Environment e{};

	p.Position = { 0.0f, 1.0f, 0.0f, 1.0f};
	p.Velocity = { 1.0f, 1.8f, 0.0f, 0.0f };
	p.Velocity = p.Velocity.NormalizeTuple() * 11.25f;
	e.Gravity = { 0.0f, -0.1f, 0.0f, 0.0f };
	e.Wind = { -0.01f, 0.0f, 0.0f, 0.0f };

	Canvas c{ 900, 500, {0, 0, 0} }; //init canvas to black
	Colour red{ 255, 0, 0 };
	while (p.Position.y() > 0)
	{
		Tick(e, p);
		std::cout << "Position : " << p.Position.x() << ", " << p.Position.y() << ", " << p.Position.z() << ", " << p.Position.w() << std::endl;
		c.WritePixel(500 - (int)p.Position.y(), (int)p.Position.x(), red);
	}
	
	//c.WritePixel(1, 1,red);
	c.WriteToPPM();


	//std::cout << newString;

	
	return 0;
}