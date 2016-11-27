#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
vector < int > G[N] , RG[N]; 
int time__ = 0;
int dtime__[N] , ftime__[N]; 
bool visited[N] , revisited[N]; 
vector < int > vv;
bool taken[N]; 

void dfs (int u) {
	if (visited[u]) {
		return ; 
	}
	visited[u] = 1;
	dtime__[u] = ++time__;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i]; 
		if (!visited[v]) {
			dfs (v);
		}
	}
	ftime__[u] = ++time__;
	vv.push_back(u);
}

void dfs2 (int u) {
	if (revisited[u]) {
		return ; 
	}
	revisited[u] = 1;
	for (int i = 0; i < RG[u].size(); i++) {
		int v = RG[u][i]; 
		if (!revisited[v]) {
			dfs2 (v);
		}
	}
}

void clean_up () {
	memset (visited , 0 , sizeof (visited)); 
	memset (revisited , 0 , sizeof (revisited));
	vv.clear(); 
	for (int i = 0; i < N; i++) {
		G[i].clear (); 
		RG[i].clear ();
	}
}
int main () {
	ios_base::sync_with_stdio (false); 
	cin.tie(); 
	cout.tie();
	int T; 
	cin >> T;
	while (T--) {
		clean_up ();
		int n; cin >> n; 
		int m; cin >> m; 
		for (int i = 0; i < m; i++) {
			int x , y; 
			cin >> x >> y;
			G[x].push_back (y); 
			RG[y].push_back (x);
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs (i);
			}
		}
		reverse (vv.begin() , vv.end());
		int cnt = 0; 
		for (int i = 0; i < vv.size(); i++) {
			if (!revisited[vv[i]]) {
				dfs2 (vv[i]); 
				cnt++;
			}
		}
		cout << cnt;
	}
} 
