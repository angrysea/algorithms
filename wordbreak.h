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

	bool break_word_dp(const string str) {
		const int size = str.size();
		if (size == 0) {
			return true;
		}

		bool * wb = new bool[size + 1];
		memset(wb, 0, sizeof(wb));

		for (int i = 1; i <= size; i++) {
			if (wb[i] == false && is_word(str.substr(0, i))) {
				wb[i] = true;
			}

			if (wb[i] == true) {
				if (i == size) {
					return true;
				}

				for (int j = i + 1; j <= size; j++) {
					if (wb[j] == false && is_word(str.substr(i, j - i))) {
						wb[j] = true;
					}
					if (j == size && wb[j] == true) {
						return true;
					}
				}
			}
		}
		return false;
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