//You are given a directed graph with n vertices and m edges

#include<bits/stdc++.h>
using namespace std;

#define MAXN 500
int n;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> ans;

void dfs (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to])
			dfs (to);
	}
	ans.push_back (v);
}

void topological_sort() {
	for (int i=0; i<n; ++i)
		used[i] = false;
	ans.clear();
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs (i);
	reverse (ans.begin(), ans.end());
	for(auto it=ans.begin();it!=ans.end();++it)
    {
        printf("%d ",*it);
    }
    printf("\n");
}

int main()
{
    int edge;
    scanf("%d %d",&n,&edge);
    for(int i=0;i<edge;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
    }
    topological_sort();
}

/*
7 7
1 3
2 3
2 5
3 4
4 6
5 6
6 7
*/
