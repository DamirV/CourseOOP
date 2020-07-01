#include "TText.h"

TText:: TText(TLink *tl)
	{
		if (tl == NULL)
		{
	     tl = new TLink();
		}
		pFirst = tl;
	}

	TText:: ~TText()
	{

	}
	
	void TText::  InsNextLine(char *ch)
	{
		TLink *temp = new TLink(ch, pCurr -> pNext, NULL);
		pCurr->pNext = temp;
	}

	void TText:: InsNextSection(char *ch)
	{
		TLink *temp = new TLink(ch, NULL, pCurr->pNext);
		pCurr->pNext = temp;
	}

	TLink* TText:: ReadRec(istream& ifs, int level)
	{
		TLink *First, *Curr;
		First = Curr = new TLink();
		char tmp[100];

		while (!ifs.eof() )
		{
			ifs.getline(tmp, 100, '\n');
			
			if (tmp[0] == '}')
			{
				break;
			}
			else if (tmp[0] == '{')
				{
					level++;
					Curr->pDown = ReadRec(ifs , level);
					level--;
				}
				else
				{
					TLink *temp = new TLink(tmp);
					Curr -> pNext = temp;
					Curr = Curr->pNext;
				}
		}
		Curr = First;
		if (First->pDown == NULL && level != 0)
		{
			First = First->pNext;
			delete Curr;
		}

		return First;
	}

	void TText:: Read(char *ch)
	{
		int level = 0;
		ifstream ifs(ch);
		pFirst = ReadRec(ifs,level);
	}

	void TText::PrintRec(TLink *p, int level)
	{
		for (int i = 0; i < level; i++, cout << " ");
		if (p==pCurr) cout << "-> ";
		cout << p->str << endl;
		if (p->pDown != NULL)
		{
			

			for (int i = 0; i < level; i++, cout << " ");
			cout << "{"<<endl;
			level += 2;

			PrintRec(p->pDown,level);
			level -= 2;

			for (int i = 0; i < level; i++,cout << " ");
			cout << "}" << endl;
			
		}
		if (p->pNext != NULL)
		{
			PrintRec(p->pNext, level);
			
		}
	}

	void TText:: Print()
	{
		int level = 0;
		PrintRec(pFirst,level);
	}

	

	void TText:: Reset()
	{
		stc.Clr();

	

		pCurr = pFirst;
		stc.Push(pCurr);

		if (pCurr->pNext != NULL)
			stc.Push(pCurr->pNext);
		if (pCurr->pDown != NULL)
			stc.Push(pCurr->pDown);
	}

	bool TText:: IsEnd()
	{
		if ( stc.IsEmpty() )
			return true;
		else
			return false;
	}

	void TText:: GoNext()
	{

		pCurr = stc.Pop();
	
		if (pCurr->pNext != NULL)
			stc.Push(pCurr->pNext);
		if (pCurr->pDown != NULL)
			stc.Push(pCurr->pDown);
		
	}

	TLink* TText:: CopyRec(TLink *tl)
	{
		TLink *temp = new TLink();

		if (tl->pDown != NULL)
			temp->pDown = CopyRec(tl->pDown);
		if (tl->pNext != NULL)
			temp->pNext = CopyRec(temp->pNext);

		return temp;
	}

	TLink* TText:: Copy()
	{
		return CopyRec(pFirst);
	}

	void TText:: SaveRec(TLink *temp, ofstream &of) {

		of << temp->str << endl;

		if (temp->pDown != NULL)
		{
			of << "{" <<endl;
			SaveRec(temp->pDown, of);
			of << "}"<<endl;
		}

		if (temp->pNext != NULL) 
		{
			SaveRec(temp->pNext, of);
		}		
	}

	void TText:: Save(char* fn)
	{
		ofstream of(fn);

		SaveRec(pFirst,of);
	}

	void TText:: InsDownLine(char *ch)
	{
		TLink* temp=new TLink(ch,pCurr->pDown,NULL);
		pCurr->pDown=temp;
	}

	void  TText:: InsDownSection(char *ch)
	{
		TLink* temp = new TLink(ch,NULL,pCurr->pDown);
			pCurr->pDown=temp;
	}

	void TText:: DelNext()
	{
		TLink* temp= pCurr->pNext;
		if(temp!=NULL)
		{
			pCurr->pNext=temp->pNext;
			delete temp;
		}
	}

	void TText:: DelDown()
	{
		TLink* temp= pCurr->pDown;
		if(temp!=NULL)
		{
			pCurr->pDown=temp->pNext;
			delete temp;
		}
	}
	void TText::ToNext()
	{
		if (pCurr->pNext != NULL)
		{
		
		    stc.Push(pCurr);
			pCurr = pCurr->pNext;
		
		}

	}
	void TText::ToDown()
	{
		if (pCurr->pDown != NULL)
		{
		
			stc.Push(pCurr);
			pCurr = pCurr->pDown;
		
		}

	}
	void TText::ToPrev()
	{
		if (!stc.IsEmpty())
		{
			
			pCurr = stc.Pop();
		
		}

	}

	void TText::ToFirst()
	{
		stc.Clr();
		pCurr = pFirst;
	}