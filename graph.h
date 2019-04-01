#pragma once
#include <ostream>
#include <vector>
#include <list>
#include <stdexcept>

class vertex {
public:
	enum { white, gray, black };

	vertex() : color(white), distance(0), predecessor(-1) {
	}

	auto operator[](int index) {
		if (index < adjacent.size()) {
			return adjacent[index];
		}
		throw new std::out_of_range("Index out of range!");
	}

	auto at(int index) {
		if (index < adjacent.size()) {
			return adjacent.at(index);
		}
		throw new std::out_of_range("Index out of range!");
	}

	void push_back(int value) {
		adjacent.push_back(value);
	}

	auto begin() {
		return adjacent.begin();
	}

	auto end() {
		return adjacent.end();
	}

	auto size() {
		return adjacent.size();
	}

	auto erase(std::vector<int>::const_iterator where) {
		return adjacent.erase(where);
	}

private:
	int color;
	int distance;
	int predecessor;
	std::vector<int> adjacent;
};

class graph {
private:
	std::vector<vertex> vertices;

public:
	graph(const int size) : vertices(size) {
	}

	void addEdge(int x, int y) {
		auto & v = vertices[x];
		for (auto d : v) {
			if (d == y) {
				return;
			}
		}
		v.push_back(y);
	}

	void clearEdge(int x, int y) {
		if (x > vertices.size() - 1) {
			throw new std::out_of_range("Index out of range!");
		}
		auto & v = vertices[x];
		for (auto i = 0; i < v.size(); ++i) {
			if (v[i] == y) {
				v.erase(v.begin() + i);
			}
		}
	}

	bool hasEdge(int x, int y) {
		if (x > vertices.size() - 1) {
			return false;
		}

		for (auto i : vertices[x]) {
			if (i == y) {
				return true;
			}
		}
		
		return false;
	}



	void breath_first_search(int s) {
	}

	int ** getMatrix(int & length, int & width) {
		length = vertices.size();
		width = 0;

		for (auto v : vertices) {
			for (auto i : v) {
				if (i > width) {
					width = i;
				}
			}
		}

		width++;
		int ** matrix = new int*[length];
		for (int i = 0; i < length; ++i) {
			matrix[i] = new int[width];
		}

		for (int i = 0; i < vertices.size(); ++i) {
			for (int j = 0; j < width; ++j) {
				matrix[i][j] = 0;
			}
			for (auto n : vertices[i]) {
				matrix[i][n] = 1;
			}
		}
		return matrix;
	}

	void deleteMatrix(int ** matrix, int & length, int & width) {
		for (int i = 0; i < length; ++i) {
			delete matrix[i];
		}
		delete matrix;
	}

	void print() {
		for (auto v : vertices) {
			for (auto i : v) {
				std::cout << i << ", ";
			}
			std::cout << std::endl;
		}
	}
};
