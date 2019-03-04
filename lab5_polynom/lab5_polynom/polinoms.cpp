#include <iostream>
#include "Tmonom.h"
using namespace std;

void Input(int A[][2], int size)
{
	int i; int x, y, z; double coef;
	for (i = 0; i < size; i++)
	{
		cout << "¬ведите степень x" << endl;
		cin >> x;
		cout << "¬ведите степень y" << endl;
		cin >> y;
		cout << "¬ведите степень z" << endl;
		cin >> z;
		cout << "¬ведите коэффициент при мономе" << endl;
		cin >> coef;
		A[i][0] = coef;
		A[i][1] = x * 100 + y * 10 + z;
	}
}

int main()
{
	setlocale(LC_ALL, "russian");
	int i, size;
	int A[100][2];
	int massiv[][2] = { {-5,101},{3,54},{2,9},{13,8},{12,3},{13,1} };
	int massiv1[][2] = { {5,101},{4,13},{-2,9} };
	TPolinom polin(massiv, 6), polin1(massiv1, 3);
	polin1 -= polin * 2;
	polin1.Print();
	//---------------------------------------------------------------------------
	cout << "¬ведите количество мономов" << endl;
	cin >> size;
	Input(A, size);
	TPolinom polinomstr(A, size);
	polinomstr.Print();
	system("pause");
	return 0;
}

