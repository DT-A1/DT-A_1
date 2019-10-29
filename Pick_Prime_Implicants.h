#include "Prime_Implicants.h"

/*
Kiểm tra tế bào lớn PI có chứa ô có mã là s hay không
Nhận vào tế bào lớn (PI) có dạng là (x | xZ | yzT | ...) và ô đã được mã hóa trong biểu đồ karnaugh
Trả về 1 nếu có, 0 nếu không
*/
int Check_Prime_Implicants(string PI, string s);

/*
Điền các tế bào lớn vào từng ô, mỗi ô có thể không có tế bào lớn nào đi qua hoặc nhiều tế bào lớn đi qua
Nhận vào mảng các tế bào lớn (PI) và biểu đồ karnaugh (kar)
Trả về mảng các tế bào lớn đi qua trong từng ô
*/
vector < vector<string>> Count_Prime_Implicants(vector<string> PI, vector<string> kar);

/*
Chuyển chuỗi mã s thành chuỗi các ký tự x,y,z,t
Nhận vào chuỗi s là các đơn thức tối tiểu
Trả về đơn thức dạng xyzt
*/
string Convert_Text(string s);

/*
Chọn ra các đơn thức tối tiểu
Nhận vào mảng các tế bào lớn trong từng ô (Count PI), mảng các tế bào lớn (PI), biểu đồ karnaugh(kar)
Trả về mảng các đơn thức đa thức tối tiểu
*/
vector < vector<string>> Minimal_Polynomial(vector<vector<string>> Count_PI, vector<string> PI, vector<string> kar);

/*
Viết các đơn thức tối tiểu thành dạng công thức đa thức tối tiểu
Nhận vào mảng các đơn thức đa thức tối tiểu (MP)
Trả về mảng các chuỗi công thức đa thức tối tiểu
*/
vector<string> Recipe_Minimal_Polynomial(vector < vector<string>> MP);
