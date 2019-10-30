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
	Vector addVector(const Vector& other);
	Vector operator+(const Vector& other);
	Vector& operator+=(const Vector& other);
	Vector operator*(const double& alpha);
	Vector& operator*=(const double& alpha);
	Vector();
	Vector(int n);
	~Vector();
};

