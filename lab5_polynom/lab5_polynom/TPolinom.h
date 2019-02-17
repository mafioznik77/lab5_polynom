#pragma once
#include <iostream>
#include "Tlist.h"
using namespace std;

struct TMonom
{
	double coeff;
	int power;
};

class TPolinom : THeadList<TMonom>
{
public:
	TPolinom()
	{
		TMonom TM;
		TM.coeff = 0;
		TM.power = -1;
		pHead->value = TM;
	}
	TPolinom(int mas[][2], int size)
	{
		pHead->value.coeff = 0;
		pHead->value.power = -1;
		for (int i = 0; i<size; i++)
		{
			TMonom m;
			m.coeff = mas[i][0];
			m.power = mas[i][1];
			InsLast(m);
		}
	}
	TPolinom(TPolinom &Q)
	{
		pHead->value.power = -1;
		pHead->value.coeff = 0;
		for (Q.Reset(); !Q.IsEnd(); Q.Next())
			InsLast(Q.pCurr->value);
	}
	void Print()
	{
		for (Reset(); !IsEnd(); Next())
			cout << pCurr->value.coeff << pCurr->value.power << ' ';
	}
	TPolinom& operator+=(TPolinom &Q)
	{
		Reset();
		Q.Reset();
		while (1)
		{
			if (pCurr->value.power > Q.pCurr->value.power) Next();
			else
				if (pCurr->value.power < Q.pCurr->value.power)
				{
					/*if (pCurr==pFirst)
					{
					InsFirst(Q.pCurr->value);
					Q.Next();
					}
					else{*/
					InsCurr(Q.pCurr->value);
					Q.Next();
					//}
				}
				else
				{
					if (pCurr->value.power == -1) break;
					pCurr->value.coeff += Q.pCurr->value.coeff;
					if (pCurr->value.coeff == 0)
					{
						if (pCurr == pFirst) {
							DelCurr();
							pCurr = pFirst;
						}
						else
							DelCurr();

					}
					else Next();
					Q.Next();
				}
		}
		return *this;
	}
	TPolinom& operator*(double c)
	{
		for (Reset(); !IsEnd(); Next())
		{
			pCurr->value.coeff = pCurr->value.coeff*c;
		}
		return *this;
	}
	TPolinom& operator =(TPolinom &Q)
	{
		while (pHead->pNext != pStop) DelFirst();
		for (Q.Reset(); !Q.IsEnd(); Q.Next())
		{
			TMonom tmp = Q.pCurr->value;
			InsLast(tmp);
		}
		return *this;
	}

	TPolinom& operator-=(TPolinom &tmp)
	{
		TPolinom Q;
		int c = -1;
		Q = tmp * c;
		Reset();
		Q.Reset();
		while (1)
		{
			if (pCurr->value.power > Q.pCurr->value.power) Next();
			else
				if (pCurr->value.power < Q.pCurr->value.power)
				{
					/*if (pCurr==pFirst)
					{
					InsFirst(Q.pCurr->value);
					Q.Next();
					}
					else{*/
					InsCurr(Q.pCurr->value);
					Q.Next();
					//}
				}
				else
				{
					if (pCurr->value.power == -1) break;
					pCurr->value.coeff += Q.pCurr->value.coeff;
					if (pCurr->value.coeff == 0)
					{
						if (pCurr == pFirst) {
							DelCurr();
							pCurr = pFirst;
						}
						else
							DelCurr();
					}
					else Next();
					Q.Next();
				}
		}
		return *this;
	}


};




