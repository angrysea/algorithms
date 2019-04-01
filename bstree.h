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

	treenode<T> *  find(T entry) {
		return head->find(entry);
	}

	treenode<T> * tree_min(treenode<T> * node) {
		while (node->left != nullptr) {
			node = node->left;
		}
		return node;
	}

	treenode<T> * tree_min() {
		return tree_min(head);
	}

	treenode<T> * tree_max(treenode<T> * node) {
		while (node->right != nullptr) {
			node = node->right;
		}
		return node;
	}

	treenode<T> * tree_max() {
		return tree_max(head);
	}

	treenode<T> * tree_successor(treenode<T> * node) {
		if (node->right != nullptr) {
			return tree_min( node);
		}
		treenode<T> * p = node->parent;
		while (p != nullptr and node == p->right) {
			node = p;
			p = p->parent;
		}
		return p;
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
