/// LCS (longest common subsequence) implementation in C language ....
/**
   there are (n*m) possible input 
   each input is processed in O(1) complexity (constant time)
   so the total complexity is O(n*m);
**/
#include <stdio.h> 
#include <string.h>

const int N = 1234;
int dp[N][N];
char str1[N] , str2[N];
int len1 , len2;

int max (int a , int b) {
	return a > b ? a : b;
}

int lcs (int i , int j) {
	if (i == len1 || j == len2) return 0; /// jodi index string er baire chole jay taile return 0;
	if (dp[i][j] != -1) return dp[i][j]; /// no need to repeat same calculation;
	int mx = 0;
	mx = max (mx , lcs (i + 1 , j)); /// go through one side;
	mx = max (mx , lcs (i , j + 1)); /// go through another side;
	if (str1[i] == str2[j])  /// if we find same character between two string;
	    mx = max (mx , 1 + lcs (i + 1 , j + 1)); /// then go through both side;
	dp[i][j] = mx; /// save the maximum value;
	return dp[i][j]; /// return the value;
}

int main () {
	for (int i = 0; i < N; i++) 
	    for (int j = 0; j < N; j++)
	        dp[i][j] = -1;
	scanf ("%s%s" , &str1 , &str2);
	len1 = strlen (str1);
	len2 = strlen (str2);
	printf ("%d\n" , lcs (0 , 0));
}
