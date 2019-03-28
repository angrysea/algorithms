#pragma once

template<class T>
class treenode {
public:
	enum { black, red };

	treenode() noexcept = default;

	~treenode() {
		delete right;
		delete left;
	}

	void set_as_head() {
		color = red;
		parent = nullptr;
	}

	treenode<T> * insert(T entry) {
		if (entry == value) {
			return false;
		}

		if (value > entry) {
			if (left != nullptr) {
				return left->insert(entry);
			}
			else {
				left = new treenode<T>();
				left->value = entry;
				left->parent = this;
				return left;
			}
		}
		else if (value < entry) {
			if (right != nullptr) {
				return right->insert(entry);
			}
			else {
				right = new treenode<T>();
				right->value = entry;
				right->parent = this;
				return right;
			}
		}
		return nullptr;
	}

	bool find(T entry, T & result) {
		if (entry == value) {
			result = value;
			return true;
		}

		if (value > entry) {
			if (left != nullptr) {
				return left->find(entry, result);
			}
		}
		else if (value < entry) {
			if (right != nullptr) {
				return right->find(entry, result);
			}
		}
		return false;
	}

	treenode<T> *  find(T entry) {
		if (entry == value) {
			return this;
		}

		if (value > entry) {
			if (left != nullptr) {
				return left->find(entry);
			}
		}
		else if (value < entry) {
			if (right != nullptr) {
				return right->find(entry);
			}
		}
		return nullptr;
	}

	const T & setValue(T & newValue) {
		value = newValue;
		return value;
	}

	const T & getValue() {
		return value;
	}

	static int height(treenode* node)
	{
		if (node == nullptr) {
			return 0;
		}
		else
		{
			int lheight = height(node->left);
			int rheight = height(node->right);

			if (lheight > rheight) {
				return(lheight + 1);
			}
			else {
				return(rheight + 1);
			}
		}
	}

	void printLevel(int level, const char * side)
	{
		if (level == 1) {
			cout << side << value << " ";
		}
		else if (level > 1)
		{
			if (left != nullptr) {
				left->printLevel(level - 1, " left ");
			}
			if (right != nullptr) {
				right->printLevel(level - 1, " right ");
			}
		}
	}

public:
	treenode<T> * parent = nullptr;
	treenode<T> * right;
	treenode<T> * left;
	bool color = red;
private:
	T value = 0;
};