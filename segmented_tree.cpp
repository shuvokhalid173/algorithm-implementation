#include <bits/stdc++.h>

using namespace std; 

const int N = 1234; 
int arr[N]; 
int seg[N * 3]; 

void construct (int n , int left , int right) {
	if (left == right) {seg[n] = arr[left]; return ;}
	int ll = n * 2; 
	int rr = ll + 1; 
	int mid = (left + right) / 2; 
	construct (ll , left , mid); 
	construct (rr , mid + 1 , right); 
	seg[n] = seg[ll] + seg[rr]; 
}

int get_sum (int n , int left , int right , int start , int end) {
	if (left > end || right < start) return 0; 
	if (left >= start && right <= end) return seg[n]; 
	int ll = n * 2; 
	int rr = ll + 1; 
	int mid = (left + right) / 2; 
	int left_p = get_sum (ll , left , mid , start , end); 
	int right_p = get_sum (rr , mid + 1 , right , start , end); 
	return left_p + right_p; 
}

void update_value (int n , int left , int right , int index , int value) {
	if (left > index || right < index) return ; 
	if (left >= index && right <= index) {seg[n] = value; return ;} 
	int ll = n * 2; 
	int rr = ll + 1; 
	int mid = (left + right) / 2;
	update_value (ll , left , mid , index , value); 
	update_value (rr , mid + 1 , right , index , value); 
	seg[n] = seg[ll] + seg[rr]; 
}

int main () {
	ios_base::sync_with_stdio (0); 
	cin.tie(); cout.tie(); 
	int n; cin >> n; 
	for (int i = 1; i <= n; i++) 
		cin >> arr[i]; 
	construct (1 , 1 , n); 
	int noq; cin >> noq; 
	for (int i = 0; i < noq; i++) {
		int ind , upd ; 
		cin >> ind >> upd; 
		update_value (1 , 1 , n , ind , upd); 
		int llf , lri; 
		cin >> llf  >> lri; 
		cout << get_sum (1 , 1 , n , llf , lri) << endl;
	}
}

