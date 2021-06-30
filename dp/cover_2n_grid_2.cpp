//covering 2*n grid using 2*1 and 2*2 rotation allowed

#include<bits/stdc++.h>
using namespace std;
#define M 5000
int dp[M];

int f(int n)
{
    if(n==1) return 1;
    if(n==2) return 3;
    if(dp[n]!=-1) return dp[n];
    dp[n]=f(n-1)+2*f(n-2);
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    cout<<f(n)<<endl;
}
