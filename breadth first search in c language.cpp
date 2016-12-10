///In the name of ALLAH  ///

/**
	breadth first search 
	implementation in c language 
	firstly i implement the queue data structure using linked list
	then i make a structure of queue instead of class for my coding efficiency 
**/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#define new_node (link*)malloc(sizeof(link));

struct MyQueue {
		struct link {
			int val; 
			link *next;
		};
		link *first = NULL , *last = NULL;
		int size = 0;
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
				///cout << x->val << endl;
				printf ("%d\n" , x->val);
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

int graph[123][123]; 
bool visited[123] ; 
MyQueue Q; 
int level[123]; 
int n , m;

void bfs (int s) {
	Q.Push(s); 
	level[s] = 0; 
	visited[s] = 1; 
	while (!Q.isEmpty()) {
		int u = Q.Front();
		int i; 
		for (i  = 0; i < n; i++) {
			if (graph[u][i] == 1 && !visited[i] ) {
				visited[i] = 1;
				level[i] = level[u] + 1; 
				Q.Push(i); 
			}
		}
		Q.Pop();
	}
}

void init () {
	int i , j;
	for (i = 0; i < 123; i++) {
		for (j = 0; j < 123; j++) {
			graph[i][j] = 0;
		}
	}
}

int main () {
	init();
	puts("how many nodes ? ---");
	scanf ("%d" , &n);
	puts("how many edges ? ---");
	scanf ("%d" , &m);
	int i; 
	puts(""); 
	puts("show their connection ... x y means there is a path bet'n  x and y .. ");
	for (i = 0; i < m; i++) {
		int x , y; 
		scanf ("%d%d" , &x , &y);
		graph[x][y] = 1; 
		graph[y][x] = 1;
	}
	puts("");
	puts("source node  ? ---");
	int s; scanf ("%d" , &s);
	bfs (s); 
	puts("");
	for (i = 0; i < n; i++) {
		printf ("the distance between %d to %d is %d\n" , s , i , level[i]);
	}
}
