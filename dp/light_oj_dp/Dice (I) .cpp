#include<bits/stdc++.h>
using namespace std;
#define M1 1005
#define M2 15005
typedef long long ll;
const ll mod=100000007;
ll dp[2][M2];
ll csum[2][M2];

int main()
{
    ll t;
    cin>>t;
    ll tks=0;
    while(t--)
    {
        tks++;
        ll n,k,w;
        cin>>n>>k>>w;

        for(ll i=1;i<=w;i++) csum[(n+1)%2][i]=1,dp[(n+1)%2][i]=0;
        dp[(n+1)%2][0]=1,csum[(n+1)%2][0]=1;

        for(ll i=n;i>=1;i--)
        {
            dp[i%2][0]=csum[i%2][0]=0;

            for(ll j=1;j<=w;j++)
            {
                if(j-k-1>=0) dp[i%2][j]=(csum[(i+1)%2][j-1]-csum[(i+1)%2][j-k-1]);
                else dp[i%2][j]=csum[(i+1)%2][j-1];
                if(dp[i%2][j]<0) dp[i%2][j]=mod+dp[i%2][j];
                dp[i%2][j]=(dp[i%2][j])%mod;
                csum[i%2][j]=(csum[i%2][j-1]+dp[i%2][j])%mod;
                //cout<<i<<','<<j<<' '<<dp[i][j]<<' '<<csum[i][j]<<endl;

            }
//            cout<<i<<' '<<dp[i][w]<<' '<<csum[i][w]<<endl;

        }
        cout<<"Case "<<tks<<": "<<dp[1][w]<<endl;
    }
}

