//// binary search tree implementation in c++ language ///

#include <bits/stdc++.h>

using namespace std;

struct link {
	int val; 
	link *left; 
	link *right;
};

#define new_() (link*)malloc(sizeof(link));
link *parent = NULL; 
link *temp_parent = NULL;

void Insert (int v) {
	link *temp = new_();
	temp->val = v; 
	temp->left = NULL; 
	temp->right = NULL;
	if (parent == NULL) {
		parent = temp;
		temp_parent = temp;
	}
	else {
		link *current_parent;
		temp_parent = parent;
		while (temp_parent != NULL) {
			current_parent = temp_parent;
			if (v < temp_parent->val) 
				temp_parent = temp_parent->left;
			else temp_parent = temp_parent->right;
		}
		if (temp->val < current_parent->val) 
			current_parent->left = temp;
		else current_parent->right = temp;
	}
}


void print__ (link *x) {
	if (x == NULL) return ;
	cout << x->val << endl;
	print__ (x->left); 
	print__ (x->right);
}

int main () {
	int n; cin >> n; 
	for (int i = 0 ; i < n; i++) {
		int x; cin >> x; 
		Insert (x);
	}
	print__ (parent);
}
