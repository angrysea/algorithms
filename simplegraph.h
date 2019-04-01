#pragma once
#include <ostream>
#include <vector>
#include <list>
#include <stdexcept>

class simple_graph {
private:
	int vertices;
	std::vector<std::vector<int>> adjacent;

public:
	simple_graph(const int vertices) : vertices(vertices), adjacent(vertices) {
	}

	void addEdge(int x, int y) {
		auto & v = adjacent[x];
		for (auto d : v) {
			if (d == y) {
				return;
			}
		}
		v.push_back(y);
	}

	void clearEdge(int x, int y) {
		if (x > vertices - 1) {
			return;
		}
		auto & v = adjacent[x];
		for (auto i = 0; i < v.size(); ++i) {
			if (v[i] == y) {
				v.erase(v.begin() + i);
			}
		}
	}

	bool hasEdge(int x, int y) {
		if (x < vertices) {
			for (auto i : adjacent[x]) {
				if (i == y) {
					return true;
				}
			}
		}
		return false;
	}

	void breath_first_search(int s) {
		bool * visited = new bool[vertices];
		for (int i = 0; i < vertices; i++) {
			visited[i] = false;
		}
		visited[s] = true;

		std::list<int> queue;
		queue.push_back(s);

		while (!queue.empty()) {
			s = queue.front();
			cout << s << " ";
			queue.pop_front();

			for (auto i : adjacent[s]) {
				if (!visited[i]) {
					visited[i] = true;
					queue.push_back(i);
				}
			}
		}
	}

	int ** getMatrix(int & length, int & width) {
		length = vertices;
		width = 0;

		for (auto v : adjacent) {
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

		for (int i = 0; i < adjacent.size(); ++i) {
			for (int j = 0; j < width; ++j) {
				matrix[i][j] = 0;
			}
			for (auto n : adjacent[i]) {
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
		for (auto v : adjacent) {
			for (auto i : v) {
				std::cout << i << ", ";
			}
			std::cout << std::endl;
		}
	}
};
