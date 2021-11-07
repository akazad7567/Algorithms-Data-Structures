// find 'a' (inverse of ) mod m ('m' must be co prime with 'a')

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod=1e9+7;
ll inverse(ll a,ll m)
{
    if(m==0)
    {
        return 1LL;
    }
    ll r=inverse(a,m/2);
    r=(r*r)%mod;
    if(m&1) r=(r*a)%mod;
    return r;
}
int main()
{
    ll a;
    cin>>a;

    cout<<inverse(a,mod-2)<<endl;

}
