#pragma once
#include<map>
class Map {
	int size;
	int* mas;
public:
	Map(int n) :size(n) {
		mas = new int[size];
		for (int i = 0; i < size; ++i) {
			mas[i] = rand() * rand() * 2 - 500000000;
		}
	}
	~Map() { 
		delete[] mas;
	}
	void mapSort(std::map<int, int>& map) {
		for (int i = 0; i < size; ++i) {
			map.insert(std::make_pair(mas[i], mas[i]));
		}
	}
};