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

void talok()
{
    string s[105];
    ll h,w;
    cin >> h >> w;
    vector<pll> S, W, D;
    for( ll i=1; i<h+1; i++ )
    {
        cin >> s[i];
        for( ll j=0;j<s[i].size();j++ )
        {
            if(s[i][j] == '$')
            {
                S.push_back(pll(i, j+1));
            }
            else if(s[i][j] == '#')
            {
                D.push_back(pll(i, j+1));   
            }

        }
    }

    for(auto j:D)
    {
        ll x = j.first, y = j.second;
        
    }
}


int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        talok();
    }
}