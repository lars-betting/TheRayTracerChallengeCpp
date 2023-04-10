#pragma once
#include <vector>
#include "Tuple.h"
class Matrix 
{
public:

	Matrix(int row, int col); 


	float& operator()(int row, int col) { return _matrixData[row * _col + col]; }
	bool operator==(Matrix& other);
	static Matrix MatrixMultiply(Matrix& matrix, Tuple& tuple);
	static Matrix MatrixMultiply(Matrix& matrix, Matrix& other);

	float& at(int row, int col);
private:
	
	int _row{};
	int _col{};
	std::vector<float> _matrixData;
	float EPSILON{ 0.00001f };
};

