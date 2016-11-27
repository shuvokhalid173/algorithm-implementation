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

int dpp[N]; 
set < int > st; 
set < int > :: iterator it;

int grundy_number (int n) {
	if (n == 0) return 0; 
	if (n == 1) return 1;
	if (dpp[n] != -1) return dpp[n];   
	int x = grundy_number (n - 1); 
	int y = grundy_number (n - 2); 
	for (int i = 0; i < N; i++) {
		if (i != x && i != y) {
			return dpp[n] = i;
		}
	}
}

int main () {
	int n; cin >> n; 
	memset (dpp , -1 , sizeof (dpp)); 
	cout << grundy_number (n) << endl;
	st.clear();
	main ();
}
