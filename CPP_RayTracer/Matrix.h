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
	Matrix operator*(Matrix& other);
	Matrix operator*(Tuple& tuple);

	static Matrix MatrixMultiply(Matrix& matrix, Tuple& tuple);
	static Matrix MatrixMultiply(Matrix& matrix, Matrix& other);
	void resetMatrix(int newRow, int newCol);
	Matrix Transpose();
	float& Determinant();
	Matrix Inverse();
	Tuple ToTuple(Matrix& matrix);

	//public for debug purposes
	float& at(int row, int col);



	// Matrix transforms
	static Matrix identityMatrix;
	static Matrix TranslationMatrix(float x, float y, float z);
	static Matrix ScalingMatrix(float x, float y, float z);
	static Matrix RotationMatrixX(float r);
	static Matrix RotationMatrixY(float r);
	static Matrix RotationMatrixZ(float r);
	static Matrix ShearingMatrix(float xY, float xZ, float yX, float yZ, float zX, float zY);
private:
	//TODO: MAKE DETERMINANT, MINOR AND COFACTOR FUNCTIONS FLEXIBLE
	static Matrix createIdentityMatrix();
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

