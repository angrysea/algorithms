#pragma once
#include <vector>
#include<iostream>

using namespace std;

class MergeSort
{
private:
	vector<int> arr;

public:
	MergeSort(int data[], unsigned int size) : arr(size) {
		copy(data, data + size, arr.begin());
	}

	void merge(int left, int middle, int right) {
		int sizeleft = middle - left + 1;
		int sizeright = right - middle;
		vector<int> leftarray(arr.begin() + left, arr.begin() + middle + 1);
		vector<int> rightarray(arr.begin() + (middle+1), arr.begin() + (right+1));
		
		for (int k = left, i = 0, j = 0; k < right+1; ++k) {
			if (i < sizeleft && j < sizeright) {
				if (leftarray[i] <= rightarray[j]) {
					arr[k] = leftarray[i];
					++i;
				}
				else {
					arr[k] = rightarray[j];
					++j;
				}
			}
			else if (i < sizeleft) {
				arr[k] = leftarray[i];
				++i;
			}
			else if (j < sizeright) {
				arr[k] = rightarray[j];
				++j;
			}
		}
	
	}

	void mergeSort(int left, int right) {
		if (left < right) {
			int middle = (left + right) / 2;
			mergeSort(left, middle);
			mergeSort( middle + 1, right);
			merge(left, middle, right);
		}
	}

	void sort() {
		mergeSort(0, arr.size()-1);
	}

	void print() {
		for (auto i : arr) {
			cout << i << " ";
		}
		cout << endl;
	}
};

