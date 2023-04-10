#pragma once
#include <vector>
#include "Tuple.h"
class Matrix 
{
public:

	Matrix(int row, int col); 


	float& operator()(int row, int col) { return _matrixData[row * _col + col]; }
	bool operator==(const Matrix& other);
	Matrix operator*(const Tuple& tuple);
	Matrix operator*(const Matrix& other);
private:
	
	int _row{};
	int _col{};
	std::vector<float> _matrixData;
};

