#include<bits/stdc++.h>
using namespace std;

ll m,n;
ll ar[12];
ll dp[12][12];

ll f(ll prv,ll cnt)
{
//    debug(prv,cnt);

    if(cnt==n) return 1;
//    if(pos>=m or cnt>n) return 0;
    if(dp[prv][cnt]!=-1) return dp[prv][cnt];

    ll ret=0;
    for(ll v=0;v<m;v++)
    {
        ll val=0;

        if(abs(prv-ar[v])<=2 or prv==0)
        {
            val=f(ar[v],cnt+1);
        }
        ret+=val;
//        debug(ret,val,cnt);
    }
//    debug(prv,cnt,ret);
    return dp[prv][cnt]=ret;
}
int main()
{
    ll t,tks=0;
    cin>>t;
    while(t--)
    {
       memset(dp,-1,sizeof dp);
       cin>>m>>n;
       for(ll i=0;i<m;i++) cin>>ar[i];

       cout<<"Case "<<++tks<<": "<<f(0,0)<<endl;
    }
}
