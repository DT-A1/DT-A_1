#include "Karnaugh.h"

/*
Kiểm tra mảng s1 đã chứa chuỗi s2 chưa
Nhận vào 2 chuỗi s1 và s2
Trả về 1 nếu đã chứa, 0 nếu chưa
*/
int Check_Coincidence(vector<string> s1, string s2); 

/*
Kiểm tra s2 có phải tế bào của s1 không
Nhận vào biểu đồ karnaugh s1, và tế bào s2
Trả về 1 nếu chứa, 0 nếu không
*/
int Check_Implicants(vector<string> s1, string s2); 

/*
Chọn ra tất cả các tế bào có thể có trong mảng s (s ở đây là biểu đồ karnaugh)
Trả về mảng các tế bào có trong biểu đồ karnaugh s
*/
vector <string> Implicants(vector<string> s);

/*
Kiểm tra chuỗi s1 có chứa s2 hay không hoặc	s2 có chứa s1 hay không
Nhận vào 2 chuỗi thuộc tế bào (s1 và s2)
Nếu chứa thì trả về chuỗi con, nếu không thì trả về "0"
*/
string Find_Child(string s1, string s2); 

/*
Sắp xếp lại các tế bào đã chọn theo thứ tự số lượng ký tự tăng dần
Nhận vào mảng các tế bào (Implicants)
Trả về mảng các tế bào đã được sắp xếp
*/
vector<string> Sort_Implicants(vector<string> Implicants);

/*
Xóa phần tử thứ k
Nhận vào 1 mảng tế bào đã được sắp xếp (s) và vị trí k
Trả về mảng s đã xóa phần tử thứ k
*/
vector<string> Erase(vector<string> s, int k);

/*
Lọc ra các tế bào lớn từ tất cả các tế bào
Nhận vào mảng các tế bào (Implicants)
Trả về mảng các tế bào lớn
*/
vector<string> Prime_Implicants(vector<string> Implicants);