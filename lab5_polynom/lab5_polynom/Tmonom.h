#include <iostream>
#include "TList.h"
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
		pHead->val = TM;
	}
	TPolinom(int mas[][2], int size)
	{
		pHead->val.coeff = 0;
		pHead->val.power = -1;
		for (int i = 0; i < size; i++)
		{
			TMonom m;
			m.coeff = mas[i][0];
			m.power = mas[i][1];
			InsLast(m);
		}
	}
	TPolinom(TPolinom &Q)
	{
		pHead->val.power = -1;
		pHead->val.coeff = 0;
		for (Q.Reset(); !Q.IsEnd(); Q.GoNext())
			InsLast(Q.pCurr->val);
	}
	void Print()
	{
		for (Reset(); !IsEnd(); GoNext())
			cout << pCurr->val.coeff << pCurr->val.power << ' ';
	}
	TPolinom& operator+=(TPolinom &Q)
	{
		Reset();
		Q.Reset();
		while (1)
		{
			if (pCurr->val.power > Q.pCurr->val.power) GoNext();
			else
				if (pCurr->val.power < Q.pCurr->val.power)
				{
					/*if (pCurr==pFirst)
					{
						InsFirst(Q.pCurr->val);
						Q.GoNext();
					}
					else{*/
					InsCurr(Q.pCurr->val);
					Q.GoNext();
					//}
				}
				else
				{
					if (pCurr->val.power == -1) break;
					pCurr->val.coeff += Q.pCurr->val.coeff;
					if (pCurr->val.coeff == 0)
					{
						if (pCurr == pFirst) {
							DelCurr();
							pCurr = pFirst;
						}
						else
							DelCurr();

					}
					else GoNext();
					Q.GoNext();
				}
		}
		return *this;
	}
	TPolinom& operator*(double c)
	{
		for (Reset(); !IsEnd(); GoNext())
		{
			pCurr->val.coeff = pCurr->val.coeff*c;
		}
		return *this;
	}
	TPolinom& operator =(TPolinom &Q)
	{
		while (pHead->pNext != pHead) DelFirst();
		for (Q.Reset(); !Q.IsEnd(); Q.GoNext())
		{
			TMonom tmp = Q.pCurr->val;
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
			if (pCurr->val.power > Q.pCurr->val.power) GoNext();
			else
				if (pCurr->val.power < Q.pCurr->val.power)
				{
					/*if (pCurr==pFirst)
					{
						InsFirst(Q.pCurr->val);
						Q.GoNext();
					}
					else{*/
					InsCurr(Q.pCurr->val);
					Q.GoNext();
					//}
				}
				else
				{
					if (pCurr->val.power == -1) break;
					pCurr->val.coeff += Q.pCurr->val.coeff;
					if (pCurr->val.coeff == 0)
					{
						if (pCurr == pFirst) {
							DelCurr();
							pCurr = pFirst;
						}
						else
							DelCurr();
					}
					else GoNext();
					Q.GoNext();
				}
		}
		return *this;
	}


};




