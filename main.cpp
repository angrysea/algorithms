#include <iostream>
#include <string>
#include <functional>
#include <memory>
#include <chrono>

#include "InsertionSort.h"
#include "AddBinary.h"
#include "MergeSort.h"
#include "utils.h"
#include "rbtree.h"

void results(std::chrono::time_point<std::chrono::high_resolution_clock> start) noexcept {
	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	std::cout << "Total elapsed time  "
		<< std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
		<< " in microseconds." << std::endl;
}

int testWordBreak();

void testMergeSort() {
	int ms[] = { 2, 4, 5, 7, 1, 2, 3, 6 };
	MergeSort test(ms, 8);
	test.sort();
	test.print();
}

void testInsertionSort() {
	int a[] = { 5, 2, 4, 6, 1, 3 };
	InsertionSort is(a, 6);
	int find = 0;
	int result = 0;
	while (result > -1) {
		result = is.linearsearch(++find);
		cout << result << " ";
	}
	cout << endl;
}

void testAddBinary() {
	int ar[] = { 1,1,1,1 };
	int al[] = { 0,1,0,1 };

	BinaryArray lhs(al, 4);
	BinaryArray rhs(ar, 4);
	auto sum = lhs.add(rhs);
	sum->print();

}

void testrbt()
{
	int a[100000];
	number_enerator(sizeof(a) / sizeof(int), &a[0]);

	rbtree<int> b;
	for (auto i : a) {
		b.insert(i);
	}

	//b.printLevelOrder();
	int max = sizeof(a) / sizeof(int);
	for (auto i = 0; i < max; ) {
		auto x{ 0 };
		auto start = std::chrono::high_resolution_clock::now();
		auto result = b.find(a[i], x);
		if (result) {
			results(start);
			std::cout << "Find results for (" << a[i] << ") result = " << x;
		}
		else {
			std::cout << "Find failed!! for " << a[i];
		}
		i += (max/20);
		std::cout << std::endl;
	}

}

void testHash()
{

	auto hash = hash_str("Hash me 1");
	auto hash2 = hash_str("Another Hash me 2");

	std::cout << "Hash 1: " << hash << " Hash 2: " << hash2 << std::endl;

	int a[]{ 10,4,7,11,3,2,12,9,5,7 };
	for (auto v : a)
		std::cout << v << ",";
	std::cout << std::endl;

	for (int i = 9; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j + 1] < a[j])
			{
				swap(a[j + 1], a[j]);
			}
		}
		for (auto v : a)
			std::cout << v << ",";
		std::cout << std::endl;
	}
}

int main() {

	testrbt();
	//testMergeSort();
}