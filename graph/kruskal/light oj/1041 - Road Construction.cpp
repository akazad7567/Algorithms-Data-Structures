#include<bits/stdc++.h>
using namespace std;
pair<int,pair<string,string>>p[150];

map<string,string>prnt;
map<string,int>sz;

string findPrnt(string i)
{
    if(prnt[i]!=i) prnt[i]=findPrnt(prnt[i]);
    return prnt[i];
}

void Union(string u,string v)
{
    string rootA=findPrnt(u);
    string rootB=findPrnt(v);
//    cout<<rootA<<' '<<rootB<<endl;
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
int kruskal(int E)
{
    int mnCost=0;
    for(int i=0;i<E;i++)
    {

        int w;
        string u,v;
        u=p[i].second.first;
        v=p[i].second.second;
        w=p[i].first;
        if(findPrnt(u)!=findPrnt(v))
        {
            mnCost+=w;
            Union(u,v);
        }

    }
    return mnCost;
}
int main()
{
//    freopen("out2.txt","w",stdout);
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
    cas++;
    int E;
    scanf("%d",&E);
    string st;
    for(int i=0;i<E;i++)
    {
        string u,v;
        int w;
        cin>>u>>v;
        cin>>w;
        p[i]={w,{u,v}};
        prnt[u]=u;
        prnt[v]=v;
        sz[u]=1;
        sz[v]=1;
    }
//    cout<<"ans= \n";
    sort(p,p+E);

    int ans=kruskal(E);
    for(int i=0;i<E;i++)
    {
        string u1,u2;
        u1=p[i].second.first;
        u2=p[i].second.second;
        Union(u1,u2);
    }
    bool bb=false;
////    cout<<endl<<endl;
//    cout<<prnt["ag"]<<endl;
//    cout<<prnt[p[0].second.first]<<endl;
    string baba=prnt[p[0].second.first];
    for(int i=1;i<E;i++)
    {
//        cout<<p[i].second.first<<' '<<p[i].second.second<<endl;
        string a,b;
        a=p[i].second.first;
        b=p[i].second.second;
//        cout<<prnt[a]<<' '<<prnt[b]<<endl;
        if(baba!=prnt[a])
        {
            bb=true;
            break;
        }
        if(baba!=prnt[b])
        {
            bb=true;
            break;
        }
    }
    if(bb) printf("Case %d: Impossible\n",cas);
    else printf("Case %d: %d\n",cas,ans);

    prnt.clear();
    sz.clear();
    }
}
