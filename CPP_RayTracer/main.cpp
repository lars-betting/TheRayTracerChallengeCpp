#include <iostream>
#include "Vector3.h"
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

	p.Position = { 0, 1, 0, 1};
	p.Velocity = { 1, 1, 0, 0};

	e.Gravity = { 0, -0.1f, 0, 0 };
	e.Wind = { -0.01f, 0, 0, 0 };

	while (p.Position.y() > 0)
	{
		Tick(e, p);
		std::cout << "Position : " << p.Position.x() << ", " << p.Position.y() << ", " << p.Position.z() << ", " << p.Position.w() << std::endl;
	}

	return 0;
}