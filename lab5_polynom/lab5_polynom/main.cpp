
#include <iostream>
#include "Tmonom.h"
#include "TPolinom.h"
#include "TList.h"

using namespace std;

int main()
{/*
	TPolinom p1;
	cin >> p1;
	double d = 1;
	p1 += d;
	cout << p1 << endl;
	*/
	TPolinom s2, s3;
	cin >> s2;
	cin >> s3;
	cout << s3 << endl;
	s3 += s2;
	cout << s2 << endl;
	cout << s3 << endl;

	system("pause");
}