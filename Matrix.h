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
	void print(); //In ra ma trận
	void interchangeRows(int row1, int row2); //Đổi vị trí 2 dòng nhận vào
	void addRowstoRow(double k, int row1, int row2);  //row2  = row2 + k*row1
	void multiplyRow(double k, int row); //row = k*row
	Matrix findEchelonForm(); //Tìm ma trận bậc thang
	Matrix findReducedEchelonForm(); //Tìm ma trận bậc thang rút gọn
	double findDeterminant(); //Tìm định thức của ma trận
	//Matrix submatrix(int row, int col); //Trả về ma trận đã bỏ đi dòng và cột nhận vào
	int findRank(); //Tìm hạng của ma trận
	Matrix multiplyMatrix(Matrix other); //Nhân với ma trận khác
	bool isRevertible(); //Kiểm tra tính khả nghịch
	Matrix findReverse(); //Tìm ma trận khả nghịch
	static void solveLinearEquation();
	double* operator[](int i);
	Matrix& operator=(const Matrix& matrix);
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

