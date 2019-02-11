#pragma once
#include <iostream>

using namespace std;

template <class T>

class TLink
{
public:
	T val;
	TLink *pNext;
};

template <class T>
class THeadList
{
protected:
	TLink<T> *pHead, *pFirst, *pPrev, *pCurr, *pLast;
	int pos, size;
public:

	THeadList() 
	{
		TLink<T>*tmp = new TLink<T>;
		pHead = tmp;
		pHead->pNext = pHead;
		pFirst = pCurr = pLast = pPrev = NULL;
		pos = -1;
		size = 0;
	}


	void InsFirst(const T elem) 
	{
		TLink<T>*tmp = new TLink<T>;
		tmp->val = elem;
		if (size > 0)
		{
			pHead->pNext = tmp;
			tmp->pNext = pFirst;
			pFirst = tmp;
			size++; pos++;
		}
		else
		{
			pHead->pNext = tmp;
			tmp->pNext = pHead;
			pFirst = tmp;
			size++; pos = 0;
			pCurr = pFirst;
		}
	}

	void InsCurr(const T elem)
	{
		TLink<T>*tmp = new TLink<T>;
		tmp->val = elem;
		pPrev->pNext = tmp;
		tmp->pNext = pCurr;
		pCurr = tmp;
		size++;
	}

	void DelCurr()
	{
		if (pCurr != pHead && size > 0)
		{
			TLink<T>*tmp = pCurr;
			pPrev->pNext = pCurr->pNext;
			delete tmp;
			pCurr = pPrev->pNext;
			size--;
		}
	}


};