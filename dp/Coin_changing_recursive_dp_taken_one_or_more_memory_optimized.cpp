#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f
#define M 500
int dp[M];

int f(int ar[],int n,int w)
{
    if(w<0) return INF;
    if(w==0) return 0;
    if(dp[w]!=-1) return dp[w];

    int ans=INF;
    for(int i=0;i<n;i++)
    {
        ans=min(ans,1+f(ar,n,w-ar[i]));
    }
    dp[w]=ans;
    return dp[w];
}
int main()
{
    fill(dp,dp+M,-1);
    int n,w;
    cin>>n>>w;
    int ar[n+10];
    for(int i=0;i<n;i++) cin>>ar[i];

    cout<<f(ar,n,w)<<endl;
}

/*
5 22
2 5 9 13 15
*/
