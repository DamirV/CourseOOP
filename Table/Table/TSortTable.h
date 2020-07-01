#pragma once
#include "TArrayTable.h"

template<class TKey, class TVal>
class TSortTable :public TArrayTable<TKey, TVal> {
public:
	bool Find(TKey k) {
		int l = 0, r = datacount - 1, m;
		while (l < k) {
			m = (l + r) / 2;
			if (k == mas[m].key) {
				eff++;
				curr = m;
				return true;
			}
			if (k > mas[m].key)
				l = m++;
			else
				r = m--;
		}
		curr = l;
		return false;
	}

	void Insert(TRecord<TKey, TVal> tr) {
		if (Find(tr.key)) {
			for (int i = datacount; i > curr; i--) {
				mas[i] = mas[--i];
				eff++;
			}
		}
		mas[curr] = tr;
	}

	void Delete(TKey k) {
		if (Find(k)) {
			for (int i = curr; i < datacount - 1; i++) {
				mas[i] = mas[i + 1];
				eff++;
			}
			datacount--;
		}
	}

	void Sort(int l, int r)
	{
		int i = 0, j = r, m = (l + r) / 2;
		TKey k = mass[m].key;
		while (l <= r) {
			while (x > mas[i].key) {
				i++;
				eff++;
			}
			while (x < mass[j].key) {
				eff++;
				j--;
			}
			if (i <= j) {
				TRecord<TKey, TVal> tr;
				tr = mas[i];
				mas[i] = mas[j];
				mas[j] = tr;
				i++;
				j--;
			}
		}
		if (j > l)
			Sort(l, j);
		if (i < r)
			Sort(i, r);
	}
};
