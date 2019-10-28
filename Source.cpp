#include "Matrix.h"
#include "Vector.h"
#include <iostream>
using namespace std;

void main()
{
	Matrix a;
	a.input();
	a.print();

	//cout << "Echelon form: " << endl;
	//Matrix b = a.findReducedEchelonForm();
	//b.print();
	//cout << "Matrix's rank: " << a.findRank() << endl;
	//cout << "Deterninant: " << a.findDeterminant() << endl;
	//cout << "Reverse: " << endl;
	//a.findReverse().print();

	/*Matrix b;
	b.input();
	b.print();

	Matrix c;
	c.input();
	c.print();
	
	cout << endl;
	a.multiplyMatrix(b).print();
	b.multiplyMatrix(a).print();
	a.multiplyMatrix(c).print();
	c.multiplyMatrix(a).print();
	b.multiplyMatrix(c).print();
	c.multiplyMatrix(b).print();*/

	//Matrix::solveLinearEquation(a);
	/*Vector v1;
	v1.input();
	v1.print();*/

	system("pause");

}