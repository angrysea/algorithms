#pragma once
#include <string>
#include <iostream>

#include "trie.h"

using namespace std;

class word_break {
public:

	void break_word(string str) {
		break_word(str, str.size(), "");
	}

	void break_word(string str, int n, string result) {
		for (int i = 1; i <= n; i++) {
			string prefix = str.substr(0, i);
			if (is_word(prefix)) {
				if (i == n) {
					result += prefix;
					cout << result << endl;
					return;
				}
				break_word(str.substr(i, n - i), n - i, result + prefix + " ");
			}
		}
	}

	bool is_word(const string & word) {
		return dictionary.search(word);
	}

	void insert_word(const string & word) {
		dictionary.insert(word);
	}

private:
	trie dictionary;
};