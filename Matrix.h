#pragma once
class Matrix
{
	double** mat;
	int nrows;
	int ncols;
public:
	void input();
	void print(); //In ra ma tran
	void interchangeRows(int row1, int row2); //Doi thu tu 2 dong
	void addRowstoRow(double k, int row1, int row2);  //row2  = row2 + k*row1
	void multiplyRow(double k, int row); //row = k*row
	Matrix findLadderMatrix(); //Tim ma tran bac thang
	double findDeterminant(); //Tim dinh thuc cua ma tran
	Matrix cutRownCol(int row, int col); //Tra ve ma tran da bo di dong row, cot col
	int findRank(); //Tìm hạng của ma trận
	bool isZeroRow(int row); //Kiểm tra dòng row có phải dòng không hay không

	Matrix();
	Matrix(int nrows, int ncols, int value);
	Matrix(const Matrix& matrix);
	~Matrix();
};

