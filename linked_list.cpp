#include <bits/stdc++.h>

using namespace std;

struct link {
	int val; 
	link *next;
};

#define new_node (link*)malloc(sizeof(link));

link *first = NULL , *last = NULL;

void push_ (int v) {
	link *pp = new_node;
	pp->val = v;
	pp->next = NULL;
	if (first == NULL) {
		first = pp;
		last = pp;
	}
	else {
		last->next = pp;
		last = pp;
	}
}

int front_ () {
	link *x = first;
	return x->val;
}

void pop_ () {
	link *x = first->next;
	first = x;
}

void print () {
	link *x = first;
	while (x != NULL) {
		cout << x->val << endl;
		x = x->next;
	}
//	cout << x->val << endl;
}

bool search (int v) {
	link *x = first;
	while (x != NULL) {
		if (x->val == v) {
			return 1;
		}
		x = x->next;
	}
	return 0;
}

void remove (int v) {
	link *x = first; 
	link *y = first->next;
	
	while (y != NULL) {
		if (y->val == v){
			x->next = y->next;
		}
		x = x->next;
		y = y->next;
	}
}

int main () {
	for (int i = 0; i < 4; i++) push_ (i);
	print();
	int n; cin >> n; 
	remove (n); 
	print();
}
