#include "bSorting.h"
#include "functions.h"
#include <algorithm>

int main() {
	int size = 10000;

	int* mas = new int[size];
	int* copyMas = new int[size];
	int* tempMas = new int[size];

	random(mas,size);
	copy(mas, copyMas, size);

	sort(mas, tempMas, size);
	std::sort(copyMas, copyMas + size);

	std::cout << equals(mas, copyMas, size) << std::endl;
	system("pause");
	return 0;
}