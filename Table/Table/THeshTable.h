#pragma once
#include "TTable.h"

template<class TKey, class TVal>
class THeshTable : public TTable<TKey, TVal> {
protected:
	int HeshFunc(TKey k) {
		int res = 0;
		for (int i = 0; i < k.size(); i++) {
			res += k[i] << i;
		}
		return res;
	}

};