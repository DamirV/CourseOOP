#include "bSorting.h"

int tact(int*, int*,int,int);
int lastTact(int*, int*, int);
int reset(int*);

int sort(int* mas, int* tempMas, int size) {

	tact(mas,tempMas,size, 0);
	tact(tempMas, mas, size, 1);
	tact(mas, tempMas, size, 2);
	lastTact(tempMas, mas, size);

	return 1;
}

int tact(int* mas, int* tempMas, int size, int byte) {

	unsigned char* c = (unsigned char*)mas;

	int counter[256];
	int offset[256];
	offset[0] = 0;
	reset(counter);

	for (int i = 0; i < size; ++i) {
		counter[c[i * 4 + byte]]++;
	}

	for (int i = 1; i < 256; ++i) {
		offset[i] = counter[i - 1] + offset[i - 1];
	}

	for (int i = 0; i < size; ++i) {
		tempMas[offset[c[i * 4 + byte]]++] = mas[i];
	}

	return 1;
}

int lastTact(int* mas, int* tempMas, int size) {

	 char* c = (char*)mas;

	 int counter[256];
	 int offset[256];
	offset[0] = 0;
	reset(counter);

	for (int i = 0; i < size; ++i) {
		counter[c[i * 4 + 3]+128]++;
	}

	for (int i = 1; i < 256; ++i) {
		offset[i] = counter[i - 1] + offset[i - 1];
	}

	for (int i = 0; i < size; ++i) {
		tempMas[offset[c[i * 4 + 3]+128]++] = mas[i];
	}

	return 1;
}

int reset(int *counter) {

	for (int i = 0; i < 256; ++i) {
		counter[i] = 0;
	}
	return 1;
}