#include<bits/stdc++.h>
using namespace std;
#define M 100010
#define INF 1000000000000
typedef long long ll;
ll dp[M][110];

void ini()
{
    for(ll i=0;i<100005;i++)
    {
        for(ll j=0;j<105;j++)
        {
            dp[i][j]=-1LL;
        }
    }
}
ll f(ll ar[],ll n,ll k,ll k2,ll i)
{
    if(i>=n-1) return 0LL;
    if(k2>=n) return INF;
    if(dp[i][k2]!=-1LL) return dp[i][k2];
    ll ans=INF;
    for(ll j=i+1;j<=min(n-1,i+k);j++)
    {
        ans=min(ans,abs(ar[i]-ar[j])+f(ar,n,k,k-(i+k-j),j));
    }
    dp[i][k2]=ans;
    return dp[i][k2];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ini();
    ll n,k;
    cin>>n>>k;
    ll ar[n+10];
    for(ll i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    cout<<f(ar,n,k,0,0)<<endl;
}
