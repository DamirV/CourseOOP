#pragma once
#include<set>
#include<time.h>
class SetSort {
	int size;
public:
	SetSort(int n) :size(n) {

	}
	~SetSort() {

	}

	double setSort(int* mas) {
		std::multiset<int> ms;
		double time = clock();
		for(int i = 0; i < size; ++i){
		ms.insert(mas[i]);
		}

		for (auto i:ms) {
			*mas = i;
			mas++;
		}

		return clock() - time;
	}
};