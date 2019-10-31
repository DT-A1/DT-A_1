#include "Vector.h"
#include <iomanip>
int Vector::Length()
{
	return length;
}
void Vector::input()
{
	cout << "Nhap chieu dai vector : ";
	cin >> length;
	vec = new double[length];
	for (int i = 0; i < length; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> vec[i];
	}
}
void Vector::print()
{
	for (int i = 0; i < length; i++)
	{
		cout << vec[i] << "\t";
	}
	cout << endl;
}

Vector Vector::addVector(const Vector& other)
{
	if (other.length != this->length)
	{
		Vector v(0);
		cout << "\nDo dai 2 vector khac nhau nen khong the cong\n";
		return v;
	}
	Vector ans;
	for (int i = 0; i < length; i++)
	{
		ans.vec[i] = this->vec[i] + other.vec[i];
	}
	return ans;
}
Vector Vector::operator+(const Vector& other)
{
	if (other.length != this->length)
	{
		Vector v(0);
		cout << "\nDo dai 2 vector khac nhau nen khong the cong\n";
		return v;
	}
	Vector ans(length);
	for (int i = 0; i < length; i++)
	{
		ans.vec[i] = this->vec[i] + other.vec[i];
	}
	return ans;
}
Vector& Vector::operator+=(const Vector& other)
{
	if (other.length != this->length)
	{
		Vector v(0);
		cout << "\nDo dai 2 vector khac nhau nen khong the cong\n";
		return v;
	}
	for (int i = 0; i < length; i++)
	{
		this->vec[i] += other.vec[i];
	}

	return *this;
}
Vector Vector::operator*(const double& alpha)
{
	Vector ans(length);
	for (int i = 0; i < length; i++)
	{
		ans.vec[i] = this->vec[i] * alpha;
	}

	return ans;
}
Vector& Vector::operator*=(const double& alpha)
{
	for (int i = 0; i < length; i++)
	{
		this->vec[i] *= alpha;
	}

	return *this;
}
Vector& Vector::operator=(const Vector& v)
{
	if (this->vec != NULL) delete[] this->vec;
	this->length = v.length;
	this->vec = new double[this->length];
	for (int i = 0; i < this->length; i++)
	{
		this->vec[i] = v.vec[i];
	}
	return *this;
}

Vector::Vector()
{
	length = 1;
	vec = new double[length];
}
Vector::Vector(int n)
{
	length = n;
	vec = new double[length];
}
Vector::Vector(const Vector& v)
{
	this->length = v.length;
	this->vec = new double[this->length];
	for (int i = 0; i < this->length; i++)
	{
		this->vec[i] = v.vec[i];
	}
}

Vector::~Vector()
{
	if (vec != NULL)
		delete[] vec;
}
