#include<bits/stdc++.h>
using namespace std;
#define INF -1e15
typedef long long ll;
ll dp[115][100050];

void ini(ll n,ll w)
{
    for(ll i=0;i<n+5;i++)
    {
        for(ll j=0;j<w+5;j++)
        {
            dp[i][j]=-1LL;
        }
    }
}
ll f(ll w[],ll v[],ll i,ll c,ll n)
{
    if(c<0) return INF;
    if(i==n)
    {
        return 0;
    }
    if(dp[i][c]!=-1LL) return dp[i][c];

    ll r1=f(w,v,i+1,c,n);
    //cout<<r1<<",,"<<c<<","<<i<<endl;
    ll r2=v[i]+f(w,v,i+1,c-w[i],n);
    dp[i][c]=max(r1,r2);
    //cout<<c<<","<<r1<<","<<r2<<endl;
    return dp[i][c];


}
int main()
{
    ll n,c;
    cin>>n>>c;
    ll w[n+10],v[n+10];
    ini(n,c);
    for(ll i=0;i<n;i++)
    {
       cin>>w[i]>>v[i];
    }

    cout<<f(w,v,0,c,n)<<endl;

}
