#include <bits/stdc++.h>

using namespace std;

const int N = 12345; 
int dp[N]; 

void game () {
	dp[0] = 0; 
	dp[1] = dp[2] = 1;
	for (int i = 3; i < N; i++) {
		if (!dp[i - 2] || !dp[i - 1]) 
			dp[i] = 1;
		else dp[i] = 0;
	}
}

int dpp[1234]; 
set < int > st; 
set < int > :: iterator it;

void grundy_number () {
	dpp[0] = 0; 
	dpp[1] = 1; 
	for (int i = 2; i < 1234; i++) {
		int x = dpp[i - 1]; 
		int y = dpp[i - 2]; 
		for (int ii = 0; ii <= N; ii++) {
			if (ii != x && ii != y) {
				dpp[i] = ii;
				break;
			}
		}
	}
}

int main () {
	int n;  
	grundy_number (); 
	while (cin >> n) {
		cout << dpp[n] << endl;
	}
}
