#include <bits/stdc++.h>
using namespace std;
char str[100];
int p = 0;
void permutation (int index , int size){
	if (index == size){ /// base case ............................
		cout << ++p << " ";
		for (int i = 0; i < size; i++)
		cout << str[i]; /// printing result ............
		cout << endl;
	}
	else{
		int i;
		for (i = index; i < size; i++){
			swap (str[index] , str[i]); /// swaping value ............
			permutation (index + 1 , size); /// recursion for generating all permutation ..........
			swap (str[index] , str[i]); /// backtrack...........................
	    }
	}
}
int main (){
	cin >> str;
	puts("");
	permutation (0 , strlen (str));
}
