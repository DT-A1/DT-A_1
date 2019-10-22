#include "Matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;


void Matrix::input()
{
	cout << "Enter number of rows: ";
	cin >> nrows;
	cout << "Enter number of colunms: ";
	cin >> ncols;
	mat = new double*[nrows];
	for (int i = 0; i < nrows; i++)
	{
		mat[i] = new double[ncols];
		for (int j = 0; j < ncols; j++)
		{
			cout << "Enter element [" << i << "][" << j << "]: ";
			cin >> mat[i][j];
		}
	}
}
void Matrix::print()
{
	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < ncols; j++)
		{
			cout << setw(10) << mat[i][j];
		}
		cout << endl;
	}
}
void Matrix::interchangeRows(int row1, int row2)
{
	for (int i = 0; i < ncols; i++)
	{
		double temp = mat[row1][i];
		mat[row1][i] = mat[row2][i];
		mat[row2][i] = temp;
	}
}
void Matrix::addRowstoRow(double k, int row1, int row2)
{
	for (int i = 0; i < ncols; i++)
	{
		mat[row2][i] += (k * mat[row1][i]);
	}
}
void Matrix::multiplyRow(double k, int row)
{
	if (k != 0)
	{
		for (int i = 0; i < ncols; i++)
		{
			mat[row][i] *= k;
		}
	}
	else cout << "k == 0 is not allowed!" << endl;
}
Matrix Matrix::findLadderMatrix()
{
	Matrix matrix = *this;
	int nonZero = 0;
	int count_nonZero = 0;
	for (int i = 0; i < ncols && i < nrows; i++)
	{
		if (matrix.mat[i][i] == 0)
		{
			for (int k = i + 1; k < nrows; k++)
			{
				if (matrix.mat[k][i] != 0)

				{
					matrix.interchangeRows(i, k);
					i--;
					break;
				}
			}
		}
		else {
			for (int j = i + 1; j < nrows; j++)
			{
				matrix.addRowstoRow(-matrix.mat[j][i] / matrix.mat[i][i], i, j);
				matrix.print();
				system("pause");
				system("cls");
			}
		}
	}
	for (int i = nrows - 1; i >= 0; i--)
	{
		if (matrix.mat[i][ncols - 1] == 0) continue;
		for (int j = 0; j < ncols; j++)
		{
			if (matrix.mat[i][j] != 0)
			{
				count_nonZero = ncols - j;
				break;
			}
		}
		if (count_nonZero == nonZero)
		{
			matrix.addRowstoRow(-matrix.mat[i + 1][ncols - 1] / matrix.mat[i][ncols - 1], i, i + 1);
		}
		nonZero = count_nonZero;
		count_nonZero = 0;
	}

	return matrix;
}
double Matrix::findDeterminant()
{
	if (nrows == 2 && ncols == 2)
	{
		return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
	}
	double ans = 0;
	for (int i = 0; i < ncols; i++)
	{
		Matrix b = cutRownCol(0, i);
		ans += mat[0][i] * b.findDeterminant() * pow(-1, i);
	}
	return ans;
}
Matrix Matrix::cutRownCol(int row, int col) {
	Matrix b(nrows - 1, ncols - 1, 0);
	int h = 0;
	int k = 0;
	for (int i = 0; i < nrows; i++)
	{
		if (i == row) continue;
		for (int j = 0; j < ncols; j++)
		{
			if (j == col) continue;
			b.mat[k][h++] = this->mat[i][j];
		}
		k++;
		h = 0;
	}
	return b;
}
int Matrix::findRank()
{
	Matrix b = findLadderMatrix();
	int count = 0;
	for (int i = 0, j = 0; i < nrows && j < ncols; i++, j++)
	{
		if (b.mat[i][j] != 0) count++;
		else
		{
			i--;
		}
	}

	return count;
}
bool Matrix::isZeroRow(int row)
{
	for (int i = 0; i < ncols; i++)
	{
		if (mat[row][i] != 0) return false;
	}
	return true;
}

Matrix::Matrix()
{
	nrows = 2;
	ncols = 2;
	mat = new double*[nrows];
	for (int i = 0; i < nrows; i++)
	{
		mat[i] = new double[ncols];
	}
	mat[0][0] = 1;
	mat[0][1] = 0;
	mat[1][0] = 0;
	mat[1][1] = 1;
}
Matrix::Matrix(const Matrix& matrix)
{
	this->nrows = matrix.nrows;
	this->ncols = matrix.ncols;
	this->mat = new double*[this->nrows];
	for (int i = 0; i < this->nrows; i++)
	{
		this->mat[i] = new double[ncols];
		for (int j = 0; j < this->ncols; j++)
		{
			this->mat[i][j] = matrix.mat[i][j];
		}
	}
}
Matrix::Matrix(int nrows, int ncols, int value)
{
	this->nrows = nrows;
	this->ncols = ncols;
	this->mat = new double*[nrows];
	for (int i = 0; i < nrows; i++)
	{
		this->mat[i] = new double[ncols];
		for (int j = 0; j <= ncols; j++)
		{
			this->mat[i][j] = value;
		}
	}
}

Matrix::~Matrix()
{
	if (mat == NULL)
	{
		for (int i = 0; i < nrows; i++)
		{
			delete[] mat[i];
		}
	}
}
