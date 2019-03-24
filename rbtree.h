#pragma once
#include <iostream>

#include "bstree.h"
#include "treenode.h"

template<class T>
class rbtree : public bstree<T> {
public:
	treenode<T> *  insert(T entry) {
		treenode<T> * x = bstree<T>::insert(entry);
		if (x == nullptr) {
			return x;
		}

		x->color = treenode<T>::red;
		while (x != bstree<T>::head && x->parent->color == treenode<T>::red) {
			if (x->parent == x->parent->parent->left) {
				auto y = x->parent->parent->right;
				if (y != nullptr && y->color == treenode<T>::red) {
					x->parent->color = treenode<T>::black;
					y->color = treenode<T>::black;
					x->parent->parent->color = treenode<T>::red;
					x = x->parent->parent;
				}
				else {
					if (x == x->parent->right) {
						x = x->parent;
						left_rotate(x);
					}
					x->parent->color = treenode<T>::black;
					x->parent->parent->color = treenode<T>::red;
					right_rotate(x->parent->parent);
				}
			}
			else {
				auto y = x->parent->parent->left;
				if (y != nullptr && y->color == treenode<T>::red) {
					x->parent->color = treenode<T>::black;
					y->color = treenode<T>::black;
					x->parent->parent->color = treenode<T>::red;
					x = x->parent->parent;
				}
				else {
					if (x == x->parent->left) {
						x = x->parent;
						right_rotate(x);
					}
					x->parent->color = treenode<T>::black;
					x->parent->parent->color = treenode<T>::red;
					left_rotate(x->parent->parent);
				}
			}
		}
		bstree<T>::head->color = treenode<T>::black;
		return x;
	}

private:	
	//				    15
	//				   /  \
	//                10   25
	//                     / \
	//                    20  30               
	// 1) y = 25
	//				    25
	//				   /  \
	//                15   20
	//                / \      
	//               10 20                 
	// 
	void left_rotate(treenode<T> * x) {
		treenode<T> * y = x->right;
		x->right = y->left;

		if (y->left != nullptr) {
			y->left->parent = x;
		}

		y->parent = x->parent;

		if (x->parent == nullptr) {
			bstree<T>::head = y;
		}
		else if (x == x->parent->left) {
			x->parent->left = y;
		}
		else {
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}

	void right_rotate(treenode<T> * x) {
		treenode<T> * y = x->left;
		x->left = y->right;

		if (y->right != nullptr) {
			y->right->parent = x;
		}

		y->parent = x->parent;

		if (x->parent == nullptr) {
			bstree<T>::head = y;
		}
		else if (x == x->parent->right) {
			x->parent->right = y;
		}
		else {
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}
};