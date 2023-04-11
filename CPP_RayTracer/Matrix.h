#pragma once
#include <vector>
#include "Tuple.h"
class Matrix 
{
public:

	Matrix(int row, int col); 
	Matrix() {};

	float& operator()(int row, int col) { return _matrixData[row * _col + col]; }
	bool operator==(Matrix& other);
	static Matrix MatrixMultiply(Matrix& matrix, Tuple& tuple);
	static Matrix MatrixMultiply(Matrix& matrix, Matrix& other);
	void resetMatrix(int newRow, int newCol);
	Matrix Transpose();
	
	float& Determinant2x2();
	Matrix SubMatrix(Matrix& other, int row, int col);


	// Public variables
	static Matrix identityMatrix;
private:
	static Matrix createIdentityMatrix();
	float& at(int row, int col);

	int _row{};
	int _col{};
	std::vector<float> _matrixData{};
	float EPSILON{ 0.00001f };
};

