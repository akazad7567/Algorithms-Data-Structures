#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>vec;

bool sortby(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.first+max(a.second,b.first)+b.second<b.first+max(b.second,a.first)+a.second;
}
int main()
{
    int n;//number of set;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        vec.push_back({a,b});
    }
    int ans=0;
    sort(vec.begin(),vec.end(),sortby);
    for(int i=0;i<n-1;i++)
    {
        ans+=vec[i].first+max(vec[i].second,vec[i+1].first)+vec[i+1].second;
    }
    printf("%d\n",ans);
}
