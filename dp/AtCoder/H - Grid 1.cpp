#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1005
ll dp[M][M];
int r,c;
char ch[M][M];
int const mod=1e9+7;

ll cal(int i,int j)
{
    if(i>=r or j>=c or ch[i][j]=='#') return 0;
    if(i==r-1 and j==c-1) return 1;
    if(dp[i][j]!=-1) return (dp[i][j])%mod;

    int r1=cal(i+1,j);
    int r2=cal(i,j+1);
    return dp[i][j]=(r1+r2)%mod;
}
int main()
{
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>ch[i][j];
        }
    }
    memset(dp,-1,sizeof dp);

    cout<<cal(0,0)<<endl;
}
