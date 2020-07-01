#pragma once
#include "THeshTable.h"

template<class TKey, class TVal>
class TArrayHesh :public THeshTable<TKey, TVal> {
private:
	int massize, step, curr;
	TRecord<TKey, TVal> *mas;

public:
	TArrayHesh(int size = 100) {
		massize = size;
		step = 13;
		mas = new TRecord<TKey, TVal>[massize];
		for (int i = 0; i < massize; i++) {
			mas[i].key = "\0";
		}
	}

	~TArrayHesh() {
		delete[] mas;
	}

	bool IsFull() {
		return datacount == massize;
	}

	bool Find(TKey k) {
		int freepos = -1;
		curr = HeshFunc(k) % massize;
		for (int i = 0; i < massize; i++) {
			eff++;
			if (mas[curr].key == "\0") {
				if (freepos == -1)
					return false;
				else {
					curr = freepos;
					return false;
				}
			}
			if (mas[curr].key = k)
				return true;
			if (mas[curr].key == "&" && freepos == -1)
				curr = (curr + step) % massize;
		}
		return false;
	}

	void Delete(TKey k) {
		if (Find(k)) {
			mas[curr].key = "&";
			datacount--;
		}
	}

	void Insert(TRecord<TKey, TVal> tr) {
		if (!Find(tr.key)) {
			mas[curr] = tr;
			datacount++;
		}
	}

	void Reset() {
		curr = 0;
		for (int i = 0; i < massize; i++) {
			if (mas[curr].key == '&' || mas[curr].key == "\0") {
				curr = i;
				break;
			}
		}
	}

	bool IsEnd() {
		return curr == massize;-1
	}
};