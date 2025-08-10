#include <iostream>
#include<cmath>
#include <vector>
#include <queue>
#include<algorithm>
#include <cstring>
#include<deque>
#include <tuple>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,bool> tll;

#define NMAX 1122


int main()
{
    ll n;
    ll a[NMAX];
    ll q;
    ll l[NMAX];
    ll dp[100005];
    memset(dp, 0, sizeof(dp)); // Initialize dp array to 0
    cin>>n;
    for (ll i=0;i<n;i++)
    {
        cin>>a[i];
        dp[a[i]] = 1; // Initialize each number as a divisor of itself

    }
    cin>>q;
    for (ll i=0;i<q;i++)
    {
        cin>>l[i];
    }
    sort(a,a+n);
    
    for (ll i=1;i<NMAX;i++)
    {
        if(a[0]==1&&i!=1)
            dp[i]++;
        for( ll j=2;j*j<=i;j++)
        {
            if (i%j==0)
            {
                dp[i]+=dp[j];
                if (j!=i/j)
                {
                    dp[i]+=dp[i/j];
                }
            }
            
        }
    }
    for (ll i=0;i<q;i++)
    {
        cout<<dp[l[i]]<<" ";
    }

}