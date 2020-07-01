#include"BucketSort.h"
#include"RadixSort.h"
#include"Map.h"
#include"Set.h"
#include"QuickSort.h"
#include<string>
#include<time.h>
#include <ctime>
#include <algorithm>

void print(int* mas, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << mas[i] << " ";
	}
	std::cout << std::endl;
}

void print(double* mas, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << mas[i] << " ";
	}
	std::cout << std::endl;
}

void rand(int* mas, int size) {
	for (int i = 0; i < size; ++i) {
		mas[i] = rand();
	}
}

void randDouble(int* mas, int size) {
	for (int i = 0; i < size; ++i) {
		mas[i] = rand()%10000;
	}
}

void rand(int* mas,int* mas1, int size) {
	for (int i = 0; i < size; ++i) {
		mas[i]= mas1[i] = rand() * rand() * 2 - 500000000;
	}
}

std::string sravn(int* mas1, int* mas2,int size) {
	for (int i = 0; i < size; ++i) {
		if (mas1[i] != mas2[i]) {
			return "ERROR";
		}
	}
	return "ALL RIGHT";
}

void main() {
	srand(time(NULL));
	double time;
	std::cout << "BUCKET SORT-----------------------------------" << std::endl;
	int n = 10;
	int* a = new int[n];
	double* b = new double[n];
	randDouble(a, n);

	for (int i = 0; i < n; ++i) {

		double temp = a[i];
		while (temp > 1) {
			temp /= 10;
		}
		b[i] = temp;
	}

	BucketSort* bs = new BucketSort(n);
	print(a, n);
	print(b, n);
	std::cout<< bs->bucketSort(b) << " ms" <<std::endl;

	print(b, n);
	std::cout<<std::endl;

	std::cout << "RADIX SORT-----------------------------------" << std::endl;
	int size = 100000;
	RadixSort* r = new RadixSort(size);
	int* mas = new int[size];
	int* mas1 = new int[size];
	rand(mas, mas1, size);

	std::cout << "radixSort() " << r->radixSort(mas) << " ms" << std::endl;

	time = clock();
	std::sort(mas1, mas1 + size);
	time = clock() - time;
	std::cout << "std::sort() " << time << " ms" << std::endl;
	std::cout << sravn(mas, mas1, size)<<std::endl;
	std::cout << std::endl;

	std::cout << "SET SORT-----------------------------------" << std::endl;
	Set* st = new Set(size);
	int* mas2 = new int[size];
	rand(mas2, size);
	std::cout << st->setSort(mas2) << " ms" << std::endl;
	std::cout << std::endl;

	std::cout << "Quick SORT-----------------------------------" << std::endl;
	QuickSort* q = new QuickSort(size);

	time = clock();
	q->quickSort();
	time = clock() - time;
	std::cout << time << " ms" << std::endl;
	std::cout << std::endl;
	system("pause");
}