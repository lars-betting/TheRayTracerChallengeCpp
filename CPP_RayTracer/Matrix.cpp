#include "Matrix.h"
#include <cmath>
#include <iostream>
Matrix::Matrix(int row, int col)
	:_row(row), _col(col), _matrixData(row* col, 0.0f) // initializes all element in the vector to 0;
{
}



bool Matrix::operator==(Matrix& matrix)
{
	for (int i = 0; i < _col; i++)
	{
		for (int j = 0; j < _row; j++)
		{
			if (abs(at(i, j) - matrix.at(i, j) >= EPSILON))
			{
				return false;
			}
		}
	}
	return true;
}

Matrix Matrix::MatrixMultiply(Matrix& matrix, Tuple& tuple)
{
	Matrix m(4, 1);
	for (int i = 0; i < 4; i++)
	{
		int j = 0;
		float& current = m.at(i, j);
		current = 0.0f;
		
		current += matrix.at(i, 0) * tuple.x();
		current += matrix.at(i, 1) * tuple.y();
		current += matrix.at(i, 2) * tuple.z();
		current += matrix.at(i, 3) * tuple.w();
	}
	return m;
}

Matrix Matrix::MatrixMultiply(Matrix& matrix, Matrix& other)
{
	Matrix m(matrix._row, other._col);
	for (int i = 0; i < m._row; i++)
	{
		for (int j = 0; j < m._col; j++)
		{
			float& current = m.at(i, j);
			current = 0.0f;
			for (int k = 0; k < matrix._col; k++)
			{
				current += matrix.at(i, k) * other.at(k, j);
			}
		}
	}
	
	return m;
}

float& Matrix::at(int row, int col)
{
	if (row < 0 || row >= _row || col < 0 || col >= _col) {
		std::cout << "Matrix out of bounds" << std::endl;
	}
	return _matrixData[row * _col + col];
}
