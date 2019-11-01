#pragma once
#include <iostream>
using namespace std;
class Vector
{
	double* vec;
	int length;
public:
	int Length();
	void input();
	void print();
	Vector operator+(const Vector& other); //Cộng hai vector
	Vector& operator+=(const Vector& other);
	Vector operator*(const double& alpha); //Nhân vector với một số alpha
	Vector& operator*=(const double& alpha);
	Vector& operator=(const Vector& v);
	Vector();
	Vector(int n);
	Vector(const Vector& v);
	~Vector();
};

