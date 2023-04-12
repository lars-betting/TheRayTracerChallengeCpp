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
	float& Determinant();
	Matrix Inverse();

	//public for debug purposes
	float& at(int row, int col);



	// Public variables
	static Matrix identityMatrix;
private:
	static Matrix createIdentityMatrix();

	//TODO: MAKE DETERMINANT, MINOR AND COFACTOR FUNCTIONS FLEXIBLE
	float& Determinant2x2();
	static float& Minor3x3(Matrix& matrix, int row, int col);
	float& Cofactor4x4(Matrix& matrix, int row, int col);
	static float& Cofactor3x3(Matrix& matrix, int row, int col);
	Matrix SubMatrix(Matrix& other, int row, int col);


	int _row{};
	int _col{};
	std::vector<float> _matrixData{};
	float EPSILON{ 0.00001f };
};

