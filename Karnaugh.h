#include "String_Processing.h"

/*
So sánh bảng mã với mảng chuỗi đã được mã hóa để điền vào biểu đồ karnaugh
Nhận vào bảng mã đầy đủ (table) và các chuỗi đã được mã hóa (str)
Trả về biểu đồ karnaugh đã được điền đầy đủ
*/
vector<string> Array_Conparisons(vector<string> Table, vector<string> str);

/*
Tổng hợp các bước để tạo biểu đồ karnaugh từ 1 chuỗi s nhập vào từ bàn phím
Nhận vào chuỗi biểu thức cần rút gọn (s)
Trả về biểu đồ karnaugh
*/
vector<string> Karnaugh(string s);