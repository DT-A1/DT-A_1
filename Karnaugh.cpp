#include "Karnaugh.h"

vector<string> Array_Conparisons(vector<string> Table, vector<string> str)
{
	vector<string> Arr;
	Arr.resize(16);
	for (int i = 0; i < 16; i++)
	{
		Arr[i] = "....";
	}

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < str.size(); j++)
		{
			if (String_Comparisons(Table[i], str[j]) == 1)
				Arr[i] = Table[i];
		}
	}
	return Arr;
}

vector < string> Karnaugh(string s)
{

	vector<string> s1 = Split_string(s);
	for (int i = 0; i < s1.size(); i++)
	{
		s1[i] = String_Encryption(s1[i]);
	}
	vector<string> Table = Code_Table_B4();
	vector<string> Table_Comparisons = Array_Conparisons(Table, s1);
	return Table_Comparisons;
}