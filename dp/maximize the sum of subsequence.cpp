//given an array with N integers find a subsequence of this array which is maximize the sum
//of subsequence where cnt't take consecutive element
#include<bits/stdc++.h>
using namespace std;
#define M 5000
int dp[M];
int ar[M];

int f(int i,int n)
{
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int ans=0;
    ans=max(f(i+1,n),ar[i]+f(i+2,n));
    return dp[i]=ans;

}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>ar[i];
    memset(dp,-1,sizeof dp);
    cout<<f(0,n)<<endl;
}

