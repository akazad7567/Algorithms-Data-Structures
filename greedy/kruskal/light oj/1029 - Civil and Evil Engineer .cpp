#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pr;
int N;
pair<int,pair<int,int>>p[12100];
int prnt[150],sz[150];
void ini()
{
    for(int i=0;i<=N;i++)
    {
        prnt[i]=i,sz[i]=1;
    }
}

bool sortby(pair<int,int>a,pair<int,int>b)
{
    return a.first>b.second;
}

bool sortby2(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.first<b.first;
}

int findParnt(int i)
{
    if(prnt[i]!=i) prnt[i]=findParnt(prnt[i]);
    return prnt[i];
}

void Union(int u,int v)
{
    int rootA=findParnt(u);
    int rootB=findParnt(v);
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

int kruskal(int edge)
{
    int totCost=0;
    for(int i=edge-1;i>=0;i--)
    {
        int u=p[i].second.first;
        int v=p[i].second.second;
        int cost=p[i].first;

        if(findParnt(u)!=findParnt(v))
        {
            totCost+=cost;
            Union(u,v);

        }
    }
    return totCost;
}

int kruskal2(int edge)
{
    int totCost=0;
    for(int i=0;i<edge;i++)
    {
        int u=p[i].second.first;
        int v=p[i].second.second;
        int cost=p[i].first;

        if(findParnt(u)!=findParnt(v))
        {
            totCost+=cost;
            Union(u,v);

        }
    }
    return totCost;
}
int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
    cas++;
    scanf("%d",&N);
    ini();
//    printf("\n");
    int edge=0;
    for(int i=0;;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        edge=i;
        if(u==0 and v==0 and w==0) break;
        p[i]={w,{u,v}};



    }

    sort(p,p+edge);

    int mxCost=kruskal(edge);
    ini();
    sort(p,p+edge);
    int mnCost=kruskal2(edge);
//    cout<<mxCost<<' '<<mnCost<<endl;


    if((mnCost+mxCost)%2==0)
    printf("Case %d: %d\n",cas,(mnCost+mxCost)/2);
    else printf("Case %d: %d/2\n",cas,(mnCost+mxCost));

    }

}
