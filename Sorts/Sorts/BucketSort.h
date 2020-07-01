#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
class BucketSort {

	std::vector<std::vector<double> > b;
	int size;
public:
	BucketSort(int n) :size(n), b(n) { }
	~BucketSort() { }

	double bucketSort(double arr[])
	{
		double time = clock();
		for (int i = 0; i<size; i++)
		{
			int x = size*arr[i];
			b[x].push_back(arr[i]);
		}

		for (int i = 0; i<size; i++)
			std::sort(b[i].begin(), b[i].end());

		int index = 0;
		for (int i = 0; i < size; i++)
			for (int j = 0; j < b[i].size(); j++)
				arr[index++] = b[i][j];
		return clock() - time;
	}

};