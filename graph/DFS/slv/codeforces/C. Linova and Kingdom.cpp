#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>adj[200510];
vector<bool>visited(200510);
vector<ll>d1(200510),d2(200510),p(200510);
vector<ll>vec;

void clean()
{
    for(ll i=0; i<200010; i++)
    {
        adj[i].clear();
        visited[i]=false;
        d1[i]=0,d2[i]=0;
        p[i]=0;

    }
    vec.clear();

}

void DFS(ll node,ll prnt)
{

    visited[node]=true;
    for(ll u:adj[node])
    {
        if(visited[u]==false and prnt!=u)
        {
            d1[u]+=d1[node]+1;;
            DFS(u,node);
            d2[node]+=d2[u]+1;
           // cout<<node<<' ';

        }
    }
   if(node!=1)
   {
      vec.push_back(d1[node]-d2[node]);
   }
}

int main()
{
    ll n,x;
    while(scanf("%lld  %lld",&n,&x)!=EOF)
    {
        clean();
        //clean2();
        ll n1,n2;
        ll re=0;
        for(ll i=0; i<n-1; i++)
        {
            scanf("%lld %lld",&n1,&n2);
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }

        DFS(1LL,0LL);
       // cout<<endl;
        sort(vec.begin(),vec.end());//sort the distance of node
        reverse(vec.begin(),vec.end());

        for(ll i=0;i<x;i++) re+=vec[i];
        cout<<re<<endl;
        clean();



    }
}


