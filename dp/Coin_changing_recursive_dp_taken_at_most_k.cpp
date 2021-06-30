#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f
#define M 500
int dp[M][M];
int k;
int f(int ar[],int n,int w,int k2)
{
    cout<<w<<' '<<k2<<endl;
    if(w<0) return INF;
    if(k2>k) return INF;
    if(w==0) return 0;
    if(dp[w][k2]!=-1) return dp[w][k2];

    int ans=INF;
    k2=0;
    for(int i=0;i<n;i++)
    {
        ans=min(ans,1+f(ar,n,w-ar[i],k2+1));
    }
    dp[w][k2]=ans;
    return dp[w][k2];
}
int main()
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<M;j++)
        {
            dp[i][j]=-1;
        }
    }
    int n,w;
    cin>>n>>w>>k;
    int ar[n+10];
    for(int i=0;i<n;i++) cin>>ar[i];

    cout<<f(ar,n,w,0)<<endl;
}

/*
5 22 1
2 5 9 13 15
*/
