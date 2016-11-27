/// generating combination ///
/// implementation in c++ ///
/**   
                           recursion for n = 3 , r = 2;
                           there will be 3 combination;
                           
                                123
                               /   \
                              /     \
                             /       \
                            /         \
                           1           2
				     	  / \           \
                         /   \           \
                        /     \           \
                       /       \           \
                      12        13         23  
**/


#include <bits/stdc++.h>
using namespace std;

int num[40];
int store[40];
int n , k;

void call_combination  (int index , int pos){
	if (pos == k){
		for (int i = 0; i < k; i++)
		cout << store[i];
		puts("");
	}
	else{
		int i;
		for (i = index; i <= n - k + pos; i++){ /// in every call pos remain still and i increase;
			store[pos] = num[i];/// in each call we put a number in store array and it will be fixed in
			/// next call (own)
			call_combination (i + 1 , pos + 1);/// recursive call to set the number beside the fixed number;
		}
	}
}

int main (){
	scanf ("%d%d" , &n , &k);
	for (int i = 0; i < n; i++)
	cin >> num[i];
	call_combination (0 , 0);
}
