#include <bits/stdc++.h>

using namespace std;

#define limit 1000
int dp[limit];
int n;
int coin[limit];

int coin_change (int taka){
	int i , j;
	dp[0] = 1;
	for (i = 0; i < n; i++){
		for (j = coin[i]; j <= taka; j++){
			dp[j] = dp[j] + dp[j - coin[i]];
		}
	}
	return dp[taka];
}

int main(){
	memset (dp , 0 , sizeof (dp));
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> coin[i];
	}
	int taka;
	cin >> taka;
	cout << "there are " << coin_change (taka) << " ways " << endl;
	main ();
}
