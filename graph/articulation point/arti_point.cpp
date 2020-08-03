//We are given an undirected graph

#include<bits/stdc++.h>
using namespace std;
#define MAX 5000
vector<int>adj[MAX];
vector<bool>vis(MAX);
int timer=0;
vector<int>low(MAX),tin(MAX);

void dfs(int v,int p=-1)
{
    vis[v]=true;
    int child=0;
    tin[v]=low[v]=timer++;
    for(size_t i=0;i<adj[v].size();i++)
    {
        int to=adj[v][i];
        if(to==p) continue;
        if(vis[to]) low[v]=min(tin[to],low[v]);
        else
        {
            dfs(to,v);
            low[v]=min(low[v],low[to]);
            if(tin[v]<=low[to] and p!=-1)
                printf("%d ",v);
                child++;
        }
    }
    if(p==-1 and child>1)
        printf("%d ",v);
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
    dfs(0);
    printf("\n");
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
