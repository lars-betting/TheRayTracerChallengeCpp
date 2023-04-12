#include "Matrix.h"
#include <cmath>
#include <iostream>
Matrix::Matrix(int row, int col)
	:_row(row), _col(col), _matrixData(row* col, 0.0f) // initializes all element in the vector to 0;
{
	std::cout << "matrix created" << std::endl;
}



bool Matrix::operator==(Matrix& other)
{
	for (int i = 0; i < other._row; i++)
	{
		for (int j = 0; j < other._col; j++)
		{
			if (abs(this->at(i, j) - other.at(i, j) >= EPSILON))
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

void Matrix::resetMatrix(int newRow, int newCol)
{
	this->_row = newRow;
	this->_col = newCol;
	_matrixData = std::vector<float>(newRow * newCol, 0.0f);
}

Matrix Matrix::Transpose()
{
	Matrix transposeMatrix(_col, _row);
	

	for (int i = 0; i < transposeMatrix._row; i++)
	{
		for (int j = 0; j < transposeMatrix._col; j++)
		{
			transposeMatrix.at(i,j) = this->at(j, i);
		}
	}
	this->resetMatrix(_col, _row);

	for (int i = 0; i < transposeMatrix._row; i++)
	{
		for (int j = 0; j < transposeMatrix._col; j++)
		{
			this->at(i, j) = transposeMatrix.at(i, j);
		}
	}
	return *this;
}

float& Matrix::Determinant2x2()
{

	float result = (this->at(0, 0) * this->at(1, 1)) - (this->at(0, 1) * this->at(1, 0));
	return result;
}

float& Matrix::Determinant()
{
	float result = 0;
	if (_col == 2)
	{
		return Determinant2x2();
	}
	else if(_col == 3)
	{
		for (int i = 0; i < _col; i++)
		{
			result += this->at(0, i) * Cofactor3x3(*this, 0, i);
		}
	}
	else if (_col == 4)
	{
		for (int i = 0; i < _col; i++)
		{
			result += this->at(0, i) * Cofactor4x4(*this, 0, i);
		}
	}
	return result;
	return result;
}

Matrix Matrix::Inverse()
{
	if (this->Determinant() == 0)
	{
		throw("Matrix not inversible");
	}
	float c = 0;
	Matrix temp(_row, _col);
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			if (_row == 3)
			{
				 c = Cofactor3x3(*this, i, j);
			}
			else if (_row == 4)
			{
				 c = Cofactor4x4(*this, i, j);
			}
			temp.at(j, i) = c / this->Determinant();
		}
	}

	return temp;
}

float& Matrix::Minor3x3(Matrix& matrix, int row, int col)
{
	Matrix temp(matrix._row, matrix._col);
	temp.SubMatrix(matrix, row, col);
	float result = temp.Determinant2x2();
	return result;
}

float& Matrix::Cofactor3x3(Matrix& matrix, int row, int col)
{
	 float result = Matrix::Minor3x3(matrix, row, col);
	if (row + col % 2 == 1)
	{
		result = -result;
	}
	return result;
}

float& Matrix::Cofactor4x4(Matrix& matrix, int row, int col)
{
	Matrix temp(3, 3);
	int sign = 0; ((row + col) % 2 == 0) ? 1 : -1;
	if ((row + col) % 2 == 1)
	{
		sign = -1;
	}
	else
	{
		sign = 1;
	}

	int subMatrix_i = 0; //SUBMATRICES 
	int subMatrix_j = 0;

	for (int i = 0; i < matrix._row; i++)
	{
		if (i == row) continue;

		subMatrix_j = 0;
		for (int j = 0; j < matrix._col; j++)
		{
			if (j == col) continue;

			temp.at(subMatrix_i, subMatrix_j) = matrix.at(i, j);
			subMatrix_j++;
		}
		subMatrix_i++;
	}
	float result = sign * temp.Determinant();
	return result;
}

Matrix Matrix::SubMatrix(Matrix& other, int row, int col)
{

	for (int i = 0, k = 0; i < other._row; ++i)
	{
		if (i == row)
			continue; // continues with the next iteration of the loop

		for (int j = 0, l = 0; j < other._col; ++j)
		{
			if (j == col)
				continue;

			this->at(k, l) = other.at(i, j);
			++l;
		}
		++k;
	}

	return *this;


}

float& Matrix::at(int row, int col)
{
	if (row < 0 || row >= _row || col < 0 || col >= _col) {
		std::cout << "Matrix out of bounds" << std::endl;
	}
	return _matrixData[row * _col + col];
}

//Matrix Matrix::identityMatrix(4, 4); // Identify  the static matrix
Matrix Matrix::createIdentityMatrix()
{
	Matrix identity(4, 4);
	for (int i = 0; i < 4; i++)
	{
		identity(i, i) = 1.0f;
	}
	return identity;
}
Matrix Matrix::identityMatrix = createIdentityMatrix() ;
