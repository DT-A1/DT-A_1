#include "Matrix.h"
#include "Vector.h"
#include <iostream>
#include <ctime>
using namespace std;

void main()
{
	//Matrix a;
	//a.inputEquations();
	//a.input();
	//a.print();
	//cout << "Echelon form: " << endl;
	///Matrix b = a.findReducedEchelonForm();
	//b.print();
	//cout << "Matrix's rank: " << a.findRank() << endl;
	//cout << "Deterninant: " << a.findDeterminant() << endl;
	//cout << "Reverse: " << endl;
	//a.findReverse().print();

	//Matrix b;
	//b.input();
	//b.print();

	//Matrix c;
	//c.input();
	//c.print();
	//
	//cout << endl;
	//a.multiplyMatrix(b).print();
	//b.multiplyMatrix(a).print();
	//a.multiplyMatrix(c).print();
	//c.multiplyMatrix(a).print();
	//b.multiplyMatrix(c).print();
	//c.multiplyMatrix(b).print();

	//Matrix::solveLinearEquation(a);
	Vector v1, v2;
	v1.input();
	v1.print();
	v2.input();
	v2.print();

	Vector v3 = v1 + v2;
	v3.print();

	system("pause");
}