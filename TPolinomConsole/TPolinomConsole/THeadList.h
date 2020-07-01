#pragma once
#include "TList.h"
template <class T>

class THeadList : public TList<T>
{
protected:
	TLink<T> *pHead;
	
public:
	THeadList() : TList<T>()
	{
		TLink<T> *temp = new TLink<T>;
		pHead = temp;
		
		pHead->pNext = pHead;
		pFirst = pLast = pPrev = pCurr = pStop = pHead;
	}

	~THeadList()
	{
		TList<T>::~TList();

		delete pHead;
	}

	void InsFirst(T elem)
	{
		TList::InsFirst(elem);
		pHead->pNext = pFirst;
	}

	void InsCurr(T elem)
	{
		TList::InsCurr(elem);

		if (size == 1)
		{
			pHead->pNext = pFirst;
		}
	}

	void DelFirst()
	{
		TList::DelFirst();
		
		if (size == 0)
		{
			pHead->pNext = pHead;
		}
		else
		{
			pHead->pNext = pFirst;
		}
	}

};