#pragma once

#include <iostream>
#include <vector>

using namespace std;

class InsertionSort {
private:
	vector<int> array;

public:
	InsertionSort(int a[], int size) {
		array.resize(size);
		std::copy(a, a+6, array.begin());
	}

	void sortascending() {
		for (auto j = 1; j < array.size(); ++j) {
			auto key = array[j];
			auto i = j - 1;
			while (i >= 0 && array[i] > key) {
				array[i + 1] = array[i];
				--i;
			}
			array[i + 1] = key;
		}
	}

	void sortdescending() {
		for (auto j = 1; j < array.size(); ++j) {
			auto key = array[j];
			auto i = j - 1;
			while (i >= 0 && array[i] < key) {
				array[i + 1] = array[i];
				--i;
			}
			array[i + 1] = key;
		}
	}

	int linearsearch(int find) {
		for (int i = 0; i < array.size(); ++i) {
			if (array[i] == find) {
				return find;
			}
		}
		return -1;
	}

	void print() {

		for (int i = 0; i < array.size(); ++i) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
};