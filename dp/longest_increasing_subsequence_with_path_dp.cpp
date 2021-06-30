#include<bits/stdc++.h>
using namespace std;
#define M 500
int dp[M];
int prnt[M];
int f(int i,vector<int>&a)
{
    int n=a.size();
    if(dp[i]!=-1) return dp[i];
    int cur=0;
    int ans=0;
    for(int j=i+1;j<n;j++)
    {
        if(a[i]<a[j])
        {
            cur=f(j,a);
            if(cur>ans)
            {
                ans=cur;
                prnt[i]=j;
            }
        }
    }

    dp[i]=ans+1;
    return dp[i];
}
void fndLIS(vector<int>&a)
{
    int n=a.size();
    int cur=0,strt=-1;
    int ans=0;

    for(int i=0;i<n;i++)
    {
        cur=f(i,a);
        if(ans<cur)
        {
            ans=cur;
            strt=i;
        }
    }

    cout<<"Path: "<<strt<<' ';
    while(prnt[strt]!=-1)
    {
        int val=prnt[strt];
        strt=prnt[strt];
        cout<<val<<' ';
    }
    cout<<endl;
}
int main()
{
    int n;
    scanf("%d",&n);
    vector<int>vec;

    fill(dp,dp+n,-1);
    fill(prnt,prnt+n,-1);

    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        vec.push_back(a);
    }
    fndLIS(vec);
}
