//you are given N taksks. each task has a starting time
// finishing time, and profit. You can do any number of non-overlapping tasks and get
// the profit associated with them. Your goal is to maximize the total profit.
#include<bits/stdc++.h>
using namespace std;
#define M 10000
int dp[M];
vector<pair<pair<int,int>,int>>vec;

bool sortby(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b)
{
    return a.first.first<b.first.first;
}
int bs(int l,int val,int n)
{
    int r=n-1;
    bool f=false;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(vec[mid].first.first>val)
        {
            r=mid-1;
            f=true;
        }
        else l=mid+1;
    }
    if(f)
    return r+1;
    else return n+1;
}
int f(int i,int n)
{
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];

    int r1=f(i+1,n);
    int nxt=bs(i+1,vec[i].first.second,n);
    int r2=f(nxt,n)+vec[i].second;
    return dp[i]=max(r1,r2);
}
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)
    {
        int a,b,val;
        cin>>a>>b>>val;
        vec.push_back({{a,b},val});
    }
    sort(vec.begin(),vec.end(),sortby);

    cout<<f(0,n)<<endl;
}
