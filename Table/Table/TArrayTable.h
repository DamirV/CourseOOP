#pragma once
#include "TTable.h"

template <class TKey, class TVal>
class TArrayTable :public TTable<TKey, TVal> {
protected:
	TRecord<TKey, TVal> *mas;
	int maxcount, curr;

public:
	TArrayTable(int  = 0) {
		curr = 0;
		maxcount = _maxcount;
		mas = new TRecord<TKey, TVal>[maxcount];
	}

	~TArrayTable() {
		delete[] mas;
	}

	TArrayTable<TKey, TVal>(TArrayTable<TKey, TVal> &tat) {
		curr = tat.curr;
		maxcount = tat.maxcount;
		delete[] mas;
		mas = new TRecord<TKey, TVal>[maxcount];
		for (int i = 0; i < maxcount; i++) {
			mas[i] = tat.mas[i];
		}
	}

	TArrayTable<TKey, TVal> operator =(TArrayTable<TKey, TVal> tat) {
		curr = tat.curr;
		maxcount = tat.maxcount;
		delete[] mas;
		mas = new TRecord<TKey, TVal>[maxcount];
		for (int i = 0; i < maxcount; i++) {
			mas[i] = tat.mas[i];
		}
	}

	void Reset() {
		curr = 0;
	}

	void GoNext() {
		curr++;
	}

	bool IsEnd() {
		if (curr == datacount) {
			return true;
		}
		return false;
	}

};