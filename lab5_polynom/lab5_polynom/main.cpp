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
	cout << "===������ �������===" << endl;
	cin >> p;
	system("cls");
	cout << "===������ �������===" << endl;
	cin >> q;
	system("cls");
	cout << "===������ �������: " << p << endl;
	cout << "===������ �������: " << q << endl;
M1:
	cout << "�������� ��������" << endl;
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
		cout << "===����� ��� ���������===:" << endl;
		cin >> m;
		p *= m;
		cout << "P * Q" <<endl << p << endl;
		goto M1;
	}
	system("pause");

}