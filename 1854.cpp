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
    ll n, m,k;
    cin >> n >> m >> k;
    vector<pll> r[NMAX];
    for( ll i=0; i<m; i++ )
    {
        ll a, b, d;
        cin >> a >> b >> d;
        r[a].push_back(pll(b, d));
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<ll> ans[105];
    pq.push(pll(0, 1)); // (distance, node)
    while(!pq.empty())
    {
        ll cd = pq.top().first; // current distance
        ll cn = pq.top().second; // current node
        pq.pop();
        if(ans[cn].size() >= k) // if we already have k distances for this node, skip
            continue;
        ans[cn].push_back(cd);
        for(auto& edge : r[cn])
        {
            ll nn = edge.first; // next node
            ll nd = cd+edge.second; // distance to next node
            
            pq.push(pll(nd, nn));
        }
    }
    for(ll i=1;i<=n;i++)
    {
        if(ans[i].size() < k)
        {
            cout << "-1\n";
            continue;
        }
        else
        {
            cout<< ans[i][k-1]<<"\n"; // k-th smallest distance
        }
    }
}