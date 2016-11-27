#include <bits/stdc++.h>
using namespace std;

char str[40];
char store[40];
int k;
vector < char > num;
char check[55];

void call_combination  (int index , int pos , int n){
	if (pos == k){
		bool ok = false;
		for (int i = 0; i < k; i++){
			if (store[i]!=check[i]){
				ok = true;
				break;
			}
		}
		if (ok){
			for (int i = 0; i < k; i++){
				check[i] = store[i];
				printf ("%c" , store[i]);
			}
			printf ("\n");
		}
		
		//puts("");
	}
	else{
		int i;
		for (i = index; i <= n - k + pos; i++){ /// in every call pos stay still and i increase;
			store[pos] = num[i];/// in each call we put a number in store array and it will be fixed in
			/// next call (own)
			call_combination (i + 1 , pos + 1 , n);/// recursive call to set the number beside the fixed number;
		}
	}
}

int main (){
	while (scanf ("%s%d" , &str , &k) == 2){
		memset (check , ',' , sizeof (check));
		num.clear();
		int len = strlen  (str);
		for (int i = 0; i < len; i++)
		num.push_back(str[i]);
		sort (num.begin() , num.end());
		call_combination (0 , 0 , len);
	}
}
