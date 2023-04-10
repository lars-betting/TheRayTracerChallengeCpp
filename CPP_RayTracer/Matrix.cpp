#include "Matrix.h"
#include <cmath>

Matrix::Matrix(int row, int col)
	:_row(row), _col(col), _matrixData(row* col, 0.0f) // initializes all element in the vector to 0;
{
}



bool Matrix::operator==(const Matrix& matrix)
{
	for (int i = 0; i < _col; i++)
	{
		for (int j = 0; j < _row; j++)
		{
			//if(abs())
		}
	}
}

Matrix Matrix::operator*(const Tuple& tuple)
{
	//return Matrix();
}

Matrix Matrix::operator*(const Matrix& other)
{
	//return Matrix();
}
