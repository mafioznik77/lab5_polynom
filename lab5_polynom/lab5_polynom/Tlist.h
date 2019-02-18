#pragma once
#include <iostream>

using namespace std;

template <class T>
//asd
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

	~THeadList()
	{
		pCurr = pFirst;
		while (pCurr != pHead)
		{
			pPrev = pCurr;
			pCurr = pCurr->pNext;
			delete pPrev;
		}
		delete pHead;
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

	void DelFirst()
	{
		if (size != 0)
		{
			pHead->pNext = pFirst->pNext;
			delete pFirst;
			pFirst = pHead->pNext;
			size--;
			pos--;
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

	void Reset()
	{
		pCurr = pFirst;
		pPrev = pHead;
		pos = 0;
	}

	void GoNext()
	{
		pPrev = pCurr;
		pCurr = pCurr->pNext;
		pos++;
	}

	bool IsEnd()
	{
		return pCurr == pHead;
	}
};