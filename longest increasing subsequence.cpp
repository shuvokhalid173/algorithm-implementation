#include <bits/stdc++.h>
using namespace std;

#define sset(x,y) memset(x,y,sizeof(x))
int sq[100];
int n;
int dp[100];
int direction[100]; // will be used for printing solution ;

int LIS (int v){
	if (dp[v]!=-1) return dp[v]; // avoid calculating same state twice;
	int mx = 0 , i;
	for (i = v + 1; i < n; i++){ // always take next value from the starting value;
		if (sq[i] > sq[v]){  // next value must be bigger than the previous;
			if (mx < LIS (i)){// finding the maximum number of value 
				mx = LIS (i); // which satisfy LIS with the starting value;
				direction[v] = i;// save printing direction in (direction) array;
			}
		}
	}
	dp[v] = 1 + mx; return dp[v]; // save and return 
}

int main (){
	sset(dp,-1);sset(direction,-1); // intialize (dp) and (direction) array with (-1);
	cin >> n;
	for (int i = 0; i < n; i++)
	cin >> sq[i];
	int mx_ind , mx_val = 0;
	for (int i = 0; i < n; i++){
		printf ("Longest subsequence of %d is %d\n" , sq[i] , LIS (i));
		if (mx_val < LIS (i)){
			mx_val = LIS (i);
			mx_ind = i;
		}
	}puts("");
	//cout << mx_ind << endl;
	//cout << sq[mx_ind] << endl;;
	while (direction[mx_ind]!=-1){
		cout << sq[mx_ind] << " ";
		mx_ind = direction[mx_ind];
	}
}


