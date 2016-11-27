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
#define spdi(x) printf("%d\n",x)
#define sdii(x,y) scanf("%d%d",&x,&y)
#define SDs(x) scanf("%s",x)
#define uu first
#define vv second

using namespace std;
vector < long long > store;

int main ()
{
    long long test;
    scanf ("%lld" , &test);
    long long t;
    for (t = 1; t <= test; t++)
    {
        long long n;
        scanf ("%lld" , &n);
        if (n <= 9)
            printf ("%lld\n" , n);
        else
        {
            store.clear ();
            long long i;
            for (i = 9; i >= 2; i--)
            {
                while (n % i == 0)
                {
                    store.push_back (i);
                    n /= i;
                }
            }
            if (n == 1)
            {
                sort (store.begin () , store.end ());
                long long j;
                ///cout << "n = " << n << endl;

                for (j = 0; j < store.size (); j++)
                {
                    printf ("%lld" , store[j]);
                }
                printf ("\n");
            }
            else
            {
                printf ("-1\n");
            }
        }
    }
}
