#include<bits/stdc++.h>
using namespace std;


void initialize(int ar[],int sz[],int n)
{
    for(int i=0;i<n;i++)
    {
        ar[i]=i;//protteke protteker baba
        sz[i]=1;//so, prottek set a ekta kore element thakbe
    }
}

int root(int ar[],int i)
{
    while(ar[i]!=i)//jodi i ,i er baba na hoy or root na hoy -> root khujte thakbe
    {
        ar[i]=ar[ar[i]];
        i=ar[i];
    }
    return i;
}
void Union(int ar[],int sz[],int a,int b)
{
    int rootA=root(ar,a);//a er baba
    int rootB=root(ar,b);//b er baba

    if(sz[rootA]<sz[rootB])//baba poriborton hosse
    {
        ar[rootA]=ar[rootB];
        sz[rootB]+=sz[rootA];
    }
    else//baba poriborton hosse
    {
        ar[rootB]=ar[rootA];
        sz[rootA]+=sz[rootB];
    }
}
int main()
{

    int ar[20050],sz[20050];
    int a,b,n;
    printf("Enter the number of Node/Vertices\n");
    scanf("%d",&n);
    initialize(ar,sz,n);
    int cnct;
    printf("Enter the number of connection\n");
    scanf("%d",&cnct);

    for(int i=0;i<cnct;i++){
    scanf("%d %d",&a,&b);
    Union(ar,sz,a,b);
    }
    for(int i=0;i<n;i++) printf("%d er baff %d\n",i,ar[i]);
    for(int i=0;i<n;i++) printf("%d er size %d\n",i,sz[i]);

    int Nset=0;
    for(int i=0;i<n;i++)
    {
        if(ar[i]==i) Nset++;
    }
    printf("Number of set %d\n",Nset);

}
