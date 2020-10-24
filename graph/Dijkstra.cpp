//You are given a directed or undirected weighted graph
//with n vertices and m edges. The weights of all edges are non-negative
/*
why dijkstra algorithms does not work with negative weight
ans: failure case
4 4
1 2 1000
1 3 500
3 4 -500
4 1 -1
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int,int> pr;

void add(vector<pr>adj[],int u,int v,int w)
{
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

void prims(vector<pr>adj[],int n)
{
     vector<int>key(n,INF),key2(n,0);
     vector<int>prnt(n,-1);
     vector<bool>inMST(n,false);
     int src=1;
     key[src]=0;
     inMST[src]=true;
     priority_queue<pr,vector<pr>,greater<pr>>pq;
     pq.push({0,src});
     int ans=0;
     while(!pq.empty())
     {
         int v=pq.top().second;
         int wt=pq.top().first;
         ans+=wt;
         inMST[v]=true;
         pq.pop();
         for(auto it:adj[v])
         {
             int u=it.first;
             int w=it.second;
             if(inMST[u]==false and key[u]>key[v]+w)
             {

                 key[u]=key[v]+w;
                 pq.push({key[u],u});
//                 key2[u]=key[u]+key2[v];

                 prnt[u]=v;
             }
         }
     }
     cout<<ans<<endl;
     cout<<"ans = "<<key[n]<<endl;
     for(int i=1;i<n;i++)
     {
         printf("%d %d->%d\n",prnt[i],i,key[i]);
     }
}
int main()
{
    vector<pr>adj[500];
    int n,edge;
    scanf("%d %d",&n,&edge);
    for(int i=0;i<edge;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        add(adj,u,v,w);
    }
    prims(adj,n);
}
/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

*/
