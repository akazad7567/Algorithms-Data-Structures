#include<bits/stdc++.h>
using namespace std;

void makeSet(int prnt[],int sz[],int n)
{
    for(int i=0;i<n;i++)
    {
        prnt[i]=i;
        sz[i]=1;
    }
}

int findPrnt(int prnt[],int i)
{
    if(prnt[i]!=i) prnt[i]=findPrnt(prnt,prnt[i]);
    return prnt[i];
}

void Union(int prnt[],int sz[],int a,int b)
{
    int rootA=findPrnt(prnt,a);
    int rootB=findPrnt(prnt,b);

    if(sz[rootA]<sz[rootB])
    {
        prnt[rootA]=prnt[rootB];
        sz[rootB]+=sz[rootA];
    }
    else
    {
        prnt[rootB]=prnt[rootA];
        sz[rootA]+=sz[rootB];
    }
}
int main()
{
    int prnt[20050],sz[20050];
    int n;
    printf("Enter the number of element\n");
    scanf("%d",&n);
    makeSet(prnt,sz,n);

    int cnct;
    printf("Enter the number of connection\n");
    scanf("%d",&cnct);
    for(int i=0;i<cnct;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        Union(prnt,sz,a,b);
    }

    for(int i=0;i<n;i++)
    {
        printf("%d er baff %d\n",i,prnt[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d set a element ace %d daa \n",i,sz[i]);
    }
    int Nset=0;

    for(int i=0;i<n;i++)
    {
        if(prnt[i]==i) Nset++;
    }

    printf("total set ace %d daa\n",Nset);
}
