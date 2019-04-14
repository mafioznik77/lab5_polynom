#pragma once
#include <iostream>
using namespace std;

struct TMonom {
	double coeff;
	int PowX, PowY, PowZ;
};

bool operator == (const TMonom& m1, const TMonom& m2) {
	if (m1.PowX == m2.PowX&&m1.PowY == m2.PowY&&m1.PowZ == m2.PowZ)
		return true;
	else
		return false;
}

bool operator >= (const TMonom& m1, const TMonom& m2) {
	if (m1 == m2)return true;
	else if (m1.PowX > m2.PowX)return true;
	else if (m1.PowY > m2.PowY)return true;
	else if (m1.PowZ > m2.PowZ)return true;
	else
		return false;
}

bool operator <=(const TMonom& m1, const TMonom& m2) {
	if (m1 == m2)return true;
	else if (m1.PowX < m2.PowX)return true;
	else if (m1.PowY < m2.PowY)return true;
	else if (m1.PowZ < m2.PowZ)return true;
	else
		return false;
}

bool operator != (const TMonom& m1, const TMonom& m2) {
	return !(m1 == m2);
}

bool operator > (const TMonom& m1, const TMonom& m2) {
	if (m1.PowX > m2.PowX)return true;
	else if (m1.PowY > m2.PowY)return true;
	else if (m1.PowZ > m2.PowZ)return true;
	else
		return false;
}

bool operator < (const TMonom& m1, const TMonom& m2) {
	if (m1.PowX < m2.PowX)return true;
	else if (m1.PowY < m2.PowY)return true;
	else if (m1.PowZ < m2.PowZ)return true;
	else
		return false;
}

istream &operator>>(istream &istr, TMonom &m)
{
	int coeff, x, y, z;
	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	std::cout << "Коэффицент:";
	istr >> coeff;
	std::cout << "Степень X:";
	istr >> x;
	std::cout << "Степень Y:";
	istr >> y;
	std::cout << "Степень Z:";
	istr >> z;
	m.PowX = x;
	m.PowY = y;
	m.PowZ = z;
	m.coeff = coeff;
	return istr;
}

ostream& operator<<(ostream &ostr, const TMonom &m)
{
	if (m.coeff != 0)
	{
		if (m.PowX == 0 && m.PowY == 0 && m.PowZ == 0)
			ostr << m.coeff;
		else
		{
			if (m.coeff != 1)
				ostr << m.coeff << " ";
			if (m.PowX != 0)
			{
				ostr << "x";
				if (m.PowX != 1)
					ostr << "^" << m.PowX << " ";
			}
			if (m.PowY != 0)
			{
				ostr << "y";
				if (m.PowY != 1)
					ostr << "^" << m.PowY << " ";
			}
			if (m.PowZ != 0)
			{
				ostr << "z";
				if (m.PowZ != 1)
					ostr << "^" << m.PowZ << " ";
			}
		}
	}
	return  ostr;
}