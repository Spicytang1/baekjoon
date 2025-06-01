#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <climits>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppl;


#define NMAX 4400


int main()
{
    ll n,m;
    cin >> n >> m;
    vector<pll> r[NMAX];
    for( ll i=0; i<m; i++ )
    {
        ll a,b,d;
        cin >> a >> b >> d;
        r[a].push_back(pll(b, d));
        r[b].push_back(pll(a, d));

    }
    ll disf[NMAX];
    ll disw[2][NMAX];
    for( ll i=0; i<NMAX; i++ )
    {
        disf[i] = LLONG_MAX;
        disw[0][i] = LLONG_MAX; 
        disw[1][i] = LLONG_MAX;
        
    }

    disf[1] = 0;    
    disw[0][1] = 0;

    priority_queue<pll> pqf;
    priority_queue<ppl> pqw;

    pqf.push(pll(0, 1)); // (distance, node)
    pqw.push(ppl(pll(0,0), 1)); // (distance, node)

    while(!pqf.empty())
    {
        ll cd = -pqf.top().first; 
        ll cn = pqf.top().second; 
        pqf.pop();

        if( disf[cn] < cd )
            continue;

        for( auto j : r[cn] )
        {
            ll nd = cd+2*j.second;
            ll nn= j.first;
            if( disf[nn] > nd )
            {
                disf[nn] = nd;
                pqf.push(pll(-nd, nn));
            }
        }
    }
    while(!pqw.empty())
    {
        ll cd = -pqw.top().first.first; 
        ll cz=pqw.top().first.second;
        ll cn = pqw.top().second; 
        pqw.pop();
        ll weight=cz==0?1:4;
        if( cd>disw[cz][cn] )
            continue;

        for( auto j : r[cn] )
        {
            
            ll nd = cd+weight*j.second;
            ll nn= j.first;
            if( disw[1-cz][nn] > nd )
            {
                disw[1-cz][nn] = nd;
                pqw.push(ppl(pll(-nd,1-cz), nn));
            }
        }
    }
    ll count=0;
    for(ll i=2;i<=n;i++)
    {
        //cout<<" eyah: "<<disf[i]<<" "<<disw[0][i]<< " "<<disw[1][i]<<"\n";
        if(disf[i]<disw[0][i]&&disf[i]<disw[1][i])
        {
            count++;
        }
    }
    cout<<count;
    return 0;
}   