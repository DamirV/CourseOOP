#pragma once
#include<set>
#include<time.h>
class Set {
	int size;
	std::multiset<int> ms;
public:
	Set(int n) :size(n) {

	}
	~Set() {

	}
	double setSort(int* mas) {
		double time = clock();
		for (int i = 0; i < size; ++i) {
			ms.insert(mas[i]);
		}

		for (auto i : ms) {
			*mas = i;
			mas++;
		}

		return clock() - time;
	}
};