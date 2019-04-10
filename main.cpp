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
#include "graph.h"
#include "simplegraph.h"
#include "wordbreak.h"

using namespace std;

void results(std::chrono::time_point<std::chrono::high_resolution_clock> start) noexcept {
	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	std::cout << "Total elapsed time  "
		<< std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
		<< " in microseconds." << std::endl;
}

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
	int a[10000];
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
		std::cout << std::endl;
		auto node = b.find(a[i]);
		auto successor = b.tree_successor(node);
		if (node == successor) {
			std::cout << "Error find succeessor " << node->getValue() << std::endl;
		}
		if (successor != nullptr) {
			std::cout << "Find succeessor " << node->getValue() << " is " << successor->getValue() << std::endl;
		}
		std::cout << std::endl;
		i += (max / 20);
		std::cout << std::endl;
	}
	auto node = b.tree_min();
	std::cout << "Find min value " << node->getValue() << std::endl;
	node = b.tree_max();
	std::cout << "Find max value " << node->getValue() << std::endl;
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

void testSimpleGraph() {
	simple_graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	g.print();
	cout << endl;

	g.breath_first_search(2);
	cout << endl;

	if (g.hasEdge(2, 3) == true)
		cout << "There is an edge between 3 and 4" << endl;
	else
		cout << "There is no edge between 3 and 4" << endl;

	if (g.hasEdge(1, 3) == true)
		cout << "There is an edge between 2 and 3" << endl;
	else
		cout << "There is no edge between 2 and 3" << endl;

	int length = 0, width = 0;

	int ** m = g.getMatrix(length, width);
	for (auto i = 0; i < length; ++i) {
		for (auto j = 0; j < width; ++j) {
			cout << m[i][j] << ", ";
		}
		cout << endl;
	}

	g.deleteMatrix(m, length, width);
}

void testGraph() {
	graph g(4);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	g.breath_first_search(2);
	g.print();
	cout << endl;

	if (g.hasEdge(2, 3) == true)
		cout << "There is an edge between 3 and 4" << endl;
	else
		cout << "There is no edge between 3 and 4" << endl;

	if (g.hasEdge(1, 3) == true)
		cout << "There is an edge between 2 and 3" << endl;
	else
		cout << "There is no edge between 2 and 3" << endl;
}

int test_word_break() {
	word_break wb;

	const string dictionary[] = { 
		"mobile", "samsung", "sam", "sung", "man", "mango", 
		"icecream","and", "go", "i", "love", "ice", "cream" 
	};

	int n = sizeof(dictionary) / sizeof(dictionary[0]);
	for (int i = 0; i < n; i++) {
		wb.insert_word(dictionary[i]);
	}

	cout << "First DP Test: is ";
	if(wb.break_word_dp("iloveicecreamandmango"))
		cout << "pass."<< endl;
	else
		cout << "fail." << endl;

	cout << "\nSecond DP Test: ";
	if (wb.break_word_dp("ilovesamsungmobile"))
		cout << "pass." << endl;
	else
		cout << "fail." << endl;

	cout << "\nThird DP Test: ";
	if (wb.break_word_dp("thiswillfail"))
		cout << "pass." << endl;
	else
		cout << "fail." << endl;

	cout << "First Test:\n";
	wb.break_word("iloveicecreamandmango");

	cout << "\nSecond Test:\n";
	wb.break_word("ilovesamsungmobile");
	return 0;
}

int main() {
	test_word_break();
	//testGraph();
	//testrbt();
	//testMergeSort();
}