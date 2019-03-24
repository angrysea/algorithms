#pragma once
#include <string>
#include <algorithm>
#include <random>

constexpr unsigned primeA = 54059;
constexpr unsigned primeB = 76963;
constexpr unsigned primeC = 86969;
constexpr unsigned seed = 31;

unsigned hash_str(const std::string & s) noexcept
{
	unsigned hash{ seed };
	for (auto c : s) {
		hash = (hash * primeA) ^ (c * primeB);
	}
	return hash; // or return h % C;
}


void swap(int & x, int & y)
{
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
	//int temp=x;
	//x=y;
	//y=temp;
}

void number_enerator(int size, int * input) {
	std::mt19937 eng{ std::random_device{}() };
	std::uniform_int_distribution<int> uid{ 0, size * 10 };
	for (int i = 0; i < size; ++i) {
		input[i] = uid(eng);
	}
}

