//Time complexity n*W
#include<bits/stdc++.h>
using namespace std;
#define M 500
int dp[M][M];
#define INF 0x3f3f3f
int n;
int f(int ar[],int i,int w)
{
    if(w<0) return INF;
    if(n==i)
    {
        if(w==0) return 0;
        return INF;
    }

    if(dp[i][w]!=-1)
        return dp[i][w];

    int r1=1+f(ar,i+1,w-ar[i]);
    int r2=f(ar,i+1,w);
    dp[i][w]=min(r1,r2);
    return dp[i][w];
}
int main()
{
    int w;
    cin>>n>>w;
    int ar[n+10];
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<M;j++)
        {
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++) cin>>ar[i];
    int r=f(ar,0,w);
    cout<<r<<endl;
}
