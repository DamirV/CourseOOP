#pragma once
#include<algorithm>
class QuickSort {
	int size;
	int* mas;
public:
	QuickSort(int n) :size(n) {
		mas = new int[size];
		for (int i = 0; i < size; ++i) {
			mas[i] = rand() * rand() * 2 - 500000000;
		}
	}
	~QuickSort() {
		delete[] mas;
	}
	void quickSort() {
		std::qsort(mas, size, sizeof *mas, [](const void* a, const void* b)
		{
			int arg1 = *static_cast<const int*>(a);
			int arg2 = *static_cast<const int*>(b);
			return (arg1 > arg2) - (arg1 < arg2);
		});
	}
	void print() {
		for (int i = 0; i < size; ++i)
			std::cout << mas[i] << " ";
		std::cout << std::endl;
	}
};