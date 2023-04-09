#include "Colour.h"

Colour::Colour(const Tuple& tuple)
    :Tuple(tuple)
{
    _r = tuple.x();
    _g = tuple.y();
    _b = tuple.z();
    _alpha = tuple.w();
}

float Colour::r()
{
    return _r;
}

float Colour::g()
{
    return _g;
}

float Colour::b()
{
    return _b;
}

float Colour::alpha()
{
    return _alpha;
}

Colour Colour::Hadamard(const Colour& other) const
{
    return { _r * other._r, _g * other._g, _b * other._b };
}
