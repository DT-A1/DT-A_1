#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

/*
Hàm tạo bảng mã B4 (hàm bool 4 biến)
Bảng mã gồm các mã như: 0000, 1111,...
*/
vector<string> Code_Table_B4(); 

/* 
Tách chuỗi nhập vào thành mảng các chuỗi con (gồm 4 biến)
Chuỗi nhập vào sẽ được tách thành các chuỗi con, các chuỗi con cách nhau bởi dấu +
vd: XY+xy -> {"XY","xy"}
Nhận vào chuỗi công thức nhập từ bàn phím (str)
Trả về mảng các chuỗi đơn thức đã tách
*/
vector<string> Split_string(string str); 

/* 
Mã hóa chuỗi từ ký tự nhập vào thành mã
vd: "XY" = "11  ", "xyZt" = "0010"
Nhận vào các đơn thức (str)
Trả về mã của các đơn thức
*/
string String_Encryption(string str); 

/*
So sánh 2 chuỗi đã được mã hóa
khác: khi 2 phần tử tại 1 vị trí của 2 chuỗi khác " " và khác nhau
Nhận vào 2 đơn thức str1 và str2
Trả về 0 nếu khác, 1 nếu bằng
*/
int String_Comparisons(string str1, string str2);
