#pragma once
#include <ostream>
#include <vector>
#include <list>
#include <stdexcept>

class vertex {
public:
	enum { white, gray, black };

	vertex() : color(white), distance(0), predecessor(nullptr) {
		value = -1;
	}

	vertex(int value) : value(value), color(white), distance(0), predecessor(nullptr) {
	}

	vertex(const vertex & toCopy) {
		value = toCopy.value;
		color = toCopy.white;
		distance = toCopy.distance;
		predecessor = toCopy.predecessor;
		adjacent = adjacent;
	}

	vertex(const vertex && toMove) {
		value = std::move(toMove.value);
		color = std::move(toMove.white);
		distance = std::move(toMove.distance);
		predecessor = std::move(toMove.predecessor);
		adjacent = std::move(adjacent);
	}

	auto operator=(const vertex & toCopy) {
		value = toCopy.value;
		color = toCopy.white;
		distance = toCopy.distance;
		predecessor = toCopy.predecessor;
		adjacent = adjacent;
		return *this;
	}

	auto operator=(const vertex && toMove) {
		value = std::move(toMove.value);
		color = std::move(toMove.white);
		distance = std::move(toMove.distance);
		predecessor = std::move(toMove.predecessor);
		adjacent = std::move(adjacent);
		return *this;
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

	void push_back(vertex * value) {
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

	/*
	auto erase(std::vector<vertex *>::const_iterator where) {
		return adjacent.erase(where);
	}
	*/

	int getColor() {
		return color;
	}

	void setColor(int newValue) {
		color = newValue;
	}

	int getDistance() {
		return distance;
	}

	void setDistance(int newValue) {
		distance = newValue;
	}

	vertex * getPredecessor() {
		return predecessor;
	}

	void setPredecessor(vertex * newValue) {
		predecessor = newValue;
	}

	int getValue() {
		return value;
	}

	void setValue(int newValue) {
		value = newValue;
	}

private:
	int color;
	int distance;
	vertex * predecessor;
	int value;
	std::vector<vertex *> adjacent;
};

class graph {
public:
	graph(const int size) : vertices(size) {
		for (int i = 0; i < size; ++i) {
			vertices[i] = std::move(vertex(i));
		}
	}

	void addEdge(int x, int y) {
		auto & v = vertices[x];
		v.push_back(&vertices[y]);
	}

	/*
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
	*/

	bool hasEdge(int x, int y) {
		if (x > vertices.size() - 1) {
			return false;
		}

		for (auto & i : vertices[x]) {
			if (i->getValue() == y) {
				return true;
			}
		}
		
		return false;
	}

	void breath_first_search(int index) {

		auto & s = vertices[index];
		for (auto & v : vertices) {
			v.setColor(vertex::white);
			v.setDistance(INT32_MAX);
			v.setPredecessor(nullptr);
		}

		s.setColor(vertex::gray);
		s.setDistance(0);
		s.setPredecessor(0);

		std::list<vertex *> queue;
		queue.push_back(&s);

		while (!queue.empty()) {
			auto & u = *(queue.front());
			queue.pop_front();
			for (auto & v : u) {
				if (v->getColor() == vertex::white) {
					v->setColor(vertex::gray);
					v->setDistance(u.getDistance() + 1);
					v->setPredecessor(&u);
					queue.push_back(v);
				}
			}
			u.setColor(vertex::black);
		}
	}

	int ** getMatrix(int & length, int & width) {
		length = vertices.size();
		width = 0;

		for (auto & v : vertices) {
			for (auto & i : v) {
				if (i->getValue() > width) {
					width = i->getValue();
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
			for (auto & n : vertices[i]) {
				matrix[i][n->getValue()] = 1;
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
		for (auto & i : vertices) {
			std::cout << "Index: " << i.getValue();
			std::cout << " color: " << i.getColor();
			std::cout << " distance: " << i.getDistance();
			if (i.getPredecessor() != nullptr) {
				std::cout << " predecessor: " << i.getPredecessor()->getValue();
			}
			std::cout << std::endl;
		}
	}

private:
	std::vector<vertex> vertices;
};
