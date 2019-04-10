#pragma once
#include <iostream> 
using namespace std;


class trie_node {
public:
	static const int ALPHABET_SIZE = 26;
	trie_node() {
		is_end_of_word = false;
		for (int i = 0; i < ALPHABET_SIZE; ++i) {
			children[i] = nullptr;
		}
	}

	trie_node * children[ALPHABET_SIZE];
	bool is_end_of_word;
};



class trie {
public:
	trie() {
		root = new trie_node;
	}

	~trie() {
		delete root;
	}

	void insert(string word) {
		trie_node * crawler = root;

		for (int i = 0; i < word.length(); i++) {
			int index =word[i] - 'a';
			if (!crawler->children[index]) {
				crawler->children[index] = new trie_node;
			}
			crawler = crawler->children[index];
		}
		crawler->is_end_of_word = true;
	}

	bool search(string word) {
	trie_node *	crawler = root;

		for (int i = 0; i < word.length(); ++i) {
			int index = word[i] - 'a';
			if (!crawler->children[index]) {
				return false;
			}
			crawler = crawler->children[index];
		}
		return (crawler != nullptr && crawler->is_end_of_word);
	}

private:
	trie_node * root;
};