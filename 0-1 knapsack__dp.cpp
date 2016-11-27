#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
 
#define stream istringstream
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define repv(i,n) for(int i=n-1; i>=0; i--)
#define repl(i,n) for(int i=1; i<=(int)n; i++)
#define replv(i,n) for(int i=n; i>=1; i--)
 
 
#define INF (1<<28)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair
 
 
#define sdi(x) scanf("%d",&x)
#define sdii(x,y) scanf("%d%d",&x,&y)
#define SDs(x) scanf("%s",x)
#define uu first
#define vv second
 
using namespace std;

#define limit 1000
long long weight[limit];
long long cost[limit];
long long capacity;
long long n;
long long save[limit][limit];
long long knapsack (long long index , long long w){
	long long lav1;
	long long lav2;
	if (index == n + 1){
		return 0;
	}
	if (save[index][w]!=-1){
		return save[index][w];
	}
	if (w + weight[index] <= capacity){
		lav1 = cost[index] + knapsack (index + 1 , w + weight[index]);
	}
	else{
		lav1 = 0;
	}
	lav2 = knapsack (index + 1 , w);
	long long ans;
	ans = max (lav1 , lav2);
	save[index][w] = ans;
	return save[index][w];
}
int main (){
	memset (save , -1 , sizeof (save));
	cin >> n;
	cin >> capacity;
	long long i;
	for (i = 0; i < n; i++){
		cin >> weight[i] >> cost[i];
	}
	cout << knapsack (0 , 0) << endl;
}
