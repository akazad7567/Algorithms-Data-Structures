//Single source shortest path with negative weight edges
//we are given a weighted directed graph G with n vertices and m edges
//time complexity is n
//Run Bellman_Ford_Algorithms 1 more itteration,
// if still distace are changed then we can say there are a negative cycle

#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 500
typedef pair<int,int>PII;
int n,m;

struct add
{
    int a,b,cost;
};
void solve(add e[])
{
    vector<int> d (n, INF);
    vector<int>prnt(n,-1);
    int src=0;
    d[src] = 0;
    bool neg_cycle=false;
    for (int i=1;i<=n;i++)
    {
        bool any = false;

        for (int j=0; j<m; ++j){
            if (d[e[j].a] < INF){
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    if(i==n) neg_cycle=true;
                    d[e[j].b] = d[e[j].a] + e[j].cost;
                    any = true;
                    prnt[e[j].b]=e[j].a;
                }
            }
        }



        if (!any) break;
    }
    if(neg_cycle) printf("Negative cycle found!\n");
    // display d, for example, on the screen
    for(int i=1;i<n;i++) printf("%d %d->%d\n",prnt[i],i,d[i]);
}
int main()
{
    add e[5000];
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        e[i].a=u;
        e[i].b=v;
        e[i].cost=w;
    }

    solve(e);
}

/*
4 4
0 1 1000
0 2 500
2 3 -500
3 0 -1
*/
