#pragma once
#include <cstddef>

template <class T>
struct TLink
{
	T val;
	TLink<T> *pNext;
}; 

template <class T>
class TList {

protected:
	TLink<T> *pLast;
	TLink<T> *pFirst;
	TLink<T> *pStop, *pPrev, *pCurr;

	int size;
	int pos;

public:
	TList()
	{

		pFirst = pLast = pPrev = pCurr = pStop = NULL;
		size = 0;
		pos = -1;

	}



	~TList()
	{
		int _size = size;

			for (int i=0; i<_size; i++)
			{
				DelFirst();
			}
		
	}

	virtual void InsFirst(T elem)
	{
		TLink<T> *temp = new TLink<T>;
		temp->val = elem;
		if (size == 0)
		{
			pFirst = pLast = temp;
			pLast->pNext = pStop;
			pos = 0;
		}
		else
		{
			temp->pNext = pFirst;
			pFirst = temp;
			pos++;
		}
		size++;

	}

	virtual void InsCurr(T elem)
	{
	

		 if (pCurr == pFirst)
		{
			InsFirst(elem);
			pCurr = pFirst;
		}
		 else
		{
			TLink<T> *temp = new TLink<T>;
			temp->val = elem;
			pPrev->pNext = temp;
			temp->pNext = pCurr;
			pCurr = temp;
			size++;
		}
		
	}

	void InsLast(T elem)
	{

		if (size == 0)
		{
			InsFirst(elem);
		}
		else
		{
			TLink<T> *temp = new TLink<T>;
			temp->val = elem;
			temp->pNext = pStop;
			pLast->pNext = temp;
			pLast = temp;
			size++;
		}

	}

	virtual void DelFirst()
	{
		
		if (size == 1)
		{
			delete pFirst;
			pFirst = pLast = pCurr = pPrev = pStop;
		}
		else
		{
			TLink <T> *temp;
			temp = pFirst;
			pFirst = pFirst->pNext;
			delete temp;
		}
		size--;

		if (pos != 0)
		{
			pos--;
		}

	}

	virtual void DelCurr()
	{
		if (size == 0 || pCurr==pStop)
		{
			throw 0;
		}

		if (pCurr == pFirst)
		{
			DelFirst();
		}
		else
		{
			pPrev->pNext = pCurr->pNext;
			delete pCurr;
			pCurr = pPrev->pNext;
			size--;
		}
	}

	void DelLast()
	{
	
		if (size == 1)
		{
			delete pFirst;
			pFirst = pLast = pCurr = pPrev = pStop;
		}
		else
		{
			TLink <T> *temp;
			temp = pLast;
			pLast = pLast->pNext;
			delete temp;
		}

		size--;
		pos--;
	}
	
 void Reset()
	{
		pCurr = pFirst;
		pos = 0;
		pPrev = pStop;
	}

	void GoNext()
	{
		pPrev = pCurr;
		pCurr = pPrev->pNext;
		pos++;
	}

	bool IsEnd()
	{
		if (pCurr == pStop)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void InsSort(T elem)
	{
		if (size == 0)
		{
			InsFirst(elem);
		}
		else
		{
			for (Reset(); ! IsEnd(); GoNext())
			{
				if (elem <= GetCurrVal())
				{
					InsCurr(elem);
						return;
			    }
			}
			InsLast(elem);
		}
	}
};