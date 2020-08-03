//Given a weighted undirected graph.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e4+5;
pair<long long,pair<int,int>>p[MAX];
int prnt[MAX],sz[MAX];
int node,edge;
void ini()
{

    for(int i=0;i<node;i++)
    {
        prnt[i]=i;
        sz[i]=1;
    }
}
int findPrnt(int i)
{
    if(prnt[i]!=i) prnt[i]=findPrnt(prnt[i]);
    return prnt[i];
}
void Union(int x,int y)
{
    int rootA=findPrnt(x);
    int rootB=findPrnt(y);
    if(sz[rootA]<sz[rootB])
    {
        prnt[rootA]=prnt[rootB];
        sz[rootB]+=sz[rootA];
    }
    else
    {
        prnt[rootB]=prnt[rootA];
        sz[rootA]+=sz[rootB];
    }
}
int kruskal(pair<ll,pair<int,int>>p[])
{
    int x=0,y=0;
    ll cost,minmumCost=0;
    for(int i=0;i<edge;i++)
    {
        x=p[i].second.first;
        y=p[i].second.second;
        cost=p[i].first;
        if(findPrnt(x)!=findPrnt(y))
        {
            minmumCost+=cost;
            Union(x,y);
//            cout<<i<<"-> "<<cost<<endl;
        }
    }
    return minmumCost;
}
int main()
{
    long long weight,cost,minmumCost;
    //ini();
    scanf("%d %d",&node,&edge);
    ini();
    for(int i=0;i<edge;i++)
    {
        int u,v;
        scanf("%d %d %lld",&u,&v,&weight);
        p[i]=make_pair(weight,make_pair(u,v));
//        cout<<p[i].first<<endl;
    }
    sort(p,p+edge);
    minmumCost=kruskal(p);
    printf("%lld\n",minmumCost);
}
/*
5 7
0 1 1
0 2 5
1 2 7
0 3 4
0 4 3
3 4 2
2 4 6
minmumCost=11
*/
