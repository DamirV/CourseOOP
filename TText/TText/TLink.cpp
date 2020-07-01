#include "TLink.h"
#include "TText.h"

TLink::	TLink(char *ch, TLink *pn, TLink *pd)
	{
		pNext = pn;
		pDown = pd;
		status = false;
		if (ch == 0)
		{
			str[0] = '\0';
		}
		else
		{
			strcpy_s(str, ch);
		}
	}

TLink::	~TLink()
	{

	}

	void* TLink:: operator new(size_t s)
	{
		TLink *temp = mem.pFree;

		if (mem.pFree != NULL)
			mem.pFree = mem.pFree->pNext;

		return temp;
	}

	void TLink::operator delete (void* p)
	{
		TLink *temp = (TLink*)p;

		temp->pNext = mem.pFree;
		mem.pFree = temp;
	}

	 void TLink::InitMem(int size)
	{

		mem.pFirst=(TLink*)new char[size * sizeof(TLink)];
		mem.pFree = mem.pFirst;

		mem.pLast = mem.pFirst + (size - 1);
		TLink *temp = mem.pFirst;

		for (int i = 0; i < size - 1; i++)
		{
			temp->str[0]='\0';
			temp->pNext = temp + 1;
			temp++;	
		}
		mem.pLast->pNext = NULL;
		mem.pLast->str[0]='\0';
	}

	 void TLink::MemClr(TText& txt)
	{
		TLink *temp = mem.pFree;

		while (temp != NULL)
		{
			temp->status = true;
			temp=temp->pNext;
		}

		for (txt.Reset(); !txt.IsEnd(); txt.GoNext())
        {
    	 txt.pCurr->status = true;
		}

		temp = mem.pFirst;

		while (temp <= mem.pLast)
		{
			if (temp->status == true)
			{
				temp->status = false;
			}
			else
			{
				temp->status = false;
				delete temp;
			}
			temp++;
		}
	 }

		void TLink:: PrintFreeTLinks()
		{
			int i = 0;
			TLink* temp = mem.pFree;
			while(temp <= mem.pLast)
			{
				if(temp->str[0] != '\0')
				{
					cout<< temp->str<<endl;
				}
				else
				{
					i++;
				}
				temp++;
			}

			cout << i << endl;
		}
	