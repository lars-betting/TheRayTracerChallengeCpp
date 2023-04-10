#include "Canvas.h"
#include <iostream>
#include <fstream>
Canvas::Canvas(const int width, const int height)
	:_height(height), _width(width)
{
	_pixel = std::vector<std::vector<Colour>>(_height, std::vector<Colour>(_width));
}

Canvas::Canvas(const int width, const int height, const Colour& colour)
	:_height(height), _width(width)
{
	_pixel = std::vector<std::vector<Colour>>(_height, std::vector<Colour>(_width));
	for (int i = 0; i < GetHeight(); i++)
	{
		for (int j = 0; j < GetWidth(); j++)
		{
			WritePixel(i, j, colour);
		}
	}
}

void Canvas::WritePixel(int x, int y, const Colour& colour)
{
	if (x >= 0 && x < _height && y >= 0 && y < _width) {
		at(x, y).set_r(colour.r());
		at(x, y).set_g(colour.g());
		at(x, y).set_b(colour.b());
	}
	else
	{
		std::cout << "what is going on" << std::endl;
	}
}

Colour Canvas::GetPixelAt(int x, int y)
{
	// Make sure the pixel is within the bounds of the canvas
	if (x >= 0 && x < _height && y >= 0 && y < _width) {
		return at(x, y);
	}
	// Return a default color if the pixel is out of bounds
	return Colour();
}

int Canvas::GetWidth() const
{
	return int(_pixel[0].size());
}

int Canvas::GetHeight() const
{
	return int(_pixel.size());
}

std::string Canvas::WriteToPPM()
{
	std::ostringstream currentLine{};
	currentLine.str("");
	_ppm.str("");
	_ppm << "P3\n" << GetWidth() << " " << GetHeight() << "\n" << "255" << "\n";
	for (int i = 0; i < GetHeight(); i++)
	{
		for (int j = 0; j < GetWidth(); j++)
		{
			Colour t = GetPixelAt(i, j);
			_ppm << t.r() << " " << t.g() << " " << t.b() << " ";
			currentLine << t.r() << " " << t.g() << " " << t.b() << " ";
			if (currentLine.str().size() >= 64)
			{
				_ppm << "\n";
				currentLine.str("");
			}
			
		}
		if (currentLine.str().find("\n"))
		{
			
		}
		else
		{
			_ppm << "\n";
			currentLine.str("");
		}
	}
	_ppm << "\n";
	std::cout << _ppm.str() << std::endl;
	std::ofstream out("output.ppm");
	out << _ppm.str();
	return _ppm.str();
}

Colour& Canvas::at(int row, int col)
{
	if (row < 0 || row >= _height || col < 0 || col >= _width) {
		throw std::out_of_range("Index out of range");
	}
	return _pixel.at(row).at(col);
}
  