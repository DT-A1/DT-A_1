#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <cmath>
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
void Matrix::inputEquations()
{
	cout << "Nhap so phuong trinh: ";
	cin >> nrows;
	cout << "Nhap so an: ";
	cin >> ncols;
	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < ncols; j++)
		{
			cout << "a" << i + 1 << j + 1 << "*x" << j + 1 << " ";
			if (j != ncols - 1) cout << "+ ";
		}
		cout << "= b" << i + 1 << endl;
	}
	mat = new double*[nrows];
	cout << "Nhap vao dang ma tran hoa của he phuong trinh: " << endl;
	for (int i = 0; i < nrows; i++)
	{
		mat[i] = new double[ncols + 1];
		for (int j = 0; j < ncols; j++)
		{
			cout << "Nhap a" << i + 1 << j + 1 << ": ";
			cin >> mat[i][j];
		}
		cout << "Nhap b" << i + 1 << ": ";
		cin >> mat[i][ncols];
	}
	++ncols; //Thêm 1 cột để chứa vế phải của phương trình
}
void Matrix::print()
{
	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < ncols; j++)
		{
			cout << setw(10);
			if (fabs(mat[i][j]) < 1e-8) cout << 0;
			else cout << mat[i][j];
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
Matrix Matrix::findEchelonForm()
{
	Matrix matrix = *this;
	int flag = 0; //flag = 1 nếu các phần tử cùng cột bên dưới mat[i][j] đều bằng 0, kể cả mat[i][j]
	for (int i = 0, j = 0; i < nrows && j < ncols; i++, j++)
	{
		if (matrix.mat[i][j] == 0) //Tìm dòng có phần tử ở cột i khác 0 để hoán vị 2 dòng
		{
			int k = 0;
			for (k = i + 1; k < nrows; k++)
			{
				if (matrix.mat[k][j] != 0)
				{
					matrix.interchangeRows(i, k); //Đổi vị trí hai dòng
					break;
				}
			}
			if (k >= nrows) flag = 1;
		}
		if (flag == 1) //Nếu flag = 1, dời sang cột bên phải
		{
			--i;
			flag = 0;
			continue;
		}
		for (int h = i + 1; h < nrows; h++)  //Biến đổi các dòng bên dưới dòng i để các phần tử dưới cột j đều bằng 0
		{
			matrix.addRowstoRow(-matrix.mat[h][j] / matrix.mat[i][j], i, h);
		}
	}
	return matrix;
}
Matrix Matrix::findReducedEchelonForm()
{
	Matrix matrix = *this;
	int flag = 0; //flag = 1 nếu các phần tử cùng cột bên dưới mat[i][j] đều bằng 0, kể cả mat[i][j]
	for (int i = 0, j = 0; i < nrows && j < ncols; i++, j++)
	{
		if (matrix.mat[i][j] == 0) //Tìm dòng có phần tử ở cột i khác 0 để swap 2 dòng
		{
			int k = 0;
			for (k = i + 1; k < nrows; k++)
			{
				if (matrix.mat[k][j] != 0)
				{
					matrix.interchangeRows(i, k);
					break;
				}
			}
			if (k >= nrows) flag = 1;
		}
		if (flag == 1)
		{
			--i;
			flag = 0;
			continue;
		}
		matrix.multiplyRow(1 / matrix.mat[i][j], i); //Biến đổi dòng để phần tử cơ sở bằng 1
		for (int h = i + 1; h < nrows; h++)  //Biến đổi các dòng bên dưới dòng i để các phần tử dưới cột j đều bằng 0
		{
			matrix.addRowstoRow(-matrix.mat[h][j] / matrix.mat[i][j], i, h);
		}
	}
	return matrix;
}
double Matrix::findDeterminant()
{
	if (nrows == ncols)
	{
		double ans = 1; //Khởi tạo biến chứa kết quả
		Matrix matrix = *this;
		int flag = 0; //flag = 1 nếu các phần tử cùng cột bên dưới mat[i][j] đều bằng 0, kể cả mat[i][j]
		for (int i = 0, j = 0; i < nrows && j < ncols; i++, j++)
		{
			if (matrix.mat[i][j] == 0) //Tìm dòng có phần tử ở cột i khác 0 để swap 2 dòng
			{
				int k = 0;
				for (k = i + 1; k < nrows; k++)
				{
					if (matrix.mat[k][j] != 0)
					{
						matrix.interchangeRows(i, k);
						ans *= -1; //Khi hoán vị 2 dòng thi det(newA) = -det(A)
						break;
					}
				}
				if (k >= nrows) flag = 1;
			}
			if (flag == 1)
			{
				--i;
				flag = 0;
				continue;
			}
			for (int h = i + 1; h < nrows; h++)  //Biến đổi các dòng bên dưới dòng i để các phần tử dưới cột j đều bằng 0
			{
				matrix.addRowstoRow(-matrix.mat[h][j] / matrix.mat[i][j], i, h);
			}
		}
		for (int i = 0; i < nrows; i++)
			ans *= matrix.mat[i][i]; //det của ma trận bậc thang bằng tích các phần tử trên đường chéo chính
		return ans;
	}
	else cout << "Khong the tinh dinh thuc! Phai la ma tran vuong!" << endl;
}
Matrix Matrix::submatrix(int row, int col) {
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
	Matrix b = findEchelonForm();
	int count = 0;
	for (int i = 0, j = 0; i < nrows && j < ncols; i++, j++)
	{                         //Phần tử đầu tiên khác không chỉ nằm từ vị trí trên đường chéo chính sang bên phải
		if (b.mat[i][j] != 0) count++; //Nếu phần tử trên đường chéo khác 0, cộng 1 vào kết quả
		else
		{
			i--; //Nếu phần tử trên đường chéo chính bằng 0, tiến sang phần tử bên phải để kiểm tra
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
int Matrix::leadingEntryPos(int row)
{
	for (int i = 0; i < ncols; i++)
	{
		if (mat[row][i] != 0) return i;
	}
	return ncols;
}
Matrix Matrix::multiplyMatrix(Matrix other)
{
	if (this->ncols == other.nrows) //Điều kiện để nhân hai ma trận
	{
		Matrix ans(this->nrows, other.ncols, 0);
		for (int i = 0; i < this->nrows; i++)
		{
			for (int j = 0; j < other.ncols; j++)
			{
				for (int k = 0; k < this->ncols; k++)
				{
					ans.mat[i][j] += this->mat[i][k] * other.mat[k][j];
				}
			}
		}
		return ans;
	}
	Matrix a(0, 0);
	cout << "Hai ma tran khong the nhan!" << endl;
	return a;
}
bool Matrix::isRevertible()
{
	return (this->findDeterminant() != 0);
}
Matrix Matrix::findReverse()
{
	if (this->isRevertible())
	{
		Matrix matrix = *this;
		Matrix unit(nrows, ncols);
		//int flag = 0; //flag = 1 nếu các phần tử cùng cột bên dưới mat[i][j] đều bằng 0, kể cả mat[i][j]
		for (int i = 0, j = 0; i < nrows && j < ncols; i++, j++)
		{
			if (matrix.mat[i][j] == 0) //Tìm dòng có phần tử ở cột i khác 0 để swap 2 dòng
			{
				int k = 0;
				for (k = i + 1; k < nrows; k++)
				{
					if (matrix.mat[k][j] != 0) //Đổi chỗ 2 dòng
					{
						unit.interchangeRows(i, k);
						matrix.interchangeRows(i, k);
						break;
					}
				}
				//if (k >= nrows) flag = 1;
			}
			/*if (flag == 1)
			{
				--i;
				flag = 0;
				continue;
			}*/
			unit.multiplyRow(1 / matrix.mat[i][j], i);
			matrix.multiplyRow(1 / matrix.mat[i][j], i);  //Chia dòng i cho 1/mat[i][j] để mat[i][j] = 1
			for (int h = i + 1; h < nrows; h++)  //Biến đổi các dòng bên dưới dòng i để các phần tử dưới cột j đều bằng 0
			{
				unit.addRowstoRow(-matrix.mat[h][j], i, h);
				matrix.addRowstoRow(-matrix.mat[h][j], i, h);
			}
		}
		for (int i = nrows - 1, j = ncols - 1; i >= 0 && j >= 0; i--, j--)
		{
			for (int k = i - 1; k >= 0; k--)
			{
				unit.addRowstoRow(-matrix.mat[k][j], i, k);
				matrix.addRowstoRow(-matrix.mat[k][j], i, k);  //Dòng k = -mat[k][j] * dòng i, để mat[k][j] = 0
			}
		}
		return unit;
	}
	else
	{
		cout << "Ma tran khong kha ngich!" << endl;
		return *this;
	}
}
void Matrix::solveLinearEquation()
{
	Matrix matrix;
	matrix.inputEquations();
	matrix = matrix.findReducedEchelonForm();
	double* ans = new double[matrix.ncols];
	int numSol = matrix.ncols - 2;
	for (int i = matrix.nrows - 1; i >= 0; i--)
	{
		if (matrix.isZeroRow(i))  //Nếu có 1 dòng (0, 0, 0, ..., 0) thì hệ có vô số nghiệm
		{
			cout << "Infinite soluntion." << endl;
			return;
		}
		if (matrix.leadingEntryPos(i) == (matrix.ncols - 1)) //Nếu có 1 dòng (0, 0, ..., 0, a) (a!=0) thì hệ vô nghiệm
		{
			cout << "No solution." << endl;
			return;
		}
		ans[numSol] = matrix.mat[i][matrix.ncols - 1];  //Nếu 2 trường hợp trên không xảy ra, hệ có nghiệm duy nhất
		for (int j = matrix.ncols - 2; j > numSol; j--) //x(i) = b - a(n)*x(n) - a(n-1)*x(n-1) - ... - a(i+1)*x(i+1)
		{
			ans[numSol] -= (matrix.mat[i][j] * ans[j]);
		}
		ans[numSol] /= matrix.mat[i][numSol];
		numSol--;
	}
	for (int i = 0; i <= matrix.ncols - 2; i++)
	{
		cout << "x" << i + 1 << " = " << ans[i] << endl;
	}
}

double* Matrix::operator[](int i)
{
	if (i < nrows) return mat[i];
}

Matrix::Matrix(int nrows, int ncols)
{
	this->nrows = nrows;
	this->ncols = ncols;
	this->mat = new double*[this->nrows];
	for (int i = 0; i < nrows; i++)
	{
		this->mat[i] = new double[this->ncols];
		for (int j = 0; j < ncols; j++)
		{
			if (j == i) mat[i][j] = 1;
			else mat[i][j] = 0;
		}
	}
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
		for (int j = 0; j < ncols; j++)
		{
			this->mat[i][j] = value;
		}
	}
}

Matrix::~Matrix()
{
	if (mat != NULL)
	{
		for (int i = 0; i < nrows; i++)
		{
			delete[] mat[i];
		}
		delete[] mat;
	}

}
