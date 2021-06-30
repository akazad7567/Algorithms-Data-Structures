#include<bits/stdc++.h>
using namespace std;
#define M 500
int dp[M][M];
#define INF 0x3f3f3f

int evalute_table(int i,int w,int n)
{
    if(w<0) return INF;
    if(i==n)
    {
        if(w==0) return 0;
        return INF;
    }
    return dp[i][w];
}

int coin_change_iterative(int ar[],int n,int w)
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=w;j++)
        {
            int r1=1+evalute_table(i+1,j-ar[i],n);
            int r2=evalute_table(i+1,j,n);
            dp[i][j]=min(r1,r2);
        }
    }
    return dp[0][w];

}
int main()
{
    int n,w;
    cin>>n>>w;
    int ar[n+10];
    for(int i=0;i<n;i++) cin>>ar[i];
    cout<<coin_change_iterative(ar,n,w)<<endl;
}
