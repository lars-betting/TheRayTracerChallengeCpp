#include "Canvas.h"
#include <iostream>
Canvas::Canvas(const int width, const int height)
	: _pixels(height, std::vector<Colour>(width))
{
	
}

Canvas::Canvas(const int width, const int height, const Colour& colour)
{

}

void Canvas::WritePixel(int x, int y, const Colour& colour)
{
	if (x >= 0 && x < _width && y >= 0 && y < _height) {
		at(y, x) = colour;
	}
}

Colour Canvas::GetPixelAt(int x, int y)
{
	// Make sure the pixel is within the bounds of the canvas
	if (x >= 0 && x < _width && y >= 0 && y < _height) {
		return at(y, x);
	}
	// Return a default color if the pixel is out of bounds
	return Colour();
}

int Canvas::GetWidth() const
{
	return _pixels[0].size();
}

int Canvas::GetHeight() const
{
	return _pixels.size();
}

std::string Canvas::WriteToPPM()
{
	_ppm << "P3\n" << GetWidth() << " " << GetHeight() << "\n" << "255" << "\n";
	for (int i = 0; i < GetWidth(); i++)
	{
		for (int j = 0; j < GetHeight(); j++)
		{
			Colour t = GetPixelAt(i, j);
			_ppm << t.r() << " " << t.g() << " " << t.b() << " ";
			
		}
		_ppm << "\n";

	}
	
	std::cout << _ppm.str() << std::endl;
	return _ppm.str();
}

Colour& Canvas::at(int row, int col)
{
	return _pixels.at(row).at(col);
}
  