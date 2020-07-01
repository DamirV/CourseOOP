#pragma once
#include <iostream>

//template <typename key>
class D_Heap {

	//int Size;
	//int index;
	//int d;
	//int d;
	//int* Array;

public:
	//int d;
	//int* Array;
	int Size;
	const int d;
	int* Array;

	D_Heap(int *arr, int size, int d_) :Array(arr), Size(size), d(d_) {
		buildHeap(Array, Size);
	}

	void restoreDown(int *arr, int len, int index)
	{
		// child array to store indexes of all 
		// the children of given node 
		if (!len <= 1)
		{
			int *child = new int[d + 1];
			while (1)
			{
				// child[i]=-1 if the node is a leaf 
				// children (no children) 
				for (int i = 1; i <= d; i++)
					child[i] = ((d*index + i) < len) ? (d*index + i) : -1;

				// max_child stores the maximum child and 
				// max_child_index holds its index 
				int max_child = -1, max_child_index;

				// loop to find the maximum of all 
				// the children of a given node 
				for (int i = 1; i <= d; i++)
				{
					if (child[i] != -1 &&
						arr[child[i]] > max_child)
					{
						max_child_index = child[i];
						max_child = arr[child[i]];
					}
				}

				// leaf node 
				if (max_child == -1)
				{
					break;
				}

				// swap only if the key of max_child_index 
				// is greater than the key of node 
				if (arr[index] < arr[max_child_index])
					std::swap(arr[index], arr[max_child_index]);

				index = max_child_index;
			}
			
			delete child;
		}
	}


	// Restores a given node up in the heap. This is used 
// in decreaseKey() and insert() 
	void restoreUp(int *arr, int index)
	{
		// parent stores the index of the parent variable 
		// of the node 
		int parent = (index - 1) / d;

		// Loop should only run till root node in case the 
		// element inserted is the maximum restore up will 
		// send it to the root node 
		while (parent >= 0)
		{
			if (arr[index] > arr[parent])
			{
				std::swap(arr[index], arr[parent]);
				index = parent;
				parent = (index - 1) / d;
			}

			// node has been restored at the correct position 
			else
				break;
		}
	}

	// Function to build a heap of arr[0..n-1] and alue of k. 
	void buildHeap(int *arr, int n)
	{
		// Heapify all internal nodes starting from last 
		// non-leaf node all the way upto the root node 
		// and calling restore down on each 
		for (int i = (n - 1) / d; i >= 0; i--)
			restoreDown(arr, n, i);
	}

	// Function to insert a value in a heap. Parameters are 
// the array, size of heap, value k and the element to 
// be inserted 
	void insert(int *arr, int* n, int elem)
	{
		// Put the new element in the last position 
		arr[*n] = elem;

		// Increase heap size by 1 
		*n = *n + 1;

		// Call restoreUp on the last index 
		restoreUp(arr, *n - 1);
	}


	// Function that returns the key of root node of 
// the heap and then restores the heap property 
// of the remaining nodes 
	int extractMax(int *arr, int n)
	{
		// Stores the key of root node to be returned 
		int max = arr[0];

		// Copy the last node's key to the root node 
		arr[0] = arr[n - 1];
		//std::cout << "-> " << arr[n - 1] << " <-  " << arr[0] << " "<< std::endl;
		// Decrease heap size by 1 
		n = n - 1;

		// Call restoreDown on the root node to restore 
		// it to the correct position in the heap 
		restoreDown(arr, n, 0);

		//printArray(arr, n);

		return max;
	}


	void heapify(int *arr, int n, int i)
	{
		int largest = i; // Initialize largest as root 
		int l = 2 * i + 1; // left = 2*i + 1 
		int r = 2 * i + 2; // right = 2*i + 2 

		// If left child is larger than root 
		if (l < n && arr[l] > arr[largest])
			largest = l;

		// If right child is larger than largest so far 
		if (r < n && arr[r] > arr[largest])
			largest = r;

		// If largest is not root 
		if (largest != i)
		{
			std::swap(arr[i], arr[largest]);

			// Recursively heapify the affected sub-tree 
			//heapify(arr, n, largest);
		}
	}

	void heapSort(int *arr, int n)
	{
		// One by one extract an element from heap 
		for (int i = n - 1; i >= 0; i--)
		{
			int curmax = extractMax(arr, i + 1);
			std::swap(arr[i], curmax);
		}
		//printArray(arr, n);
	}

	void printArray(int arr[], int n)
	{
		for (int i = 0; i < n; ++i)
			std::cout << arr[i] << " ";
		std::cout << std::endl << std::endl;
	}

	~D_Heap() {}

};
