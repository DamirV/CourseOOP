#pragma once
#include "TTable.h"

template<class TKey, class TVal>
struct TNode {
	TRecord<TKey, TVal> rec;
	TNode *pLeft, *PRight; //int bal
};

template<class TKey, class TVal>
class TTreeTable :public TTable<TKey, TVal> {
protected:
	TNode *pRoot, *pCurr, **pRes;
	TStack<TNode<TKey, TVal>*> stc;
	
public:
	TTreeTable() {
		stc.Clr()
		pRoot = pCurr = *pRes = NULL;
	}

	~TTreeTable() {
	}
	
	bool Find(TKey k) {
		pRes = &pRoot;
		while (*pRes != NULL) {
			eff++;
			if ((*pRes)->rec.key == k) {
				return true;
			}
			else if ((*pRes)->rec.key > k)
				pRes = &(*pRes->pRight);
			else if ((*pRes)->rec.key < k)
				pRes = &(*pRes->pLeft);
			}
		return false;
		}

	void Insetr(TRecord<TKey, TVal> tr) {
		if (!Find(rec.key)) {
			TNode *tmp = new TNode<TKey, TVal>();
			tmp->rec = rec;
			tmp->pRight = tmp->pLeft = NULL;
			*Pres = tmp;
		}
	}

	void Delete(TKey k) {
		if (Find(k)) {
			TNode *tmp = *pRes;
			if (tmp->pLeft == NULL) {
				*pRes = tmp->pRight;
			else if (tmp->pRight == NULL)
				*pRes = tmp->pLeft;
			}
			else {
				TNode *p = tmp->pRight, **pPrev = &(tmp->pLeft);
				pPrev = &(p->pRight);
				p = p->pRight;
			}
			tmp->rec = p->rec;
			tmp = p;
			*pPrev = pLeft;
			delete tmp;
		}
	}
};