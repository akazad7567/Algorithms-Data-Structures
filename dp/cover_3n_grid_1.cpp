//covering 3*n grid using 3*1 and 3*2 rotation allowed

#include<bits/stdc++.h>
#define M 5000
using namespace std;
int dp[M];

int f(int n)
{
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 6;
    if(n<1) return 0;
    if(dp[n]!=-1) return dp[n];
    dp[n]=f(n-1)+f(n-2)+3*f(n-3);
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    cout<<f(n)<<endl;
}
