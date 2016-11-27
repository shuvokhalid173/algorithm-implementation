#include <bits/stdc++.h>

using namespace std;

string a , b;
int dp[123][123];
vector < char > sol; 

int gooo (int i , int j) {
	if (i >= a.size() || j >= b.size())  
		return 0; 
	if (dp[i][j] != -1) return dp[i][j];
	int ret = -124; 
	ret = max (ret , gooo (i + 1 , j)); 
	ret = max (ret , gooo (i , j + 1)); 
	if (a[i] == b[j]) 
		ret = max (ret , 1 + gooo (i + 1 , j + 1)); 
	return dp[i][j] = ret;
}

void goooo (int i , int j) {
	if (i >= a.size() || j >= b.size()) 
		return ; 
	if (a[i] == b[j]) {
		sol.push_back(a[i]); 
		goooo (i + 1 , j + 1);
	}
	else {
		if (dp[i + 1][j] > dp[i][j + 1]) {
			goooo (i + 1 , j);
		}
		else {
			goooo (i , j + 1);
		}
	}
}

int main () {
	memset (dp , -1 , sizeof (dp)); 
	cin >> a >> b; 
	cout << gooo (0 , 0);
	cout << endl; 
	goooo (0 , 0);
	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i];
	}
	cout << endl;
}
