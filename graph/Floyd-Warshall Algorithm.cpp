//Given an undirected weighted graph G with n vertices.

#include<bits/stdc++.h>
using namespace std;
#define MAX 500
#define INF 0x3f3f3f
int d[MAX][MAX];
int prnt[MAX][MAX];
int n;
void ini()
{
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            if(i==j)
                d[i][j]=0;
            else
                d[i][j]=INF;
            prnt[i][j]=-1;
        }
    }
}

void floydW()
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(d[i][j]>d[i][k]+d[k][j])
                {
                    d[i][j] =d[i][k] + d[k][j];
                    prnt[i][j]=prnt[k][j];
                }

            }
        }
    }
    // if there are negative weight edges in the graph
    /*
    for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][k] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}
*/

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<i<<"->"<<j<<"= "<<d[i][j]<<',';
        }
        cout<<endl;
    }
}
int main()
{
    ini();
    int m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        d[u][v]=w;
        d[v][u]=w;
        prnt[u][v]=u;
        prnt[v][u]=v;
    }
    floydW();


}

/*
4 5
0 1 3
0 2 3
1 2 8
1 3 4
2 3 1
*/
