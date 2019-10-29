#include "Pick_Prime_Implicants.h"

int Check_Prime_Implicants(string PI, string s)
{
	PI = String_Encryption(PI);
	if (String_Comparisons(PI, s) == 1)
		return 1;
	else
		return 0;
}

vector<vector<string>> Count_Prime_Implicants(vector<string> PI, vector<string> kar)
{
	vector<vector<string>> CPI;
	CPI.resize(16);
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < PI.size(); j++)
		{
			if (kar[i] != "...." && Check_Prime_Implicants(PI[j], kar[i]) == 1)
				CPI[i].push_back(PI[j]);
		}
	}
	return CPI;
}

vector<string> New_Kar(string PI, vector<string> kar)
{
	vector<string> New_Kar;
	New_Kar.resize(16);
	for (int i = 0; i < 16; i++)
	{
		New_Kar[i] = "....";
	}
	for (int i = 0; i < kar.size(); i++)
	{
		if (Check_Prime_Implicants(PI, kar[i]) == 0)
			New_Kar[i] = kar[i];
	}
	return New_Kar;
}

string Convert_Text(string s)
{
	string s1;
	if (s[0] == '1')
		s1.push_back('X');
	else if (s[0] == '0')
		s1.push_back('x');
	if (s[1] == '1')
		s1.push_back('Y');
	else if (s[1] == '0')
		s1.push_back('y');
	if (s[2] == '1')
		s1.push_back('Z');
	else if (s[2] == '0')
		s1.push_back('z');
	if (s[3] == '1')
		s1.push_back('T');
	else if (s[3] == '0')
		s1.push_back('t');
	return s1;
}

vector < vector<string>> Minimal_Polynomial(vector<vector<string>> Count_PI, vector<string> PI, vector<string> kar)
{
	vector<vector<string>> All_MP;
	vector<string> MP1;
	for (int i = 0; i < Count_PI.size(); i++)
	{
		if (Count_PI[i].size() == 1)
		{
			if (Check_Coincidence(MP1, Count_PI[i][0]) == 0)
				MP1.push_back(Count_PI[i][0]);
			kar = New_Kar(Count_PI[i][0], kar);
		}
	}
	All_MP.push_back(MP1);
	Count_PI = Count_Prime_Implicants(PI, kar);
	for (int i = 0; i < Count_PI.size(); i++)
	{
		if (Count_PI[i].size() > 1)
		{
			for (int j = 0; j < Count_PI[i].size() - 1; j++)
			{
				All_MP.push_back(MP1);
			}
			for (int j = 0; j < Count_PI[i].size(); j++)
			{
				if (Check_Coincidence(All_MP[j], Count_PI[i][j]) == 0)
					All_MP[j].push_back(Count_PI[i][j]);
			}
			for (int j = 0; j < Count_PI[i].size() - 1; j++)
			{
				kar = New_Kar(Count_PI[i][j], kar);
			}
			Count_PI = Count_Prime_Implicants(PI, kar);
		}
		if (kar[i] != "...." && Count_PI[i].size() == 0)
		{
			for (int j = 0; j < All_MP.size(); j++)
			{
				All_MP[j].push_back(Convert_Text(kar[i]));
			}
		}
	}
	return All_MP;
}

vector<string> Recipe_Minimal_Polynomial(vector < vector<string>> MP)
{
	vector<string> RMP;
	RMP.resize(MP.size());
	for (int i = 0; i < MP.size(); i++)
	{
		for (int j = 0; j < MP[i].size(); j++)
		{
			RMP[i] += MP[i][j];
			if (j != MP[i].size() - 1)
				RMP[i] += "+";
		}
	}
	return RMP;
}