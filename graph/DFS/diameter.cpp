/*
approach->
1.Pick any vertex as source vertex.
2.Find the most distant vertex from the source. Make this vertex new source.
3.Repeat step 2 two times.
4.Distance between the source and the the most distant vertex from the source is diameter
*/




#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>>adj;
map<int,bool>visited;
map<int,int>d;//distance
int x=INT_MIN;
int nxt=0;
void clean()
{
    adj.clear();
    visited.clear();
    d.clear();
}

void DFS(int node)
{
    visited[node]=true;

    for(int u:adj[node])
    {
        if(visited[u]==false)
        {
            d[u]=d[node]+1;
            if(x<d[u])
            {
                x=max(x,d[u]);
                nxt=u;
            }
            DFS(u);
        }
    }

}
int main()
{
    int V,E;
    while(scanf("%d %d ",&V,&E)!=EOF)
    {
        clean();
        int n1,n2;
        for(int i=0;i<E;i++)
        {

            scanf("%d %d",&n1,&n2);
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }
        DFS(n1);//choose any node(n1) and find maximum distance from this node(n1)
        visited.clear();
        d.clear();
        x=INT_MIN;
        DFS(nxt);//next is the maximum distance form n1;
        cout<<"Diameter is ="<<x+1<<endl;
    }

}
