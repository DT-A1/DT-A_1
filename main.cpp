#include "General.h"
#include "Vector.h"
#include "Matrix.h"
#include <iomanip>

void Menu_Program(int& i)
{
	cout << "-------------------------------------------------------" << endl;
	cout << "\tChon mot so de thuc hien yeu cau:                    " << endl;
	cout << "\t0: Thoat khoi chuong trinh                                " << endl;
	cout << "\t1: Ham bool                                                         " << endl;
	cout << "\t2: Vector                                                              " << endl;
	cout << "\t3: Ma tran                                                            " << endl;
	cout << "\t4: Thong tin sinh vien                                         " << endl << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "\tSo de thuc hien yeu cau chuong trinh la: "; cin >> i;
}
int main()
{
	int i;
	cout << "\tDO AN MON CAU TRUC DU LIEU VA GIAI THUAT" << endl << endl;
	Menu_Program(i);
	while (i != 0)
	{
		if (i == 1)
		{
			cout << "\n\tTim tat ca cac cong thuc da thuc toi tieu cua ham bool:\n\n";
			General();
		}
		if (i == 2)
		{
			cout << "\nCac phep toan tren vector:\n\n";
			int n_vec;
			cout << "\tChon mot so de thuc hien yeu cau:" << endl;
			cout << "\t0: Tro ve menu chinh" << endl;
			cout << "\t1: Cong 2 vector" << endl;
			cout << "\t2: Nhan vector voi 1 so alpha" << endl;
			cout << "\tSo de thuc hien yeu cau tren vector la: ";
			cin >> n_vec;
			while (n_vec != 0)
			{
				if (n_vec == 1)
				{
					cout << "\n\tCong 2 vector:" << endl;
					Vector v1, v2, v3;
					cout << "\nNhap thong tin cua vector thu nhat:\n";
					v1.input();
					cout << "\nNhap thong tin cua vector thu hai:\n";
					v2.input();
					cout << "\nTong cua 2 vector la: ";
					v1 += v2;
					v1.print();
					//v3.print();
				}
				if (n_vec == 2)
				{
					cout << "\n\tNhan vector voi 1 so alpha:" << endl;
					Vector v;
					cout << "\nNhap thong tin cua vector:\n";
					v.input();
					double alpha;
					cout << "Nhap vao so alpha: ";
					cin >> alpha;
					cout << "\nTich cua vector voi so alpha la: ";
					Vector vt = v*alpha;
					vt.print();
				}
				cout << "-------------------------------------------------------" << endl;
				cout << "\tSo de thuc hien yeu cau tren vector la: ";
				cin >> n_vec;
			}
		}
		if (i == 3)
		{
			cout << "\nCac phep toan tren ma tran:\n\n";
			int n_matrix;
			cout << "\tChon mot so de thuc hien yeu cau:" << endl;
			cout << "\t0: Tro ve menu chinh" << endl;
			cout << "\t1: Tim dinh thuc" << endl;
			cout << "\t2: Nghich dao ma tran" << endl;
			cout << "\t3: Tich 2 ma tran" << endl;
			cout << "\t4: Tim hang cua ma tran" << endl;
			cout << "\t5: He phuong trinh tuyen tinh" << endl;
			cout << "\tSo de thuc hien yeu cau tren ma tran la: "; cin >> n_matrix;
			while (n_matrix != 0)
			{
				if (n_matrix == 1)
				{
					cout << "\n\tTinh dinh thuc cua ma tran: " << endl;
					Matrix m;
					cout << "\nNhap vao ma tran:\n";
					m.input();
					cout << "Dinh thuc cua ma tran la: " << m.findDeterminant() << endl;
				}
				if (n_matrix == 2)
				{
					cout << "\n\tTim ma tran nghich dao: " << endl;
					Matrix m;
					cout << "\nNhap vao ma tran:\n";
					m.input();
					cout << "\nMa tran nghich dao la:\n";
					m.findReverse().print();
				}
				if (n_matrix == 3)
				{
					cout << "\n\tTinh tich hai ma tran: " << endl;
					Matrix m1, m2;
					cout << "\nNhap vao ma tran thu nhat:" << endl;
					m1.input();
					cout << "\nNhap vao ma tran thu hai:" << endl;
					m2.input();
					cout << "\nTich 2 ma tran la: \n";
					m1.multiplyMatrix(m2).print();
				}
				if (n_matrix == 4)
				{
					cout << "\n\tTim hang cua ma tran: " << endl;
					Matrix m;
					cout << "\nNhap vao ma tran:" << endl;
					m.input(); 
					cout << "\nHang cua ma tran: " << m.findRank() << endl;
				}
				if (n_matrix == 5)
				{
					cout << "\n\tGiai he phuong trinh tuyen tinh:" << endl;
					Matrix::solveLinearEquation();
				}
				
				cout << "-------------------------------------------------------" << endl;
				cout << "\tSo de thuc hien yeu cau tren ma tran la: "; cin >> n_matrix;
			}
		}
		if (i == 4)
		{
			cout << "\nThanh vien:" << endl;
			cout << "Ho Hoang Viet Tien - MSSV: 18120689" << endl;
			cout << "Nguyen Hoang Trung - MSSV: 18120623" << endl;
		}
		Menu_Program(i);
	}
	system("pause");
	return 0;
}