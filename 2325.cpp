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


ll n,m;
vector<pll> v[NMAX];
ll bf[NMAX]={0};
bool na[NMAX][NMAX];

ll dij(bool x)
{
    
    ll dis[NMAX];
    for(ll i=0;i<NMAX;i++)
    {
        dis[i]=LLONG_MAX;
    }
    dis[1]=0;
    
    priority_queue<pll> pq;
    
    pq.push(pll(0,1));
    
    while(!pq.empty())
    {
        pll z=pq.top();
        pq.pop();
        
        ll nn=z.second;
        ll np=-z.first;
        
        if(np>dis[nn])
        {
            continue;
        }
        
        for(auto j:v[nn])
        {
            ll an=j.first;
            if(na[nn][an])
            {
                continue;
            }
            if(dis[an]>np+j.second)
            {
                dis[an]=np+j.second;
                pq.push(pll(-dis[an],an));
                if(x)
                {
                    bf[an]=nn;
                    //cerr<<an<<" to "<<nn<<"\n";
                }
            }
        }
    }
    return dis[n];
}

int main()
{
    
    cin>>n>>m;
    
    for(ll i=0;i<m;i++)
    {
        ll a,b,g;
        cin>>a>>b>>g;
        v[a].push_back(pll(b,g));
        v[b].push_back(pll(a,g));
    }
    
    for(ll i=0;i<NMAX;i++)
    {
        for(ll j=0;j<NMAX;j++)
        {
            na[i][j]=false;
        }
    }
       
    ll idis=dij(true);
    
    vector<pll> nlist;
    ll pt=n;
    while(pt!=1)
    {
        ll npt=bf[pt];
        nlist.push_back(pll(npt,pt));
        pt=npt;
    
    }
    
    ll ans=0;
    for(auto w:nlist)
    {
        ll xx=w.first;
        ll yy=w.second;
        
        na[xx][yy]=true;
        na[yy][xx]=true;
        ll h=dij(false);
        na[xx][yy]=false;
        na[yy][xx]=false;
        
        ans=max(ans,h);
        
        if(h==LLONG_MAX)
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}