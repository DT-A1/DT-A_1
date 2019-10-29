#include "Genaral.h"

void Genaral()
{
	string str;
	cout << "Nhap vao bieu thuc (4 bien xyzt, khang dinh viet hoa, phu dinh viet thuong, cach nhau boi dau + ):\n";
	cin >> str; 
	vector<string>kar = Karnaugh(str);
	cout << "Bieu do Karnaugh: \n\n";
	for (int i = 0; i < kar.size(); i++)
	{
		cout << kar[i] << "\t";
		if (i % 4 == 3)
			cout << endl << endl;
	}
	vector<string> I = Implicants(kar);
	vector<string> PI = Prime_Implicants(I);
	cout << "Cac te bao lon: \n";

	for (int i = 0; i < PI.size(); i++)
	{
		cout << PI[i] << "\t";
	}
	cout << "\nCac da thuc toi tieu: \n";
	vector<vector<string>> CPI = Count_Prime_Implicants(PI, kar);
	vector < vector<string>> MP = Minimal_Polynomial(CPI, PI, kar);
	vector<string> RMP;
	vector<string> Table = Code_Table_B4();
	if(kar == Table)
	{
		RMP.push_back("1");
	}
	else
		RMP = Recipe_Minimal_Polynomial(MP);
	for (int i = 0; i < RMP.size(); i++)
	{
		cout << RMP[i] << endl;
	}
	cout << endl;
}