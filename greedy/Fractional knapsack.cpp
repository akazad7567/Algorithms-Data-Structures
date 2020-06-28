#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int,int>PII;
typedef long long ll;

bool cmp(pair<int,int>a,pair<int,int>b)
{
    return a.second*b.first>a.first*b.second;
}

int main()
{
    vector<PII>v;

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int price,weight;
        scanf("%d %d",&weight,&price);
        v.push_back(PII(weight,price));
    }
    sort(v.begin(),v.end(),cmp);
//    cout<<endl;
//    for(int i=0;i<n;i++)
//    {
//        cout<<v[i].first<<' '<<v[i].second<<endl;
//    }
    int w,ans=0;
    scanf("%d",&w);
    for(int i=0;i<n;i++)
    {
        int z=min(w,v[i].first);
        w-=z;
        ans+=(((double)v[i].second/v[i].first)*z);


    }
    printf("Maximum cost: %d\n",ans);
}
