#pragma once
#include<iostream>
#include"TStack.h"

template <class TKey, class TVal>
struct TRecord {
	TKey key;
	TVal val;
};

template <class TKey, class TVal>
class TTable {
protected:
	int datacount, eff;

public:
	TTable(){
		datacount = eff = 0;
	}

	~TTable() {

	}

	bool IsEmpty()const {
		return datacount;
	}

	virtual bool IsFull()const = 0;
	virtual void Insert(TKey k, TVal v) = 0;
	virtual bool Find(TKey k) = 0;
	virtual void Reset() = 0;
	virtual bool IsEnd() = 0;
	virtual void GoNext() = 0;
	virtual TRecord<TKey, TVal> GetCurr() = 0;
	virtual void Print() {
		TRecord<TKey, TVal> tmp;
		for (Reset(); !IsEnd(); GoNext()) {
			tmp = GetCurr();
			std::cout << "key = " << tmp.key << "\n" << "val = " << tmp.val << endl;
		}
	}

};

