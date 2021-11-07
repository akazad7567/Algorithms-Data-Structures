//time complexity log(n)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod=1e9+7;
ll const mxn=1e7;

ll fact[mxn+10],inv[mxn+10];

ll bpow(ll a,ll n)
{
    if(n==0) return 1LL;
    ll r=bpow(a,n/2);
    r=(r*r)%mod;
    if(n&1) r=(r*a)%mod;
    return r;

}
void cal()
{
    fact[0]=inv[0]=1;
    for(ll i=1;i<mxn;i++) fact[i]=(fact[i-1]*i)%mod;
    inv[mxn-1]=bpow(fact[mxn-1],mod-2);

    for(ll i=mxn-2;i>=1;i--) inv[i]=(inv[i+1]*(i+1))%mod;
}
int main()
{
    cal();

    ll n,r;
    cin>>n>>r;
    cout<<(fact[n]*inv[r]%mod*inv[n-r])%mod<<endl;
}
