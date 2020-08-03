//You are given a directed graph G with vertices V and edges E

#include<bits/stdc++.h>
using namespace std;
#define MAX 500
vector <int>g[MAX], gr[MAX];
vector<bool> used;
vector<int> order, component;

void dfs1 (int v)
{
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (int v)
{
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}

int main()
{
    int n,edge;
    scanf("%d %d",&n,&edge);

    for (int i=0;i<n;i++)
    {
        int a, b;
        scanf("%d %d",&a,&b);
        g[a].push_back (b);
        gr[b].push_back (a);
    }

    used.assign (n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n, false);
    for (int i=0; i<n; ++i)
    {
        int v = order[n-1-i];
        if (!used[v])
        {
            dfs2 (v);
            for(auto it=component.begin();it!=component.end();it++)
            {
                cout<<*it<<' ';
            }
            cout<<endl;
            component.clear();
        }
    }
}

/*
5 5
0 1
1 2
2 0
0 4
3 2
*/
