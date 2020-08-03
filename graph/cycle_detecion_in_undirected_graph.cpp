#include<bits/stdc++.h>
using namespace std;
#define MAX 500
vector<int>g[MAX];
vector<int>prnt(MAX),sz(MAX);
int n;

void ini()
{
    for(int i=0;i<MAX;i++)
    {
        prnt[i]=i,sz[i]=1;
    }
}

int findPrant(int i)
{
    if(prnt[i]!=i)
    {
        i=prnt[i];
        findPrant(i);
    }
    return prnt[i];
}

void Union(int A,int B)
{
    int rootA=findPrant(A);
    int rootB=findPrant(B);
    if(sz[rootA]<rootB)
    {
        prnt[rootA]=rootB;
        sz[rootB]+=sz[rootA];
    }
    else
    {
        prnt[rootB]=rootA;
        sz[rootA]+=sz[rootB];
    }
}
int main()
{
    ini();
    int edge;
    scanf("%d %d",&n,&edge);
    int Ncycle=0;
    for(int i=0;i<edge;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        int rootU=findPrant(u);
        int rootV=findPrant(v);
        if(rootU!=rootV)
        {
            Union(u,v);
        }
        else Ncycle++;
    }
    printf("%d\n",Ncycle);


}

/*
6 7
1 2
1 3
2 3
3 4
3 5
5 6
4 6
*/
