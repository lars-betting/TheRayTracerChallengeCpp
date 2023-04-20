#include "Shape.h"
#include <stdarg.h>

std::vector<Intersection&> Shape::Intersections(int noOfArguments, ...)
{
	va_list args;
	va_start(args, noOfArguments);
	for (int i = 0; i < noOfArguments; i++)
	{
		_Intersections.push_back(va_arg(args, Intersection));
	}
	va_end(args);

	return _Intersections;
}