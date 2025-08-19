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

#define NMAX 12

int main()
{
    ll n;
    cin>>n;
    ll a[NMAX];
    ll b[NMAX];
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
        b[n-i-1]=a[i];
    }


    ll dp[NMAX][NMAX];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = (a[0] == b[0]) ? 1 : 0;
    for(ll i=1; i<n; i++)
    {
        dp[i][0]=a[i]==b[0] ? 1 : dp[i-1][0];
        dp[0][i]=a[0]==b[i] ? 1 : dp[0][i-1];
    }

    for(ll i=1; i<n; i++)
    {
        for(ll j=1; j<n; j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    //cout<<dp[n-1][n-1]<<endl;

    ll t;
    cin>>t;
    for(ll i=0; i<t; i++)
    {
        ll x;
        cin>>x;
        if(x==1)
        {
            cout<<n-1<<endl;
            continue;
        }
        if(x==n)
        {
            cout<<n-1<<endl;
            continue;
        }
        ll k=dp[x-2][n-1-x];
        ll ans=n-1-k-k;
        cout<<ans<<endl;
    }


}