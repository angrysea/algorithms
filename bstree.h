#pragma once
#include <iostream>
#include <functional>
#include <memory>
#include <fstream>
#include <chrono>

#include "treenode.h"

template<class T>
class bstree {
public:
	enum { black, red };

	bstree() noexcept = default;

	~bstree() {
		delete head;
	}

	treenode<T> * insert(T entry) {
		if (head == nullptr) {
			head = new treenode<T>();
			head->setValue(entry);
			head->set_as_head();
			return head;
		}
		return head->insert(entry);
	}

	bool find(T entry, T & result) {
		return head->find(entry, result);
	}

public:
	void printLevelOrder()
	{
		int h = treenode<T>::height(head);
		int i;
		for (i = 1; i <= h; i++) {
			head->printLevel(i, " root ");
			cout << std::endl;
		}
	}

protected:
	treenode<T> * head;
};
