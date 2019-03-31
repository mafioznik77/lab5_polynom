#pragma once
#include <iostream>
#include "Tmonom.h"
#include "TPolinom.h"
#include "TList.h"


class TPolinom :public THeadList<TMonom> {
public:
	void InsMonom(const TMonom &n);
	void operator *=(double d);
	void operator *=(TMonom &n);
	void operator +=(TMonom &n) { InsMonom(n); }
	void operator +=(TPolinom &n);

	void operator *=(const int &n);
	void operator -=(TPolinom &n);
	void operator +=(double d);
	void operator -=(double d);
	TPolinom();
	friend ostream& operator<<(ostream &ostr, const TPolinom &n);
	friend istream& operator>>(istream &istr, TPolinom &n);
};

TPolinom::TPolinom()
{
	TMonom m;
	m.coeff = 0;
	m.PowX = m.PowY = 0;
	m.PowZ = -1;
	pHead->val = m;
}

void TPolinom::InsMonom(const TMonom &n) {
	if (size == 0)
		InsFirst(n);
	else
		for (Reset(); !IsEnd(); GoNext())
		{
			if (pCurr->val == n)
			{
				pCurr->val.coeff += n.coeff;
				if (pCurr->val.coeff == 0)
				{
					DelCurr();
					break;
				}
			}
			if (n > pCurr->val)
			{
				InsCurr(n);
				break;
			}
		}
}

void TPolinom::operator*=(double d) {
	for (Reset(); !IsEnd(); GoNext())
		pCurr->val.coeff *= d;
}

void TPolinom::operator *= (TMonom &n) {
	for (Reset(); !IsEnd(); GoNext())
	{
		pCurr->val.coeff *= n.coeff;
		if (pCurr->val.coeff == 0)
		{
			DelCurr();
			break;
		}
		pCurr->val.PowX += n.PowX;
		pCurr->val.PowY += n.PowY;
		pCurr->val.PowZ += n.PowZ;
	}
}

void TPolinom::operator+=(TPolinom &n) {
	Reset();
	n.Reset();
	while (1)
	{
		if (pCurr->val > n.pCurr->val)GoNext();
		else if (pCurr->val < n.pCurr->val) {
			InsCurr(n.pCurr->val);
			n.GoNext();
		}
		else
		{
			if (pCurr->val.PowZ == -1 || n.pCurr->val.PowZ == -1)
				break;
			if ((n.pCurr->val.coeff + pCurr->val.coeff) == 0)
			{
				DelCurr();
				n.GoNext();
			}
			else {
				pCurr->val.coeff = n.pCurr->val.coeff + pCurr->val.coeff;
				n.GoNext();
				GoNext();
			}
		}
	}
}

ostream& operator<<(ostream  &ostr, TPolinom &p)
{
	if (p.size == 0)
		cout << 0;
	else
	{
		for (p.Reset(); !p.IsEnd(); p.GoNext())
		{
			if (p.pos != 0)
				if (p.pCurr->val.coeff > 0)
					ostr << "+" << p.pCurr->val;
				else
					ostr << p.pCurr->val;
			else
				ostr << p.pCurr->val;
		}
	}
	return ostr;
}

istream& operator>>(istream &istr, TPolinom &n)
{
	int k;
	int i = 0;
	std::cout << "Enter the number of objects: ";
	istr >> k;
	while (i<k)
	{
		std::cout << "Monom:" << i + 1 << endl;
		TMonom m1;
		istr >> m1;
		n.InsMonom(m1);
		i++;
		std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	}
	return istr;
}

void TPolinom::operator*=(const int &n)
{
	for (Reset(); !IsEnd(); GoNext())
	{
		pCurr->val.coeff *= n;
	}
}

void TPolinom::operator-=(TPolinom &n)
{
	n *= -1;
	this->operator+=(n);
}

void TPolinom::operator+=(double d)
{
	if (pLast->val.PowX == 0)
	{
		if (pLast->val.PowY == 0)
		{
			if (pLast->val.PowZ == 0)
				pLast->val.coeff += d;
		}
	}
	else
	{
		TMonom m1;
		m1.coeff = d;
		m1.PowX = m1.PowY = m1.PowZ = 0;
		InsLast(m1);
	}
}

void TPolinom::operator-=(double d)
{
	d *= -1;
	this->operator+=(d);
}