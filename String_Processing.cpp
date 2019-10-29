#include "String_Processing.h"

vector<string> Code_Table_B4()
{
	vector<string> CT;
	CT.resize(16);
	CT[0] = "1010";		CT[1] = "1110";		CT[2] = "0110";		CT[3] = "0010";
	CT[4] = "1011";			CT[5] = "1111";		CT[6] = "0111";			CT[7] = "0011";
	CT[8] = "1001";		CT[9] = "1101";		CT[10] = "0101";		CT[11] = "0001";
	CT[12] = "1000";		CT[13] = "1100";	CT[14] = "0100";		CT[15] = "0000";
	return CT;
}

vector<string> Split_string(string str)
{
	int n = 1;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '+')
		{
			n++;
		}
	}
	vector<string> str1;
	str1.resize(n);
	int index_x = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '+')
		{
			index_x++;
		}
		else
		{
			str1[index_x].push_back(str[i]);
		}
	}
	return str1;
}

string String_Encryption(string str)
{
	string s;
	string str1 = str;
	if (str1[0] != 'X' && str1[0] != 'x')
	{
		s.push_back(' ');
		str1.insert(0, 1, ' ');
	}
	else
	{
		if (str1[0] == 'X')
			s.push_back('1');
		else if (str1[0] == 'x')
			s.push_back('0');
	}

	if (str1[1] != 'Y' && str1[1] != 'y')
	{
		s.push_back(' ');
		str1.insert(1, 1, ' ');
	}
	else
	{
		if (str1[1] == 'Y')
			s.push_back('1');
		else if (str1[1] == 'y')
			s.push_back('0');
	}

	if (str1[2] != 'Z' && str1[2] != 'z')
	{
		s.push_back(' ');
		str1.insert(2, 1, ' ');
	}
	else
	{
		if (str1[2] == 'Z')
			s.push_back('1');
		else if (str1[2] == 'z')
			s.push_back('0');
	}

	if (str1[3] != 'T' && str1[3] != 't')
	{
		s.push_back(' ');
		str1.insert(3, 1, ' ');
	}
	else
	{
		if (str1[3] == 'T')
			s.push_back('1');
		else if (str1[3] == 't')
			s.push_back('0');
	}

	return s;
}
int String_Comparisons(string str1, string str2)
{
	int n1 = 0, n2 = 0;
	for (int i = 0; i < str1.length(); i++)
		if (str1[i] != ' ')
			n1++;
	for (int i = 0; i < str2.length(); i++)
		if (str2[i] != ' ')
			n2++;
	if (n1 == n2)
		if (str1 != str2)
			return 0;
		else
			return 1;
	if (n1 < n2)
	{
		string temp = str1;
		str1 = str2;
		str2 = temp;
	}
	for (int i = 0; i < 4; i++)
	{
		if (str2[i] != ' ' && str1[i] != str2[i])
			return 0;
	}
	return 1;
}