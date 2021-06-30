//for DAG(directed acyclic graph)
//time complexity n*n

#include<bits/stdc++.h>
using namespace std;
#define M 500
#define INF 0x3f3f3f
int w[M][M];
int dp[M];

int f(int u,int n)
{
    if(u==n-1) return 0;
    if(dp[u]!=-1) return dp[u];
    int ans=INT_MAX;

    for(int v=0;v<n;v++)
    {
        if(w[u][v]!=INF)
        {
            ans=min(ans,f(v,n)+w[u][v]);
        }
    }
    dp[u]=ans;
    return dp[u];
}
int main()
{
    int N,E;
    cin>>N>>E;
    fill(dp,dp+M,-1);
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<M;j++)
        {
            w[i][j]=INF;
        }
    }
    for(int i=0;i<E;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        w[u][v]=wt;
    }

    cout<<f(0,N)<<endl;
}
/*
5 6
0 3 1
0 1 2
3 1 3
1 2 1
1 4 9
2 4 3
*/
