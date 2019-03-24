#pragma once
#include <vector>
#include<iostream>

using namespace std;


class Triple {
private:
	int maxLeft = 0;
	int maxRight = 0;
	int total = 0;

public:
	Triple(int maxLeft, int rightSum, int total) : maxLeft(maxLeft), maxRight(maxRight), total(total) {
	}

	int getNaxLeft() {
		return maxLeft;
	}

	int getMaxRight() {
		return maxRight;
	}

	int getTotal() {
		return total;
	}
};

class MaxSubarray {
private:
	vector<int> arr;

public:
	MaxSubarray(int data[], unsigned int size) : arr(size) {
		copy(data, data + size, arr.begin());
	}

	unique_ptr <Triple> findMaxCrossingSubarray(int low, int mid, int high) {
		int sum = 0;
		int leftSum = INT_MAX;
		int maxLeft = -1;
		for (int i = mid; i >= low; --i) {
			sum += arr[i];
			if (sum > leftSum) {
				leftSum = sum;
				maxLeft = i;
			}
		}

		sum = 0;
		int rightSum = INT_MIN;
		int maxRight = -1;

		for (int i = low; i < high; ++i) {
			sum += arr[i];
			if (sum > rightSum) {
				rightSum = sum;
				maxRight = i;
			}
		}
		return unique_ptr <Triple>(new Triple(maxLeft, maxRight, leftSum + rightSum));
	}

	void print() {
		for (auto i : arr) {
			cout << i << " ";
		}
		cout << endl;
	}
};
