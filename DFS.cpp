#include <bits/stdc++.h>
using namespace std;

vector < int > adjlst[100];
bool visits[100];
int level[100] , parent[100]; /// if parent need then we will use;
queue < int > Q;

void BFS__ (int sr , int dest){
	memset (visits , false , sizeof (visits));
	Q.push(sr);level[sr] = 0;visits[sr] = true;
	while (!Q.empty()){
		int fst = Q.front() , i;
		for (i = 0; i < adjlst[fst].size(); i++){
			int nxt = adjlst[fst][i]; /// asign first connected node with root into (nxt);
			if (!visits[nxt]){ /// if not visited;
				visits[nxt] = true; /// make visited;
				level[nxt] = level[fst] + 1;
				parent[nxt] = level[fst];/// if need ///
				Q.push(nxt); /// push on queue for processing
			}
		}
		Q.pop(); /// after finishing one node's processing pop it from queue;
	}
	cout << "the distance from " << sr << " to " << dest << " is " << level[dest] << endl;
}
/// driver function for above ////
int main (){
	int nod , eg;
	cin >> nod >> eg;
	for (int i = 1; i <= eg; i++){
		int x , y;
		cin >> x >> y;
		adjlst[x].push_back (y);
		adjlst[y].push_back (x);
	}
	int sr , dest;
	cin >> sr >> dest;
	BFS__ (sr , dest);
}
