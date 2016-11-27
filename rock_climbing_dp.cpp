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
 
 
#define inf (1<<28)
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
int mat[][10]={
    {3, 2, 5},
    {4, -2, 3},
    {1 , 2 ,10,}
};
int dp[10][10];
int r=3,c=3;
int call(int i,int j)
{
    if(i>=0 && i<r && j>=0 && j<c) //if still inside the array.............................
    {      
        if(dp[i][j]!=-1) return dp[i][j];
        int ret=-inf;
                //try to move to 3 direction,also add current cell's point...................
        ret=max(ret,call(i+1,j)+mat[i][j]);
        ret=max(ret,call(i+1,j-1)+mat[i][j]);
        ret=max(ret,call(i+1,j+1)+mat[i][j]);
        return dp[i][j]=ret;
    }
    else return 0; //if outside the array.......
}
int main()
{
//    READ("in");
    mem(dp,-1);
    printf("%d\n",call(0,0));
    return 0;
}

