#pragma once
#include "TArrayTable.h"

template<class TKey, class TVal>
class TScanTable :public TArrayTable<TKey, TVal> {
public:
	bool Find(TKey k) {
		for (int i = 0; i < datacaount; i++) {
			if (mas[i].key == k) {
				curr = i;
				return true;
			}
			eff++;
		}
		curr = datacount;
		return false;
	}

	void Insert(TRecord<TKey, TVal> tr) {
		if (!Find(tr.key)) {
			mas[curr] = tr;
			datacount++;
			eff++;
		}
	}

	void Delete(TRecord<TKey, TVal> tr) {
		if (Find(tr.key)) {
			mas[curr] = mas[datacount];
			datacount--;
			eff++;
		}
	}


	
};