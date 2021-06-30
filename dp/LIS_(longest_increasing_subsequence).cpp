
//time complexity n*n
#include<bits/stdc++.h>
using namespace std;
#define M 500
int dp[M];


int f(int i,vector<int>&a)
{
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    int ans=0;
    for(int j=i+1;j<a.size();j++)
    {
        if(a[i]<a[j])
        {
            ans=max(ans,f(j,a));
        }
    }
    dp[i]=ans+1;
    return dp[i];
}
int fndLIS(vector<int>&a)
{
    int n=a.size();
    fill(dp,dp+n,-1);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,f(i,a));
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>vec;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        vec.push_back(a);
    }
    int ans=fndLIS(vec);
    cout<<ans<<endl;
}
