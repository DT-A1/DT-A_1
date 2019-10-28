#pragma once
class Matrix
{
private:
	double** mat;
	int nrows;
	int ncols;
public:
	void input(); //Nhập ma trận
	void inputEquations(); //Nhập hệ phương trình tuyến tính ở dạng ma trận hóa
	void print(); //In ra ma tran
	void interchangeRows(int row1, int row2); //Doi thu tu 2 dong
	void addRowstoRow(double k, int row1, int row2);  //row2  = row2 + k*row1
	void multiplyRow(double k, int row); //row = k*row
	Matrix findEchelonForm(); //Tim ma tran bac thang
	Matrix findReducedEchelonForm(); //Tìm ma trận bậc thang rút gọn
	double findDeterminant(); //Tim dinh thuc cua ma tran
	Matrix submatrix(int row, int col); //Tra ve ma tran da bo di dong row, cot col
	int findRank(); //Tìm hạng của ma trận
	Matrix multiplyMatrix(Matrix other); //Nhân với ma trận khác
	bool isRevertible(); //Kiểm tra tính khả nghịch
	Matrix findReverse(); //Tìm ma trận khả nghịch
	static void solveLinearEquation(Matrix a);
	double* operator[](int i);
private:
	bool isZeroRow(int row); //Kiểm tra dòng row có phải dòng không hay không
	int leadingEntryPos(int row); //Vị trí của phần tử khác 0 đầu tiên của dòng

public:
	Matrix();
	Matrix(int nrows, int ncols, int value);
	Matrix(int nrows, int ncols);
	Matrix(const Matrix& matrix);
	~Matrix();
};

