#include<bits/stdc++.h>
using namespace std;
#define M 500
int dp[M][M];

void ini()
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<M;j++)
        {
            dp[i][j]=-1;
        }
    }
}
int f(int n,int r)
{
    if(n==r or (n>=0 and r==0)) return 1;
    if(r>n) return 0;
    if(dp[n][r]!=-1) return dp[n][r];

    int res=f(n-1,r-1)+f(n-1,r);
    dp[n][r]=res;
    return dp[n][r];
}
int main()
{
    ini();
    int n,r;
    cin>>n>>r;
    cout<<f(n,r)<<endl;
}
