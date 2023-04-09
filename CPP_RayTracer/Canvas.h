#pragma once
#include "Colour.h" 
#include <vector>
#include <sstream>
class Canvas
{
public:
	Canvas() {}
	Canvas(const int width, const int height); // Initialize grid to white
	Canvas(const int width, const int height, const Colour& colour); // Initialize grid to specific colour 

	void WritePixel(int x, int y, const Colour& colour);
	Colour GetPixelAt(int x, int y);

	// Getters
	int GetWidth() const;
	int GetHeight() const;

	std::string WriteToPPM();
	
private:
	Colour& at(int row, int col);
	std::vector<std::vector<Colour>> _pixels{};
	int _width{};
	int _height{};
	std::ostringstream _ppm;
};

