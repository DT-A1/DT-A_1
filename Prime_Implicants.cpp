#include "Prime_Implicants.h"

int Check_Coincidence(vector<string> s1, string s2) //kiểm tra s2 có trong s1 chưa
{
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == s2)
			return 1;
	}
	return 0;
}

int Check_Implicants(vector<string> s1, string s2)
{
	int n = pow(2, 4 - s2.length());
	int count = 0;
	s2 = String_Encryption(s2);
	for (int i = 0; i < s1.size(); i++)
	{
		if (String_Comparisons(s1[i], s2) == 1)
			count++;
	}
	if (count == n)
		return 1;
	else
		return 0;
}

vector<string> Implicants(vector<string> s)
{
	vector<string> Implicants;

	if (Check_Implicants(s, "X") == 1)
		Implicants.push_back("X");
	else
	{
		int flat = 0;
		if (Check_Implicants(s, "XY") == 1 && Check_Coincidence(Implicants, "XY") == 0) {
			Implicants.push_back("XY");
		}
		else flat++;
		if (Check_Implicants(s, "Xy") == 1 && Check_Coincidence(Implicants, "Xy") == 0) {
			Implicants.push_back("Xy");
		}
		else flat++;
		if (Check_Implicants(s, "XZ") == 1 && Check_Coincidence(Implicants, "XZ") == 0) {
			Implicants.push_back("XZ");
		}
		else flat++;
		if (Check_Implicants(s, "Xz") == 1 && Check_Coincidence(Implicants, "Xz") == 0) {
			Implicants.push_back("Xz");
		}
		else flat++;
		if (Check_Implicants(s, "XT") == 1 && Check_Coincidence(Implicants, "XT") == 0) {
			Implicants.push_back("XT");
		}
		else flat++;
		if (Check_Implicants(s, "Xt") == 1 && Check_Coincidence(Implicants, "Xt") == 0) {
			Implicants.push_back("Xt");
		}
		else flat++;
		if (flat == 6)
		{
			if (Check_Implicants(s, "XYZ") == 1 && Check_Coincidence(Implicants, "XYZ") == 0)
				Implicants.push_back("XYZ");
			if (Check_Implicants(s, "XYz") == 1 && Check_Coincidence(Implicants, "XYz") == 0)
				Implicants.push_back("XYz");
			if (Check_Implicants(s, "XYT") == 1 && Check_Coincidence(Implicants, "XYT") == 0)
				Implicants.push_back("XYT");
			if (Check_Implicants(s, "XYt") == 1 && Check_Coincidence(Implicants, "XYt") == 0)
				Implicants.push_back("XYt");
			if (Check_Implicants(s, "XyZ") == 1 && Check_Coincidence(Implicants, "XyZ") == 0)
				Implicants.push_back("XyZ");
			if (Check_Implicants(s, "Xyz") == 1 && Check_Coincidence(Implicants, "Xyz") == 0)
				Implicants.push_back("Xyz");
			if (Check_Implicants(s, "XyT") == 1 && Check_Coincidence(Implicants, "XyT") == 0)
				Implicants.push_back("XyT");
			if (Check_Implicants(s, "Xyt") == 1 && Check_Coincidence(Implicants, "Xyt") == 0)
				Implicants.push_back("Xyt");
			if (Check_Implicants(s, "XYZ") == 1 && Check_Coincidence(Implicants, "XYZ") == 0)
				Implicants.push_back("XYZ");
			if (Check_Implicants(s, "XyZ") == 1 && Check_Coincidence(Implicants, "XyZ") == 0)
				Implicants.push_back("XyZ");
			if (Check_Implicants(s, "XZT") == 1 && Check_Coincidence(Implicants, "XZT") == 0)
				Implicants.push_back("XZT");
			if (Check_Implicants(s, "XZt") == 1 && Check_Coincidence(Implicants, "XZt") == 0)
				Implicants.push_back("XZt");
			if (Check_Implicants(s, "XYz") == 1 && Check_Coincidence(Implicants, "XYz") == 0)
				Implicants.push_back("XYz");
			if (Check_Implicants(s, "Xyz") == 1 && Check_Coincidence(Implicants, "Xyz") == 0)
				Implicants.push_back("Xyz");
			if (Check_Implicants(s, "XzT") == 1 && Check_Coincidence(Implicants, "XzT") == 0)
				Implicants.push_back("XzT");
			if (Check_Implicants(s, "Xzt") == 1 && Check_Coincidence(Implicants, "Xzt") == 0)
				Implicants.push_back("Xzt");
			if (Check_Implicants(s, "XYT") == 1 && Check_Coincidence(Implicants, "XYT") == 0)
				Implicants.push_back("XYT");
			if (Check_Implicants(s, "XyT") == 1 && Check_Coincidence(Implicants, "XyT") == 0)
				Implicants.push_back("XyT");
			if (Check_Implicants(s, "XZT") == 1 && Check_Coincidence(Implicants, "XZT") == 0)
				Implicants.push_back("XZT");
			if (Check_Implicants(s, "XzT") == 1 && Check_Coincidence(Implicants, "XzT") == 0)
				Implicants.push_back("XzT");
			if (Check_Implicants(s, "XYt") == 1 && Check_Coincidence(Implicants, "XYt") == 0)
				Implicants.push_back("XYt");
			if (Check_Implicants(s, "Xyt") == 1 && Check_Coincidence(Implicants, "Xyt") == 0)
				Implicants.push_back("Xyt");
			if (Check_Implicants(s, "XZt") == 1 && Check_Coincidence(Implicants, "XZt") == 0)
				Implicants.push_back("XZt");
			if (Check_Implicants(s, "Xzt") == 1 && Check_Coincidence(Implicants, "Xzt") == 0)
				Implicants.push_back("Xzt");
		}
	}

	if (Check_Implicants(s, "x") == 1)
		Implicants.push_back("x");
	else
	{
		int flat = 0;
		if (Check_Implicants(s, "xY") == 1 && Check_Coincidence(Implicants, "xY") == 0) {
			Implicants.push_back("xY");
		}
		else flat++;
		if (Check_Implicants(s, "xy") == 1 && Check_Coincidence(Implicants, "xy") == 0) {
			Implicants.push_back("xy");
		}  flat++;
		if (Check_Implicants(s, "xZ") == 1 && Check_Coincidence(Implicants, "xZ") == 0) {
			Implicants.push_back("xZ");
		}  flat++;
		if (Check_Implicants(s, "xz") == 1 && Check_Coincidence(Implicants, "xz") == 0) {
			Implicants.push_back("xz");
		}  flat++;
		if (Check_Implicants(s, "xT") == 1 && Check_Coincidence(Implicants, "xT") == 0) {
			Implicants.push_back("xT");
		}  flat++;
		if (Check_Implicants(s, "xt") == 1 && Check_Coincidence(Implicants, "xt") == 0) {
			Implicants.push_back("xt");
		}  flat++;
		if (flat == 6)
		{
			if (Check_Implicants(s, "xYZ") == 1 && Check_Coincidence(Implicants, "xYZ") == 0)
				Implicants.push_back("xYZ");
			if (Check_Implicants(s, "xYz") == 1 && Check_Coincidence(Implicants, "xYz") == 0)
				Implicants.push_back("xYz");
			if (Check_Implicants(s, "xYT") == 1 && Check_Coincidence(Implicants, "xYT") == 0)
				Implicants.push_back("xYT");
			if (Check_Implicants(s, "xYt") == 1 && Check_Coincidence(Implicants, "xYt") == 0)
				Implicants.push_back("xYt");
			if (Check_Implicants(s, "xyZ") == 1 && Check_Coincidence(Implicants, "xyZ") == 0)
				Implicants.push_back("xyZ");
			if (Check_Implicants(s, "xyz") == 1 && Check_Coincidence(Implicants, "xyz") == 0)
				Implicants.push_back("xyz");
			if (Check_Implicants(s, "xyT") == 1 && Check_Coincidence(Implicants, "xyT") == 0)
				Implicants.push_back("xyT");
			if (Check_Implicants(s, "xyt") == 1 && Check_Coincidence(Implicants, "xyt") == 0)
				Implicants.push_back("xyt");
			if (Check_Implicants(s, "xYZ") == 1 && Check_Coincidence(Implicants, "xYZ") == 0)
				Implicants.push_back("xYZ");
			if (Check_Implicants(s, "xyZ") == 1 && Check_Coincidence(Implicants, "xyZ") == 0)
				Implicants.push_back("xyZ");
			if (Check_Implicants(s, "xZT") == 1 && Check_Coincidence(Implicants, "xZT") == 0)
				Implicants.push_back("xZT");
			if (Check_Implicants(s, "xZt") == 1 && Check_Coincidence(Implicants, "xZt") == 0)
				Implicants.push_back("xZt");
			if (Check_Implicants(s, "xYz") == 1 && Check_Coincidence(Implicants, "xYz") == 0)
				Implicants.push_back("xYz");
			if (Check_Implicants(s, "xyz") == 1 && Check_Coincidence(Implicants, "xyz") == 0)
				Implicants.push_back("xyz");
			if (Check_Implicants(s, "xzT") == 1 && Check_Coincidence(Implicants, "xzT") == 0)
				Implicants.push_back("xzT");
			if (Check_Implicants(s, "xzt") == 1 && Check_Coincidence(Implicants, "xzt") == 0)
				Implicants.push_back("xzt");
			if (Check_Implicants(s, "xYT") == 1 && Check_Coincidence(Implicants, "xYT") == 0)
				Implicants.push_back("xYT");
			if (Check_Implicants(s, "xyT") == 1 && Check_Coincidence(Implicants, "xyT") == 0)
				Implicants.push_back("xyT");
			if (Check_Implicants(s, "xZT") == 1 && Check_Coincidence(Implicants, "xZT") == 0)
				Implicants.push_back("xZT");
			if (Check_Implicants(s, "xzT") == 1 && Check_Coincidence(Implicants, "xzT") == 0)
				Implicants.push_back("xzT");
			if (Check_Implicants(s, "xYt") == 1 && Check_Coincidence(Implicants, "xYt") == 0)
				Implicants.push_back("xYt");
			if (Check_Implicants(s, "xyt") == 1 && Check_Coincidence(Implicants, "xyt") == 0)
				Implicants.push_back("xyt");
			if (Check_Implicants(s, "xZt") == 1 && Check_Coincidence(Implicants, "xZt") == 0)
				Implicants.push_back("xZt");
			if (Check_Implicants(s, "xzt") == 1 && Check_Coincidence(Implicants, "xzt") == 0)
				Implicants.push_back("xzt");
		}
	}

	if (Check_Implicants(s, "Y") == 1)
		Implicants.push_back("Y");
	else
	{
		int flat = 0;
		if (Check_Implicants(s, "XY") == 1 && Check_Coincidence(Implicants, "XY") == 0)
		{
			Implicants.push_back("XY");
			flat = 0;
		}
		if (Check_Implicants(s, "xY") == 1 && Check_Coincidence(Implicants, "xY") == 0)
		{
			Implicants.push_back("xY");
			flat = 0;
		}
		if (Check_Implicants(s, "YZ") == 1 && Check_Coincidence(Implicants, "YZ") == 0)
		{
			Implicants.push_back("YZ");
			flat = 0;
		}
		if (Check_Implicants(s, "Yz") == 1 && Check_Coincidence(Implicants, "Yz") == 0)
		{
			Implicants.push_back("Yz");
			flat = 0;
		}
		if (Check_Implicants(s, "YT") == 1 && Check_Coincidence(Implicants, "YT") == 0)
		{
			Implicants.push_back("YT");
			flat = 0;
		}
		if (Check_Implicants(s, "Yt") == 1 && Check_Coincidence(Implicants, "Yt") == 0)
		{
			Implicants.push_back("Yt");
			flat = 0;
		}
		if (flat == 6)
		{
			if (Check_Implicants(s, "XYZ") == 1 && Check_Coincidence(Implicants, "XYZ") == 0)
				Implicants.push_back("XYZ");
			if (Check_Implicants(s, "XYz") == 1 && Check_Coincidence(Implicants, "XYz") == 0)
				Implicants.push_back("XYz");
			if (Check_Implicants(s, "XYT") == 1 && Check_Coincidence(Implicants, "XYT") == 0)
				Implicants.push_back("XYT");
			if (Check_Implicants(s, "XYt") == 1 && Check_Coincidence(Implicants, "XYt") == 0)
				Implicants.push_back("XYt");
			if (Check_Implicants(s, "xYZ") == 1 && Check_Coincidence(Implicants, "xYZ") == 0)
				Implicants.push_back("xYZ");
			if (Check_Implicants(s, "xYz") == 1 && Check_Coincidence(Implicants, "xYz") == 0)
				Implicants.push_back("xYz");
			if (Check_Implicants(s, "xYT") == 1 && Check_Coincidence(Implicants, "xYT") == 0)
				Implicants.push_back("xYT");
			if (Check_Implicants(s, "xYt") == 1 && Check_Coincidence(Implicants, "xYt") == 0)
				Implicants.push_back("xYt");
			if (Check_Implicants(s, "XYZ") == 1 && Check_Coincidence(Implicants, "XYZ") == 0)
				Implicants.push_back("XYZ");
			if (Check_Implicants(s, "xYZ") == 1 && Check_Coincidence(Implicants, "xYZ") == 0)
				Implicants.push_back("xYZ");
			if (Check_Implicants(s, "YZT") == 1 && Check_Coincidence(Implicants, "YZT") == 0)
				Implicants.push_back("YZT");
			if (Check_Implicants(s, "YZt") == 1 && Check_Coincidence(Implicants, "YZt") == 0)
				Implicants.push_back("xZt");
			if (Check_Implicants(s, "XYz") == 1 && Check_Coincidence(Implicants, "XYz") == 0)
				Implicants.push_back("XYz");
			if (Check_Implicants(s, "xYz") == 1 && Check_Coincidence(Implicants, "xYz") == 0)
				Implicants.push_back("xYz");
			if (Check_Implicants(s, "YzT") == 1 && Check_Coincidence(Implicants, "YzT") == 0)
				Implicants.push_back("YzT");
			if (Check_Implicants(s, "Yzt") == 1 && Check_Coincidence(Implicants, "Yzt") == 0)
				Implicants.push_back("xzt");
			if (Check_Implicants(s, "XYT") == 1 && Check_Coincidence(Implicants, "XYT") == 0)
				Implicants.push_back("XYT");
			if (Check_Implicants(s, "xYT") == 1 && Check_Coincidence(Implicants, "xYT") == 0)
				Implicants.push_back("xYT");
			if (Check_Implicants(s, "YZT") == 1 && Check_Coincidence(Implicants, "YZT") == 0)
				Implicants.push_back("YZT");
			if (Check_Implicants(s, "YzT") == 1 && Check_Coincidence(Implicants, "YzT") == 0)
				Implicants.push_back("YzT");
			if (Check_Implicants(s, "XYt") == 1 && Check_Coincidence(Implicants, "XYt") == 0)
				Implicants.push_back("XYt");
			if (Check_Implicants(s, "xYt") == 1 && Check_Coincidence(Implicants, "xYt") == 0)
				Implicants.push_back("xYt");
			if (Check_Implicants(s, "YZt") == 1 && Check_Coincidence(Implicants, "YZt") == 0)
				Implicants.push_back("YZt");
			if (Check_Implicants(s, "Yzt") == 1 && Check_Coincidence(Implicants, "Yzt") == 0)
				Implicants.push_back("Yzt");
		}
	}

	if (Check_Implicants(s, "y") == 1)
		Implicants.push_back("y");
	else
	{
		int flat = 0;
		if (Check_Implicants(s, "Xy") == 1 && Check_Coincidence(Implicants, "Xy") == 0) {
			Implicants.push_back("Xy");
		}
		else flat++;
		if (Check_Implicants(s, "xy") == 1 && Check_Coincidence(Implicants, "xy") == 0) {
			Implicants.push_back("xy");
		}
		else flat++;
		if (Check_Implicants(s, "yZ") == 1 && Check_Coincidence(Implicants, "yZ") == 0) {
			Implicants.push_back("yZ");
		}
		else flat++;
		if (Check_Implicants(s, "yz") == 1 && Check_Coincidence(Implicants, "yz") == 0) {
			Implicants.push_back("yz");
		}
		else flat++;
		if (Check_Implicants(s, "yT") == 1 && Check_Coincidence(Implicants, "yT") == 0) {
			Implicants.push_back("yT");
		}
		else flat++;
		if (Check_Implicants(s, "yt") == 1 && Check_Coincidence(Implicants, "yt") == 0) {
			Implicants.push_back("yt");
		}
		else flat++;
		if (flat == 6)
		{
			if (Check_Implicants(s, "XyZ") == 1 && Check_Coincidence(Implicants, "XyZ") == 0)
				Implicants.push_back("XyZ");
			if (Check_Implicants(s, "Xyz") == 1 && Check_Coincidence(Implicants, "Xyz") == 0)
				Implicants.push_back("Xyz");
			if (Check_Implicants(s, "XyT") == 1 && Check_Coincidence(Implicants, "XyT") == 0)
				Implicants.push_back("XyT");
			if (Check_Implicants(s, "Xyt") == 1 && Check_Coincidence(Implicants, "Xyt") == 0)
				Implicants.push_back("Xyt");
			if (Check_Implicants(s, "xyZ") == 1 && Check_Coincidence(Implicants, "xyZ") == 0)
				Implicants.push_back("xyZ");
			if (Check_Implicants(s, "xyz") == 1 && Check_Coincidence(Implicants, "xyz") == 0)
				Implicants.push_back("xyz");
			if (Check_Implicants(s, "xyT") == 1 && Check_Coincidence(Implicants, "xyT") == 0)
				Implicants.push_back("xyT");
			if (Check_Implicants(s, "xyt") == 1 && Check_Coincidence(Implicants, "xyt") == 0)
				Implicants.push_back("xyt");
			if (Check_Implicants(s, "XyZ") == 1 && Check_Coincidence(Implicants, "XyZ") == 0)
				Implicants.push_back("XyZ");
			if (Check_Implicants(s, "xyZ") == 1 && Check_Coincidence(Implicants, "xyZ") == 0)
				Implicants.push_back("xyZ");
			if (Check_Implicants(s, "yZT") == 1 && Check_Coincidence(Implicants, "yZT") == 0)
				Implicants.push_back("yZT");
			if (Check_Implicants(s, "yZt") == 1 && Check_Coincidence(Implicants, "yZt") == 0)
				Implicants.push_back("yZt");
			if (Check_Implicants(s, "Xyz") == 1 && Check_Coincidence(Implicants, "Xyz") == 0)
				Implicants.push_back("Xyz");
			if (Check_Implicants(s, "xyz") == 1 && Check_Coincidence(Implicants, "xyz") == 0)
				Implicants.push_back("xyz");
			if (Check_Implicants(s, "yzT") == 1 && Check_Coincidence(Implicants, "yzT") == 0)
				Implicants.push_back("yzT");
			if (Check_Implicants(s, "yzt") == 1 && Check_Coincidence(Implicants, "yzt") == 0)
				Implicants.push_back("xzt");
			if (Check_Implicants(s, "XyT") == 1 && Check_Coincidence(Implicants, "XyT") == 0)
				Implicants.push_back("XyT");
			if (Check_Implicants(s, "xyT") == 1 && Check_Coincidence(Implicants, "xyT") == 0)
				Implicants.push_back("xyT");
			if (Check_Implicants(s, "yZT") == 1 && Check_Coincidence(Implicants, "yZT") == 0)
				Implicants.push_back("yZT");
			if (Check_Implicants(s, "yzT") == 1 && Check_Coincidence(Implicants, "yzT") == 0)
				Implicants.push_back("yzT");
			if (Check_Implicants(s, "Xyt") == 1 && Check_Coincidence(Implicants, "Xyt") == 0)
				Implicants.push_back("Xyt");
			if (Check_Implicants(s, "xyt") == 1 && Check_Coincidence(Implicants, "xyt") == 0)
				Implicants.push_back("xyt");
			if (Check_Implicants(s, "yZt") == 1 && Check_Coincidence(Implicants, "yZt") == 0)
				Implicants.push_back("yZt");
			if (Check_Implicants(s, "yzt") == 1 && Check_Coincidence(Implicants, "yzt") == 0)
				Implicants.push_back("yzt");
		}
	}

	if (Check_Implicants(s, "Z") == 1)
		Implicants.push_back("Z");
	else
	{
		int flat = 0;
		if (Check_Implicants(s, "XZ") == 1 && Check_Coincidence(Implicants, "XZ") == 0) {
			Implicants.push_back("XZ");
		}
		else flat++;
		if (Check_Implicants(s, "xZ") == 1 && Check_Coincidence(Implicants, "xZ") == 0) {
			Implicants.push_back("xZ");
		}
		else flat++;
		if (Check_Implicants(s, "YZ") == 1 && Check_Coincidence(Implicants, "YZ") == 0) {
			Implicants.push_back("YZ");
		}
		else flat++;
		if (Check_Implicants(s, "yZ") == 1 && Check_Coincidence(Implicants, "yZ") == 0) {
			Implicants.push_back("yZ");
		}
		else flat++;
		if (Check_Implicants(s, "ZT") == 1 && Check_Coincidence(Implicants, "ZT") == 0) {
			Implicants.push_back("ZT");
		}
		else flat++;
		if (Check_Implicants(s, "Zt") == 1 && Check_Coincidence(Implicants, "Zt") == 0) {
			Implicants.push_back("Zt");
		}
		else flat++;
		if (flat == 6)
		{
			if (Check_Implicants(s, "XYZ") == 1 && Check_Coincidence(Implicants, "XYZ") == 0)
				Implicants.push_back("XYZ");
			if (Check_Implicants(s, "XyZ") == 1 && Check_Coincidence(Implicants, "XyZ") == 0)
				Implicants.push_back("XyZ");
			if (Check_Implicants(s, "XZT") == 1 && Check_Coincidence(Implicants, "XZT") == 0)
				Implicants.push_back("XZT");
			if (Check_Implicants(s, "XZt") == 1 && Check_Coincidence(Implicants, "XZt") == 0)
				Implicants.push_back("XZt");
			if (Check_Implicants(s, "xYZ") == 1 && Check_Coincidence(Implicants, "xYZ") == 0)
				Implicants.push_back("xYZ");
			if (Check_Implicants(s, "xyZ") == 1 && Check_Coincidence(Implicants, "xyZ") == 0)
				Implicants.push_back("xyZ");
			if (Check_Implicants(s, "xZT") == 1 && Check_Coincidence(Implicants, "xZT") == 0)
				Implicants.push_back("xZT");
			if (Check_Implicants(s, "xZt") == 1 && Check_Coincidence(Implicants, "xZt") == 0)
				Implicants.push_back("xZt");
			if (Check_Implicants(s, "XYZ") == 1 && Check_Coincidence(Implicants, "XYZ") == 0)
				Implicants.push_back("XYZ");
			if (Check_Implicants(s, "xYZ") == 1 && Check_Coincidence(Implicants, "xYZ") == 0)
				Implicants.push_back("xYZ");
			if (Check_Implicants(s, "YZT") == 1 && Check_Coincidence(Implicants, "YZT") == 0)
				Implicants.push_back("YZT");
			if (Check_Implicants(s, "YZt") == 1 && Check_Coincidence(Implicants, "YZt") == 0)
				Implicants.push_back("YZt");
			if (Check_Implicants(s, "XyZ") == 1 && Check_Coincidence(Implicants, "XyZ") == 0)
				Implicants.push_back("XyZ");
			if (Check_Implicants(s, "xyZ") == 1 && Check_Coincidence(Implicants, "xyZ") == 0)
				Implicants.push_back("xyZ");
			if (Check_Implicants(s, "yZT") == 1 && Check_Coincidence(Implicants, "yZT") == 0)
				Implicants.push_back("yZT");
			if (Check_Implicants(s, "yZt") == 1 && Check_Coincidence(Implicants, "yZt") == 0)
				Implicants.push_back("yZt");
			if (Check_Implicants(s, "XZT") == 1 && Check_Coincidence(Implicants, "XZT") == 0)
				Implicants.push_back("XZT");
			if (Check_Implicants(s, "xZT") == 1 && Check_Coincidence(Implicants, "xZT") == 0)
				Implicants.push_back("xZT");
			if (Check_Implicants(s, "YZT") == 1 && Check_Coincidence(Implicants, "YZT") == 0)
				Implicants.push_back("YZT");
			if (Check_Implicants(s, "yZT") == 1 && Check_Coincidence(Implicants, "yZT") == 0)
				Implicants.push_back("yZT");
			if (Check_Implicants(s, "XZt") == 1 && Check_Coincidence(Implicants, "XZt") == 0)
				Implicants.push_back("XZt");
			if (Check_Implicants(s, "xZt") == 1 && Check_Coincidence(Implicants, "xZt") == 0)
				Implicants.push_back("xZt");
			if (Check_Implicants(s, "YZt") == 1 && Check_Coincidence(Implicants, "YZt") == 0)
				Implicants.push_back("YZt");
			if (Check_Implicants(s, "yZt") == 1 && Check_Coincidence(Implicants, "yZt") == 0)
				Implicants.push_back("yZt");
		}
	}

	if (Check_Implicants(s, "z") == 1)
		Implicants.push_back("z");
	else
	{
		int flat = 0;
		if (Check_Implicants(s, "Xz") == 1 && Check_Coincidence(Implicants, "Xz") == 0) {
			Implicants.push_back("Xz");
		}
		else flat++;
		if (Check_Implicants(s, "xz") == 1 && Check_Coincidence(Implicants, "xz") == 0) {
			Implicants.push_back("xz");
		}
		else flat++;
		if (Check_Implicants(s, "Yz") == 1 && Check_Coincidence(Implicants, "Yz") == 0) {
			Implicants.push_back("Yz");
		}
		else flat++;
		if (Check_Implicants(s, "yz") == 1 && Check_Coincidence(Implicants, "yz") == 0) {
			Implicants.push_back("yz");
		}
		else flat++;
		if (Check_Implicants(s, "zT") == 1 && Check_Coincidence(Implicants, "zT") == 0) {
			Implicants.push_back("zT");
		}
		else flat++;
		if (Check_Implicants(s, "zt") == 1 && Check_Coincidence(Implicants, "zt") == 0) {
			Implicants.push_back("zt");
		}
		else flat++;
		if (flat == 6)
		{
			if (Check_Implicants(s, "XYz") == 1 && Check_Coincidence(Implicants, "XYz") == 0)
				Implicants.push_back("XYz");
			if (Check_Implicants(s, "Xyz") == 1 && Check_Coincidence(Implicants, "Xyz") == 0)
				Implicants.push_back("Xyz");
			if (Check_Implicants(s, "XzT") == 1 && Check_Coincidence(Implicants, "XzT") == 0)
				Implicants.push_back("XzT");
			if (Check_Implicants(s, "Xzt") == 1 && Check_Coincidence(Implicants, "Xzt") == 0)
				Implicants.push_back("Xzt");
			if (Check_Implicants(s, "xYz") == 1 && Check_Coincidence(Implicants, "xYz") == 0)
				Implicants.push_back("xYz");
			if (Check_Implicants(s, "xyz") == 1 && Check_Coincidence(Implicants, "xyz") == 0)
				Implicants.push_back("xyz");
			if (Check_Implicants(s, "xzT") == 1 && Check_Coincidence(Implicants, "xzT") == 0)
				Implicants.push_back("xzT");
			if (Check_Implicants(s, "xzt") == 1 && Check_Coincidence(Implicants, "xzt") == 0)
				Implicants.push_back("xzt");
			if (Check_Implicants(s, "XYz") == 1 && Check_Coincidence(Implicants, "XYz") == 0)
				Implicants.push_back("XYz");
			if (Check_Implicants(s, "xYz") == 1 && Check_Coincidence(Implicants, "xYz") == 0)
				Implicants.push_back("xYz");
			if (Check_Implicants(s, "YzT") == 1 && Check_Coincidence(Implicants, "YzT") == 0)
				Implicants.push_back("YzT");
			if (Check_Implicants(s, "Yzt") == 1 && Check_Coincidence(Implicants, "Yzt") == 0)
				Implicants.push_back("Yzt");
			if (Check_Implicants(s, "Xyz") == 1 && Check_Coincidence(Implicants, "Xyz") == 0)
				Implicants.push_back("Xyz");
			if (Check_Implicants(s, "xyz") == 1 && Check_Coincidence(Implicants, "xyz") == 0)
				Implicants.push_back("xyz");
			if (Check_Implicants(s, "yzT") == 1 && Check_Coincidence(Implicants, "yzT") == 0)
				Implicants.push_back("yzT");
			if (Check_Implicants(s, "yzt") == 1 && Check_Coincidence(Implicants, "yzt") == 0)
				Implicants.push_back("yzt");
			if (Check_Implicants(s, "XzT") == 1 && Check_Coincidence(Implicants, "XzT") == 0)
				Implicants.push_back("XzT");
			if (Check_Implicants(s, "xzT") == 1 && Check_Coincidence(Implicants, "xzT") == 0)
				Implicants.push_back("xzT");
			if (Check_Implicants(s, "YzT") == 1 && Check_Coincidence(Implicants, "YzT") == 0)
				Implicants.push_back("YzT");
			if (Check_Implicants(s, "yzT") == 1 && Check_Coincidence(Implicants, "yzT") == 0)
				Implicants.push_back("yzT");
			if (Check_Implicants(s, "Xzt") == 1 && Check_Coincidence(Implicants, "Xzt") == 0)
				Implicants.push_back("Xzt");
			if (Check_Implicants(s, "xzt") == 1 && Check_Coincidence(Implicants, "xzt") == 0)
				Implicants.push_back("xzt");
			if (Check_Implicants(s, "Yzt") == 1 && Check_Coincidence(Implicants, "Yzt") == 0)
				Implicants.push_back("Yzt");
			if (Check_Implicants(s, "yzt") == 1 && Check_Coincidence(Implicants, "yzt") == 0)
				Implicants.push_back("yzt");
		}
	}

	if (Check_Implicants(s, "T") == 1)
		Implicants.push_back("T");
	else
	{
		int flat = 0;
		if (Check_Implicants(s, "XT") == 1 && Check_Coincidence(Implicants, "XT") == 0) {
			Implicants.push_back("XT");
		}
		else flat++;
		if (Check_Implicants(s, "xT") == 1 && Check_Coincidence(Implicants, "xT") == 0) {
			Implicants.push_back("xT");
		}
		else flat++;
		if (Check_Implicants(s, "YT") == 1 && Check_Coincidence(Implicants, "YT") == 0) {
			Implicants.push_back("YT");
		}
		else flat++;
		if (Check_Implicants(s, "yT") == 1 && Check_Coincidence(Implicants, "yT") == 0) {
			Implicants.push_back("yT");
		}
		else flat++;
		if (Check_Implicants(s, "ZT") == 1 && Check_Coincidence(Implicants, "ZT") == 0) {
			Implicants.push_back("ZT");
		}
		else flat++;
		if (Check_Implicants(s, "zT") == 1 && Check_Coincidence(Implicants, "zT") == 0) {
			Implicants.push_back("zT");
		}
		else flat++;
		if (flat == 6)
		{
			if (Check_Implicants(s, "XYT") == 1 && Check_Coincidence(Implicants, "XYT") == 0)
				Implicants.push_back("XYT");
			if (Check_Implicants(s, "XyT") == 1 && Check_Coincidence(Implicants, "XyT") == 0)
				Implicants.push_back("XyT");
			if (Check_Implicants(s, "XZT") == 1 && Check_Coincidence(Implicants, "XZT") == 0)
				Implicants.push_back("XZT");
			if (Check_Implicants(s, "XzT") == 1 && Check_Coincidence(Implicants, "XzT") == 0)
				Implicants.push_back("XzT");
			if (Check_Implicants(s, "xYT") == 1 && Check_Coincidence(Implicants, "xYT") == 0)
				Implicants.push_back("xYT");
			if (Check_Implicants(s, "xyT") == 1 && Check_Coincidence(Implicants, "xyT") == 0)
				Implicants.push_back("xyT");
			if (Check_Implicants(s, "xZT") == 1 && Check_Coincidence(Implicants, "xZT") == 0)
				Implicants.push_back("xZT");
			if (Check_Implicants(s, "xzT") == 1 && Check_Coincidence(Implicants, "xzT") == 0)
				Implicants.push_back("xzT");
			if (Check_Implicants(s, "XYT") == 1 && Check_Coincidence(Implicants, "XYT") == 0)
				Implicants.push_back("XYT");
			if (Check_Implicants(s, "xYT") == 1 && Check_Coincidence(Implicants, "xYT") == 0)
				Implicants.push_back("xYT");
			if (Check_Implicants(s, "YZT") == 1 && Check_Coincidence(Implicants, "YZT") == 0)
				Implicants.push_back("YZT");
			if (Check_Implicants(s, "YzT") == 1 && Check_Coincidence(Implicants, "YzT") == 0)
				Implicants.push_back("YzT");
			if (Check_Implicants(s, "XyT") == 1 && Check_Coincidence(Implicants, "XyT") == 0)
				Implicants.push_back("XyT");
			if (Check_Implicants(s, "xyT") == 1 && Check_Coincidence(Implicants, "xyT") == 0)
				Implicants.push_back("xyT");
			if (Check_Implicants(s, "yZT") == 1 && Check_Coincidence(Implicants, "yZT") == 0)
				Implicants.push_back("yZT");
			if (Check_Implicants(s, "yzT") == 1 && Check_Coincidence(Implicants, "yzT") == 0)
				Implicants.push_back("yzT");
			if (Check_Implicants(s, "XZT") == 1 && Check_Coincidence(Implicants, "XZT") == 0)
				Implicants.push_back("XZT");
			if (Check_Implicants(s, "xZT") == 1 && Check_Coincidence(Implicants, "xZT") == 0)
				Implicants.push_back("xZT");
			if (Check_Implicants(s, "YZT") == 1 && Check_Coincidence(Implicants, "YZT") == 0)
				Implicants.push_back("YZT");
			if (Check_Implicants(s, "yZT") == 1 && Check_Coincidence(Implicants, "yZT") == 0)
				Implicants.push_back("yZT");
			if (Check_Implicants(s, "XzT") == 1 && Check_Coincidence(Implicants, "XzT") == 0)
				Implicants.push_back("XzT");
			if (Check_Implicants(s, "xzT") == 1 && Check_Coincidence(Implicants, "xzT") == 0)
				Implicants.push_back("xzT");
			if (Check_Implicants(s, "YzT") == 1 && Check_Coincidence(Implicants, "YzT") == 0)
				Implicants.push_back("YzT");
			if (Check_Implicants(s, "yzT") == 1 && Check_Coincidence(Implicants, "yzT") == 0)
				Implicants.push_back("yzT");
		}
	}

	if (Check_Implicants(s, "t") == 1)
		Implicants.push_back("t");
	else
	{
		int flat = 0;
		if (Check_Implicants(s, "Xt") == 1 && Check_Coincidence(Implicants, "Xt") == 0) {
			Implicants.push_back("Xt");
		}
		else flat++;
		if (Check_Implicants(s, "xt") == 1 && Check_Coincidence(Implicants, "xt") == 0) {
			Implicants.push_back("xt");
		}
		else flat++;
		if (Check_Implicants(s, "Yt") == 1 && Check_Coincidence(Implicants, "Yt") == 0) {
			Implicants.push_back("Yt");
		}
		else flat++;
		if (Check_Implicants(s, "yt") == 1 && Check_Coincidence(Implicants, "yt") == 0) {
			Implicants.push_back("yt");
		}
		else flat++;
		if (Check_Implicants(s, "Zt") == 1 && Check_Coincidence(Implicants, "Zt") == 0) {
			Implicants.push_back("Zt");
		}
		else flat++;
		if (Check_Implicants(s, "zt") == 1 && Check_Coincidence(Implicants, "zt") == 0) {
			Implicants.push_back("zt");
		}
		else flat++;
		if (flat == 6)
		{
			if (Check_Implicants(s, "XYt") == 1 && Check_Coincidence(Implicants, "XYt") == 0)
				Implicants.push_back("XYt");
			if (Check_Implicants(s, "Xyt") == 1 && Check_Coincidence(Implicants, "Xyt") == 0)
				Implicants.push_back("Xyt");
			if (Check_Implicants(s, "XZt") == 1 && Check_Coincidence(Implicants, "XZt") == 0)
				Implicants.push_back("XZt");
			if (Check_Implicants(s, "Xzt") == 1 && Check_Coincidence(Implicants, "Xzt") == 0)
				Implicants.push_back("Xzt");
			if (Check_Implicants(s, "xYt") == 1 && Check_Coincidence(Implicants, "xYt") == 0)
				Implicants.push_back("xYt");
			if (Check_Implicants(s, "xyt") == 1 && Check_Coincidence(Implicants, "xyt") == 0)
				Implicants.push_back("xyt");
			if (Check_Implicants(s, "xZt") == 1 && Check_Coincidence(Implicants, "xZt") == 0)
				Implicants.push_back("xZt");
			if (Check_Implicants(s, "xzt") == 1 && Check_Coincidence(Implicants, "xzt") == 0)
				Implicants.push_back("xzt");
			if (Check_Implicants(s, "XYt") == 1 && Check_Coincidence(Implicants, "XYt") == 0)
				Implicants.push_back("XYt");
			if (Check_Implicants(s, "xYt") == 1 && Check_Coincidence(Implicants, "xYt") == 0)
				Implicants.push_back("xYt");
			if (Check_Implicants(s, "YZt") == 1 && Check_Coincidence(Implicants, "YZt") == 0)
				Implicants.push_back("YZt");
			if (Check_Implicants(s, "Yzt") == 1 && Check_Coincidence(Implicants, "Yzt") == 0)
				Implicants.push_back("Yzt");
			if (Check_Implicants(s, "Xyt") == 1 && Check_Coincidence(Implicants, "Xyt") == 0)
				Implicants.push_back("Xyt");
			if (Check_Implicants(s, "xyt") == 1 && Check_Coincidence(Implicants, "xyt") == 0)
				Implicants.push_back("xyt");
			if (Check_Implicants(s, "yZt") == 1 && Check_Coincidence(Implicants, "yZt") == 0)
				Implicants.push_back("yZt");
			if (Check_Implicants(s, "yzt") == 1 && Check_Coincidence(Implicants, "yzt") == 0)
				Implicants.push_back("yzt");
			if (Check_Implicants(s, "XZt") == 1 && Check_Coincidence(Implicants, "XZt") == 0)
				Implicants.push_back("XZt");
			if (Check_Implicants(s, "xZt") == 1 && Check_Coincidence(Implicants, "xZt") == 0)
				Implicants.push_back("xZt");
			if (Check_Implicants(s, "YZt") == 1 && Check_Coincidence(Implicants, "YZt") == 0)
				Implicants.push_back("YZt");
			if (Check_Implicants(s, "yZt") == 1 && Check_Coincidence(Implicants, "yZt") == 0)
				Implicants.push_back("yZt");
			if (Check_Implicants(s, "Xzt") == 1 && Check_Coincidence(Implicants, "Xzt") == 0)
				Implicants.push_back("Xzt");
			if (Check_Implicants(s, "xzt") == 1 && Check_Coincidence(Implicants, "xzt") == 0)
				Implicants.push_back("xzt");
			if (Check_Implicants(s, "Yzt") == 1 && Check_Coincidence(Implicants, "Yzt") == 0)
				Implicants.push_back("Yzt");
			if (Check_Implicants(s, "yzt") == 1 && Check_Coincidence(Implicants, "yzt") == 0)
				Implicants.push_back("yzt");
		}
	}

	return Implicants;
}

