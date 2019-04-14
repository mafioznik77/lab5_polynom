#pragma once
#include <iostream>
#include "TLink.h"
using namespace std;


template <class T>
class THeadList {
public:
	int pos, size;
	TLink<T> *pHead, *pFirst;
public:
	void InsFirst(const T elem);
	void  InsCurr(const T elem);
	void DelCurr();
	void InsElem(const T elem);
	void PrintList();
	void InsLast(const T elem);
	THeadList();
	~THeadList();
	TLink<T>  *pPrev, *pCurr, *pLast;
	void Reset();
	void GoNext();
	bool IsEnd();
	T GetCurr();
};

template <class T>
THeadList<T>::THeadList() {
	pHead = new TLink<T>;
	pHead->pNext = pHead;
	pFirst = pCurr = pPrev = pLast = pHead;
	size = 0;
	pos = -1;
}

template <class T>
void THeadList<T>::InsFirst(const T elem) {
	TLink<T> *tmp = new TLink<T>;
	tmp->val = elem;
	if (size > 0)
	{
		pHead->pNext = tmp;
		tmp->pNext = pFirst;
		if (size == 1)pLast = tmp->pNext;
		pFirst = tmp;
		size++;
		pos++;
	}
	else
	{
		pHead->pNext = tmp;
		tmp->pNext = pHead;
		pFirst = tmp;
		pLast = tmp;
		pLast->pNext = pHead;
		size++;
		pos = 0;
		pCurr = pFirst;
	}
}

template <class T>
void THeadList<T>::InsCurr(const T elem) {
	TLink <T> *tmp = new TLink <T>;
	tmp->val = elem;
	if (pos == 0 && pPrev == pHead)
	{
		pFirst = tmp;
	}
	pPrev->pNext = tmp;
	tmp->pNext = pCurr;
	if (pCurr == pHead)
	{
		pLast = tmp;
	}
	pCurr = tmp;
	if (size == 0)
	{
		pos = 0;
		pLast = tmp;
		pLast->pNext = pHead;
		pFirst = tmp;
	}
	size++;
}

template <class T>
void THeadList<T>::DelCurr() {
	if (pCurr != pHead && size > 0)
	{
		TLink<T> *tmp = pCurr;
		pPrev->pNext = tmp->pNext;
		delete tmp;
		pCurr = pPrev->pNext;
		size--;
		if (size == 0)
		{
			pFirst = pLast = pPrev = pCurr = pHead;
			pos = -1;
		}
	}
}

template <class T>
void THeadList<T>::InsElem(const T elem) {
	TLink<T> *tmp = new TLink<T>;
	tmp->val = elem;
	if (pHead->pNext == pHead)
	{
		pFirst = tmp;
		pLast = tmp;
		pHead->pNext = pFirst;
		pFirst->pNext = pHead;
		pLast = pFirst;
		pCurr = pFirst;
		pos = 0;
		size++;
	}
	else if (pFirst == pLast)
	{
		pLast = tmp;
		pFirst->pNext = pLast;
		pLast->pNext = pHead;
		size++;
	}
	else
	{
		pLast->pNext = tmp;
		pLast = tmp;
		tmp->pNext = pHead;
	}
}

template <class T>
void THeadList<T>::PrintList() {
	TLink<T> *tmp = pFirst;
	while (tmp != pHead)
	{
		std::cout << tmp->val << std::endl;
		tmp = tmp->pNext;
	}
	std::cout << std::endl;
}

template <class T>
void THeadList<T>::Reset()
{
	if (size == 0)
		throw - 1;
	pCurr = pFirst;
	pPrev = pHead;
	pos = 0;
}

template <class T>
void THeadList<T>::GoNext() {
	if (pCurr != pHead)
	{
		pPrev = pCurr;
		pCurr = pCurr->pNext;
		pos++;
	}
	else
		throw (-1);
}

template <class T>
bool THeadList<T>::IsEnd() {
	return(pCurr == pHead);
}

template <class T>
T THeadList<T>::GetCurr() {
	if (pCurr != pHead)
		return pCurr->val;
	else
		throw (-1);
}

template <class T>
THeadList<T>::~THeadList() {
	pCurr = pFirst;
	while (pCurr != pHead)
	{
		pPrev = pCurr;
		pCurr = pCurr->pNext;
		delete pPrev;
	}
	delete pHead;
}

template <class T>
void THeadList<T>::InsLast(const T elem)
{
	TLink<T> *tmp = new TLink<T>;
	tmp->val = elem;
	pLast->pNext = tmp;
	tmp->pNext = pHead;
	pLast = tmp;
}
