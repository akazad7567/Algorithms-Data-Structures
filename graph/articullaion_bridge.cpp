//We are given an undirected graph

#include<bits/stdc++.h>
using namespace std;
#define MAX 500

vector<int>adj[MAX];
int timer=0;
vector<int>vis(MAX),tin(MAX),low(MAX);

void dfs(int v,int p=-1)
{
    vis[v]=true;
    tin[v]=low[v]=timer++;
    for(int to:adj[v])
    {
        if(to==p) continue;
        if(vis[to]) low[v]=min(low[v],tin[to]);
        else
        {
            dfs(to,v);
            low[v]=min(low[v],low[to]);
            if(tin[v]<low[to])
                printf("%d %d\n",v,to);
        }
    }
}
int main()
{
    int n,edge;
    scanf("%d %d",&n,&edge);
    for(int i=0;i<edge;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<"the bridges are:\n";
    dfs(0);
}

/*
6 6
0 1
1 3
3 4
4 5
0 2
1 2
*/
