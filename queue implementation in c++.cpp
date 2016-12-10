///In the name of ALLAH  ///

#include <bits/stdc++.h>

using namespace std;

#define new_node (link*)malloc(sizeof(link));

class MyQueue {
	private:
		struct link {
			int val; 
			link *next;
		};
		link *first = NULL , *last = NULL;
		int size = 0;
	public:
		void Push (int v) {
			size++;
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
		int Front () {
			link *x = first;
			return x->val;
		}
		
		void Pop () {
			if (size > 0) size--;
			link *x = first->next;
			first = x;
		}
		
		void Print () {
			link *x = first;
			while (x != NULL) {
				cout << x->val << endl;
				x = x->next;
			}
		//	cout << x->val << endl;
		}
		
		bool Search (int v) {
			link *x = first;
			while (x != NULL) {
				if (x->val == v) {
					return 1;
				}
				x = x->next;
			}
			return 0;
		}
		
		void Remove (int v) {
			link *x = first; 
			link *y = first->next;
			
			while (y != NULL) {
				if (y->val == v){
					size--;
					x->next = y->next;
				}
				x = x->next;
				y = y->next;
			}
		}
		
		int Size () {
			return size;
		}
		bool isEmpty () {
			return Size () == 0;
		}

};

int main () {
    MyQueue ST;
	int n; cin >> n; 
	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x; 
		ST.Push(x);
	} 	
	while (1) {
		string ss;
		cin >> ss;
		if (ss == "push") {
			int x;
			cin >> x;
			ST.Push(x);
		}
		else if (ss == "pop") {
			ST.Pop();
		}
		else if (ss == "remove") {
			int x; 
			cin >> x;
			ST.Remove(x);
		}
		else if (ss == "print"){
			ST.Print();
		}
		else if (ss == "size" ) {
			cout << ST.Size() << endl;
		}
		else if (ss == "isEmpty") {
			cout << ST.isEmpty () << endl;
		}
		else if (ss == "front") {
			cout << ST.Front() << endl;
		}
		else {
			cout << "wrong operation" << endl;
		}
	}
}
