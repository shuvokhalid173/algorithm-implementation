///In the name of ALLAH  ///

#include <bits/stdc++.h>

using namespace std;

class Trie {
	private :
		struct node {
			bool mark; 
			node *next[27]; 
			node () {
				for (int i = 0; i < 26; i++) {
					next[i] = NULL;
				}
				mark = false;
			}
		};
		node *root = new node (); 
	
	public :
		
		void insert__ (string ss) {
			node *temp = root ;
			int len = ss.size(); 
			for (int i = 0; i < len; i++) {
				int id = ss[i] - 'a'; 
				if (temp->next[id] == NULL) {
					temp->next[id] = new node ();
				}
				temp = temp->next[id];
			}
			temp->mark = true;
		}
		
		bool search__ (string ss) {
			node *temp = root;
			int len = ss.size(); 
			for (int i = 0; i < len; i++) {
				int id = ss[i] - 'a'; 
				if (temp->next[id] == NULL) {
					return false;
				}
				temp = temp->next[id]; 
			}
			return temp->mark;
		}
		
	private :
		void delete_ (node *curr) {
			for (int i = 0; i < 26; i++) {
				if (curr->next[i]) {
					delete_ (curr->next[i]);
				}
			}
			delete (curr); 
		}
	public : 
		void delete__ () {
			delete_ (root);
		} 
};



int main () {
	int n; 
	cin >> n; 
	Trie tt;
	for (int i = 0; i < n; i++) {
		string ssss; 
		cin >> ssss; 
		tt.insert__(ssss);
	}
	int m; 
	cin >> m; 
	for (int i = 0; i < m; i++) {
		string sss; 
		cin >> sss; 
		cout << tt.search__(sss) << endl;
	}
	tt.delete__();
}
