#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 100050
#define INF 10000000000
ll dp[M];

ll f(ll ar[],ll n,ll i)
{
    if(i==n-1) return 0LL;
    if(i>=n) return INF;
    if(dp[i]!=-1LL) return dp[i];
    ll r1=abs(ar[i]-ar[i+1])+f(ar,n,i+1);
    ll r2=abs(ar[i]-ar[i+2])+f(ar,n,i+2);
    dp[i]=min(r1,r2);
    return dp[i];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    fill(dp,dp+M,-1LL);
    ll n;
    cin>>n;
    ll ar[n+10];
    for(ll i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    cout<<f(ar,n,0LL)<<endl;
}
