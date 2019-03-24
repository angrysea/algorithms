#pragma once
#include <iostream>
#include <vector>

using namespace std;

/*
Binary math in an array
1 0 0 1 1 0
1 0 1 0 1 1
*/

class BinaryArray {
private:
	vector<int> a;

public:
	BinaryArray(int arr[], unsigned int size) : a(size) {
		std::copy(arr, arr + size, a.begin());
	}

	BinaryArray(unsigned int size, int def) : a(size, def) {
	}

	int size() {
		return a.size();
	}

	unique_ptr <BinaryArray> add(BinaryArray & rhs) {
		auto size = rhs.size() > a.size() ? rhs.size() + 1 : a.size() + 1;

		unique_ptr <BinaryArray> result(new BinaryArray(size, 0));
		for (int i = a.size()-1; i >= 0; i--) {
			int x = rhs.a[i] + a[i] + result->a[i + 1];

			if (x == 3) {
				result->a[i+1] = 1;
				result->a[i] = 1;
			}
			else if (x == 2) {
				result->a[i+1] = 0;
				result->a[i] = 1;
			}
			else if (x == 1) {
				result->a[0+1] = 1;
			}
		}
		return result;
	}

	void print() {
		for (auto i : a) {
			cout << i << " ";
		}
		cout << endl;
	}
};