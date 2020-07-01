#pragma once
#include<time.h>
class RadixSort {
	int size;
	int *counter;
	int *offset;
	int *tempMas;

	void reset(int *counter) {

		for (int i = 0; i < 65536; ++i) {
			counter[i] = 0;
		}
	}

	void radixFirst(int* mas, int* tempMas) {

		unsigned short int* c = (unsigned short int*)mas;

		for (int i = 0; i < size; ++i) {
			counter[c[i * 2]]++;
		}

		for (int i = 1; i < 65536; ++i) {
			offset[i] = counter[i - 1] + offset[i - 1];
		}

		for (int i = 0; i < size; ++i) {
			tempMas[offset[c[i * 2]]++] = mas[i];
		}
	}

	void radixLast(int* mas, int* tempMas) {

		short int* c = (short int*)mas;
		offset[0] = 0;
		reset(counter);
		for (int i = 0; i < size; ++i) {
			counter[c[i * 2 + 1] + 32768]++;
		}

		for (int i = 1; i < 65536; ++i) {
			offset[i] = counter[i - 1] + offset[i - 1];
		}

		for (int i = 0; i < size; ++i) {
			tempMas[offset[32768 + c[i * 2 + 1]]++] = mas[i];
		}
		
	}

public:

	RadixSort(int n):size(n) {
		 counter = new int[65536];
		 offset = new int[65536];
		 tempMas = new int[size];
		 offset[0] = 0;
		 reset(counter);
	}

	~RadixSort() {
		delete[] counter;
		delete[] offset;
		delete[] tempMas;
	}

	double radixSort(int* mas) {
		double time = clock();
		radixFirst(mas, tempMas);
		radixLast(tempMas,mas);
		return clock() - time;
	}
};