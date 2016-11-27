/// (KMP) Knuth Morris Pratt algorithm implementation in C language ///

#include <bits/stdc++.h>
using namespace std;

int failure_table[10000];

void failure_function (string pattern) {
	int length_p = pattern.size();
	int index = 1 , pslength = 0;
	failure_table[0] = 0;
	while (index < length_p) {
		if (pattern[index] == pattern[pslength])
			failure_table[index++] = ++pslength;
		else {
			if (pslength) pslength = failure_table[pslength - 1];
			else failure_table[index++] = 0;
		}
	}
}

void KMP_matcher (string text , string pattern) {
	int length_pt = pattern.size();
	int length_tx = text.size();
	int index_t , index_p;
	index_t = index_p = 0;
	while (index_t < length_tx) {
		if (text[index_t] == pattern[index_p]) {
			index_t++; index_p++;
			if (index_p == length_pt) 
				printf ("A match is found at index %d \n" , index_t - length_pt);
		}
		else {
			if (index_p) index_p = failure_table[index_p - 1];
			else index_t++;
		}
	}
}

int main () {
	string text , pattern;
	cin >> text >> pattern;
	failure_function (pattern);
	KMP_matcher (text , pattern);
}
