#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int prnt[200000];
int sz[200000];

void ini(int n)
{
    for(int i=1;i<=n;i++) prnt[i]=i,sz[i]=1;
}

int fndRoot(int i)
{
    if(prnt[i]!=i) prnt[i]=fndRoot(prnt[i]);
    return prnt[i];
}
int Union(int u,int v)
{
    int rootU=fndRoot(u);
    int rootV=fndRoot(v);
//    cout<<"debug= "<<rootU<<' '<<rootV<<' '<<sz[rootU]<<' '<<sz[rootV]<<endl;
    if(rootU==rootV) return 0;
    int ans=abs(sz[rootU]-sz[rootV]);

    if(sz[rootU]<sz[rootV])
    {
        prnt[rootU]=prnt[rootV];
        sz[rootV]+=sz[rootU];
    }
    else
    {
        prnt[rootV]=prnt[rootU];
        sz[rootU]+=sz[rootV];
    }

    return ans;

}
int main()
{
    int n;
    cin>>n;
    ini(n);

    int k;
    cin>>k;
    vector<pair<int,int>>vec;
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        Union(a,b);
        vec.push_back({a,b});
    }
//    cout<<endl<<endl;

    for(auto x:vec)
    {
//        cout<<x.first<<' '<<x.second<<' '<<sz[x.first]<<' '<<sz[x.second]<<endl;
        cout<<Union(x.first,x.second)<<endl;
    }

//    int cnt=0;
//
////    for(int i=1;i<=n;i++) prnt[i]=fndRoot(i);
//
//    for(int i=1;i<=n;i++)
//    {
//        if(prnt[i]==i) cnt++;
//    }
//
//    cout<<cnt<<endl;
}
