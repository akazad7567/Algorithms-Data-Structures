//Given a weighted undirected graph.


#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;
#define INF 0x3f3f3f3f

void make(vector<pair<int,int>> adj[],int u,int v,int w)
{
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

void prims(vector<pair<int,int>>adj[],int V)
{
    priority_queue<pr,vector<pr>,greater<pr> >pq;
    vector<int>key(V,INF);
    vector<int>prnt(V,-1);
    vector<bool>inMST(V,false);
    int src=0;
//    cout<<"Enter the starting node \n";
//    scanf("%d",&src);
    key[src]=0;
    int ans=0;
    pq.push(make_pair(0,src));
    int cost=0;

    while(!pq.empty())
    {
        int u=pq.top().second;
        ans+=pq.top().first;
        pq.pop();
        inMST[u]=true;


        for(auto it:adj[u])
        {
            int v=it.first;
            int w=it.second;
            if(inMST[v]==false and key[v]>w)
            {
                //key update
                key[v]=w;
                pq.push(make_pair(key[v],v));
                prnt[v]=u;
            }
        }
    }
    cout<<ans<<endl;

    for(int i=1;i<V;i++) printf("%d -> %d\n",prnt[i],i);
}

int main()
{
    int N;
    scanf("%d",&N);
    vector<pr>adj[N];
    int edg;
    scanf("%d",&edg);

    for(int i=0;i<edg;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        make(adj,u,v,w);

    }

    prims(adj,N);

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
