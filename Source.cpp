#include "Matrix.h"
#include <iostream>
using namespace std;

void main()
{
	Matrix a;
	a.input();
	a.print();
	//cout << "Deterninant: " << a.findDeterminant() << endl;
	Matrix b = a.findLadderMatrix();
	b.print();
	//cout << "Matrix's rank: " << a.findRank() << endl;
	system("pause");
}