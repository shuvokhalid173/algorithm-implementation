#include <bits/stdc++.h>

using namespace std; 

struct bits_ {
	int Set (int n , int pos) {return n = n | (1<<pos);}
	int Reset (int n , int pos) {return n = n & ~ (1<<pos);}
	bool check (int n , int pos) {return (bool) (n & (1<<pos));}
}bit;

const int N = (1<<16);
int dp[N][16]; 
int dist[16][16]; 
int n; 
const int inf = (1<<28); 

int tsp (int asi , int mask) {
	if (mask == (1<<n) - 1) 
		return 0; 
	if (dp[asi][mask] != -1) 
		return dp[asi][mask]; 
	int ans = inf;
	for (int i = 0; i < n; i++) {
		if (!bit.check(mask , i)) {
			ans = min (ans , dist[asi][i] + tsp (i , bit.Set(mask , i)));
		}
	}
	return dp[asi][mask] = ans;
}

int main () {
	cin >> n; 
	for (int i = 0; i < n; i++) dist[i][i] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x; 
			cin >> x; 
			dist[i][j] = x; 
			dist[j][i] = x; 
		}
	} 
	memset (dp , -1 , sizeof (dp)); 
	cout << tsp (0 , 0) << endl;
}
