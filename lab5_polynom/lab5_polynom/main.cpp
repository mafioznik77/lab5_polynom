#include <iostream>
#include "TList.h"
#include "Tmonom.h"
#include "TPolinom.h"
#include <locale>


using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int r, m;
	TPolinom p, q, copy;
	cout << "===ÏÅÐÂÛÉ ÏÎËÈÍÎÌ===" << endl;
	cin >> p;
	system("cls");
	cout << "===ÂÒÎÐÎÉ ÏÎËÈÍÎÌ===" << endl;
	cin >> q;
	system("cls");
	cout << "===Ïåðâûé ïîëèíîì: " << p << endl;
	cout << "===Âòîðîé ïîëèíîì: " << q << endl;
M1:
	cout << "Âûáåðèòå îïåðàöèþ" << endl;
	cout << "=== 1)P + Q" << endl;
	cout << "=== 2)P - Q" << endl;
	cout << "=== 3)P * Q" << endl;
	cin >> r;
	if (r == 1)
	{
		p += q;
		cout << "P + Q" << endl << p << endl;
		goto M1;
	}
	if (r == 2)
	{
		p -= q;
		cout << "P - Q" << endl << p << endl;
		goto M1;
	}
	if (r == 3)
	{
		cout << "===×èñëî äëÿ óìíîæåíèÿ===:" << endl;
		cin >> m;
		p *= m;
		cout << "P * Q" <<endl << p << endl;
		goto M1;
	}
	system("pause");

}