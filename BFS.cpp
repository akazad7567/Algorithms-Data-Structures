#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100010];  // adjacency list representation

vector<bool> used(100010);//()same to array
vector<int> d(100010), p(100010);


void chek(int s){

queue<int> q;

q.push(s);
used[s] = true;
//cout<<s<<' ';
p[s] = -1;
while (!q.empty()) {
    int v = q.front();
    cout<<v<<' ';
    q.pop();
    for (int u : adj[v]) {
        if (!used[u]) {
            used[u] = true;
            q.push(u);
            d[u] = d[v] + 1;
            p[u] = v;
        }
    }
}
cout<<endl;

}


int main()
{
    int n,E; // number of nodes and edges
    int s; // source vertex
    int u,v;
    while(2==scanf("%d%d",&n,&E))
    {
        for(int i=0;i<n;i++)
        {
            used[i]=false;
            adj[i].clear();
        }
        for(int i=0;i<E;i++)
        {
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            //adj[v].push_back(u);
        }
        chek(2);
    }



}
