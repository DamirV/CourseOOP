#pragma once
#include<algorithm>
#include<time.h>

class QuickSort {
	int size;
public:
	QuickSort(int n) :size(n) {
		
	}
	~QuickSort() {

	}

	double quickSort(int* mas) {
		double time = clock();
		std::sort(mas, mas + size);
		return clock() - time;
	}

};