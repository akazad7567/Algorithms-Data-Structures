//find a subsequence of an array which is maximize the following expression
////a1-a2+a3-a4+a5........ can't take consecutive element
#include<bits/stdc++.h>
using namespace std;
#define M 1000
int dp[M][2];
int ar[M];

int f(int i,int cnt,int n)
{
    if(i>=n) return 0;
    if(dp[i][cnt%2]!=-1) return dp[i][cnt%2];

    int r1=f(i+1,cnt,n);
    int r2=f(i+2,cnt+1,n)+(ar[i]*pow(-1,cnt%2));
    return dp[i][cnt%2]=max(r1,r2);
}
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);

    for(int i=0;i<n;i++) cin>>ar[i];
    cout<<f(0,0,n)<<endl;
}