string Find_Child(string s1, string s2) //tìm chuỗi con
{
	int n1 = s1.length(), n2 = s2.length();
	string s01 = String_Encryption(s1);
	string s02 = String_Encryption(s2);
	if (String_Comparisons(s01, s02) == 1)
	{
		if (n1 > n2)
			return s2;
		else
			return s1;
	}
	else
		return "0";
}

vector<string> Sort_Implicants(vector<string> Implicants)
{
	for (int i = 0; i < Implicants.size(); i++)
	{
		for (int j = i + 1; j < Implicants.size(); j++)
		{
			if (Implicants[i].length() > Implicants[j].length())
			{
				string temp = Implicants[i];
				Implicants[i] = Implicants[j];
				Implicants[j] = temp;
			}
		}
	}
	return Implicants;
}

vector<string> Erase(vector<string> s, int k)
{
	for (int i = k; i < s.size() - 1; i++)
	{
		s[i] = s[i + 1];
	}
	s.pop_back();
	return s;
}

vector<string> Prime_Implicants(vector<string> Implicants)
{
	Implicants = Sort_Implicants(Implicants);
	for (int i = 0; i < Implicants.size(); i++)
	{
		int j = 0;
		while (j < Implicants.size())
		{
			string temp = Find_Child(Implicants[i], Implicants[j]);
			if (temp != "0" && Implicants[i].length() < Implicants[j].length())
			{
				Implicants = Erase(Implicants, j);
			}
			else
				j++;
		}

	}
	return Implicants;
}